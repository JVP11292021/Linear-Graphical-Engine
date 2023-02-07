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

#include "lgeUtility.hpp"

_LGE_BEGIN_NP_LGE_CORE

template <class base, class src>
LGE_CUDA_FUNC_DECL
bool isinstance(const src* source) noexcept {
	return dynamic_cast<const base*>(source) != nullptr;
}

_LGE_END_NP_LGE_CORE