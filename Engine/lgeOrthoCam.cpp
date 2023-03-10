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

#include "lgeOrthoCam.hpp"

_LGE_BEGIN_NP_LGE_GFX

LGE_CUDA_FUNC_DECL void OrthoCam::updateCameraMatrices() {
	lmm::mat4 translated = lmm::translate(lmm::mat4(true), this->pos);
	lmm::mat4 rotmat = lmm::rotate(lmm::mat4(true), (f32)lmm::radians(this->rotation), lmm::vec3(0.0F, 0.0F, 1.0F));
	lmm::mat4 transform = lmm::dot(translated, rotmat);

	this->view = lmm::inverse(transform);
	this->viewProjection = lmm::dot(this->projection, this->view);
}

OrthoCam::OrthoCam() {
	this->rotation = 0.0F;
}

OrthoCam::OrthoCam(f32 left, f32 right, f32 bottom, f32 top) {
	this->rotation = 0.0F;
	this->projection = lmm::ortho(left, right, bottom, top, -1.0F, 1.0F);
	this->view = lmm::mat4(true);
	this->viewProjection = lmm::dot(this->projection, this->view);
}

_LGE_END_NP_LGE_GFX
