#include <iostream>
#include <lge.h>

class ExampleLayer : public lge::ILayer {
private:
	lge::ref<lge::gfx::Shader> shader;
	lge::ref<lge::gfx::VertexArray> VAO;
	lge::ref<lge::gfx::IndexBuffer> IBO;
	lge::ref<lge::gfx::VertexBuffer> VBO;

	lge::gfx::OrthoCam camera;
	
public:
	ExampleLayer()
		: ILayer("Example")
	{
		//std::cout <<wglGetCurrentDC();
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
			//{lge::gfx::glShaderDataTypes::vec4, std::string("a_Color")},
		};

		VBO->setLayout(layout);
		VAO->addVertexBuffer(VBO.get());

		IBO.reset(lge::gfx::ibo::create(indeces, sizeof(indeces) / sizeof(uint32)));
		VAO->setIndexBuffer(IBO.get());

		shader.reset(lge::gfx::Shader::create(std::string("../shaders/basic.glsl")));

		//lge::gfx::MaterialRef material = new lge::gfx::Material(this->shader.get());
		//lge::gfx::MaterialInstanceRef mi = lge::gfx::MaterialInstanceRef(material);
		
	}

	void onUpdate(lge::Timestep ts) override {
		lge::gfx::RenderCommand::clear();
		lge::gfx::RenderCommand::setClearColor({ 0.6F, 0.8F, 0.44F, 0.5F });
		
		//this->camera.setPos({ 0.5F, 0.5F, 0.0F });
		//this->camera.setRotation(45.0F);

		lge::gfx::Renderer::beginScene(this->camera);

		lge::gfx::Renderer::submit(this->shader.get(), this->VAO.get());

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
