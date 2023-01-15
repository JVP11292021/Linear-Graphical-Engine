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

#ifndef __LGE_RENDERER_COMMAND_API__
#define __LGE_RENDERER_COMMAND_API__

#include "engine_setup.h"
#include "lgeRenderAPI.hpp"
#include <../lmm/lmm.h>

_LGE_BEGIN_NP_LGE_GFX

class LGE_API RenderCommand {
private:
	LGE_STATIC RenderAPI* R_API;

public:

	LGE_CUDA_FUNC_DECL LGE_STATIC LGE_INLINE void setClearColor(const lmm::vec4& color) {
		R_API->setClearColor(color);
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC LGE_INLINE void clear() {
		R_API->clear();
	}

	LGE_CUDA_FUNC_DECL LGE_STATIC LGE_INLINE void draw(VertexArray* VAO) {
		R_API->draw(VAO);
	} 

};

_LGE_END_NP_LGE_GFX
#endif