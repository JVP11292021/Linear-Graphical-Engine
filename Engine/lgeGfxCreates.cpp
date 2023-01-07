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

#include "lgeShader.hpp"
#include "lgeBuffers.hpp"
#include "lgeTexture.hpp"
#include "lgeVertexArray.hpp"
#include "GL_API.h"

_LGE_BEGIN_NP_LGE_GFX

// =====================================================================
// Shader 
// =====================================================================

LGE_CUDA_FUNC_DECL Shader* Shader::create(std::string& shaderPath) {
	return new GlShader(shaderPath);
}

LGE_CUDA_FUNC_DECL Shader* Shader::create(istr vertex, istr fragment, istr geometry) {
	return new GlShader(vertex, fragment, geometry);
}

// =====================================================================
// IndexBuffer
// =====================================================================

LGE_CUDA_FUNC_DECL IndexBuffer* IndexBuffer::create(const void* data, uint32 count) {
	return new GlIndexBuffer(data, count);
}

// =====================================================================
// VertexBuffer
// =====================================================================

LGE_CUDA_FUNC_DECL VertexBuffer* VertexBuffer::create(const void* data, uint32 size) {
	return new GlVertexBuffer(data, size);
}

// =====================================================================
// Texture
// =====================================================================

LGE_CUDA_FUNC_DECL Texture* Texture::create(std::string& path) {
	return new GlTexture(path);
}

// =====================================================================
// VertexArray
// =====================================================================

LGE_CUDA_FUNC_DECL VertexArray* VertexArray::create() {
	return new GlVertexArray();
}

_LGE_END_NP_LGE_GFX