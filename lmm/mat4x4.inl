#pragma once

#include "mat4x4.hpp"

// =====================================================================
// c++ matrix constructors & destructors
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat() {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	//this->__elem[0] = Vec<T, 4>();
	//this->__elem[1] = Vec<T, 4>();
	//this->__elem[2] = Vec<T, 4>();
	//this->__elem[3] = Vec<T, 4>();

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(bool id) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	if (id) {
		this->__elem[0] = Vec<T, 4>((T)1, (T)0, (T)0, (T)0);
		this->__elem[1] = Vec<T, 4>((T)0, (T)1, (T)0, (T)0);
		this->__elem[2] = Vec<T, 4>((T)0, (T)0, (T)1, (T)0);
		this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)1);
	}
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(T e1) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = Vec<T, 4>(e1, (T)0, (T)0, (T)0);
	this->__elem[1] = Vec<T, 4>((T)0, (T)1, (T)0, (T)0);
	this->__elem[2] = Vec<T, 4>((T)0, (T)0, (T)1, (T)0);
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
	this->__elem[2] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, T e5) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = Vec<T, 4>(e5, (T)0, (T)0, (T)0);
	this->__elem[2] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, T e5, T e6) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = Vec<T, 4>(e5, e6, (T)0, (T)0);
	this->__elem[2] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, T e5, T e6, T e7) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = Vec<T, 4>(e5, e6, e7, (T)0);
	this->__elem[2] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, const Vec<T, 4>& v2) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, const Vec<T, 4>& v2, T e9) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = Vec<T, 4>(e9, (T)0, (T)0, (T)0);
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, const Vec<T, 4>& v2, T e9, T e10) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = Vec<T, 4>(e9, e10, (T)0, (T)0);
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, const Vec<T, 4>& v2, T e9, T e10, T e11) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = Vec<T, 4>(e9, e10, e11, (T)0);
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, const Vec<T, 4>& v2, const Vec<T, 4>& v3) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = v3;
	this->__elem[3] = Vec<T, 4>((T)0, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, const Vec<T, 4>& v2, const Vec<T, 4>& v3, T e13) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = v3;
	this->__elem[3] = Vec<T, 4>(e13, (T)0, (T)0, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, const Vec<T, 4>& v2, const Vec<T, 4>& v3, T e13, T e14) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = v3;
	this->__elem[3] = Vec<T, 4>(e13, e14, (T)0, (T)0);
}


