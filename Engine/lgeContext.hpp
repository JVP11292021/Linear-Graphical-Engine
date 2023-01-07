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

#ifndef __LGE_GRAPHICS_CONTEXT__
#define __LGE_GRAPHICS_CONTEXT__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE_GFX

class LGE_API IContext {
public:
	LGE_CUDA_FUNC_DECL virtual void init() = 0;
	LGE_CUDA_FUNC_DECL virtual void swapBuffers() = 0;

};

_LGE_END_NP_LGE_GFX

#endif