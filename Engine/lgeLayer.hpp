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

#ifndef __LGE_ILAYER__
#define __LGE_ILAYER__

#include "engine_setup.h"
#include "lgeEvents.h" 
#include "lgeTimestep.hpp"

#include <string>

_LGE_BEGIN_NP_LGE

class LGE_API ILayer {
protected:
	std::string debugName; // For debugging purposes only

public:
	ILayer(const std::string& name = "Layer");
	virtual ~ILayer();

	LGE_CUDA_FUNC_DECL virtual void onAttach() {}
	LGE_CUDA_FUNC_DECL virtual void onDetach() {}
	LGE_CUDA_FUNC_DECL virtual void onUpdate(Timestep ts) {}
	LGE_CUDA_FUNC_DECL virtual void onEvent(hid::Event& e) {}
	LGE_CUDA_FUNC_DECL virtual void onImGuiRender() {};

	LGE_CUDA_FUNC_DECL LGE_INLINE std::string getName() const { return this->debugName; } // For debugging purposes only

};

_LGE_END_NP_LGE

#endif