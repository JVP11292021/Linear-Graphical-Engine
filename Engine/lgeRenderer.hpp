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

#ifndef __LGE_RENDERER__
#define __LGE_RENDERER__

#include "engine_setup.h"
#include "lgeRenderCommand.hpp"
#include "lgeOrthoCam.hpp"
#include "lgeShader.hpp"

_LGE_BEGIN_NP_LGE_GFX

class LGE_API Renderer {
private:
	struct _sceneData {
		lmm::mat4 viewProjection;
	};

	LGE_STATIC _sceneData* data;

public:

	LGE_CUDA_FUNC_DECL LGE_STATIC void beginScene(OrthoCam&);
	LGE_CUDA_FUNC_DECL LGE_STATIC void endScene();

	LGE_CUDA_FUNC_DECL LGE_STATIC void submit(Shader*, VertexArray*, const lmm::mat4& transform = lmm::mat4(true));

	LGE_CUDA_FUNC_DECL LGE_INLINE LGE_STATIC RenderAPI::API getAPI() { return RenderAPI::getState(); }
 };

_LGE_END_NP_LGE_GFX
#endif