template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, const Vec<T, 4>& v2, const Vec<T, 4>& v3, T e13, T e14, T e15) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = v3;
	this->__elem[3] = Vec<T, 4>(e13, e14, e15, (T)0);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Vec<T, 4>& v1, const Vec<T, 4>& v2, const Vec<T, 4>& v3, const Vec<T, 4>& v4) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = v1;
	this->__elem[1] = v2;
	this->__elem[2] = v3;
	this->__elem[3] = v4;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(T e1, T e2, T e3, T e4, T e5, T e6, T e7, T e8, T e9, T e10, T e11, T e12, T e13, T e14, T e15, T e16) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = Vec<T, 4>(e1, e2, e3, e4);
	this->__elem[1] = Vec<T, 4>(e5, e6, e7, e8);
	this->__elem[2] = Vec<T, 4>(e9, e10, e11, e12);
	this->__elem[3] = Vec<T, 4>(e13, e14, e15, e16);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Mat<T, 4, 4>& m) {
	this->rows = m.rows;
	this->cols = m.cols;
	this->size = m.size;
	
	this->__elem[0] = m.__elem[0];
	this->__elem[1] = m.__elem[1];
	this->__elem[2] = m.__elem[2];
	this->__elem[3] = m.__elem[3];
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Mat<T, 3, 3>& m) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = m.__elem[0];
	this->__elem[1] = m.__elem[1];
	this->__elem[2] = m.__elem[2];
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Mat<T, 3, 3>& m, int32 allignment) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	switch (allignment) {
		case LGE_MAT_TOPLEFT_ALLIGN:
			this->__elem[0][0] = m[0][0];
			this->__elem[0][1] = m[0][1];
			this->__elem[0][2] = m[0][2];

			this->__elem[1][0] = m[1][0];
			this->__elem[1][1] = m[1][1];
			this->__elem[1][2] = m[1][2];

			this->__elem[2][0] = m[2][0];
			this->__elem[2][1] = m[2][1];
			this->__elem[2][2] = m[2][2];

			break;
		case LGE_MAT_TOPRIGHT_ALLIGN:
			this->__elem[0][0] = m[0][0];
			this->__elem[0][1] = m[0][1];
			this->__elem[0][2] = m[0][2];

			this->__elem[1][0] = m[1][0];
			this->__elem[1][1] = m[1][1];
			this->__elem[1][2] = m[1][2];

			this->__elem[2][0] = m[2][0];
			this->__elem[2][1] = m[2][1];
			this->__elem[2][2] = m[2][2];

			break;
		case LGE_MAT_BOTRIGHT_ALLIGN:
			this->__elem[1][1] = m[0][0];
			this->__elem[1][2] = m[0][1];
			this->__elem[1][3] = m[0][2];

			this->__elem[2][1] = m[1][0];
			this->__elem[2][2] = m[1][1];
			this->__elem[2][3] = m[1][2];

			this->__elem[3][1] = m[2][0];
			this->__elem[3][2] = m[2][1];
			this->__elem[3][3] = m[2][2];

			break;
		case LGE_MAT_BOTLEFT_ALLIGN:
			this->__elem[1][1] = m[0][0];
			this->__elem[1][2] = m[0][1];
			this->__elem[1][3] = m[0][2];

			this->__elem[2][1] = m[1][0];
			this->__elem[2][2] = m[1][1];
			this->__elem[2][3] = m[1][2];

			this->__elem[3][1] = m[2][0];
			this->__elem[3][2] = m[2][1];
			this->__elem[3][3] = m[2][2];

			break;
		default: LMM_EXCEPTION("LMM::Exception Unknown matrix allignment");
	}
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Mat<T, 2, 2>& m) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	this->__elem[0] = m.__elem[0];
	this->__elem[1] = m.__elem[1];
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4>::Mat(const Mat<T, 2, 2>& m, int32 allignment) {
	this->rows = 4;
	this->cols = 4;
	this->size = this->rows * this->cols * sizeof(T);

	switch (allignment) {
		case LGE_MAT_TOPLEFT_ALLIGN:
			this->__elem[0][0] = m[0][0];
			this->__elem[0][1] = m[0][1];

			this->__elem[1][0] = m[1][0];
			this->__elem[1][1] = m[1][1];

			break;
		case LGE_MAT_TOPRIGHT_ALLIGN:
			this->__elem[0][2] = m[0][0];
			this->__elem[0][3] = m[0][1];

			this->__elem[1][2] = m[1][0];
			this->__elem[1][3] = m[1][1];

			break;
		case LGE_MAT_BOTRIGHT_ALLIGN:
			this->__elem[2][2] = m[0][0];
			this->__elem[2][3] = m[0][1];

			this->__elem[3][2] = m[1][0];
			this->__elem[3][3] = m[1][1];

			break;
		case LGE_MAT_BOTLEFT_ALLIGN:
			this->__elem[2][0] = m[0][0];
			this->__elem[2][1] = m[0][1];

			this->__elem[3][0] = m[1][0];
			this->__elem[3][1] = m[1][1];

			break;
		case LGE_MAT_MIDDLE_ALLIGN:
			this->__elem[1][1] = m[0][0];
			this->__elem[1][2] = m[0][1];

			this->__elem[2][1] = m[1][0];
			this->__elem[2][2] = m[1][1];

			break;
		case LGE_MAT_MIDDLELEFT_ALLIGN:
			this->__elem[1][0] = m[0][0];
			this->__elem[1][1] = m[0][1];

			this->__elem[2][0] = m[1][0];
			this->__elem[2][1] = m[1][1];

			break;
		case LGE_MAT_MIDDLERIGHT_ALLIGN:
			this->__elem[1][2] = m[0][0];
			this->__elem[1][3] = m[0][1];

			this->__elem[2][2] = m[1][0];
			this->__elem[2][3] = m[1][1];

			break;
		default: LMM_EXCEPTION("LMM::Exception Unknown matrix allignment");
	}
}

