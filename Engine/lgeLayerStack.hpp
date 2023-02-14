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

#ifndef __LGE_LAYERSTACK__
#define __LGE_LAYERSTACK__

#include "engine_setup.h"
#include "lgeLayer.hpp"
#include "lgeCollections.h"

_LGE_BEGIN_NP_LGE

class LGE_API LayerStack {
private:
	core::List<ILayer*> layers;
	int32 layer_insert;

public:
	LayerStack();
	~LayerStack();

	LGE_CUDA_FUNC_DECL void push_layer(ILayer*);
	LGE_CUDA_FUNC_DECL void push_overlay(ILayer*);
	LGE_CUDA_FUNC_DECL void pop_layer(ILayer*);
	LGE_CUDA_FUNC_DECL void pop_overlay(ILayer*);

	//LGE_CUDA_FUNC_DECL core::List<ILayer*> begin() { return this->layers.begin(); }
	//LGE_CUDA_FUNC_DECL core::List<ILayer*> end() { return this->layers.end(); }

	LGE_CUDA_FUNC_DECL LGE_INLINE uint32 getLen() const { return this->layers.length(); }

	LGE_CUDA_FUNC_DECL ILayer* operator [] (uint32);

};

_LGE_END_NP_LGE

#endif