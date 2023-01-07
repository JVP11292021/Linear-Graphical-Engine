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

#ifndef __LGE_TEXTUREMANAGER__
#define __LGE_TEXTUREMANAGER__

#include "lgeManager.hpp"

_LGE_BEGIN_NP_LGE_CORE

class LGE_API TextureManager : public IManager {
public:
	LGE_CUDA_FUNC_DEF void startUp()
#ifdef LGE_HAS_OVERRIDE
		override;
#else
		;
#endif

	LGE_CUDA_FUNC_DEF void shutDown()
#ifdef LGE_HAS_OVERRIDE
		override;
#else
		;
#endif
};

_LGE_END_NP_LGE_CORE

#endif