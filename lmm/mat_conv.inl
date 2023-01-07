#pragma once 

#include "mat_conv.hpp"

template <typename T>
LMM_FUNC_DECL Mat<T, 3, 3> convert(const Mat<T, 2, 2>& m) {
	return Mat<T, 3, 3>(m);
}

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> convert(const Mat<T, 2, 2>& m) {
	return Mat<T, 4, 4>(m);
}

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> convert(const Mat<T, 3, 3>& m) {
	return Mat<T, 4, 4>(m);
}