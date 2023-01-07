#pragma once

#include "lmm_defs.h"
#include "types.h"

template <typename T>
class Quaternion;

// =====================================================================
// c++ quaternion operations.  
// =====================================================================

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator + (const Quaternion<T>&, const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator - (const Quaternion<T>&, const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator * (const Quaternion<T>&, const Quaternion<T>&);

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator * (const Quaternion<T>&, const T);

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator * (const T, const Quaternion<T>&);

#ifndef LMM_EXTERNAL_TEMPLATE
#include "quat_geometry.inl"
#endif