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

#include "lgeMaterial.hpp"

_LGE_BEGIN_NP_LGE_GFX

Material::Material(Shader* shader) {
	this->shader = shader;
}

Material::Material(const Material& material) {
	this->shader = material.shader;
}

LGE_CUDA_FUNC_DECL Material Material::operator = (const Material& material) {
	this->shader = material.shader;
	return *this;
}


MaterialInstance::MaterialInstance(Material* material) {
	this->mat = material;
}

MaterialInstance::MaterialInstance(const MaterialInstance& instance) {
	this->mat = instance.mat;
}

_LGE_END_NP_LGE_GFX