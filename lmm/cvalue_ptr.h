#include "cvec2.h"
#include "cvec2.h"
#include "cvec3.h"
#include "cvec4.h"
#include "cvec_geometry.h"

#include "cMatrix.h"

#include "lmm_defs.h"
#include "types.h"

#ifndef LMM_C_VPTR
#define LMM_C_VPTR

#	ifdef LMM_CPP
extern "C" {
#	endif

	LMM_FUNC_DECL f32 const* value_ptr_vec2fc(vec2f const v);
	LMM_FUNC_DECL f32* value_ptr_vec2f(vec2f v);

	LMM_FUNC_DECL f64 const* value_ptr_vec2dc(vec2d const v);
	LMM_FUNC_DECL f64* value_ptr_vec2d(vec2d v);

	LMM_FUNC_DECL f32 const* value_ptr_vec3fc(vec3f const v);
	LMM_FUNC_DECL f32* value_ptr_vec3f(vec3f v);

	LMM_FUNC_DECL f64 const* value_ptr_vec3dc(vec3d const v);
	LMM_FUNC_DECL f64* value_ptr_vec3d(vec3d v);

	LMM_FUNC_DECL f32 const* value_ptr_vec4fc(vec4f const v);
	LMM_FUNC_DECL f32* value_ptr_vec4f(vec4f v);

	LMM_FUNC_DECL f64 const* value_ptr_vec4dc(vec4d const v);
	LMM_FUNC_DECL f64* value_ptr_vec4d(vec4d v);


	LMM_FUNC_DECL f32 const* value_ptr_matc(mat const m);
	LMM_FUNC_DECL f32* value_ptr_mat(mat m);

#	ifdef LMM_CPP
}
#	endif

#endif

