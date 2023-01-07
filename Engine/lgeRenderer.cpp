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

#include "lgeRenderer.hpp"

_LGE_BEGIN_NP_LGE_GFX

LGE_CUDA_FUNC_DECL void Renderer::beginScene() {

}

LGE_CUDA_FUNC_DECL void Renderer::endScene() {

}

LGE_CUDA_FUNC_DECL void Renderer::submit(VertexArray* VAO) {
	VAO->bind();
	RenderCommand::draw(VAO);
}

_LGE_END_NP_LGE_GFX
