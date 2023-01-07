#pragma once
#ifndef LMM_VEC3
#define LMM_VEC3

#include "types.h"
#include "lmm_defs.h"

#ifdef __cplusplus
	extern "C" {
#endif
		#define vec3_f32_DEFAULT {0.0F, 0.0F, 0.0F}
		#define vec3_f64_DEFAULT {0.0, 0.0, 0.0}

		struct vec3_f32 {
			f32 x;
			f32 y;
			f32 z;
			size_t size;
		};

		struct vec3_f64 {
			f64 x;
			f64 y;
			f64 z;
			size_t size;
		};

		LMM_FUNC_DECL struct vec3_f32* createVec3f32Ptr(f32 x, f32 y, f32 z);
		LMM_FUNC_DECL struct vec3_f64* createVec3f64Ptr(f64 x, f64 y, f64 z);
		LMM_FUNC_DECL struct vec3_f32* createVec3f32DynPtr(struct vec3_f32* v, f32 x, f32 y, f32 z, int nBytes);
		LMM_FUNC_DECL struct vec3_f64* createVec3f64DynPtr(struct vec3_f64* v, f64 x, f64 y, f64 z, int nBytes);
		LMM_FUNC_DECL void freeVec3f32(struct vec3_f32* v);
		LMM_FUNC_DECL void freeVec3f64(struct vec3_f64* v);
#ifdef __cplusplus
	}
#endif
#endif