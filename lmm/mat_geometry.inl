#pragma once

#include "mat_geometry.hpp"

// =====================================================================
// 2++ matrix overloaded arithmatic operators
// =====================================================================

// =====================================================================
// MAT 2 OPERATORS
// =====================================================================

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator + (const Mat<T, 2, 2>& m, T s) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator += (const Mat<T, 2, 2>& m, T s) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator + (T s, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator += (T s, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator += (const Mat<T, 2, 2>& m1, const Mat<T, 2, 2>& m2) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m1.__elem[0] + m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] + m2.__elem[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator + (const Mat<T, 2, 2>& m1, const Mat<T, 2, 2>& m2) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m1.__elem[0] + m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] + m2.__elem[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator += (const Mat<T, 2, 2>& m, const Vec<T, 2>& v) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] + v[0];
	nm.__elem[1] = m.__elem[1] + v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator + (const Mat<T, 2, 2>& m, const Vec<T, 2>& v) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] + v[0];
	nm.__elem[1] = m.__elem[1] + v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator += (const Vec<T, 2>& v, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] + v[0];
	nm.__elem[1] = m.__elem[1] + v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator + (const Vec<T, 2>& v, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] + v[0];
	nm.__elem[1] = m.__elem[1] + v[1];

	return nm;
}

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator - (const Mat<T, 2, 2>& m, T s) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator -= (const Mat<T, 2, 2>& m, T s) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator - (T s, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator -= (T s, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator -= (const Mat<T, 2, 2>& m1, const Mat<T, 2, 2>& m2) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m1.__elem[0] - m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] - m2.__elem[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator - (const Mat<T, 2, 2>& m1, const Mat<T, 2, 2>& m2) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m1.__elem[0] - m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] - m2.__elem[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator -= (const Mat<T, 2, 2>& m, const Vec<T, 2>& v) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] - v[0];
	nm.__elem[1] = m.__elem[1] - v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator - (const Mat<T, 2, 2>& m, const Vec<T, 2>& v) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] - v[0];
	nm.__elem[1] = m.__elem[1] - v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator -= (const Vec<T, 2>& v, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] - v[0];
	nm.__elem[1] = m.__elem[1] - v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator - (const Vec<T, 2>& v, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] - v[0];
	nm.__elem[1] = m.__elem[1] - v[1];

	return nm;
}

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator / (const Mat<T, 2, 2>& m, T s) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator /= (const Mat<T, 2, 2>& m, T s) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator / (T s, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator /= (T s, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator /= (const Mat<T, 2, 2>& m, const Vec<T, 2>& v) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] / v[0];
	nm.__elem[1] = m.__elem[1] / v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator / (const Mat<T, 2, 2>& m, const Vec<T, 2>& v) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] / v[0];
	nm.__elem[1] = m.__elem[1] / v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator /= (const Vec<T, 2>& v, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] / v[0];
	nm.__elem[1] = m.__elem[1] / v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator / (const Vec<T, 2>& v, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] / v[0];
	nm.__elem[1] = m.__elem[1] / v[1];

	return nm;
}

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator * (const Mat<T, 2, 2>& m, T s) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator *= (const Mat<T, 2, 2>& m, T s) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator * (T s, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator *= (T s, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator *= (const Mat<T, 2, 2>& m, const Vec<T, 2>& v) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] * v[0];
	nm.__elem[1] = m.__elem[1] * v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator * (const Mat<T, 2, 2>& m, const Vec<T, 2>& v) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] * v[0];
	nm.__elem[1] = m.__elem[1] * v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator *= (const Vec<T, 2>& v, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] * v[0];
	nm.__elem[1] = m.__elem[1] * v[1];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> operator * (const Vec<T, 2>& v, const Mat<T, 2, 2>& m) {
	Mat<T, 2, 2> nm;

	nm.__elem[0] = m.__elem[0] * v[0];
	nm.__elem[1] = m.__elem[1] * v[1];

	return nm;
}

