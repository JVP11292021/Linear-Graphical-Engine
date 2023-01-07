#pragma once

#include "types.h"
#include "vec_types.hpp"
#include "lmm_defs.h"

// Vector class forward declarations
template <typename T>
class Vec<T, 2>;

template <typename T>
class Vec<T, 3>;

template <typename T>
class Vec<T, 4>;

// =====================================================================
// c++ vector operations.  
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T magnitude(const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T magnitude(const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T magnitude(const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 2> normalize(const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3> normalize(const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4> normalize(const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T cross(T, T, T, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3> cross(const Vec<T, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4> cross(const Vec<T, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T dot(T, T, T);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T dot(const Vec<T, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T dot(const Vec<T, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T dot(const Vec<T, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 2> negate(const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3> negate(const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4> negate(const Vec<T, 4>&);

#ifndef LMM_EXTERN_TEMPLATE
#include "vec_transforms.inl"
#endif