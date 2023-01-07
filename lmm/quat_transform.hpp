#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "vec_transforms.hpp"

template <typename T>
class Quaternion;

// =====================================================================
// c++ quaternion operations.  
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> mul(const Quaternion<T>&, const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T norm(const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> normalize(const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> make_unitnorm(const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> conjugate(const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> inverse(const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> inverse(const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3> rotateBy(const Vec<T, 3>&, f32, const Vec<T, 3>&);

#ifndef LMM_EXTERNAL_TEMPLATE
#include "quat_transform.inl"
#endif