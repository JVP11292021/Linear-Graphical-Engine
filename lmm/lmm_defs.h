#pragma once

#define LMM_MAJOR		0.2
#define LMM_MINOR		0.1
#define	LMM_PATCH		0.2
#define LMM_REVISION	0
#define LMM_VERSION		0.2
#define LMM_MESSAGE		"LMM: V0.2"

#include "lmm_exceptions.h"
#include "lmm_platform_setup.h"
#include "lmm_compiler_setup.h"

#ifdef __cplusplus
#define LMM_CPP 
#else
#define LMM_C
#endif

#ifdef LMM_RH_COORD_SYSTEM
#	define LMM_RH
#else
#	define LMM_LH
#endif

#if LMM_CUDA_COMPILER & LMM_COMPILER
#	define LMM_CUDA_FUNC_DEF __device__ __host__
#	define LMM_CUDA_FUNC_DECL __device__ __host__
#else
#	define LMM_CUDA_FUNC_DEF
#	define LMM_CUDA_FUNC_DECL
#endif

#ifndef INLINE
#	if __GNUC__ && !__GNUC_STDC_INLINE__
#	 define LMM_INLINE extern inline
#	else
#	 define LMM_INLINE inline
#	endif
#endif

#ifdef LMM_CPP
#	define LMM_CONSTEXPR constexpr
#endif

#define LMM_ENABLE  1
#define LMM_DISABLE 0

#define LMM_FILE	__FILE__
#define LMM_LINE	__LINE__

#if __STDCPP_THREADS__ == 1
#	define LMM_MULTITHREAD
#else
#	define LMM_SINGLETHREAD
#endif

#ifdef LMM_CUDA_FUNC_DEF & LMM_CUDA_FUNC_DECL
#	define LMM_FUNC_DECL LMM_CUDA_FUNC_DECL
#	define LMM_FUNC_QUALIFIER LMM_CUDA_FUNC_DEF LMM_INLINE
#endif



