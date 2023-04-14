#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

#include "mat.hpp"

#include "lmm_defs.h"
#include "types.h"

#include <stdio.h>

#ifndef LMM_CPP_VPTR
#define LMM_CPP_VPTR

template <typename T>
LMM_FUNC_DECL LMM_INLINE 
const T* value_ptr(const Vec<T, 2>& v);

template <typename T>
LMM_FUNC_DECL LMM_INLINE 
const T* value_ptr(const Vec<T, 3>& v);

template <typename T>
LMM_FUNC_DECL LMM_INLINE 
const T* value_ptr(const Vec<T, 4>& v);

template <typename T>
LMM_FUNC_DECL LMM_INLINE
const T* value_ptr(const Mat<T, 2, 2>& m);

template <typename T>
LMM_FUNC_DECL LMM_INLINE
const T* value_ptr(const Mat<T, 3, 3>& m);

template <typename T>
LMM_FUNC_DECL LMM_INLINE
const T* value_ptr(const Mat<T, 4, 4>& m);

#ifndef LMM_EXTERNAL_TEMPLATE
#	include "cppvalue_ptr.inl"
#endif
#endif