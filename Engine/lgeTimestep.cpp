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

#include "lgeTimestep.hpp"

_LGE_BEGIN_NP_LGE

Timestep::Timestep(f32 time)
#ifdef LGE_HAS_INITIALIZER_LIST
	: time(time)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->time = time;
#endif
}

LGE_CUDA_FUNC_DECL f32 Timestep::operator * (f32 t) {
	return this->time * t;
}

LGE_CUDA_FUNC_DECL f32 Timestep::operator + (f32 t) {
	return this->time + t;
}

LGE_CUDA_FUNC_DECL f32 Timestep::operator - (f32 t) {
	return this->time - t;
}


LGE_CUDA_FUNC_DECL f32 delta(const Timestep& t1, const Timestep& t2) {
	return t1.getSeconds() - t2.getSeconds();
}

LGE_CUDA_FUNC_DECL f32 delta(f32 t1, f32 t2) {
	return t1 - t2;
}

LGE_CUDA_FUNC_DECL f32 delta_ms(const Timestep& t1, const Timestep& t2) {
	return t1.getMilliseconds() - t2.getMilliseconds();
}

LGE_CUDA_FUNC_DECL f32 delta_ms(f32 t1, f32 t2) {
	return t1 - t2;
}

_LGE_END_NP_LGE