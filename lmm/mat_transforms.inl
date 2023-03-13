#pragma once

#include "mat_transforms.hpp"
#include "types.h"
#include "lmm_defs.h"
#include "mat.hpp"

// =====================================================================
// MAT 2 TRANSFORMS
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T sum(const Mat<T, 2, 2>& m) {
	T finalVal = 0;

	for (int32 i = 0; i < m.getRows(); i++)
		for (int32 c = 0; c < m.getCols(); c++)
			finalVal += m[i][c];

	return finalVal;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T minimum(const Mat<T, 2, 2>& m) {
	T min = (T)1000000000;

	for (int32 i = 0; i < m.getRows(); i++)
		for (int32 c = 0; c < m.getCols(); c++)
			if (m[i][c] < min)
				min = m[i][c];

	return min;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T maximum(const Mat<T, 2, 2>& m) {
	T max = 0;

	for (int32 i = 0; i < m.getRows(); i++)
		for (int32 c = 0; c < m.getCols(); c++)
			if (m[i][c] > max)
				max = m[i][c];

	return max;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> dot(const Mat<T, 2, 2>& m1, const Mat<T, 2, 2>& m2) {
	T A11 = m1[0][0] * m2[0][0] + m1[0][1] * m2[1][0];
	T A12 = m1[0][0] * m2[0][1] + m1[0][1] * m2[1][1];
	T A21 = m1[1][0] * m2[0][0] + m1[1][1] * m2[1][0];
	T A22 = m1[1][0] * m2[0][1] + m1[1][1] * m2[1][1];

	return Mat<T, 2, 2>(
		A11, A12,
		A21, A22
	);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> negate(const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] * (T)-1;
	nm.__elem[1] = m.__elem[1] * (T)-1;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> adjoint(const Mat<T, 2, 2>& m) {
	return transpose(cofactor(m));
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> inverse(const Mat<T, 2, 2>& m) {
	if (determinant(m) == 0)
		LMM_EXCEPTION("LMM:Exception determinant cannot be zero.");
	return (1 / determinant(m)) * adjoint(m);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> cofactor(const Mat<T, 2, 2>& m) {
	T A11 = m[1][1];
	T A12 = m[1][0] * -1;
	T A21 = m[0][1] * -1;
	T A22 = m[0][0];

	return Mat<T, 2, 2>(
		A11, A12,
		A21, A22
	);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T determinant(const Mat<T, 2, 2>& m) {
	return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> transpose(const Mat<T, 2, 2>& m) {
	T A11 = m[0][0];
	T A12 = m[1][0];
	T A21 = m[0][1];
	T A22 = m[1][1];

	return Mat<T, 2, 2>(
		A11, A12,
		A21, A22
	);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> reverse(const Mat<T, 2, 2>& m) {}

// =====================================================================
// MAT 3 TRANSFORMS
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T sum(const Mat<T, 3, 3>& m) {
	T finalVal = 0;

	for (int32 i = 0; i < m.getRows(); i++)
		for (int32 c = 0; c < m.getCols(); c++)
			finalVal += m[i][c];

	return finalVal;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T minimum(const Mat<T, 3, 3>& m) {
	T min = (T)1000000000;

	for (int32 i = 0; i < m.getRows(); i++)
		for (int32 c = 0; c < m.getCols(); c++)
			if (m[i][c] < min)
				min = m[i][c];

	return min;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T maximum(const Mat<T, 3, 3>& m) {
	T max = 0;

	for (int32 i = 0; i < m.getRows(); i++)
		for (int32 c = 0; c < m.getCols(); c++)
			if (m[i][c] > max)
				max = m[i][c];

	return max;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> dot(const Mat<T, 3, 3>& m1, const Mat<T, 3, 3>& m2) {
	T A11 = (m1[0][0] * m2[0][0]) + (m1[0][1] * m2[1][0]) + (m1[0][2] * m2[2][0]);
	T A12 = (m1[0][0] * m2[0][1]) + (m1[0][1] * m2[1][1]) + (m1[0][2] * m2[2][1]);
	T A13 = (m1[0][0] * m2[0][2]) + (m1[0][1] * m2[1][2]) + (m1[0][2] * m2[2][2]);

	T A21 = (m1[1][0] * m2[0][0]) + (m1[1][1] * m2[1][0]) + (m1[1][2] * m2[2][0]);
	T A22 = (m1[1][0] * m2[0][1]) + (m1[1][1] * m2[1][1]) + (m1[1][2] * m2[2][1]);
	T A23 = (m1[1][0] * m2[0][2]) + (m1[1][1] * m2[1][2]) + (m1[1][2] * m2[2][2]);

	T A31 = (m1[2][0] * m2[0][0]) + (m1[2][1] * m2[1][0]) + (m1[2][2] * m2[2][0]);
	T A32 = (m1[2][0] * m2[0][1]) + (m1[2][1] * m2[1][1]) + (m1[2][2] * m2[2][1]);
	T A33 = (m1[2][0] * m2[0][2]) + (m1[2][1] * m2[1][2]) + (m1[2][2] * m2[2][2]);

	return Mat<T, 3, 3>(
		A11, A12, A13,
		A21, A22, A23,
		A31, A32, A33
	);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> negate(const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;
	nm.__elem[0] = m.__elem[0] * (T)-1;
	nm.__elem[1] = m.__elem[1] * (T)-1;
	nm.__elem[2] = m.__elem[2] * (T)-1;


	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> adjoint(const Mat<T, 3, 3>& m) {
	return transpose(cofactor(m));
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> inverse(const Mat<T, 3, 3>& m) {
	if (determinant(m) == 0)
		LMM_EXCEPTION("LMM:Exception determinant cannot be zero.");
	return (1 / determinant(m)) * adjoint(m);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> cofactor(const Mat<T, 3, 3>& m) {
	T A11 = (m[1][1] * m[2][2]) - (m[2][1] * m[1][2]);
	T A12 = ((m[1][0] * m[2][2]) - (m[2][0] * m[1][2])) * -1;
	T A13 = (m[1][0] * m[2][1]) - (m[2][0] * m[1][1]);

	T A21 = ((m[0][1] * m[2][2]) - (m[2][1] * m[2][2])) * -1;
	T A22 = (m[0][0] * m[2][2]) - (m[2][0] * m[0][2]);
	T A23 = (m[0][0] * m[2][1]) - (m[2][0] * m[0][1]) * -1;

	T A31 = (m[0][1] * m[1][2]) - (m[0][2] * m[1][1]);
	T A32 = ((m[0][0] * m[1][2]) - (m[1][0] * m[0][2])) * -1;
	T A33 = (m[0][0] * m[1][1]) - (m[1][0] * m[0][1]);

	return Mat<T, 3, 3>(
		A11, A12, A13,
		A21, A22, A23,
		A31, A32, A33
	);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T determinant(const Mat<T, 3, 3>& m) {
	T det1 = m[0][0] * ((m[1][1] * m[2][2]) - (m[2][1] * m[1][2]));
	T det2 = m[0][1] * ((m[1][0] * m[2][2]) - (m[2][0] * m[1][2]));
	T det3 = m[0][2] * ((m[1][0] * m[2][1]) - (m[2][0] * m[1][1]));
	
	return det1 - det2 + det3;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> transpose(const Mat<T, 3, 3>& m) {
	T A11 = m[0][0];
	T A12 = m[1][0];
	T A13 = m[2][0];
	
	T A21 = m[0][1];
	T A22 = m[1][1];
	T A23 = m[2][1];
	
	T A31 = m[0][2];
	T A32 = m[1][2];
	T A33 = m[2][2];

	return Mat<T, 3, 3>(
		A11, A12, A13,
		A21, A22, A23,
		A31, A32, A33
	);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> reverse(const Mat<T, 3, 3>& m) {}

// =====================================================================
// MAT 4 TRANSFORMS
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T sum(const Mat<T, 4, 4>& m) {
	T finalVal = 0;

	for (int32 i = 0; i < m.getRows(); i++)
		for (int32 c = 0; c < m.getCols(); c++)
			finalVal += m[i][c];

	return finalVal;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T minimum(const Mat<T, 4, 4>& m) {
	T min = (T)1000000000;

	for (int32 i = 0; i < m.getRows(); i++)
		for (int32 c = 0; c < m.getCols(); c++)
			if (m[i][c] < min)
				min = m[i][c];

	return min;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T maximum(const Mat<T, 4, 4>& m) {
	T max = 0;

	for (int32 i = 0; i < m.getRows(); i++)
		for (int32 c = 0; c < m.getCols(); c++)
			if (m[i][c] > max)
				max = m[i][c];

	return max;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> dot(const Mat<T, 4, 4>& m1, const Mat<T, 4, 4>& m2) {
	T A11 = (m1[0][0] * m2[0][0]) + (m1[0][1] * m2[1][0]) + (m1[0][2] * m2[2][0]) + (m1[0][3] * m2[3][0]);
	T A12 = (m1[0][0] * m2[0][1]) + (m1[0][1] * m2[1][1]) + (m1[0][2] * m2[2][1]) + (m1[0][3] * m2[3][1]);
	T A13 = (m1[0][0] * m2[0][2]) + (m1[0][1] * m2[1][2]) + (m1[0][2] * m2[2][2]) + (m1[0][3] * m2[3][2]);
	T A14 = (m1[0][0] * m2[0][3]) + (m1[0][1] * m2[1][3]) + (m1[0][2] * m2[2][3]) + (m1[0][3] * m2[3][3]);

	T A21 = (m1[1][0] * m2[0][0]) + (m1[1][1] * m2[1][0]) + (m1[1][2] * m2[2][0]) + (m1[1][3] * m2[3][0]);
	T A22 = (m1[1][0] * m2[0][1]) + (m1[1][1] * m2[1][1]) + (m1[1][2] * m2[2][1]) + (m1[1][3] * m2[3][1]);
	T A23 = (m1[1][0] * m2[0][2]) + (m1[1][1] * m2[1][2]) + (m1[1][2] * m2[2][2]) + (m1[1][3] * m2[3][2]);
	T A24 = (m1[1][0] * m2[0][3]) + (m1[1][1] * m2[1][3]) + (m1[1][2] * m2[2][3]) + (m1[1][3] * m2[3][3]);

	T A31 = (m1[2][0] * m2[0][0]) + (m1[2][1] * m2[1][0]) + (m1[2][2] * m2[2][0]) + (m1[2][3] * m2[3][0]);
	T A32 = (m1[2][0] * m2[0][1]) + (m1[2][1] * m2[1][1]) + (m1[2][2] * m2[2][1]) + (m1[2][3] * m2[3][1]);
	T A33 = (m1[2][0] * m2[0][2]) + (m1[2][1] * m2[1][2]) + (m1[2][2] * m2[2][2]) + (m1[2][3] * m2[3][2]);
	T A34 = (m1[2][0] * m2[0][3]) + (m1[2][1] * m2[1][3]) + (m1[2][2] * m2[2][3]) + (m1[2][3] * m2[3][3]);

	T A41 = (m1[3][0] * m2[0][0]) + (m1[3][1] * m2[1][0]) + (m1[3][2] * m2[2][0]) + (m1[3][3] * m2[3][0]);
	T A42 = (m1[3][0] * m2[0][1]) + (m1[3][1] * m2[1][1]) + (m1[3][2] * m2[2][1]) + (m1[3][3] * m2[3][1]);
	T A43 = (m1[3][0] * m2[0][2]) + (m1[3][1] * m2[1][2]) + (m1[3][2] * m2[2][2]) + (m1[3][3] * m2[3][2]);
	T A44 = (m1[3][0] * m2[0][3]) + (m1[3][1] * m2[1][3]) + (m1[3][2] * m2[2][3]) + (m1[3][3] * m2[3][3]);

	return Mat<T, 4, 4>(
		A11, A12, A13, A14,
		A21, A22, A23, A24,
		A31, A32, A33, A34,
		A41, A42, A43, A44
	);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> negate(const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] * (T)-1;
	nm.__elem[1] = m.__elem[1] * (T)-1;
	nm.__elem[2] = m.__elem[2] * (T)-1;
	nm.__elem[3] = m.__elem[3] * (T)-1;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> adjoint(const Mat<T, 4, 4>& m) {
	return transpose(cofactor(m));
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> inverse(const Mat<T, 4, 4>& m) {
	if (determinant(m) == 0)
		LMM_EXCEPTION("LMM:Exception determinant cannot be zero.");
	return (1 / determinant(m)) * adjoint(m);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> cofactor(const Mat<T, 4, 4>& m) {
	T A11 = ((m[1][1] * m[2][2] * m[3][3]) + (m[1][2] * m[2][3] * m[3][1]) + (m[1][3] * m[2][1] * m[3][2]) - (m[1][3] * m[2][2] * m[3][1]) - (m[1][2] * m[2][1] * m[3][3]) - (m[1][1] * m[2][3] * m[3][2]));
	T A12 = ((m[1][0] * m[2][2] * m[3][3]) + (m[1][2] * m[2][3] * m[3][0]) + (m[1][3] * m[2][0] * m[3][2]) - (m[1][3] * m[2][2] * m[3][0]) - (m[1][2] * m[2][0] * m[3][3]) - (m[1][0] * m[2][3] * m[3][2])) * -1;
	T A13 = ((m[1][0] * m[2][1] * m[3][3]) + (m[1][1] * m[2][3] * m[3][0]) + (m[1][3] * m[2][0] * m[3][1]) - (m[1][3] * m[2][1] * m[3][0]) - (m[1][1] * m[2][0] * m[3][3]) - (m[1][0] * m[2][3] * m[3][1]));
	T A14 = ((m[1][0] * m[2][1] * m[3][2]) + (m[1][1] * m[2][2] * m[3][0]) + (m[1][2] * m[2][0] * m[3][1]) - (m[1][2] * m[2][1] * m[3][0]) - (m[1][1] * m[2][0] * m[3][2]) - (m[1][0] * m[2][2] * m[3][1])) * -1;

	T A21 = ((m[0][1] * m[2][2] * m[3][3]) + (m[0][2] * m[2][3] * m[3][1]) + (m[0][3] * m[2][1] * m[3][2]) - (m[0][3] * m[2][2] * m[3][1]) - (m[0][2] * m[2][1] * m[3][3]) - (m[0][1] * m[2][3] * m[3][2])) * -1;
	T A22 = ((m[0][0] * m[2][2] * m[3][3]) + (m[0][2] * m[2][3] * m[3][0]) + (m[0][3] * m[2][0] * m[3][2]) - (m[0][3] * m[2][2] * m[3][0]) - (m[0][2] * m[2][0] * m[3][3]) - (m[0][0] * m[2][3] * m[3][2]));
	T A23 = ((m[0][0] * m[2][1] * m[3][3]) + (m[0][1] * m[2][3] * m[3][0]) + (m[0][3] * m[2][0] * m[3][1]) - (m[0][3] * m[2][1] * m[3][0]) - (m[0][1] * m[2][0] * m[3][3]) - (m[0][0] * m[2][3] * m[3][1])) * -1;
	T A24 = ((m[0][0] * m[2][1] * m[3][2]) + (m[0][1] * m[2][2] * m[3][0]) + (m[0][2] * m[2][0] * m[3][1]) - (m[0][2] * m[2][1] * m[3][0]) - (m[0][1] * m[2][0] * m[3][2]) - (m[0][0] * m[2][2] * m[3][1]));

	T A31 = ((m[0][1] * m[1][2] * m[3][3]) + (m[0][2] * m[1][3] * m[3][1]) + (m[0][3] * m[1][1] * m[3][2]) - (m[0][3] * m[1][2] * m[3][1]) - (m[0][2] * m[1][1] * m[3][3]) - (m[0][1] * m[1][3] * m[3][2]));
	T A32 = ((m[0][0] * m[1][2] * m[3][3]) + (m[0][2] * m[1][3] * m[3][0]) + (m[0][3] * m[1][0] * m[3][2]) - (m[0][3] * m[1][2] * m[3][0]) - (m[0][2] * m[1][0] * m[3][3]) - (m[0][0] * m[1][3] * m[3][2])) * -1;
	T A33 = ((m[0][0] * m[1][1] * m[3][3]) + (m[0][1] * m[1][3] * m[3][0]) + (m[0][3] * m[1][0] * m[3][1]) - (m[0][3] * m[1][1] * m[3][0]) - (m[0][1] * m[1][0] * m[3][3]) - (m[0][0] * m[1][3] * m[3][1]));
	T A34 = ((m[0][0] * m[1][1] * m[3][2]) + (m[0][1] * m[1][2] * m[3][0]) + (m[0][2] * m[1][0] * m[3][1]) - (m[0][2] * m[1][1] * m[3][0]) - (m[0][1] * m[1][0] * m[3][2]) - (m[0][0] * m[1][2] * m[3][1])) * -1;

	T A41 = ((m[0][1] * m[1][2] * m[2][3]) + (m[0][2] * m[1][3] * m[2][1]) + (m[0][3] * m[1][1] * m[2][2]) - (m[0][3] * m[1][2] * m[2][1]) - (m[0][2] * m[1][1] * m[2][3]) - (m[0][1] * m[1][3] * m[2][2])) * -1;
	T A42 = ((m[0][0] * m[1][2] * m[2][3]) + (m[0][2] * m[1][3] * m[2][0]) + (m[0][3] * m[1][0] * m[2][2]) - (m[0][3] * m[1][2] * m[2][0]) - (m[0][2] * m[1][0] * m[2][3]) - (m[0][0] * m[1][3] * m[2][2]));
	T A43 = ((m[0][0] * m[1][1] * m[2][3]) + (m[0][1] * m[1][3] * m[2][0]) + (m[0][3] * m[1][0] * m[2][1]) - (m[0][3] * m[1][1] * m[2][0]) - (m[0][1] * m[1][0] * m[2][3]) - (m[0][0] * m[1][3] * m[2][1])) * -1;
	T A44 = ((m[0][0] * m[1][1] * m[2][2]) + (m[0][1] * m[1][2] * m[2][0]) + (m[0][2] * m[1][0] * m[2][1]) - (m[0][2] * m[1][1] * m[2][0]) - (m[0][1] * m[1][0] * m[2][2]) - (m[0][0] * m[1][2] * m[2][1]));

	return Mat<T, 4, 4>(
		A11, A12, A13, A14,
		A21, A22, A23, A24,
		A31, A32, A33, A34,
		A41, A42, A43, A44
	);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T determinant(const Mat<T, 4, 4>& m) {
	T det1 = determinant(Mat<T, 3, 3>(
		m[1][1], m[1][2], m[1][3],
		m[2][1], m[2][2], m[2][3],
		m[3][1], m[3][2], m[3][3]
		));

	T det2 = determinant(Mat<T, 3, 3>(
		m[0][1], m[0][2], m[0][3],
		m[2][1], m[2][2], m[2][3],
		m[3][1], m[3][2], m[3][3]
		));

	T det3 = determinant(Mat<T, 3, 3>(
		m[0][1], m[0][2], m[0][3],
		m[1][1], m[1][2], m[1][3],
		m[3][1], m[3][2], m[3][3]
		));

	T det4 = determinant(Mat<T, 3, 3>(
		m[0][1], m[0][2], m[0][3],
		m[1][1], m[1][2], m[1][3],
		m[2][1], m[2][2], m[2][3]
		));

	return m[0][0] * det1 - m[1][0] * det2 + m[2][0] * det3 - m[3][0] * det4;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> transpose(const Mat<T, 4, 4>& m) {
	T A11 = m[0][0];
	T A12 = m[1][0];
	T A13 = m[2][0];
	T A14 = m[3][0];
			    
	T A21 = m[0][1];
	T A22 = m[1][1];
	T A23 = m[2][1];
	T A24 = m[3][1];
			    
	T A31 = m[0][2];
	T A32 = m[1][2];
	T A33 = m[2][2];
	T A34 = m[3][2];
			    
	T A41 = m[0][3];
	T A42 = m[1][3];
	T A43 = m[2][3];
	T A44 = m[3][3];

	return Mat<T, 4, 4>(
		A11, A12, A13, A14,
		A21, A22, A23, A24,
		A31, A32, A33, A34,
		A41, A42, A43, A44
	);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> reverse(const Mat<T, 4, 4>& m) {}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> translate(const Mat<T, 4, 4>& m, const Vec<T, 3>& v) {
	Mat<T, 4, 4> result = m;
	result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> scale(const Mat<T, 4, 4>& m, const Vec<T, 3>& v) {
	Mat<T, 4, 4> result;
	result[0] = m[0] * v[0];
	result[1] = m[1] * v[1];
	result[2] = m[2] * v[2];
	result[3] = m[3];
	return result;
}

#ifndef LMM_EXTERNAL_TEMPLATE
#include "mat_transforms.inl"
#endif