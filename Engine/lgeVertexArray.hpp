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

#ifndef __LGE_VERTEXARRAY_INTERFACE__
#define __LGE_VERTEXARRAY_INTERFACE__

#include "engine_setup.h"
#include <memory>

_LGE_BEGIN_NP_LGE_GFX

class VertexBuffer;
class IndexBuffer;

typedef class LGE_API VertexArray {
protected:
	uint32 ID;

public:
	virtual ~VertexArray() {};

	LGE_CUDA_FUNC_DECL virtual void bind() const = 0;
	LGE_CUDA_FUNC_DECL virtual void unbind() const = 0;

	LGE_CUDA_FUNC_DECL virtual void addVertexBuffer(const VertexBuffer*) = 0;
	LGE_CUDA_FUNC_DECL virtual void setIndexBuffer(const IndexBuffer*) = 0;

	LGE_CUDA_FUNC_DECL virtual const IndexBuffer& getIndexBuffer() const = 0;
		
	LGE_CUDA_FUNC_DECL LGE_STATIC VertexArray* create();

}
vao;

_LGE_END_NP_LGE_GFX

#endif