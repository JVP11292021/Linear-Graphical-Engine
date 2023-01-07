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

#include "lgeWindowsListener.hpp"
#include "lgeApplication.hpp"

#include <GLFW/glfw3.h>

_LGE_BEGIN_NP_LGE_HID

Input* Input::instance = new WinListener();

LGE_CUDA_FUNC_DECL mBOOL WinListener::isKeyPressedImpl(mINT keyCode) {
	LGE_AUTO window = static_cast<GLFWwindow*>(Application::get().getWindow().getNative());
	if (glfwGetKey(window, keyCode) == GLFW_PRESS)
		return LGE_TRUE;
	else if (glfwGetKey(window, keyCode) == GLFW_REPEAT)
		return LGE_FALSE;
	return LGE_FALSE;
}

LGE_CUDA_FUNC_DECL mBOOL  WinListener::isMouseButtonPressedImpl(mINT button) {
	LGE_AUTO window = static_cast<GLFWwindow*>(Application::get().getWindow().getNative());
	if (glfwGetMouseButton(window, button) == GLFW_PRESS)
		return LGE_TRUE;
	else
		return LGE_FALSE;
}

LGE_CUDA_FUNC_DECL mFLOAT WinListener::getMouseXImpl() {
	LGE_AUTO window = static_cast<GLFWwindow*>(Application::get().getWindow().getNative());
	f64 xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	return (mFLOAT)xpos;
}

LGE_CUDA_FUNC_DECL mFLOAT WinListener::getMouseYImpl() {
	LGE_AUTO window = static_cast<GLFWwindow*>(Application::get().getWindow().getNative());
	f64 xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	return (mFLOAT)ypos;
}

LGE_CUDA_FUNC_DECL core::Tuple<mFLOAT> WinListener::getMousePosImpl() {
	LGE_AUTO window = static_cast<GLFWwindow*>(Application::get().getWindow().getNative());
	f64 xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	return core::Tuple<mFLOAT>{(mFLOAT)xpos, (mFLOAT)ypos};
}


_LGE_END_NP_LGE_HID