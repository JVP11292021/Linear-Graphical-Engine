#pragma once

#include "mat2x2.hpp"

// =====================================================================
// c++ matrix constructors & destructors
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2>::Mat() {
	this->rows = 2;
	this->cols = 2;
	this->size = this->rows * this->cols * sizeof(T);

	//this->__elem[0] = Vec<T, 2>();
	//this->__elem[1] = Vec<T, 2>();
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2>::Mat(bool id) {
	this->rows = 2;
	this->cols = 2;
	this->size = this->rows * this->cols * sizeof(T);

	if (id) {
		this->__elem[0] = Vec<T, 2>((T)1, (T)0);
		this->__elem[1] = Vec<T, 2>((T)0, (T)1);
	}
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2>::Mat(T e1) {
	this->rows = 2;
	this->cols = 2;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = Vec<T, 2>(e1, (T)0);
	this->__elem[1] = Vec<T, 2>((T)0, (T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2>::Mat(const Vec<T, 2>& v1) {
	this->rows = 2;
	this->cols = 2;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = Vec<T, 2>();
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2>::Mat(const Vec<T, 2>& v1, T e3) {
	this->rows = 2;
	this->cols = 2;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = Vec<T, 2>(e3, (T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2>::Mat(T e1, T e2, T e3, T e4) {
	this->rows = 2;
	this->cols = 2;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = Vec<T, 2>(e1, e2);
	this->__elem[1] = Vec<T, 2>(e3, e4);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2>::Mat(const Vec<T, 2>& v1, const Vec<T, 2>& v2) {
	this->rows = 2;
	this->cols = 2;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2>::Mat(const Mat<T, 2, 2>& m) {
	this->rows = m.rows;
	this->cols = m.cols;
	this->size = m.size;

	this->__elem[0] = m.__elem[0];
	this->__elem[1] = m.__elem[1];
}

// =====================================================================
// c++ matrix operator overloaded functions
// =====================================================================

template <typename T>
LMM_FUNC_DECL Mat<T, 2, 2> Mat<T, 2, 2>::operator += (const Mat<T, 2, 2>& m) {
	this->__elem[0] += m[0];
	this->__elem[1] += m[1];
	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 2, 2> Mat<T, 2, 2>::operator -= (const Mat<T, 2, 2>& m) {
	this->__elem[0] -= m[0];
	this->__elem[1] -= m[1];
	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 2, 2> Mat<T, 2, 2>::operator += (const T s) {
	this->__elem[0][0] += s;
	this->__elem[0][1] += s;

	this->__elem[1][0] += s;
	this->__elem[1][1] += s;
	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 2, 2> Mat<T, 2, 2>::operator -= (const T s) {
	this->__elem[0][0] -= s;
	this->__elem[0][1] -= s;

	this->__elem[1][0] -= s;
	this->__elem[1][1] -= s;
	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 2, 2> Mat<T, 2, 2>::operator /= (const T s) {
	this->__elem[0][0] /= s;
	this->__elem[0][1] /= s;

	this->__elem[1][0] /= s;
	this->__elem[1][1] /= s;
	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 2, 2> Mat<T, 2, 2>::operator *= (const T s) {
	this->__elem[0][0] *= s;
	this->__elem[0][1] *= s;

	this->__elem[1][0] *= s;
	this->__elem[1][1] *= s;
	return *this;
}