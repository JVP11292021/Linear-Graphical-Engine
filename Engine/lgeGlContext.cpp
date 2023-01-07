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

#include "lgeGlContext.hpp"

#include <stdio.h>

_LGE_BEGIN_NP_LGE_GFX

OpenGlContext::OpenGlContext() {}

OpenGlContext::OpenGlContext(GLFWwindow* window) 
#ifdef LGE_HAS_INITIALIZER_LIST
	: window(window)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->window = window;
#endif

}

LGE_CUDA_FUNC_DECL void OpenGlContext::init() {
	glfwMakeContextCurrent(this->window); // context

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		printf("Failed to initialize GLAD\n");
		return;
	}
}

LGE_CUDA_FUNC_DECL void OpenGlContext::swapBuffers() {
	glfwSwapBuffers(this->window);
}

_LGE_END_NP_LGE_GFX