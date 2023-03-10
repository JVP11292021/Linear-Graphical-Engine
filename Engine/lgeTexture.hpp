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

#ifndef __LGE_TEXTURE_INTERFACE__
#define __LGE_TEXTURE_INTERFACE__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE_GFX

class LGE_API Texture {
protected:
	std::string path;

public:
	LGE_CLS_DTOR_DEFAULT(Texture)
	
	LGE_CUDA_FUNC_DECL virtual void bind(uint32 = 0) const = 0;
	LGE_CUDA_FUNC_DECL virtual void unbind() const = 0;

	LGE_CUDA_FUNC_DECL virtual int32 getWidth() const = 0;
	LGE_CUDA_FUNC_DECL virtual int32 getHeight() const = 0;

};

class LGE_API Texture2D : public Texture {
public:
	LGE_CUDA_FUNC_DECL LGE_STATIC Texture2D* create(const std::string&);
};

_LGE_END_NP_LGE_GFX

#endif