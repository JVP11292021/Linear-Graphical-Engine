#include "cppvalue_ptr.hpp"

#pragma once


template <typename T>
LMM_FUNC_DECL LMM_INLINE T* value_ptr(Vec<T, 2> v) {
	T layout[2] = { v.x, v.y };
	return &(layout[0]);
}

template <typename T>
LMM_FUNC_DECL LMM_INLINE T* value_ptr(Vec<T, 3> v) {
	T layout[3] = { v.x, v.y, v.z };
	return &(layout[0]);
}

template <typename T>
LMM_FUNC_DECL LMM_INLINE T* value_ptr(Vec<T, 4> v) {
	T layout[4] = { v.x, v.y, v.z, v.w };
	return &(layout[0]);
}
