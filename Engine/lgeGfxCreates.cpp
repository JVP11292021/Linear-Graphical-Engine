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

#include "lgeShader.hpp"
#include "lgeBuffers.hpp"
#include "lgeTexture.hpp"
#include "lgeVertexArray.hpp"
#include "GL_API.h"
#include "lgeRenderer.hpp"

_LGE_BEGIN_NP_LGE_GFX

// =====================================================================
// Shader 
// =====================================================================

LGE_CUDA_FUNC_DECL Shader* Shader::create(std::string& shaderPath) {
	switch (Renderer::getAPI()) {
	case RenderAPI::API::NONE:	lgeASSERT(LGE_FALSE);
	case RenderAPI::API::GL:	return new GlShader(shaderPath);
	}

	lgeASSERT(LGE_FALSE);
	return nullptr;
}

LGE_CUDA_FUNC_DECL Shader* Shader::create(istr vertex, istr fragment, istr geometry) {
	switch (Renderer::getAPI()) {
	case RenderAPI::API::NONE:	lgeASSERT(LGE_FALSE);
	case RenderAPI::API::GL:	return new GlShader(vertex, fragment, geometry);
	}

	lgeASSERT(LGE_FALSE);
	return nullptr;
}

// =====================================================================
// IndexBuffer
// =====================================================================

LGE_CUDA_FUNC_DECL IndexBuffer* IndexBuffer::create(const void* data, uint32 count) {
	switch (Renderer::getAPI()) {
	case RenderAPI::API::NONE:	lgeASSERT(LGE_FALSE);
	case RenderAPI::API::GL:	return new GlIndexBuffer(data, count);
	}

	lgeASSERT(LGE_FALSE);
	return nullptr;
}

// =====================================================================
// VertexBuffer
// =====================================================================

LGE_CUDA_FUNC_DECL VertexBuffer* VertexBuffer::create(const void* data, uint32 size) {
	switch (Renderer::getAPI()) {
	case RenderAPI::API::NONE:	lgeASSERT(LGE_FALSE);
	case RenderAPI::API::GL:	return new GlVertexBuffer(data, size);
	}

	lgeASSERT(LGE_FALSE);
	return nullptr;
}

// =====================================================================
// Textures
// =====================================================================

LGE_CUDA_FUNC_DECL Texture2D* Texture2D::create(const std::string& path) {
	switch (Renderer::getAPI()) {
	case RenderAPI::API::NONE:	lgeASSERT(LGE_FALSE);
	case RenderAPI::API::GL:	return new GlTexture2D(path);
	}

	lgeASSERT(LGE_FALSE);
	return nullptr;
}

// =====================================================================
// VertexArray
// =====================================================================

LGE_CUDA_FUNC_DECL VertexArray* VertexArray::create() {
	switch (Renderer::getAPI()) {
	case RenderAPI::API::NONE:	lgeASSERT(LGE_FALSE);
	case RenderAPI::API::GL:	return new GlVertexArray();
	}

	return nullptr;
}

_LGE_END_NP_LGE_GFX