#pragma once

#include "mat3x3.hpp"

// =====================================================================
// c++ matrix constructors & destructors
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat() {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	//this->__elem[0] = Vec<T, 3>();
	//this->__elem[1] = Vec<T, 3>();
	//this->__elem[2] = Vec<T, 3>();

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(bool id) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	if (id) {
		this->__elem[0] = Vec<T, 3>((T)1, (T)0, (T)0);
		this->__elem[1] = Vec<T, 3>((T)0, (T)1, (T)0);
		this->__elem[2] = Vec<T, 3>((T)0, (T)0, (T)1);
	}
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(T e1) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = Vec<T, 3>(e1, (T)0, (T)0);
	this->__elem[1] = Vec<T, 3>((T)0, (T)0, (T)0);
	this->__elem[2] = Vec<T, 3>((T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Vec<T, 3>& v1) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = Vec<T, 3>((T)0, (T)1, (T)0);
	this->__elem[2] = Vec<T, 3>((T)0, (T)0, (T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Vec<T, 3>& v1, T e4) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = Vec<T, 3>(e4, (T)1, (T)0);
	this->__elem[2] = Vec<T, 3>((T)0, (T)0, (T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Vec<T, 3>& v1, T e4, T e5) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = Vec<T, 3>(e4, e5, (T)0);
	this->__elem[2] = Vec<T, 3>((T)0, (T)0, (T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Vec<T, 3>& v1, const Vec<T, 3>& v2) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = Vec<T, 3>((T)0, (T)0, (T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Vec<T, 3>& v1, const Vec<T, 3>& v2, T e7) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = Vec<T, 3>(e7, (T)0, (T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Vec<T, 3>& v1, const Vec<T, 3>& v2, T e7, T e8) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = Vec<T, 3>(e7, e8, (T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Vec<T, 3>& v1, const Vec<T, 3>& v2, const Vec<T, 3>& v3) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = v3;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(T e1, T e2, T e3, T e4, T e5, T e6, T e7, T e8, T e9) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = Vec<T, 3>(e1, e2, e3);
	this->__elem[1] = Vec<T, 3>(e4, e5, e6);
	this->__elem[2] = Vec<T, 3>(e7, e8, e9);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Mat<T, 3, 3>& m) {
	this->rows = m.rows;
	this->cols = m.cols;
	this->size = m.size;

	this->__elem[0] = m.__elem[0];
	this->__elem[1] = m.__elem[1];
	this->__elem[2] = m.__elem[2];
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Mat<T, 3, 3>& m, int32 allignment) {
	this->rows = 3;
	this->cols = 3;
	this->size = this->rows * this->cols * sizeof(T);

	switch (allignment) {
	case LGE_MAT_TOPLEFT_ALLIGN:
		this->__elem[0][0] = m[0][0];
		this->__elem[0][1] = m[0][1];

		this->__elem[1][0] = m[1][0];
		this->__elem[1][1] = m[1][1];

		break;
	case LGE_MAT_TOPRIGHT_ALLIGN:
		this->__elem[0][0] = m[0][0];
		this->__elem[0][1] = m[0][1];

		this->__elem[1][0] = m[1][0];
		this->__elem[1][1] = m[1][1];

		break;
	case LGE_MAT_BOTRIGHT_ALLIGN:
		this->__elem[1][1] = m[0][0];
		this->__elem[1][2] = m[0][1];

		this->__elem[2][1] = m[1][0];
		this->__elem[2][2] = m[1][1];

		break;
	case LGE_MAT_BOTLEFT_ALLIGN:
		this->__elem[1][0] = m[0][0];
		this->__elem[1][1] = m[0][1];

		this->__elem[2][0] = m[1][0];
		this->__elem[2][1] = m[1][1];
		break;
	default: LMM_EXCEPTION("LMM::Exception Unknown matrix allignment");
	}
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3>::Mat(const Mat<T, 2, 2>& m) {
	this->rows = m.rows;
	this->cols = m.cols;
	this->size = m.size;

	this->__elem[0] = m.__elem[0];
	this->__elem[1] = m.__elem[1];
	this->__elem[2] = Vec<T, 3>();
}

// =====================================================================
// c++ matrix operator overloaded functions
// =====================================================================

template <typename T>
LMM_FUNC_DECL Mat<T, 3, 3> Mat<T, 3, 3>::operator += (const Mat<T, 3, 3>& m) {
	this->__elem[0] += m[0];
	this->__elem[1] += m[1];
	this->__elem[2] += m[2];
	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 3, 3> Mat<T, 3, 3>::operator -= (const Mat<T, 3, 3>& m) {
	this->__elem[0] -= m[0];
	this->__elem[1] -= m[1];
	this->__elem[2] -= m[2];
	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 3, 3> Mat<T, 3, 3>::operator += (const T s) {
	this->__elem[0][0] += s;
	this->__elem[0][1] += s;
	this->__elem[0][2] += s;

	this->__elem[1][0] += s;
	this->__elem[1][1] += s;
	this->__elem[1][2] += s;

	this->__elem[2][0] += s;
	this->__elem[2][1] += s;
	this->__elem[2][2] += s;

	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 3, 3> Mat<T, 3, 3>::operator -= (const T s) {
	this->__elem[0][0] -= s;
	this->__elem[0][1] -= s;
	this->__elem[0][2] -= s;

	this->__elem[1][0] -= s;
	this->__elem[1][1] -= s;
	this->__elem[1][2] -= s;

	this->__elem[2][0] -= s;
	this->__elem[2][1] -= s;
	this->__elem[2][2] -= s;

	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 3, 3> Mat<T, 3, 3>::operator /= (const T s) {
	this->__elem[0][0] /= s;
	this->__elem[0][1] /= s;
	this->__elem[0][2] /= s;

	this->__elem[1][0] /= s;
	this->__elem[1][1] /= s;
	this->__elem[1][2] /= s;

	this->__elem[2][0] /= s;
	this->__elem[2][1] /= s;
	this->__elem[2][2] /= s;

	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 3, 3> Mat<T, 3, 3>::operator *= (const T s) {
	this->__elem[0][0] *= s;
	this->__elem[0][1] *= s;
	this->__elem[0][2] *= s;

	this->__elem[1][0] *= s;
	this->__elem[1][1] *= s;
	this->__elem[1][2] *= s;

	this->__elem[2][0] *= s;
	this->__elem[2][1] *= s;
	this->__elem[2][2] *= s;

	return *this;
}