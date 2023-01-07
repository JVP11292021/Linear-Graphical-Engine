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

#ifndef __LGE_MANAGER__
#define __LGE_MANAGER__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE_CORE

class LGE_API IManager {
public:
	LGE_CUDA_FUNC_DEF virtual void startUp() = 0;
	LGE_CUDA_FUNC_DEF virtual void shutDown() = 0;
};

_LGE_END_NP_LGE_CORE

#endif