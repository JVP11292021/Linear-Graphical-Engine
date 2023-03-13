#pragma once

#include "types.h"
#include "lmm_defs.h"
#include "mat.hpp"
#include "vec.hpp"

// =====================================================================
// MAT 2 TRANSFORMS
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T sum(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T minimum(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T maximum(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> dot(const Mat<T, 2, 2>&, const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> negate(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> adjoint(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> inverse(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> cofactor(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T determinant(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> transpose(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 2, 2> reverse(const Mat<T, 2, 2>&);

// =====================================================================
// MAT 3 TRANSFORMS
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T sum(const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T minimum(const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T maximum(const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> dot(const Mat<T, 3, 3>&, const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> negate(const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> adjoint(const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> inverse(const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> cofactor(const Mat<T, 3, 3>&);
 
template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T determinant(const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> transpose(const Mat<T, 3, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 3, 3> reverse(const Mat<T, 3, 3>&);

// =====================================================================
// MAT 4 TRANSFORMS
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T sum(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T minimum(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T maximum(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> dot(const Mat<T, 4, 4>&, const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> negate(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> adjoint(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> inverse(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> cofactor(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T determinant(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> transpose(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> reverse(const Mat<T, 4, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> translate(const Mat<T, 4, 4>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, 4, 4> scale(const Mat<T, 4, 4>&, const Vec<T, 3>&);

#ifndef LMM_EXTERNAL_TEMPLATE
#include "mat_transforms.inl"
#endif