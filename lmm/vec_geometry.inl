#pragma once

#include "vec_geometry.hpp"

// =====================================================================
// c++ vector overloaded operators.  
// =====================================================================

// =====================================================================
// Vec 2 operations
// =====================================================================

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator + (const Vec<T, 2>& v, T s) {
	return Vec<T, 2>(
		v.x + s,
		v.y + s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator + (T s, const Vec<T, 2>& v) {
	return Vec<T, 2>(
		v.x + s,
		v.y + s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator + (const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	return Vec<T, 2>(
		v1.x + v2.x,
		v1.y + v2.y
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator += (const Vec<T, 2>& v, T s) {
	return Vec<T, 2>(
		v.x + s,
		v.y + s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator += (T s, const Vec<T, 2>& v) {
	return Vec<T, 2>(
		v.x + s,
		v.y + s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator += (const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	return Vec<T, 2>(
		v1.x + v2.x,
		v1.y + v2.y
	);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator - (const Vec<T, 2>& v, T s) {
	return Vec<T, 2>(
		v.x - s,
		v.y - s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator - (T s, const Vec<T, 2>& v) {
	return Vec<T, 2>(
		v.x - s,
		v.y - s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator - (const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	return Vec<T, 2>(
		v1.x - v2.x,
		v1.y - v2.y
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator -= (const Vec<T, 2>& v, T s) {
	return Vec<T, 2>(
		v.x - s,
		v.y - s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator -= (T v, const Vec<T, 2>& s) {
	return Vec<T, 2>(
		v.x - s,
		v.y - s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator -= (const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	return Vec<T, 2>(
		v1.x - v2.x,
		v1.y - v2.y
	);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator / (const Vec<T, 2>& v, T s) {
	return Vec<T, 2>(
		v.x / s,
		v.y / s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator / (T s, const Vec<T, 2>& v) {
	return Vec<T, 2>(
		v.x / s,
		v.y / s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator / (const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	return Vec<T, 2>(
		v1.x / v2.x,
		v1.y / v2.y
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator /= (const Vec<T, 2>& v, T s) {
	return Vec<T, 2>(
		v.x / s,
		v.y / s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator /= (T s, const Vec<T, 2>& v) {
	return Vec<T, 2>(
		v.x / s,
		v.y / s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator /= (const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	return Vec<T, 2>(
		v1.x / v2.x,
		v1.y / v2.y
	);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator * (const Vec<T, 2>& v, T s) {
	return Vec<T, 2>(
		v.x * s,
		v.y * s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator * (T s, const Vec<T, 2>& v) {
	return Vec<T, 2>(
		v.x * s,
		v.y * s
	);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator *= (const Vec<T, 2>& v, T s) {
	return Vec<T, 2>(
		v.x * s,
		v.y * s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator *= (T s, const Vec<T, 2>& v) {
	return Vec<T, 2>(
		v.x * s,
		v.y * s
		);
}

// =====================================================================
// Vec 3 operations
// =====================================================================

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator + (const Vec<T, 3>& v, T s) {
	return Vec<T, 3>(
		v.x + s,
		v.y + s,
		v.z + s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator + (T s, const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x + s,
		v.y + s,
		v.z + s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator + (const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return Vec<T, 3>(
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator += (const Vec<T, 3>& v, T s) {
	return Vec<T, 3>(
		v.x + s,
		v.y + s,
		v.z + s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator += (T s, const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x + s,
		v.y + s,
		v.z + s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator += (const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return Vec<T, 3>(
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
		);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator - (const Vec<T, 3>& v, T s) {
	return Vec<T, 3>(
		v.x - s,
		v.y - s,
		v.z - s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator - (T s, const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x - s,
		v.y - s,
		v.z - s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator - (const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return Vec<T, 3>(
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator -= (const Vec<T, 3>& v, T s) {
	return Vec<T, 3>(
		v.x - s,
		v.y - s,
		v.z - s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator -= (T s, const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x - s,
		v.y - s,
		v.z - s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator -= (const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return Vec<T, 3>(
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
		);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator / (const Vec<T, 3>& v, T s) {
	return Vec<T, 3>(
		v.x / s,
		v.y / s,
		v.z / s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator / (T s, const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x / s,
		v.y / s,
		v.z / s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator / (const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return Vec<T, 3>(
		v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator /= (const Vec<T, 3>& v, T s) {
	return Vec<T, 3>(
		v.x / s,
		v.y / s,
		v.z / s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator /= (T s, const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x / s,
		v.y / s,
		v.z / s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator /= (const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return Vec<T, 3>(
		v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z
		);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator * (const Vec<T, 3>& v, T s) {
	return Vec<T, 3>(
		v.x * s,
		v.y * s,
		v.z * s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator * (T s, const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x * s,
		v.y * s,
		v.z * s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator *= (const Vec<T, 3>& v, T s) {
	return Vec<T, 3>(
		v.x * s,
		v.y * s,
		v.z * s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator *= (T s, const Vec<T, 3>& v) {
	return Vec<T, 3>(
		v.x * s,
		v.y * s,
		v.z * s
		);
}

// =====================================================================
// Vec 4 operations
// =====================================================================

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator + (const Vec<T, 4>& v, T s) {
	return Vec<T, 4>(
		v.x + s,
		v.y + s,
		v.z + s,
		v.w + s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator + (T s, const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x + s,
		v.y + s,
		v.z + s,
		v.w + s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator + (const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return Vec<T, 4>(
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z,
		v1.w + v2.w
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator += (const Vec<T, 4>& v, T s) {
	return Vec<T, 4>(
		v.x + s,
		v.y + s,
		v.z + s,
		v.w + s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator += (T s, const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x + s,
		v.y + s,
		v.z + s,
		v.w + s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator += (const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return Vec<T, 4>(
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z,
		v1.w + v2.w
		);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator - (const Vec<T, 4>& v, T s) {
	return Vec<T, 4>(
		v.x - s,
		v.y - s,
		v.z - s,
		v.w - s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator - (T s, const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x - s,
		v.y - s,
		v.z - s,
		v.w - s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator - (const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return Vec<T, 4>(
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z,
		v1.w - v2.w
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator -= (const Vec<T, 4>& v, T s) {
	return Vec<T, 4>(
		v.x - s,
		v.y - s,
		v.z - s,
		v.w - s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator -= (T s, const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x - s,
		v.y - s,
		v.z - s,
		v.w - s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator -= (const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return Vec<T, 4>(
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z,
		v1.w - v2.w
		);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator / (const Vec<T, 4>& v, T s) {
	return Vec<T, 4>(
		v.x / s,
		v.y / s,
		v.z / s,
		v.w / s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator / (T s, const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x / s,
		v.y / s,
		v.z / s,
		v.w / s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator / (const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return Vec<T, 4>(
		v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z,
		v1.w / v2.w
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator /= (const Vec<T, 4>& v, T s) {
	return Vec<T, 4>(
		v.x / s,
		v.y / s,
		v.z / s,
		v.w / s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator /= (T s, const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x / s,
		v.y / s,
		v.z / s,
		v.w / s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator /= (const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return Vec<T, 4>(
		v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z,
		v1.w / v2.w
		);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator * (const Vec<T, 4>& v, T s) {
	return Vec<T, 4>(
		v.x * s,
		v.y * s,
		v.z * s,
		v.w * s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator * (T s, const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x * s,
		v.y * s,
		v.z * s,
		v.w * s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator *= (const Vec<T, 4>& v, T s) {
	return Vec<T, 4>(
		v.x * s,
		v.y * s,
		v.z * s,
		v.w * s
		);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator *= (T s, const Vec<T, 4>& v) {
	return Vec<T, 4>(
		v.x * s,
		v.y * s,
		v.z * s,
		v.w * s
		);
}

template <typename T>
LMM_FUNC_DECL T operator * (const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	return (v1.x + v2.x) * (v1.y + v2.y);
}

template <typename T>
LMM_FUNC_DECL T operator *= (const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	return (v1.x + v2.x) * (v1.y + v2.y);
}

template <typename T>
LMM_FUNC_DECL T operator * (const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return (v1.x + v2.x) * (v1.y + v2.y) * (v1.z + v2.z);
}

template <typename T>
LMM_FUNC_DECL T operator *= (const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	return (v1.x + v2.x) * (v1.y + v2.y) * (v1.z + v2.z);
}

template <typename T>
LMM_FUNC_DECL T operator * (const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return (v1.x + v2.x) * (v1.y + v2.y) * (v1.z + v2.z) * (v1.w + v2.w);
}

template <typename T>
LMM_FUNC_DECL T operator *= (const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	return (v1.x + v2.x) * (v1.y + v2.y) * (v1.z + v2.z) * (v1.w + v2.w);
}