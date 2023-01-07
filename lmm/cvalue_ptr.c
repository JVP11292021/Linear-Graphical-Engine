#include "cvalue_ptr.h"

LMM_FUNC_DECL f32 const* value_ptr_vec2fc(vec2f const v) {
	return &(v.x);
}

LMM_FUNC_DECL f32* value_ptr_vec2f(vec2f v) {
	return &(v.x);
}

LMM_FUNC_DECL f64 const* value_ptr_vec2dc(vec2d const v) {
	return &(v.x);
}

LMM_FUNC_DECL f64* value_ptr_vec2d(vec2d v) {
	return &(v.x);
}

LMM_FUNC_DECL f32 const* value_ptr_vec3fc(vec3f const v) {
	return &(v.x);
}

LMM_FUNC_DECL f32* value_ptr_vec3f(vec3f v) {
	return &(v.x);
}

LMM_FUNC_DECL f64 const* value_ptr_vec3dc(vec3d const v) {
	return &(v.x);
}

LMM_FUNC_DECL f64* value_ptr_vec3d(vec3d v) {
	return &(v.x);
}

LMM_FUNC_DECL f32 const* value_ptr_vec4fc(vec4f const v) {
	return &(v.x);
}

LMM_FUNC_DECL f32* value_ptr_vec4f(vec4f v) {
	return &(v.x);
}

LMM_FUNC_DECL f64 const* value_ptr_vec4dc(vec4d const v) {
	return &(v.x);
}

LMM_FUNC_DECL f64* value_ptr_vec4d(vec4d v) {
	return &(v.x);
}


LMM_FUNC_DECL f32 const* value_ptr_matc(mat const m) {
	return &(m.items[0 * m.cols + 0]);
}

LMM_FUNC_DECL f32* value_ptr_mat(mat m) {
	return &(m.items[0 * m.cols + 0]);
}