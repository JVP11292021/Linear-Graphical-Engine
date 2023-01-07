#pragma once

#include "types.h"
#include "lmm_defs.h"
#include "mat.hpp"
#include "vec.hpp"

// =====================================================================
// 2++ matrix overloaded arithmatic operators
// =====================================================================

// =====================================================================
// MAT 2 OPERATORS
// =====================================================================

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator + (const Mat<T, 2, 2>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator += (const Mat<T, 2, 2>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator + (T, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator += (T, const Mat<T, 2, 2>&); 

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator += (const Mat<T, 2, 2>&, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator + (const Mat<T, 2, 2>&, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator += (const Mat<T, 2, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator + (const Mat<T, 2, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator += (const Vec<T, 2>&, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator + (const Vec<T, 2>&, const Mat<T, 2, 2>&);

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator - (const Mat<T, 2, 2>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator -= (const Mat<T, 2, 2>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator - (T, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator -= (T, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator -= (const Mat<T, 2, 2>&, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator - (const Mat<T, 2, 2>&, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator -= (const Mat<T, 2, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator - (const Mat<T, 2, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator -= (const Vec<T, 2>&, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator - (const Vec<T, 2>&, const Mat<T, 2, 2>&);

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator / (const Mat<T, 2, 2>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator /= (const Mat<T, 2, 2>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator / (T, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator /= (T, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator /= (const Mat<T, 2, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator / (const Mat<T, 2, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator /= (const Vec<T, 2>&, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator / (const Vec<T, 2>&, const Mat<T, 2, 2>&);

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator * (const Mat<T, 2, 2>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator *= (const Mat<T, 2, 2>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator * (T, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator *= (T, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator *= (const Mat<T, 2, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator * (const Mat<T, 2, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator *= (const Vec<T, 2>&, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 2, 2> operator * (const Vec<T, 2>&, const Mat<T, 2, 2>&);

// =====================================================================
// MAT 3 OPERATORS
// =====================================================================

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator + (const Mat<T, 3, 3>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator += (const Mat<T, 3, 3>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator + (T, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator += (T, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator += (const Mat<T, 3, 3>&, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator + (const Mat<T, 3, 3>&, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator += (const Mat<T, 3, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator + (const Mat<T, 3, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator += (const Vec<T, 3>&, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator + (const Vec<T, 3>&, const Mat<T, 3, 3>&);

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator - (const Mat<T, 3, 3>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator -= (const Mat<T, 3, 3>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator - (T, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator -= (T, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator -= (const Mat<T, 3, 3>&, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator - (const Mat<T, 3, 3>&, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator -= (const Mat<T, 3, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator - (const Mat<T, 3, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator -= (const Vec<T, 3>&, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator - (const Vec<T, 3>&, const Mat<T, 3, 3>&);

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator / (const Mat<T, 3, 3>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator /= (const Mat<T, 3, 3>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator / (T, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator /= (T, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator /= (const Mat<T, 3, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator / (const Mat<T, 3, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator /= (const Vec<T, 3>&, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator / (const Vec<T, 3>&, const Mat<T, 3, 3>&);

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator * (const Mat<T, 3, 3>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator *= (const Mat<T, 3, 3>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator * (T, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator *= (T, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator *= (const Mat<T, 3, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator * (const Mat<T, 3, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator *= (const Vec<T, 3>&, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 3, 3> operator * (const Vec<T, 3>&, const Mat<T, 3, 3>&);

// =====================================================================
// MAT 4 OPERATORS
// =====================================================================

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator + (const Mat<T, 4, 4>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator += (const Mat<T, 4, 4>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator + (T, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator += (T, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator += (const Mat<T, 4, 4>&, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator + (const Mat<T, 4, 4>&, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator += (const Mat<T, 4, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator + (const Mat<T, 4, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator += (const Vec<T, 4>&, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator + (const Vec<T, 4>&, const Mat<T, 4, 4>&);

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator - (const Mat<T, 4, 4>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator -= (const Mat<T, 4, 4>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator - (T, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator -= (T, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator -= (const Mat<T, 4, 4>&, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator - (const Mat<T, 4, 4>&, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator -= (const Mat<T, 4, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator - (const Mat<T, 4, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator -= (const Vec<T, 4>&, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator - (const Vec<T, 4>&, const Mat<T, 4, 4>&);

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator / (const Mat<T, 4, 4>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator /= (const Mat<T, 4, 4>&, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator /= (T, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator /= (const Mat<T, 4, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator / (const Mat<T, 4, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator / (const Vec<T, 4>&, const Mat<T, 4, 4>&);

// ---------------------------------------------------------------------

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator *= (const Mat<T, 4, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator * (const Mat<T, 4, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator *= (const Vec<T, 4>&, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR  Mat<T, 4, 4> operator * (const Vec<T, 4>&, const Mat<T, 4, 4>&);

#ifndef LMM_EXTERNAL_TEMPLATE
#include "mat_geometry.inl"
#endif