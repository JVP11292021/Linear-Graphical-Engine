//		*****************************************************************************************
//		* This source code is from the Github repo: Linear Graphical Engine (LGE)				*
//		*	Created by: JVP11292021 (J. van Polanen)											*
//		*	Started on: 06-01-2023																*
//		*																						*
//		* Copyright (c) Jessy van Polanen														*
//		*																						*
//		* NOTICE:																				*
//		*	This notice must remain at the top of each file, any alterations to this notice		*
//		*	strictly breaks the license the user aggreed upon when using this software.			*
//		*****************************************************************************************

#include "lgeImGuiLayer.hpp"
#include "lgeApplication.hpp"

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#include <GLFW/glfw3.h>

_LGE_BEGIN_NP_LGE

ImGuiLayer::ImGuiLayer() 
	: ILayer("ImGui Layer")
{
	this->time = 0.0F;
}

ImGuiLayer::~ImGuiLayer() {

}

LGE_CUDA_FUNC_DECL void ImGuiLayer::onAttach() {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();

	ImGuiIO& io = ImGui::GetIO();

	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	
	ImGui::StyleColorsDark();

	ImGuiStyle& style = ImGui::GetStyle();
	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		style.WindowRounding = 0.0F;
		style.Colors[ImGuiCol_WindowBg].w = 1.0F;
	}

	Application& app = Application::get();
	GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getNative());

	//io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
	//io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
	//io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
	//io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
	//io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
	//io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
	//io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
	//io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
	//io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
	//io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
	//io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
	//io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
	//io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
	//io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
	//io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
	//io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
	//io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
	//io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
	//io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
	//io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
	//io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

	ImGui_ImplGlfw_InitForOpenGL(window, LGE_TRUE);
	ImGui_ImplOpenGL3_Init("#version 410");
}

LGE_CUDA_FUNC_DECL void ImGuiLayer::onDetach() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

LGE_CUDA_FUNC_DECL void ImGuiLayer::onImGuiRender() {
	LGE_STATIC bool show = LGE_TRUE;
	ImGui::ShowDemoWindow(&show);
}


LGE_CUDA_FUNC_DECL void ImGuiLayer::begin() {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

LGE_CUDA_FUNC_DECL void ImGuiLayer::end() {
	ImGuiIO& io = ImGui::GetIO();
	Application& app = Application::get();
	io.DisplaySize = ImVec2((f32)app.getWindow().getWidth(), (f32)app.getWindow().getHeight());

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}
}

_LGE_END_NP_LGE