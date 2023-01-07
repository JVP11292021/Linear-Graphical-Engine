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
// c++ vector overloaded operators.  
// =====================================================================

// =====================================================================
// Vec 2 operations
// =====================================================================

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator + (const Vec<T, 2>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator + (T, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator + (const Vec<T, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator += (const Vec<T, 2>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator += (T, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator += (const Vec<T, 2>&, const Vec<T, 2>&);


template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator - (const Vec<T, 2>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator - (T, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator - (const Vec<T, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator -= (const Vec<T, 2>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator -= (T, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator -= (const Vec<T, 2>&, const Vec<T, 2>&);


template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator / (const Vec<T, 2>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator / (T, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator / (const Vec<T, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator /= (const Vec<T, 2>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator /= (T, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator /= (const Vec<T, 2>&, const Vec<T, 2>&);


template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator * (const Vec<T, 2>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator * (T, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL T operator * (const Vec<T, 2>&, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator *= (const Vec<T, 2>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 2> operator *= (T, const Vec<T, 2>&);

template <typename T>
LMM_FUNC_DECL T operator *= (const Vec<T, 2>&, const Vec<T, 2>&);

// =====================================================================
// Vec 3 operations
// =====================================================================

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator + (const Vec<T, 3>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator + (T, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator + (const Vec<T, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator += (const Vec<T, 3>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator += (T, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator += (const Vec<T, 3>&, const Vec<T, 3>&);


template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator - (const Vec<T, 3>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator - (T, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator - (const Vec<T, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator -= (const Vec<T, 3>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator -= (T, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator -= (const Vec<T, 3>&, const Vec<T, 3>&);


template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator / (const Vec<T, 3>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator / (T, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator / (const Vec<T, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator /= (const Vec<T, 3>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator /= (T, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator /= (const Vec<T, 3>&, const Vec<T, 3>&);


template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator * (const Vec<T, 3>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator * (T, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL T operator * (const Vec<T, 3>&, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator *= (const Vec<T, 3>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 3> operator *= (T, const Vec<T, 3>&);

template <typename T>
LMM_FUNC_DECL T operator *= (const Vec<T, 3>&, const Vec<T, 3>&);

// =====================================================================
// Vec 4 operations
// =====================================================================

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator + (const Vec<T, 4>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator + (T, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator + (const Vec<T, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator += (const Vec<T, 4>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator += (T, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator += (const Vec<T, 4>&, const Vec<T, 4>&);


template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator - (const Vec<T, 4>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator - (T, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator - (const Vec<T, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator -= (const Vec<T, 4>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator -= (T, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator -= (const Vec<T, 4>&, const Vec<T, 4>&);


template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator / (const Vec<T, 4>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator / (T, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator / (const Vec<T, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator /= (const Vec<T, 4>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator /= (T, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator /= (const Vec<T, 4>&, const Vec<T, 4>&);


template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator * (const Vec<T, 4>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator * (T, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL T operator * (const Vec<T, 4>&, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator *= (const Vec<T, 4>&, T);

template <typename T>
LMM_FUNC_DECL Vec<T, 4> operator *= (T, const Vec<T, 4>&);

template <typename T>
LMM_FUNC_DECL T operator *= (const Vec<T, 4>&, const Vec<T, 4>&);

#ifndef LMM_EXTERNAL_TEMPLATE
#	include "vec_geometry.inl"
#endif