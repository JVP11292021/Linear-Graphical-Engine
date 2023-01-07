#pragma once

#include "manipulations.hpp"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 2, 2> fill2x2(T _X) noexcept {
	return Mat<T, 2, 2>(
		_X, _X,
		_X, _X
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 3, 3> fill3x3(T _X) noexcept {
	return Mat<T, 3, 3>(
		_X, _X, _X,
		_X, _X, _X,
		_X, _X, _X
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> fill4x4(T _X) noexcept {
	return Mat<T, 3, 3>(
		_X, _X, _X, _X,
		_X, _X, _X, _X,
		_X, _X, _X, _X,
		_X, _X, _X, _X
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 2, 2> identity2x2() noexcept {
	return Mat<T, 2, 2>(
		1, 0,
		0, 1
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 3, 3> identity3x3() noexcept {
	return Mat<T, 3, 3>(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
		);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> identity4x4() noexcept {
	return Mat<T, 3, 3>(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
}