// =====================================================================
// MAT 3 OPERATORS
// =====================================================================

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator + (const Mat<T, 3, 3>& m, T s) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;
	nm.__elem[2] = m.__elem[2] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator += (const Mat<T, 3, 3>& m, T s) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;
	nm.__elem[2] = m.__elem[2] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator + (T s, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;
	nm.__elem[2] = m.__elem[2] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator += (T s, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;
	nm.__elem[2] = m.__elem[2] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator += (const Mat<T, 3, 3>& m1, const Mat<T, 3, 3>& m2) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m1.__elem[0] + m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] + m2.__elem[1];
	nm.__elem[2] = m1.__elem[2] + m2.__elem[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator + (const Mat<T, 3, 3>& m1, const Mat<T, 3, 3>& m2) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m1.__elem[0] + m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] + m2.__elem[1];
	nm.__elem[2] = m1.__elem[2] + m2.__elem[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator += (const Mat<T, 3, 3>& m, const Vec<T, 3>& v) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] + v[0];
	nm.__elem[1] = m.__elem[1] + v[1];
	nm.__elem[2] = m.__elem[2] + v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator + (const Mat<T, 3, 3>& m, const Vec<T, 3>& v) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] + v[0];
	nm.__elem[1] = m.__elem[1] + v[1];
	nm.__elem[2] = m.__elem[2] + v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator += (const Vec<T, 3>& v, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] + v[0];
	nm.__elem[1] = m.__elem[1] + v[1];
	nm.__elem[2] = m.__elem[2] + v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator + (const Vec<T, 3>& v, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] + v[0];
	nm.__elem[1] = m.__elem[1] + v[1];
	nm.__elem[2] = m.__elem[2] + v[2];

	return nm;
}

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator - (const Mat<T, 3, 3>& m, T s) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;
	nm.__elem[2] = m.__elem[2] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator -= (const Mat<T, 3, 3>& m, T s) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;
	nm.__elem[2] = m.__elem[2] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator - (T s, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;
	nm.__elem[2] = m.__elem[2] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator -= (T s, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;
	nm.__elem[2] = m.__elem[2] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator -= (const Mat<T, 3, 3>& m1, const Mat<T, 3, 3>& m2) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m1.__elem[0] - m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] - m2.__elem[1];
	nm.__elem[2] = m1.__elem[2] - m2.__elem[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator - (const Mat<T, 3, 3>& m1, const Mat<T, 3, 3>& m2) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m1.__elem[0] - m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] - m2.__elem[1];
	nm.__elem[2] = m1.__elem[2] - m2.__elem[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator -= (const Mat<T, 3, 3>& m, const Vec<T, 3>& v) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] - v[0];
	nm.__elem[1] = m.__elem[1] - v[1];
	nm.__elem[2] = m.__elem[2] - v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator - (const Mat<T, 3, 3>& m, const Vec<T, 3>& v) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] - v[0];
	nm.__elem[1] = m.__elem[1] - v[1];
	nm.__elem[2] = m.__elem[2] - v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator -= (const Vec<T, 3>& v, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] - v[0];
	nm.__elem[1] = m.__elem[1] - v[1];
	nm.__elem[2] = m.__elem[2] - v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator - (const Vec<T, 3>& v, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] - v[0];
	nm.__elem[1] = m.__elem[1] - v[1];
	nm.__elem[2] = m.__elem[2] - v[2];

	return nm;
}

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator / (const Mat<T, 3, 3>& m, T s) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;
	nm.__elem[2] = m.__elem[2] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator /= (const Mat<T, 3, 3>& m, T s) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;
	nm.__elem[2] = m.__elem[2] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator / (T s, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;
	nm.__elem[2] = m.__elem[2] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator /= (T s, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;
	nm.__elem[2] = m.__elem[2] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator /= (const Mat<T, 3, 3>& m, const Vec<T, 3>& v) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] / v[0];
	nm.__elem[1] = m.__elem[1] / v[1];
	nm.__elem[2] = m.__elem[2] / v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator / (const Mat<T, 3, 3>& m, const Vec<T, 3>& v) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] / v[0];
	nm.__elem[1] = m.__elem[1] / v[1];
	nm.__elem[2] = m.__elem[2] / v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator /= (const Vec<T, 3>& v, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] / v[0];
	nm.__elem[1] = m.__elem[1] / v[1];
	nm.__elem[2] = m.__elem[2] / v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator / (const Vec<T, 3>& v, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] / v[0];
	nm.__elem[1] = m.__elem[1] / v[1];
	nm.__elem[2] = m.__elem[2] / v[2];

	return nm;
}

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator * (const Mat<T, 3, 3>& m, T s) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;
	nm.__elem[2] = m.__elem[2] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator *= (const Mat<T, 3, 3>& m, T s) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;
	nm.__elem[2] = m.__elem[2] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator * (T s, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;
	nm.__elem[2] = m.__elem[2] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator *= (T s, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;
	nm.__elem[2] = m.__elem[2] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator *= (const Mat<T, 3, 3>& m, const Vec<T, 3>& v) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] * v[0];
	nm.__elem[1] = m.__elem[1] * v[1];
	nm.__elem[2] = m.__elem[2] * v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator * (const Mat<T, 3, 3>& m, const Vec<T, 3>& v) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] * v[0];
	nm.__elem[1] = m.__elem[1] * v[1];
	nm.__elem[2] = m.__elem[2] * v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator *= (const Vec<T, 3>& v, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] * v[0];
	nm.__elem[1] = m.__elem[1] * v[1];
	nm.__elem[2] = m.__elem[2] * v[2];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> operator * (const Vec<T, 3>& v, const Mat<T, 3, 3>& m) {
	Mat<T, 3, 3> nm;

	nm.__elem[0] = m.__elem[0] * v[0];
	nm.__elem[1] = m.__elem[1] * v[1];
	nm.__elem[2] = m.__elem[2] * v[2];

	return nm;
}

