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

#ifndef __LGE_GL_CONTEXT__
#define __LGE_GL_CONTEXT__

#include "engine_setup.h"
#include "lgeContext.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

_LGE_BEGIN_NP_LGE_GFX

class LGE_API OpenGlContext : public IContext {
private:
	GLFWwindow* window;

public:
	OpenGlContext();
	OpenGlContext(GLFWwindow*);

	LGE_CUDA_FUNC_DECL void init() override;
	LGE_CUDA_FUNC_DECL void swapBuffers() override;
};

_LGE_END_NP_LGE_GFX

#endif