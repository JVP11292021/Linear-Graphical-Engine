#pragma once

// =====================================================================
// Built in compiler support
// =====================================================================

#define LMM_COMPILER_UNKNOWN		0x00000000

// Intel
#define LMM_COMPILER_INTEL			0x00100000
#define LMM_COMPILER_INTEL14		0x00100040
#define LMM_COMPILER_INTEL15		0x00100050
#define LMM_COMPILER_INTEL16		0x00100060
#define LMM_COMPILER_INTEL17		0x00100070

// Visual C++ defines
#define LMM_COMPILER_VC				0x01000000
#define LMM_COMPILER_VC12			0x01000001
#define LMM_COMPILER_VC14			0x01000002
#define LMM_COMPILER_VC15			0x01000003
#define LMM_COMPILER_VC15_3			0x01000004
#define LMM_COMPILER_VC15_5			0x01000005
#define LMM_COMPILER_VC15_6			0x01000006
#define LMM_COMPILER_VC15_7			0x01000007
#define LMM_COMPILER_VC15_8			0x01000008
#define LMM_COMPILER_VC15_9			0x01000009
#define LMM_COMPILER_VC16			0x0100000A

// GCC defines
#define LMM_COMPILER_GCC			0x02000000
#define LMM_COMPILER_GCC46			0x020000D0
#define LMM_COMPILER_GCC47			0x020000E0
#define LMM_COMPILER_GCC48			0x020000F0
#define LMM_COMPILER_GCC49			0x02000100
#define LMM_COMPILER_GCC5			0x02000200
#define LMM_COMPILER_GCC6			0x02000300
#define LMM_COMPILER_GCC7			0x02000400
#define LMM_COMPILER_GCC8			0x02000500

// CUDA
#define LMM_COMPILER_CUDA			0x10000000
#define LMM_COMPILER_CUDA75			0x10000001
#define LMM_COMPILER_CUDA80			0x10000002
#define LMM_COMPILER_CUDA90			0x10000004

// SYCL
#define LMM_COMPILER_SYCL			0x00300000

// Clang
#define LMM_COMPILER_CLANG			0x20000000
#define LMM_COMPILER_CLANG34		0x20000050
#define LMM_COMPILER_CLANG35		0x20000060
#define LMM_COMPILER_CLANG36		0x20000070
#define LMM_COMPILER_CLANG37		0x20000080
#define LMM_COMPILER_CLANG38		0x20000090
#define LMM_COMPILER_CLANG39		0x200000A0
#define LMM_COMPILER_CLANG40		0x200000B0
#define LMM_COMPILER_CLANG41		0x200000C0
#define LMM_COMPILER_CLANG42		0x200000D0

// Intellisense
#define LMM_COMPILER_INTELLISENSE

// Build model
#define LMM_MODEL_32				0x00000010
#define LMM_MODEL_64				0x00000020

// Force generic C++ compiler
#ifdef LMM_FORCE_COMPILER_UNKNOWN
#	define LMM_COMPILER LMM_COMPILER_UNKNOWN

#elif defined(__INTEL_COMPILER)
#	if __INTEL_COMPILER >= 1700
#		define LMM_COMPILER LMM_COMPILER_INTEL17
#	elif __INTEL_COMPILER >= 1600
#		define LMM_COMPILER LMM_COMPILER_INTEL16
#	elif __INTEL_COMPILER >= 1500
#		define LMM_COMPILER LMM_COMPILER_INTEL15
#	elif __INTEL_COMPILER >= 1400
#		define LMM_COMPILER LMM_COMPILER_INTEL14
#	elif __INTEL_COMPILER < 1400
#		error "LMM requires ICC 2013 SP1 or newer"
#	endif

// CUDA
#elif defined(__CUDACC__)
#	if !defined(CUDA_VERSION) && !defined(LMM_FORCE_CUDA)
#		include <cuda.h>  // make sure version is defined since nvcc does not define it itself!
#	endif
#	if CUDA_VERSION >= 8000
#		define LMM_COMPILER LMM_COMPILER_CUDA80
#	elif CUDA_VERSION >= 7500
#		define LMM_COMPILER LMM_COMPILER_CUDA75
#	elif CUDA_VERSION >= 7000
#		define LMM_COMPILER GLM_COMPILER_CUDA70
#	elif CUDA_VERSION < 7000
#		error "LMM requires CUDA 7.0 or higher"
#	endif

// SYCL
#elif defined(__SYCL_DEVICE_ONLY__)
#	define LMM_COMPILER LMM_COMPILER_SYCL

