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

#ifndef __LGE_COLOR__
#define __LGE_COLOR__

#include "engine_setup.h"

#include <../lmm/lmm.h>

_LGE_BEGIN_NP_LGE

class 
	LGE_API Color {
private:
	lmm::vec4 color;

public:
	LGE_CLS_CTOR_DEFAULT(Color)

	Color(int64);
	Color(f32, f32, f32);
	Color(f32, f32, f32, f32);

	operator lmm::vec4() { return this->color; }

	LGE_CUDA_FUNC_DECL void normal() noexcept;
	LGE_CUDA_FUNC_DECL int64 toHex() noexcept;
	LGE_CUDA_FUNC_DECL lmm::vec4 RGBA() noexcept;

	LGE_CUDA_FUNC_DECL LGE_STATIC int64 toHex(const lmm::vec4&) noexcept;
	LGE_CUDA_FUNC_DECL LGE_STATIC lmm::vec4 toRGB(int64) noexcept;

};

__declspec(selectany) LGE_API int64 (*to_hex)(const lmm::vec4&) = &Color::toHex;
__declspec(selectany) LGE_API lmm::vec4 (*to_rgb)(int64) = &Color::toRGB;

_LGE_END_NP_LGE

#endif 