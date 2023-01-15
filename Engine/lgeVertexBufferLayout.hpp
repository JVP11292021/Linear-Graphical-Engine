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

#ifndef __LGE_VERTEXBUFFERLAYOUT_INTERFACE__
#define __LGE_VERTEXBUFFERLAYOUT_INTERFACE__

#include "engine_setup.h"
#include "lgeCollections.h"

_LGE_BEGIN_NP_LGE_GFX

LGE_API enum class glShaderDataTypes;
LGE_CUDA_FUNC_DECL LGE_API int32 glShaderTypeSize(glShaderDataTypes);

struct LGE_API BufferElement {
	std::string name;
	glShaderDataTypes type;
	size_t offset;
	uint32 size;
	bool normalized;

	BufferElement() = default;

	BufferElement(glShaderDataTypes type, std::string& name)
#ifdef LGE_HAS_INITIALIZER_LIST
		: name(name), type(type), offset(0), size(glShaderTypeSize(type)), normalized(LGE_FALSE)
#endif
	{
#ifndef LGE_HAS_INITIALIZER_LIST
		this->name = name;
		this->type = type;
		this->offset = 0;
		this->size = glShaderTypeSize(type);
		this->normalized = LGE_FALSE;
#endif
	}

	BufferElement(glShaderDataTypes type, std::string& name, bool normalized)
#ifdef LGE_HAS_INITIALIZER_LIST
		: name(name), type(type), offset(0), size(glShaderTypeSize(type)), normalized(normalized)
#endif
	{
#ifndef LGE_HAS_INITIALIZER_LIST
		this->name = name;
		this->type = type;
		this->offset = 0;
		this->size = glShaderTypeSize(type);
		this->normalized = normalized;
#endif
	}
};

template <uint32 C>
class LGE_API VertexBufferLayout {
private:
	core::Array<BufferElement, C> elements;
	uint32 stride;

	LGE_CUDA_FUNC_DECL void calculateOffset() {
		uint32 offset = 0;
		this->stride = 0;

		for (uint32 i = 0; i < this->elements.curr_pos; i++) {
			this->elements[i].offset = offset;
			offset += this->elements[i].size;
			this->stride += this->elements[i].size;
		}
	}

public:

	VertexBufferLayout() {
		this->stride = 0;
	}

	VertexBufferLayout(std::initializer_list<BufferElement> elements) {
		for (BufferElement element : elements)
			this->elements.append(element);
		this->calculateOffset();
	}

	~VertexBufferLayout() {}

	LGE_CUDA_FUNC_DECL LGE_INLINE core::List<BufferElement> getElements() const { return this->elements; }
	LGE_CUDA_FUNC_DECL LGE_INLINE uint32 getStride() const { return this->stride; }
	LGE_CUDA_FUNC_DECL LGE_INLINE uint32 getLen() const { return this->elements.curr_pos; }

	LGE_CUDA_FUNC_DECL BufferElement& operator [] (uint32 index) { return this->elements[index]; }
	LGE_CUDA_FUNC_DECL BufferElement& operator [] (uint32 index) const { return this->elements[index]; }

};

typedef VertexBufferLayout<LGE_VBL_BUFFER> vbl;

_LGE_END_NP_LGE_GFX

#endif