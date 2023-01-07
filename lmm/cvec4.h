#pragma once
#ifndef LMM_VEC4
#define LMM_VEC4

#include "types.h"
#include "lmm_defs.h"

#ifdef __cplusplus
	extern "C" {
#endif
		#define vec4_f32_DEFAULT {0.0F, 0.0F, 0.0F, 0.0F}
		#define vec4_f64_DEFAULT {0.0, 0.0, 0.0, 0.0}

		struct vec4_f32 {
			f32 x;
			f32 y;
			f32 z;
			f32 w;
			size_t size;
		};

		struct vec4_f64 {
			f64 x;
			f64 y;
			f64 z;
			f64 w;
			size_t size;
		};

		LMM_FUNC_DECL struct vec4_f32* createVec4f32Ptr(f32 x, f32 y, f32 z, f32 w);
		LMM_FUNC_DECL struct vec4_f64* createVec4f64Ptr(f64 x, f64 y, f64 z, f64 w);
		LMM_FUNC_DECL struct vec4_f32* createVec4f32DynPtr(struct vec4_f32* v, f32 x, f32 y, f32 z, f32 w, int nBytes);
		LMM_FUNC_DECL struct vec4_f64* createVec4f64DynPtr(struct vec4_f64* v, f64 x, f64 y, f64 z, f64 w, int nBytes);
		LMM_FUNC_DECL void freeVec4f32(struct vec4_f32* v);
		LMM_FUNC_DECL void freeVec4f64(struct vec4_f64* v);
#ifdef __cplusplus
	}
#endif
#endif