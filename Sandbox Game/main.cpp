#include <iostream>
#include <lge.h>

class ExampleLayer : public lge::ILayer {
private:
	std::shared_ptr<lge::gfx::Shader> shader;
	std::shared_ptr<lge::gfx::VertexArray> VAO;
	std::shared_ptr<lge::gfx::IndexBuffer> IBO;
	std::shared_ptr<lge::gfx::VertexBuffer> VBO;

	lge::gfx::OrthoCam camera;

public:
	ExampleLayer()
		: ILayer("Example")
	{
		this->camera = lge::gfx::OrthoCam(-1.6F, 1.6F, -0.9F, 0.9F);

		f32 vertices[3 * 3] = {
			-0.5F, -0.5F, 0.0F, //0.8F, 0.2F, 0.8F, 1.0F,
			 0.5F, -0.5F, 0.0F, //0.2F, 0.3F, 0.8F, 1.0f,
			 0.0F,  0.5F, 0.0F, //0.8F, 0.8F, 0.2F, 1.0F,
		};

		uint32 indeces[3] = { 0, 1, 2 };

		VAO.reset(lge::gfx::vao::create());
		VBO.reset(lge::gfx::vbo::create(vertices, sizeof(vertices)));

		lge::gfx::vbl layout = {
			{lge::gfx::glShaderDataTypes::vec3, std::string("a_Position")},
			//{gfx::glShaderDataTypes::vec4, std::string("a_Color")},
		};

		VBO->setLayout(layout);
		VAO->addVertexBuffer(VBO.get());

		IBO.reset(lge::gfx::ibo::create(indeces, 3));
		VAO->setIndexBuffer(IBO.get());

		shader.reset(lge::gfx::Shader::create(std::string("../shaders/basic.glsl")));
	}

	void onUpdate(lge::Timestep ts) override {
		std::cout << "Delta time: " << ts.getSeconds() << "s" << "\n";

		lge::gfx::RenderCommand::clear();
		lge::gfx::RenderCommand::setClearColor({ 1.0F, 1.0F, 1.0F, 1.0F });
		
		this->camera.setPos({ 0.5F, 0.5F, 0.0F });
		this->camera.setRotation(45.0F);

		lge::gfx::Renderer::beginScene(this->camera);

		//lge::gfx::Renderer::submit(this->shader.get(), this->VAO.get());

		lge::gfx::Renderer::endScene();
	}

	void onImGuiRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Hello engine");
		ImGui::End();
	}

	void onEvent(lge::hid::Event& e) override {
		lge::hid::EventDispatcher dispatcher(e);
		dispatcher.dispatch<lge::hid::KeyPressedEvent>(lgeBindEvent(ExampleLayer::onKeyPressedEvent));
	}

	bool onKeyPressedEvent(lge::hid::KeyPressedEvent& e) {
		if (e.getKeyCode() == LGE_KEY_0)
			std::cout << "0 example layer" << "\n";
		else if (e.getKeyCode() == LGE_KEY_1)
			std::cout << "1 example layer" << "\n";

		return false;
	}
};

class SandBox : public lge::Application {
public:
	SandBox() {
		this->push_layer(new ExampleLayer());
	}

	~SandBox() {
		
	}
}; 

lge::Application* lge::createApplication() {
	return new SandBox();
} 