// =====================================================================
// MAT 4 OPERATORS
// =====================================================================

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator + (const Mat<T, 4, 4>& m, T s) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;
	nm.__elem[2] = m.__elem[2] + s;
	nm.__elem[3] = m.__elem[3] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator += (const Mat<T, 4, 4>& m, T s) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;
	nm.__elem[2] = m.__elem[2] + s;
	nm.__elem[3] = m.__elem[3] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator + (T s, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;
	nm.__elem[2] = m.__elem[2] + s;
	nm.__elem[3] = m.__elem[3] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator += (T s, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] + s;
	nm.__elem[1] = m.__elem[1] + s;
	nm.__elem[2] = m.__elem[2] + s;
	nm.__elem[3] = m.__elem[3] + s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator += (const Mat<T, 4, 4>& m1, const Mat<T, 4, 4>& m2) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] + m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] + m2.__elem[1];
	nm.__elem[2] = m1.__elem[2] + m2.__elem[2];
	nm.__elem[3] = m1.__elem[3] + m2.__elem[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator + (const Mat<T, 4, 4>& m1, const Mat<T, 4, 4>& m2) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] + m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] + m2.__elem[1];
	nm.__elem[2] = m1.__elem[2] + m2.__elem[2];
	nm.__elem[3] = m1.__elem[3] + m2.__elem[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator += (const Mat<T, 4, 4>& m, const Vec<T, 4>& v) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] + v[0];
	nm.__elem[1] = m1.__elem[1] + v[1];
	nm.__elem[2] = m1.__elem[2] + v[2];
	nm.__elem[3] = m1.__elem[3] + v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator + (const Mat<T, 4, 4>& m, const Vec<T, 4>& v) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] + v[0];
	nm.__elem[1] = m1.__elem[1] + v[1];
	nm.__elem[2] = m1.__elem[2] + v[2];
	nm.__elem[3] = m1.__elem[3] + v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator += (const Vec<T, 4>& v, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] + v[0];
	nm.__elem[1] = m1.__elem[1] + v[1];
	nm.__elem[2] = m1.__elem[2] + v[2];
	nm.__elem[3] = m1.__elem[3] + v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator + (const Vec<T, 4>& v, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] + v[0];
	nm.__elem[1] = m1.__elem[1] + v[1];
	nm.__elem[2] = m1.__elem[2] + v[2];
	nm.__elem[3] = m1.__elem[3] + v[3];

	return nm;
}

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator - (const Mat<T, 4, 4>& m, T s) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;
	nm.__elem[2] = m.__elem[2] - s;
	nm.__elem[3] = m.__elem[3] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator -= (const Mat<T, 4, 4>& m, T s) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;
	nm.__elem[2] = m.__elem[2] - s;
	nm.__elem[3] = m.__elem[3] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator - (T s, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;
	nm.__elem[2] = m.__elem[2] - s;
	nm.__elem[3] = m.__elem[3] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator -= (T s, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] - s;
	nm.__elem[1] = m.__elem[1] - s;
	nm.__elem[2] = m.__elem[2] - s;
	nm.__elem[3] = m.__elem[3] - s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator -= (const Mat<T, 4, 4>& m1, const Mat<T, 4, 4>& m2) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] - m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] - m2.__elem[1];
	nm.__elem[2] = m1.__elem[2] - m2.__elem[2];
	nm.__elem[3] = m1.__elem[3] - m2.__elem[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator - (const Mat<T, 4, 4>& m1, const Mat<T, 4, 4>& m2) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] - m2.__elem[0];
	nm.__elem[1] = m1.__elem[1] - m2.__elem[1];
	nm.__elem[2] = m1.__elem[2] - m2.__elem[2];
	nm.__elem[3] = m1.__elem[3] - m2.__elem[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator -= (const Mat<T, 4, 4>& m, const Vec<T, 4>& v) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] - v[0];
	nm.__elem[1] = m1.__elem[1] - v[1];
	nm.__elem[2] = m1.__elem[2] - v[2];
	nm.__elem[3] = m1.__elem[3] - v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator - (const Mat<T, 4, 4>& m, const Vec<T, 4>& v) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] - v[0];
	nm.__elem[1] = m1.__elem[1] - v[1];
	nm.__elem[2] = m1.__elem[2] - v[2];
	nm.__elem[3] = m1.__elem[3] - v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator -= (const Vec<T, 4>& v, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] - v[0];
	nm.__elem[1] = m1.__elem[1] - v[1];
	nm.__elem[2] = m1.__elem[2] - v[2];
	nm.__elem[3] = m1.__elem[3] - v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator - (const Vec<T, 4>& v, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] - v[0];
	nm.__elem[1] = m1.__elem[1] - v[1];
	nm.__elem[2] = m1.__elem[2] - v[2];
	nm.__elem[3] = m1.__elem[3] - v[3];

	return nm;
}

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator / (const Mat<T, 4, 4>& m, T s) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;
	nm.__elem[2] = m.__elem[2] / s;
	nm.__elem[3] = m.__elem[3] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator /= (const Mat<T, 4, 4>& m, T s) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;
	nm.__elem[2] = m.__elem[2] / s;
	nm.__elem[3] = m.__elem[3] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator / (T s, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;
	nm.__elem[2] = m.__elem[2] / s;
	nm.__elem[3] = m.__elem[3] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator /= (T s, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] / s;
	nm.__elem[1] = m.__elem[1] / s;
	nm.__elem[2] = m.__elem[2] / s;
	nm.__elem[3] = m.__elem[3] / s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator /= (const Mat<T, 4, 4>& m, const Vec<T, 4>& v) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] / v[0];
	nm.__elem[1] = m1.__elem[1] / v[1];
	nm.__elem[2] = m1.__elem[2] / v[2];
	nm.__elem[3] = m1.__elem[3] / v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator / (const Mat<T, 4, 4>& m, const Vec<T, 4>& v) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] / v[0];
	nm.__elem[1] = m1.__elem[1] / v[1];
	nm.__elem[2] = m1.__elem[2] / v[2];
	nm.__elem[3] = m1.__elem[3] / v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator /= (const Vec<T, 4>& v, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] / v[0];
	nm.__elem[1] = m1.__elem[1] / v[1];
	nm.__elem[2] = m1.__elem[2] / v[2];
	nm.__elem[3] = m1.__elem[3] / v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator / (const Vec<T, 4>& v, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] / v[0];
	nm.__elem[1] = m1.__elem[1] / v[1];
	nm.__elem[2] = m1.__elem[2] / v[2];
	nm.__elem[3] = m1.__elem[3] / v[3];

	return nm;
}

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator * (const Mat<T, 4, 4>& m, T s) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;
	nm.__elem[2] = m.__elem[2] * s;
	nm.__elem[3] = m.__elem[3] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator *= (const Mat<T, 4, 4>& m, T s) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;
	nm.__elem[2] = m.__elem[2] * s;
	nm.__elem[3] = m.__elem[3] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator * (T s, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;
	nm.__elem[2] = m.__elem[2] * s;
	nm.__elem[3] = m.__elem[3] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator *= (T s, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m.__elem[0] * s;
	nm.__elem[1] = m.__elem[1] * s;
	nm.__elem[2] = m.__elem[2] * s;
	nm.__elem[3] = m.__elem[3] * s;

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator *= (const Mat<T, 4, 4>& m, const Vec<T, 4>& v) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] * v[0];
	nm.__elem[1] = m1.__elem[1] * v[1];
	nm.__elem[2] = m1.__elem[2] * v[2];
	nm.__elem[3] = m1.__elem[3] * v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator * (const Mat<T, 4, 4>& m, const Vec<T, 4>& v) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] * v[0];
	nm.__elem[1] = m1.__elem[1] * v[1];
	nm.__elem[2] = m1.__elem[2] * v[2];
	nm.__elem[3] = m1.__elem[3] * v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator *= (const Vec<T, 4>& v, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] * v[0];
	nm.__elem[1] = m1.__elem[1] * v[1];
	nm.__elem[2] = m1.__elem[2] * v[2];
	nm.__elem[3] = m1.__elem[3] * v[3];

	return nm;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> operator * (const Vec<T, 4>& v, const Mat<T, 4, 4>& m) {
	Mat<T, 4, 4> nm;

	nm.__elem[0] = m1.__elem[0] * v[0];
	nm.__elem[1] = m1.__elem[1] * v[1];
	nm.__elem[2] = m1.__elem[2] * v[2];
	nm.__elem[3] = m1.__elem[3] * v[3];

	return nm;
}