// =====================================================================
// c++ matrix operator overloaded functions
// =====================================================================

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> Mat<T, 4, 4>::operator += (const Mat<T, 4, 4>& m) {
	this->__elem[0] += m[0];
	this->__elem[1] += m[1];
	this->__elem[2] += m[2];
	this->__elem[3] += m[3];
	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> Mat<T, 4, 4>::operator -= (const Mat<T, 4, 4>& m) {
	this->__elem[0] -= m[0];
	this->__elem[1] -= m[1];
	this->__elem[2] -= m[2];
	this->__elem[3] -= m[3];
	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> Mat<T, 4, 4>::operator += (const T s) {
	this->__elem[0][0] += s;
	this->__elem[0][1] += s;
	this->__elem[0][2] += s;
	this->__elem[0][3] += s;

	this->__elem[1][0] += s;
	this->__elem[1][1] += s;
	this->__elem[1][2] += s;
	this->__elem[1][3] += s;

	this->__elem[2][0] += s;
	this->__elem[2][1] += s;
	this->__elem[2][2] += s;
	this->__elem[2][3] += s;

	this->__elem[3][0] += s;
	this->__elem[3][1] += s;
	this->__elem[3][2] += s;
	this->__elem[3][3] += s;

	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> Mat<T, 4, 4>::operator -= (const T s) {
	this->__elem[0][0] -= s;
	this->__elem[0][1] -= s;
	this->__elem[0][2] -= s;
	this->__elem[0][3] -= s;

	this->__elem[1][0] -= s;
	this->__elem[1][1] -= s;
	this->__elem[1][2] -= s;
	this->__elem[1][3] -= s;

	this->__elem[2][0] -= s;
	this->__elem[2][1] -= s;
	this->__elem[2][2] -= s;
	this->__elem[2][3] -= s;

	this->__elem[3][0] -= s;
	this->__elem[3][1] -= s;
	this->__elem[3][2] -= s;
	this->__elem[3][3] -= s;

	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> Mat<T, 4, 4>::operator /= (const T s) {
	this->__elem[0][0] /= s;
	this->__elem[0][1] /= s;
	this->__elem[0][2] /= s;
	this->__elem[0][3] /= s;

	this->__elem[1][0] /= s;
	this->__elem[1][1] /= s;
	this->__elem[1][2] /= s;
	this->__elem[1][3] /= s;

	this->__elem[2][0] /= s;
	this->__elem[2][1] /= s;
	this->__elem[2][2] /= s;
	this->__elem[2][3] /= s;

	this->__elem[3][0] /= s;
	this->__elem[3][1] /= s;
	this->__elem[3][2] /= s;
	this->__elem[3][3] /= s;

	return *this;
}

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> Mat<T, 4, 4>::operator *= (const T s) {
	this->__elem[0][0] *= s;
	this->__elem[0][1] *= s;
	this->__elem[0][2] *= s;
	this->__elem[0][3] *= s;

	this->__elem[1][0] *= s;
	this->__elem[1][1] *= s;
	this->__elem[1][2] *= s;
	this->__elem[1][3] *= s;

	this->__elem[2][0] *= s;
	this->__elem[2][1] *= s;
	this->__elem[2][2] *= s;
	this->__elem[2][3] *= s;

	this->__elem[3][0] *= s;
	this->__elem[3][1] *= s;
	this->__elem[3][2] *= s;
	this->__elem[3][3] *= s;

	return *this;
}