// Clang
#elif defined(__clang__)
#	if defined(__apple_build_version__)
#		if (__clang_major__ < 6)
#			error "LMM requires Clang 3.4 / Apple Clang 6.0 or higher"
#		elif __clang_major__ == 6 && __clang_minor__ == 0
#			define LMM_COMPILER LMM_COMPILER_CLANG35
#		elif __clang_major__ == 6 && __clang_minor__ >= 1
#			define LMM_COMPILER LMM_COMPILER_CLANG36
#		elif __clang_major__ >= 7
#			define LMM_COMPILER LMM_COMPILER_CLANG37
#		endif
#	else
#		if ((__clang_major__ == 3) && (__clang_minor__ < 4)) || (__clang_major__ < 3)
#			error "LMM requires Clang 3.4 or higher"
#		elif __clang_major__ == 3 && __clang_minor__ == 4
#			define LMM_COMPILER LMM_COMPILER_CLANG34
#		elif __clang_major__ == 3 && __clang_minor__ == 5
#			define LMM_COMPILER LMM_COMPILER_CLANG35
#		elif __clang_major__ == 3 && __clang_minor__ == 6
#			define LMM_COMPILER LMM_COMPILER_CLANG36
#		elif __clang_major__ == 3 && __clang_minor__ == 7
#			define LMM_COMPILER LMM_COMPILER_CLANG37
#		elif __clang_major__ == 3 && __clang_minor__ == 8
#			define LMM_COMPILER LMM_COMPILER_CLANG38
#		elif __clang_major__ == 3 && __clang_minor__ >= 9
#			define LMM_COMPILER LMM_COMPILER_CLANG39
#		elif __clang_major__ == 4 && __clang_minor__ == 0
#			define LMM_COMPILER LMM_COMPILER_CLANG40
#		elif __clang_major__ == 4 && __clang_minor__ == 1
#			define LMM_COMPILER LMM_COMPILER_CLANG41
#		elif __clang_major__ == 4 && __clang_minor__ >= 2
#			define LMM_COMPILER LMM_COMPILER_CLANG42
#		elif __clang_major__ >= 4
#			define LMM_COMPILER LMM_COMPILER_CLANG42
#		endif
#	endif

// Visual C++
#elif defined(_MSC_VER)
#	if _MSC_VER >= 1920
#		define LMM_COMPILER LMM_COMPILER_VC16
#	elif _MSC_VER >= 1916
#		define LMM_COMPILER LMM_COMPILER_VC15_9
#	elif _MSC_VER >= 1915
#		define LMM_COMPILER LMM_COMPILER_VC15_8
#	elif _MSC_VER >= 1914
#		define LMM_COMPILER LMM_COMPILER_VC15_7
#	elif _MSC_VER >= 1913
#		define LMM_COMPILER LMM_COMPILER_VC15_6
#	elif _MSC_VER >= 1912
#		define LMM_COMPILER LMM_COMPILER_VC15_5
#	elif _MSC_VER >= 1911
#		define LMM_COMPILER LMM_COMPILER_VC15_3
#	elif _MSC_VER >= 1910
#		define LMM_COMPILER LMM_COMPILER_VC15
#	elif _MSC_VER >= 1900
#		define LMM_COMPILER LMM_COMPILER_VC14
#	elif _MSC_VER >= 1800
#		define LMM_COMPILER LMM_COMPILER_VC12
#	elif _MSC_VER < 1800
#		error "LMM requires Visual C++ 12 - 2013 or higher"
#	endif//_MSC_VER

// G++
#elif defined(__GNUC__) || defined(__MINGW32__)
#	if __GNUC__ >= 8
#		define LMM_COMPILER LMM_COMPILER_GCC8
#	elif __GNUC__ >= 7
#		define LMM_COMPILER LMM_COMPILER_GCC7
#	elif __GNUC__ >= 6
#		define LMM_COMPILER LMM_COMPILER_GCC6
#	elif __GNUC__ >= 5
#		define LMM_COMPILER LMM_COMPILER_GCC5
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 9
#		define LMM_COMPILER LMM_COMPILER_GCC49
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 8
#		define LMM_COMPILER LMM_COMPILER_GCC48
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 7
#		define LMM_COMPILER LMM_COMPILER_GCC47
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 6
#		define LMM_COMPILER LMM_COMPILER_GCC46
#	elif ((__GNUC__ == 4) && (__GNUC_MINOR__ < 6)) || (__GNUC__ < 4)
#		error "LMM requires GCC 4.6 or higher"
#	endif

// Intellisense
#elif defined(__INTELLISENSE__)
#	define LMM_COMPILER LMM_COMPILER_INTELLISENSE

#else
#	define LMM_COMPILOR_ERROR_UNKNOWNCOMPILER
#	define LMM_COMPILER LMM_COMPILER_UNKNOWN
#endif



#ifndef LMM_COMPILER
#define LMM_COMPILER_ERROR_FLAG
#	error "LMM_COMPILER undefined, your compiler may not be supported by LMM. Add #define LMM_COMPILER 0 to ignore this message."
#endif