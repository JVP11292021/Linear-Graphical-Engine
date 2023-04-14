#include <iostream>
#include <lge.h>

class ExampleLayer : public lge::ILayer {
private:
	lge::ref<lge::gfx::Shader> shader;
	lge::ref<lge::gfx::VertexArray> VAO;
	lge::ref<lge::gfx::IndexBuffer> IBO;
	lge::ref<lge::gfx::VertexBuffer> VBO;

	lge::gfx::OrthoCam camera;
	lmm::vec3 camPos = lmm::vec3(0.0F, 0.0F, 0.0F);
	float camMoveSpeed = 30.0F;

	float camRotation = 0.0F;
	float camRotationSpeed = 180.0F;

public:
	ExampleLayer()
		: ILayer("Example")
	{	
		
		this->camera = lge::gfx::OrthoCam(-1.6F, 1.6F, -0.9F, 0.9F);

		f32 vertices[4 * 9] = {
			// POSITION				COLOR						TEXCORD
			-0.5F, -0.5F, 0.0F,		0.8F, 0.2F, 0.8F, 1.0F,		0.0F, 0.0F,
			 0.5F, -0.5F, 0.0F,		0.2F, 0.3F, 0.8F, 1.0f,		1.0F, 0.0F,
			 0.5F,  0.5F, 0.0F,		0.8F, 0.8F, 0.2F, 1.0F,		1.0F, 1.0F,
			-0.5F,  0.5F, 0.0F,		0.8F, 0.8F, 0.2F, 1.0F,		0.0F, 1.0F,
		};

		uint32 indeces[2 * 3] = {
			0, 1, 3,
			1, 2, 3
		};

		VAO.reset(lge::gfx::vao::create());
		VBO.reset(lge::gfx::vbo::create(vertices, sizeof(vertices)));

		lge::gfx::vbl layout = {
			{lge::gfx::glShaderDataTypes::vec3, std::string("a_Position")},
			{lge::gfx::glShaderDataTypes::vec4, std::string("a_Color")},
			{lge::gfx::glShaderDataTypes::vec2, std::string("a_TexCoord")},
		};

		VBO->setLayout(layout);
		VAO->addVertexBuffer(VBO.get());

		IBO.reset(lge::gfx::ibo::create(indeces, sizeof(indeces) / sizeof(uint32)));
		VAO->setIndexBuffer(IBO.get());

		shader.reset(lge::gfx::Shader::create(std::string("../shaders/basic.glsl")));
		
	}

	void onUpdate(lge::Timestep ts) override {
		if (lge::isKeyPressed(LGE_KEY_LEFT))
			this->camPos.x -= this->camMoveSpeed * ts;
		else if (lge::isKeyPressed(LGE_KEY_RIGHT))
			this->camPos.x += this->camMoveSpeed * ts;
		if (lge::isKeyPressed(LGE_KEY_UP))
			this->camPos.y += this->camMoveSpeed * ts;
		else if (lge::isKeyPressed(LGE_KEY_DOWN))
			this->camPos.y -= this->camMoveSpeed * ts;

		if (lge::isKeyPressed(LGE_KEY_A))
			this->camRotation += this->camRotationSpeed * ts;
		if (lge::isKeyPressed(LGE_KEY_D)) 
			this->camRotation -= this->camRotationSpeed * ts;

		lge::gfx::RenderCommand::clear();
		lge::gfx::RenderCommand::setClearColor(lge::to_rgb(0xFF6677)); 

		this->camera.setPos(this->camPos);
		//this->camera.setRotation(this->camRotation);

		lge::gfx::Renderer::beginScene(this->camera);

		// POSSIBLE lmm::value_ptr ERROR
		// ERROR: matrices are wrong or something
		lge::gfx::Renderer::submit(this->shader.get(), this->VAO.get()), lmm::scale(lmm::mat4(1.0f), lmm::vec3(1.5f, 1.5f, 1.5f));
		
		lge::gfx::Renderer::endScene();
	}

	void onImGuiRender() override {
		ImGui::Begin("Test");
		ImGui::Text("Hello engine");
		ImGui::Button("Test button!");
		ImGui::End();
	}

	void onEvent(lge::hid::Event& e) override {
		lge::hid::EventDispatcher dispatcher(e);
		dispatcher.dispatch<lge::hid::KeyPressedEvent>(lgeBindEvent(ExampleLayer::onKeyPressedEvent)); // To bind an event
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
