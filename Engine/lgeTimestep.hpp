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

#ifndef __LGE_TIMESTEP__
#define __LGE_TIMESTEP__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE

class LGE_API Timestep {
private:
	f32 time;

public:
	Timestep(f32 time = 0.0F);

	LGE_CUDA_FUNC_DECL f32 operator * (f32);
	LGE_CUDA_FUNC_DECL f32 operator + (f32);
	LGE_CUDA_FUNC_DECL f32 operator - (f32);

	LGE_CUDA_FUNC_DECL operator float() const { return this->time; }

	LGE_CUDA_FUNC_DECL LGE_INLINE f32 getSeconds() const { return this->time; }
	LGE_CUDA_FUNC_DECL LGE_INLINE f32 getMilliseconds() const { return this->time * 1000.0F; }

};

LGE_API LGE_CUDA_FUNC_DECL f32 delta(const Timestep&, const Timestep&);
LGE_API LGE_CUDA_FUNC_DECL f32 delta(f32, f32);
LGE_API LGE_CUDA_FUNC_DECL f32 delta_ms(const Timestep&, const Timestep&);
LGE_API LGE_CUDA_FUNC_DECL f32 delta_ms(f32, f32);

_LGE_END_NP_LGE

#endif