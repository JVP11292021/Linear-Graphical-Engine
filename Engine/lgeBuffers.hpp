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

#ifndef __LGE_BUFFERS_INTERFACE__
#define __LGE_BUFFERS_INTERFACE__

#include "engine_setup.h"
#include "lgeVertexBufferLayout.hpp"

_LGE_BEGIN_NP_LGE_GFX

typedef class LGE_API IndexBuffer {
protected:
	uint32 ID;
	uint32 count;

public:
	virtual ~IndexBuffer() {}

	LGE_CUDA_FUNC_DECL virtual void bind() const = 0;
	LGE_CUDA_FUNC_DECL virtual void unbind() const = 0;

	LGE_CUDA_FUNC_DECL LGE_STATIC IndexBuffer* create(const void*, uint32);
	LGE_CUDA_FUNC_DECL LGE_INLINE uint32 getCount() const { return this->count; }

}
ibo;


typedef class LGE_API VertexBuffer {
protected:
	uint32 ID;
	VertexBufferLayout<LGE_VBL_BUFFER> layout;

public:
	virtual ~VertexBuffer() {}

	LGE_CUDA_FUNC_DECL virtual void bind() const = 0;
	LGE_CUDA_FUNC_DECL virtual void unbind() const = 0;
	LGE_CUDA_FUNC_DECL virtual void setLayout(const VertexBufferLayout<LGE_VBL_BUFFER>&) = 0;
	LGE_CUDA_FUNC_DECL virtual const VertexBufferLayout<LGE_VBL_BUFFER>& getLayout() const = 0;

	LGE_CUDA_FUNC_DECL LGE_STATIC VertexBuffer* create(const void*, uint32);
}
vbo;

_LGE_END_NP_LGE_GFX

#endif