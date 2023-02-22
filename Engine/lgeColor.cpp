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

#include "lgeColor.hpp"

_LGE_BEGIN_NP_LGE

Color::Color(int64 hex) {
	this->color.r = ((hex >> 16) & 0xFF);
	this->color.g = ((hex >> 8) & 0xFF); 
	this->color.b = ((hex) & 0xFF);      
}

Color::Color(f32 r, f32 g, f32 b) 
#ifdef LGE_HAS_INITIALIZER_LIST
	: color(lmm::vec4(r, g, b))
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->color = lmm::vec4(r, g, b);
#endif
}

Color::Color(f32 r, f32 g, f32 b, f32 a)
#ifdef LGE_HAS_INITIALIZER_LIST
	: color(lmm::vec4(r, g, b, a))
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->color = lmm::vec4(r, g, b, a);
#endif
}

LGE_CUDA_FUNC_DECL 
void Color::normal() 
noexcept {
	this->color = lmm::normalize(this->color);
}

LGE_CUDA_FUNC_DECL 
int64 Color::toHex() 
noexcept {
	return (((int64)this->color[0] & 0xff) << 16) + (((int64)this->color.g & 0xff) << 8) + ((int64)this->color.b & 0xff) + ((int64)this->color.a & 0xff);
}

LGE_CUDA_FUNC_DECL 
lmm::vec4 Color::RGBA()
noexcept {
	this->normal();
	return this->color;
}

LGE_CUDA_FUNC_DECL 
int64 Color::toHex(const lmm::vec4& color) 
noexcept {
	return (((int64)color[0] & 0xff) << 16) + (((int64)color.g & 0xff) << 8) + ((int64)color.b & 0xff) + ((int64)color.a & 0xff);
}

LGE_CUDA_FUNC_DECL 
lmm::vec4 Color::toRGB(int64 hex) 
noexcept {
	lmm::vec4 color;
	color.r = ((hex >> 16) & 0xFF);
	color.g = ((hex >> 8) & 0xFF);
	color.b = ((hex) & 0xFF);
	color.a = 255.0F;
	return lmm::normalize(color);
}

_LGE_END_NP_LGE
