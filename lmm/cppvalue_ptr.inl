#include "cppvalue_ptr.hpp"

#pragma once


template <typename T>
LMM_FUNC_DECL LMM_INLINE 
const T* value_ptr(const Vec<T, 2>& v) {
	static const T layout[2] = { v.x, v.y };
	return layout;
}

template <typename T>
LMM_FUNC_DECL LMM_INLINE 
const T* value_ptr(const Vec<T, 3>& v) {
	static const T layout[3] = { v.x, v.y, v.z };
	return layout;
}

template <typename T>
LMM_FUNC_DECL LMM_INLINE 
const T* value_ptr(const Vec<T, 4>& v) {
	static const T layout[4] = { v.x, v.y, v.z, v.w };
	return layout;
}

template <typename T>
LMM_FUNC_DECL LMM_INLINE
const T* value_ptr(const Mat<T, 2, 2>& m) {
	static const T layout[2*2] = {
		m[0][0], m[0][1],
		m[1][0], m[1][1]
	};
	return layout;
}

template <typename T>
LMM_FUNC_DECL LMM_INLINE
const T* value_ptr(const Mat<T, 3, 3>& m) {
	static const T layout[3*3] = {
		m[0][0], m[0][1], m[0][2],
		m[1][0], m[1][1], m[1][2],
		m[2][0], m[2][1], m[2][2],
	};
	return layout;
}

template <typename T>
LMM_FUNC_DECL LMM_INLINE
const T* value_ptr(const Mat<T, 4, 4>& m) {
	static const T layout[4*4] = {
		m[0][0], m[0][1], m[0][2], m[0][3],
		m[1][0], m[1][1], m[1][2], m[1][3],
		m[2][0], m[2][1], m[2][2], m[2][3],
		m[3][0], m[3][1], m[3][2], m[3][3],
	};
	return layout;
}