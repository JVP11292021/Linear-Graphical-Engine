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

#include "lgeRenderer.hpp"
#include <iostream>

_LGE_BEGIN_NP_LGE_GFX

Renderer::_sceneData* Renderer::data = new Renderer::_sceneData;

LGE_CUDA_FUNC_DECL void Renderer::beginScene(OrthoCam& cam) {
	Renderer::data->viewProjection = cam.getViewProjection();
}

LGE_CUDA_FUNC_DECL void Renderer::endScene() {

}

LGE_CUDA_FUNC_DECL void Renderer::submit(Shader* shader, VertexArray* VAO, const lmm::mat4& transform) {
	shader->bind();
	shader->setMat4("u_Transform", transform);

	VAO->bind();
	RenderCommand::draw(VAO);
}

_LGE_END_NP_LGE_GFX
