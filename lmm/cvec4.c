#include "cvec4.h"

#include <stdlib.h>

LMM_FUNC_DECL struct vec4_f32* createVec4f32Ptr(f32 x, f32 y, f32 z, f32 w) {
	return &(struct vec4_f32) { x, y, z, w, sizeof(x) + sizeof(y) + sizeof(z) + sizeof(w) };
}

LMM_FUNC_DECL struct vec4_f64* createVec4f64Ptr(f64 x, f64 y, f64 z, f64 w) {
	return &(struct vec4_f32) { x, y, z, w, sizeof(x) + sizeof(y) + sizeof(z) + sizeof(w) };
}

LMM_FUNC_DECL struct vec4_f32* createVec4f32DynPtr(struct vec4_f32* v, f32 x, f32 y, f32 z, f32 w, int nBytes) {
	if (nBytes <= 1)
		v = (struct vec4_f32*)malloc(1 * sizeof(struct vec4_f32));
	else
		v = (struct vec4_f32*)malloc(nBytes * sizeof(struct vec4_f32));

	if (v != NULL) {
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		v->size = sizeof(x) + sizeof(y) + sizeof(z) + sizeof(w);
		return v;
	}
	else {
		return -1;
	}
}

LMM_FUNC_DECL struct vec4_f64* createVec4f64DynPtr(struct vec4_f64* v, f64 x, f64 y, f64 z, f64 w, int nBytes) {
	if (nBytes <= 1)
		v = (struct vec4_f64*)malloc(1 * sizeof(struct vec4_f64));
	else
		v = (struct vec4_f64*)malloc(nBytes * sizeof(struct vec4_f64));

	if (v != NULL) {
		v->x = x;
		v->y = y;
		v->z = z;
		v->w = w;
		v->size = sizeof(x) + sizeof(y) + sizeof(z) + sizeof(w);
		return v;
	}
	else {
		return -1;
	}
}

LMM_FUNC_DECL void freeVec4f32(struct vec4_f32* v) {
	free(v);
	v = NULL;
}

LMM_FUNC_DECL void freeVec4f64(struct vec4_f64* v) {
	free(v);
	v = NULL;
}
