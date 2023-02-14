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

LGE_API LGE_CUDA_FUNC_DECL
uint32 len(const Collection& _X) noexcept {
	return _X.length();
}

LGE_API LGE_CUDA_FUNC_DECL
int32 max_capacity(const Collection& _X) noexcept {
	return _X.max_capacity();
}

LGE_API LGE_CUDA_FUNC_DECL
size_t size(const Collection& _X) noexcept {
	return _X.getSize();
}

_LGE_END_NP_LGE_CORE