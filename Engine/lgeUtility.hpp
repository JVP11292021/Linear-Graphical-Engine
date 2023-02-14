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

#ifndef __LGE_UTILITY__
#define __LGE_UTILITY__

#include "engine_setup.h"
#include "lgeCollections.h"

_LGE_BEGIN_NP_LGE_CORE

template <class base, class src>
LGE_API LGE_CUDA_FUNC_DECL LGE_INLINE
bool isderived(const src* source) noexcept {
	return dynamic_cast<const base*>(source) != nullptr;
}

template <class T1, class T2>
LGE_API LGE_CUDA_FUNC_DECL LGE_INLINE
bool issame(const T1& _X, const T2& _Y) noexcept {
	return typeid(_X) == typeid(_Y);
}

template <class T>
LGE_API LGE_CUDA_FUNC_DECL 
T rand_t(const T _L, const T _H, const int64 _MAX = 1000) noexcept {
    return (T)(_L + (_H - _L) * (rand() % _MAX) / _MAX);
}

LGE_API LGE_CUDA_FUNC_DECL
uint32 len(const Collection& _X)
noexcept;

LGE_API LGE_CUDA_FUNC_DECL
int32 max_capacity(const Collection& _X)
noexcept;

LGE_API LGE_CUDA_FUNC_DECL
size_t size(const Collection& _X)
noexcept;

_LGE_END_NP_LGE_CORE

#endif