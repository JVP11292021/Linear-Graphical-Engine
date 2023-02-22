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
#include <GLFW/glfw3.h>

#include <iostream>

_LGE_BEGIN_NP_LGE

Application* Application::instance = nullptr;

Application::Application() {
	this->instance = this;
	this->win = IWindow::create();
	this->win->setEventCallback(lgeBindEvent(Application::onEvent));

	this->imguiLayer = new ImGuiLayer();
	this->push_overlay(this->imguiLayer);

}

Application::~Application() {
	delete this->win;
}

LGE_CUDA_FUNC_DECL void Application::onEvent(hid::Event& e) {
	hid::EventDispatcher dispatcher(e);
	dispatcher.dispatch<hid::WindowCloseEvent>(lgeBindEvent(Application::onWindowClose));

	std::cout << "Event: " << e << "\n";
	
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
		f32 time = (f32)glfwGetTime(); // TODO Platform::getTime;
		Timestep timestep = delta(time, this->lastFrameTime);
		this->lastFrameTime = time;

		for (uint32 i = 0; i < this->layerStack.getLen(); i++)
			this->layerStack[i]->onUpdate(timestep);

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