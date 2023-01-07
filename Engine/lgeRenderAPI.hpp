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

#ifndef __LGE_RENDERER_API__
#define __LGE_RENDERER_API__

#include "engine_setup.h"
#include "lgeVertexArray.hpp"

#include <../lmm/lmm.h>

_LGE_BEGIN_NP_LGE_GFX


class LGE_API RenderAPI {
public:
	LGE_API enum class API {
		NONE = -1,
		GL = 1,
		DX = 2,
		VULKAN = 3
	};

	LGE_CUDA_FUNC_DECL virtual void setClearColor(const lmm::vec4&) = 0;
	LGE_CUDA_FUNC_DECL virtual void clear() = 0;

	LGE_CUDA_FUNC_DECL virtual void draw(VertexArray*) = 0;

	LGE_CUDA_FUNC_DECL LGE_INLINE LGE_STATIC API getState() { return api_state; }

private:
	LGE_STATIC API api_state;
};

_LGE_END_NP_LGE_GFX
#endif