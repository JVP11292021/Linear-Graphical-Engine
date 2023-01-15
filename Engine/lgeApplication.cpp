/*
 ________________________________________________________________________________________
| This source code is from the Github repo: Linear Graphical Engine (LGE)                |
|  Created by: JVP11292021 (J. van Polanen)                                              |
|  Started on: 06-01-2023                                                                |
|                                                                                        |
| Copyright (c) Jessy van Polanen                                                        |
|                                                                                        |
| NOTICE:                                                                                |
|   This notice must remain at the top of each file.                                     |
|________________________________________________________________________________________|
*/

#include "lgeApplication.hpp"
#include "lgeInput.hpp"
#include "lgeGFX.h"

#include <iostream>

_LGE_BEGIN_NP_LGE

Application* Application::instance = nullptr;

Application::Application() {
	this->instance = this;
	this->win = IWindow::create();
	this->win->setEventCallback(lgeBindEvent(Application::onEvent));

	this->imguiLayer = new ImGuiLayer();
	this->push_overlay(this->imguiLayer);
	
	f32 vertices[3 * 3] = {
		-0.5F, -0.5F, 0.0F, //0.8F, 0.2F, 0.8F, 1.0F,
		 0.5F, -0.5F, 0.0F, //0.2F, 0.3F, 0.8F, 1.0f,
		 0.0F,  0.5F, 0.0F, //0.8F, 0.8F, 0.2F, 1.0F,
	};

	uint32 indeces[3] = { 0, 1, 2 };

	VAO = gfx::vao::create();
	VBO = gfx::vbo::create(vertices, sizeof(vertices));

	gfx::vbl layout = {
		{gfx::glShaderDataTypes::vec3, std::string("a_Position")},
		//{gfx::glShaderDataTypes::vec4, std::string("a_Color")},
	};

	VBO->setLayout(layout);
	VAO->addVertexBuffer(VBO);

	IBO = gfx::ibo::create(indeces, 3);
	VAO->setIndexBuffer(IBO);

	shader = gfx::Shader::create(std::string("C:/Users/Jessy/OneDrive/Programming Projects/C-C++/Uncompleted Projects/Linear Game Engine/LinearEngine/Engine/basic.glsl"));

}

Application::~Application() {
	delete this->win;
}

LGE_CUDA_FUNC_DECL void Application::onEvent(hid::Event& e) {
	hid::EventDispatcher dispatcher(e);
	dispatcher.dispatch<hid::WindowCloseEvent>(lgeBindEvent(Application::onWindowClose));

	std::cout << "Event: " << e << "\n";
	
	 //This part could/causes lge::ArrayOutOfBounds exception
	for (uint32 i = 0; i < this->layerStack.getLen(); i++) {
		if (e.handled)
			break;
		this->layerStack[i]->onEvent(e);
	}
}

LGE_CUDA_FUNC_DECL void Application::push_layer(ILayer* layer) {
	this->layerStack.push_layer(layer);
	layer->onAttach();
}

LGE_CUDA_FUNC_DECL void Application::push_overlay(ILayer* layer) {
	this->layerStack.push_overlay(layer);
	layer->onAttach();
}


LGE_CUDA_FUNC_DECL void Application::run() {
	while (this->running) {
		gfx::RenderCommand::clear();
		gfx::RenderCommand::setClearColor({ 1.0F, 1.0F, 1.0F, 1.0F });
		//std::cout << "Input Windows: " << hid::Input::getMousePos()[0] << " " << hid::Input::getMousePos()[1] << std::endl;

		shader->bind();
		
		gfx::RenderCommand::draw(this->VAO);

		for (uint32 i = 0; i < this->layerStack.getLen(); i++)
			this->layerStack[i]->onUpdate();

		this->imguiLayer->begin();
		for (uint32 i = 0; i < this->layerStack.getLen(); i++)
			this->layerStack[i]->onImGuiRender();
		this->imguiLayer->end();

		this->win->onUpdate();
	}
}

LGE_CUDA_FUNC_DECL int8 Application::onWindowClose(hid::WindowCloseEvent e) {
	this->running = LGE_FALSE;
	return LGE_TRUE;
}

_LGE_END_NP_LGE