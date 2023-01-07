#include "cvec3.h"

#include<stdlib.h>


LMM_FUNC_DECL struct vec3_f32* createVec3f32Ptr(f32 x, f32 y, f32 z) {
	return &(struct vec3_f32) { x, y, z, sizeof(x) + sizeof(y) + sizeof(z) };
}

LMM_FUNC_DECL struct vec3_f64* createVec3f64Ptr(f64 x, f64 y, f64 z) {
	return &(struct vec3_f64) { x, y, z, sizeof(x) + sizeof(y) + sizeof(z) };
}

LMM_FUNC_DECL struct vec3_f32* createVec3f32DynPtr(struct vec3_f32* v, f32 x, f32 y, f32 z, int nBytes) {
	if (nBytes <= 1)
		v = (struct vec3_f32*)malloc(1 * sizeof(struct vec3_f32));
	else
		v = (struct vec3_f32*)malloc(nBytes * sizeof(struct vec3_f32));

	if (v != NULL) {
		v->x = x;
		v->y = y;
		v->z = z;
		v->size = sizeof(x) + sizeof(y) + sizeof(z);
		return v;
	}
	else {
		return -1;
	}
}

LMM_FUNC_DECL struct vec3_f64* createVec3f64DynPtr(struct vec3_f64* v, f64 x, f64 y, f64 z, int nBytes) {
	if (nBytes <= 1)
		v = (struct vec3_f64*)malloc(1 * sizeof(struct vec3_f64));
	else
		v = (struct vec3_f64*)malloc(nBytes * sizeof(struct vec3_f64));

	if (v != NULL) {
		v->x = x;
		v->y = y;
		v->z = z;
		v->size = sizeof(x) + sizeof(y) + sizeof(z);
		return v;
	}
	else {
		return -1;
	}
}

LMM_FUNC_DECL void freeVec3f32(struct vec3_f32* v) {
	free(v);
	v = NULL;
}

LMM_FUNC_DECL void freeVec3f64(struct vec3_f64* v) {
	free(v);
	v = NULL;
}
