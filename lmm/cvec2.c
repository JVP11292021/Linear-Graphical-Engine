#include "cvec2.h"

#include <stdlib.h>

LMM_FUNC_DECL struct vec2_f32* createVec2f32Ptr(f32 x, f32 y) {
	return &(struct vec2_f32) { x, y, sizeof(x) + sizeof(y) };
}

LMM_FUNC_DECL struct vec2_f64* createVec2f64Ptr(f64 x, f64 y) {
	return &(struct vec2_f64) { x, y, sizeof(x) + sizeof(y) };
}

LMM_FUNC_DECL struct vec2_f32* createVec2f32DynPtr(struct vec2_f32* v, f32 x, f32 y, int nBytes) {
	if (nBytes <= 1)
		v = (struct vec2_f32*)malloc(1 * sizeof(struct vec2_f32));
	else
		v = (struct vec2_f32*)malloc(nBytes * sizeof(struct vec2_f32));

	if (v != NULL) {
		v->x = x;
		v->y = y;
		v->size = sizeof(x) + sizeof(y);
		return v;
	}
	else {
		return -1;
	}
}

LMM_FUNC_DECL struct vec2_f64* createVec2f64DynPtr(struct vec2_f64* v, f64 x, f64 y, int nBytes) {
	if (nBytes <= 1)
		v = (struct vecdf*)malloc(1 * sizeof(struct vec2_f64));
	else
		v = (struct vec2_f64*)malloc(nBytes * sizeof(struct vec2_f64));

	if (v != NULL) {
		v->x = x;
		v->y = y;
		v->size = sizeof(x) + sizeof(y);
		return v;
	}
	else {
		return -1;
	}
}

LMM_FUNC_DECL void freeVec2f32(struct vec2_f32* v) {
	free(v);
	v = NULL;
}

LMM_FUNC_DECL void freeVec2f64(struct vec2_f64* v) {
	free(v);
	v = NULL;
}
