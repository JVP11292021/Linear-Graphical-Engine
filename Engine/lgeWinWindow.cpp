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

#include "lgeWinWindow.hpp"
#include "lgeLogging.hpp"
#include "lgeHID.h"

#include "lgeGlContext.hpp"

_LGE_BEGIN_NP_LGE

LGE_STATIC int8 glfw_initialized = LGE_FALSE;

LGE_STATIC void win_error_callback(int error, const char* description) {

}

LGE_CUDA_FUNC_DECL IWindow* IWindow::create(const WindowProps& props) {
	return new WinWindow(props);
}

// Private methods

LGE_CUDA_FUNC_DECL void WinWindow::init(const WindowProps& props) {
	this->data.title = props.title;
	this->data.width = props.width;
	this->data.height = props.height;

	//LGE_CORE_INFO("Creating window {0}, ({1}, {2})", this->data.title, this->data.width, this->data.height);

	if (!glfw_initialized) {
		int32 success = glfwInit();
		glfwSetErrorCallback(win_error_callback);
		//lgeASSERT(success, "Could not initialize GLFW library.");
		glfw_initialized = LGE_TRUE;
	}

	this->window = glfwCreateWindow((int32)this->data.width, (int32)this->data.height, this->data.title.c_str(), nullptr, nullptr);
	this->context = new gfx::OpenGlContext(this->window);

	this->context->init();

	glfwSetWindowUserPointer(this->window, &data);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

	this->setVSync(LGE_TRUE);

	// GLFW callbacks
	glfwSetWindowSizeCallback(this->window, [](GLFWwindow* window, int width, int height) {
		wData& data = *(wData*)glfwGetWindowUserPointer(window);
		data.width = width;
		data.height = height;

		hid::WindowResizeEvent e(width, height);
		data.eventCallback(e);
	});

	glfwSetWindowCloseCallback(this->window, [](GLFWwindow* window) {
		wData& data = *(wData*)glfwGetWindowUserPointer(window);
		hid::WindowCloseEvent e;
		data.eventCallback(e);
	});

	glfwSetKeyCallback(this->window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		wData& data = *(wData*)glfwGetWindowUserPointer(window);
		
		switch (action) {
			case GLFW_PRESS: {
				hid::KeyPressedEvent kp1_e((hid::mINT)key, 0);
				data.eventCallback(kp1_e);
				break;
			}
			case GLFW_RELEASE: {
				hid::KeyReleasedEvent kr_e((hid::mINT)key);
				data.eventCallback(kr_e);
				break;
			}
			case GLFW_REPEAT: {
				hid::KeyPressedEvent kp2_e((hid::mINT)key, 1);
				break;
			}
		}
	});

	glfwSetMouseButtonCallback(this->window, [](GLFWwindow* window, int button, int action, int mods) {
		wData& data = *(wData*)glfwGetWindowUserPointer(window);

		switch (action) {
			case GLFW_PRESS: {
				hid::MouseButtonPressedEvent mbp_e(button);
				data.eventCallback(mbp_e);
				break;
			}
			case GLFW_RELEASE: {
				hid::MouseButtonReleasedEvent mbr_e(button);
				data.eventCallback(mbr_e);
				break;
			}
		}
	});

	glfwSetScrollCallback(this->window, [](GLFWwindow* window, double xOffset, double yOffset) {
		wData& data = *(wData*)glfwGetWindowUserPointer(window);

		hid::MouseScrollEvent e((hid::mFLOAT)xOffset, (hid::mFLOAT)yOffset);
		data.eventCallback(e);
	});

	glfwSetCursorPosCallback(this->window, [](GLFWwindow* window, double xPos, double yPos) {
		wData& data = *(wData*)glfwGetWindowUserPointer(window);

		hid::MouseMovedEvent e((hid::mFLOAT)xPos, (hid::mFLOAT)yPos);
		data.eventCallback(e);
	});

	glfwSetCharCallback(this->window, [](GLFWwindow* window, unsigned int character) {
		wData& data = *(wData*)glfwGetWindowUserPointer(window);

		hid::KeyTypedEvent e(character);
		data.eventCallback(e);
	});
}

LGE_CUDA_FUNC_DECL void WinWindow::shutdown() {
	glfwDestroyWindow(this->window);
	delete this->context;
}

// Public methods

WinWindow::WinWindow(const WindowProps& props) {
	this->init(props);
}

WinWindow::~WinWindow() {
	this->shutdown();
}

LGE_CUDA_FUNC_DECL void WinWindow::onUpdate() {
	glfwPollEvents();
	this->context->swapBuffers();
}

LGE_CUDA_FUNC_DECL void WinWindow::setVSync(int8 enabled) {
	if (enabled)
		glfwSwapInterval(1);
	else
		glfwSwapInterval(0);

	this->data.VSync = enabled;
}

LGE_CUDA_FUNC_DECL int8 WinWindow::isVSync() const {
	return this->data.VSync;
}

_LGE_END_NP_LGE