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

#include "lgeLayer.hpp"

_LGE_BEGIN_NP_LGE

ILayer::ILayer(const std::string& name)
#ifdef LGE_HAS_INITIALIZER_LIST
	: debugName(name)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->debugName = name;
#endif
}

ILayer::~ILayer() {}

_LGE_END_NP_LGE