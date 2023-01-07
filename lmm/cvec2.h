#pragma once
#ifndef LMM_VEC2
#define LMM_VEC2

#include "types.h"
#include "lmm_defs.h"

#ifdef __cplusplus
	extern "C" {
#endif
		#define vec2_f32_DEFAULT {0.0F, 0.0F}
		#define vec2_f64_DEFAULT {0.0, 0.0}

		struct vec2_f32 {
			f32 x;
			f32 y;
			size_t size;
		};

		struct vec2_f64 {
			f64 x;
			f64 y;
			size_t size;
		};
			
		LMM_FUNC_DECL struct vec2_f32* createVec2f32Ptr(f32 x, f32 y);
		LMM_FUNC_DECL struct vec2_f64* createVec2f64Ptr(f64 x, f64 y);
		LMM_FUNC_DECL struct vec2_f32* createVec2f32DynPtr(struct vec2_f32* v, f32 x, f32 y, int nBytes);
		LMM_FUNC_DECL struct vec2_f64* createVec2f64DynPtr(struct vec2_f64* v, f64 x, f64 y, int nBytes);
		LMM_FUNC_DECL void freeVec2f32(struct vec2_f32* v);
		LMM_FUNC_DECL void freeVec2f64(struct vec2_f64* v);
#ifdef __cplusplus
	}
#endif
#endif
