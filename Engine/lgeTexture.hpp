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

#ifndef __LGE_TEXTURE_INTERFACE__
#define __LGE_TEXTURE_INTERFACE__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE_GFX

typedef class LGE_API Texture {
protected:
	uint32 ID;
	std::string path;

public:
	virtual  ~Texture() {}
	
	LGE_CUDA_FUNC_DECL virtual void bind(uint32 = 0) const = 0;
	LGE_CUDA_FUNC_DECL virtual void unbind() const = 0;

	LGE_CUDA_FUNC_DECL LGE_STATIC Texture* create(std::string&);
}
tex;

_LGE_END_NP_LGE_GFX

#endif