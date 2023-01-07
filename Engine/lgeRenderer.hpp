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

#ifndef __LGE_RENDERER__
#define __LGE_RENDERER__

#include "engine_setup.h"
#include "lgeRenderCommand.hpp"

_LGE_BEGIN_NP_LGE_GFX

class LGE_API Renderer {
public:

	LGE_CUDA_FUNC_DECL LGE_STATIC void beginScene();
	LGE_CUDA_FUNC_DECL LGE_STATIC void endScene();

	LGE_CUDA_FUNC_DECL LGE_STATIC void submit(VertexArray*);

	LGE_CUDA_FUNC_DECL LGE_INLINE LGE_STATIC RenderAPI::API getAPI() { return RenderAPI::getState(); }
 };

_LGE_END_NP_LGE_GFX
#endif