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

#include "lgeLayerStack.hpp"

_LGE_BEGIN_NP_LGE

LayerStack::LayerStack() {
	this->layer_insert = 0;
}

LayerStack::~LayerStack() {
	for (int32 i = 0; i < this->layers.length(); i++) {
		this->layers[i]->onDetach();
		delete this->layers[i];
	}
}

LGE_CUDA_FUNC_DECL void LayerStack::push_layer(ILayer* layer) {
	this->layer_insert = this->layers.emplace(this->layer_insert, layer);
	this->layer_insert++;
}

LGE_CUDA_FUNC_DECL void LayerStack::push_overlay(ILayer* layer) {
	this->layers.append(layer);
}

LGE_CUDA_FUNC_DECL void LayerStack::pop_layer(ILayer* layer) {
	ILayer* it = core::find<ILayer*>(this->layers, layer);

	if (it != this->layers.last()) {
		layer->onDetach();
		this->layers.del(it);
		this->layer_insert--;
	}
}

LGE_CUDA_FUNC_DECL void LayerStack::pop_overlay(ILayer* layer) {
	ILayer* it = core::find<ILayer*>(this->layers, layer);

	if (it != this->layers.last()) {
		layer->onDetach();
		this->layers.del(it);
	}
}

LGE_CUDA_FUNC_DECL ILayer* LayerStack::operator [] (uint32 index) {
	return this->layers[index];
}

_LGE_END_NP_LGE