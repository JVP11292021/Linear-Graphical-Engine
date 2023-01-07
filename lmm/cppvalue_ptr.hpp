#include "vec2.hpp"
#include "vec3.hpp"
#include "vec4.hpp"

#include "mat.hpp"

#include "lmm_defs.h"
#include "types.h"

#ifndef LMM_CPP_VPTR
#define LMM_CPP_VPTR

template <typename T>
LMM_FUNC_DECL LMM_INLINE T* value_ptr(Vec<T, 2> v);

template <typename T>
LMM_FUNC_DECL LMM_INLINE T* value_ptr(Vec<T, 3> v);

template <typename T>
LMM_FUNC_DECL LMM_INLINE T* value_ptr(Vec<T, 4> v);

#ifndef LMM_EXTERNAL_TEMPLATE
#	include "cppvalue_ptr.inl"
#endif
#endif