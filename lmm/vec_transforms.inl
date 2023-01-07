#pragma once

#include "vec_transforms.hpp"
//#include "lmm_math.h"
#include "trigonometry.h"

// =====================================================================
// c++ vector operations.  
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T magnitude(const Vec<T, 2>& v) {
	return sqrt(v.x * v.x + v.y * v.y);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T magnitude(const Vec<T, 3>& v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T magnitude(const Vec<T, 4>& v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 2> normalize(const Vec<T, 2>& v) {
	return Vec<T, 2>(
		v.x / magnitude(v),
		v.y / magnitude(v)
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3> normalize(const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x / magnitude(v),
		v.y / magnitude(v),
		v.z / magnitude(v)
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4> normalize(const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x / magnitude(v),
		v.y / magnitude(v),
		v.z / magnitude(v),
		v.w / magnitude(v)
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T cross(T v1Magnitude, T v2Magnitude, T angleRad, const Vec<T, 3>& unitVec) {
	return v1Magnitude * v2Magnitude * sin_t<T>(angleRad) * magnitude(unitVec);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3> cross(const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return Vec<T, 3>(
		(v1.y * v2.z) - (v1.z * v2.y),
		(v1.z * v2.x) - (v1.x * v2.z),
		(v1.x * v2.y) - (v1.y * v2.x)
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4> cross(const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return Vec<T, 4>(
		(v1.y * v2.z) - (v1.z * v2.y),
		(v1.z * v2.x) - (v1.x * v2.z),
		(v1.x * v2.y) - (v1.y * v2.x),
		v1.w - v2.w,
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T dot(T v1Magnitude, T v2Magnitude, T angleRad) {
	return v1Magnitude * v2Magnitude * cos_t<T>(angleRad);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T dot(const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	return v1.x * v2.x + v1.y + v2.y;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T dot(const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return v1.x * v2.x + v1.y + v2.y + v1.z * v2.z;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T dot(const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return v1.x * v2.x + v1.y + v2.y + v1.z * v2.z + v1.w * v2.w;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 2> negate(const Vec<T, 2>& v) {
	return Vec<T, 2>(
		v.x * -1,
		v.y * -1
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3> negate(const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x * -1,
		v.y * -1,
		v.z * -1
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4> negate(const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x * -1,
		v.y * -1,
		v.z * -1,
		v.w * -1
		);
}