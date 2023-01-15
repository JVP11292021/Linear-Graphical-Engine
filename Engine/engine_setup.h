/*
 ________________________________________________________________________________________
| This source code is from the Github repo: Linear Graphical Engine (LGE)                |
|  Created by: JVP11292021 (J. van Polanen)                                              |
|  Started on: 06-01-2023                                                                |
|                                                                                        |
| Copyright (c) Jessy van Polanen                                                        |
|                                                                                        |
| NOTICE:                                                                                |
|   This notice must remain at the top of each file.                                     |
|________________________________________________________________________________________|
*/

#ifndef __LGE_ENGINE_SETUP__
#define __LGE_ENGINE_SETUP__

#	define __LGE_MAJOR__		0.1
#	define __LGE_MINOR__		0.0
#	define __LGE_PATCH__		0.0
#	define __LGE_REVISION__		0.0
#	define __LGE_VERSION__		0.1
#	define __LGE_MESSAGE__		"LGE: V0.1"

// =====================================================================
// Built in compiler support
// =====================================================================

#	define LGE_COMPILER_UNKNOWN			0x00000000

// Intel
#	define LGE_COMPILER_INTEL			0x00100000
#	define LGE_COMPILER_INTEL14			0x00100040
#	define LGE_COMPILER_INTEL15			0x00100050
#	define LGE_COMPILER_INTEL16			0x00100060
#	define LGE_COMPILER_INTEL17			0x00100070

// Visual C++ defines
#	define LGE_COMPILER_VC				0x01000000
#	define LGE_COMPILER_VC12			0x01000001
#	define LGE_COMPILER_VC14			0x01000002
#	define LGE_COMPILER_VC15			0x01000003
#	define LGE_COMPILER_VC15_3			0x01000004
#	define LGE_COMPILER_VC15_5			0x01000005
#	define LGE_COMPILER_VC15_6			0x01000006
#	define LGE_COMPILER_VC15_7			0x01000007
#	define LGE_COMPILER_VC15_8			0x01000008
#	define LGE_COMPILER_VC15_9			0x01000009
#	define LGE_COMPILER_VC16			0x0100000A

// GCC defines
#	define LGE_COMPILER_GCC				0x02000000
#	define LGE_COMPILER_GCC46			0x020000D0
#	define LGE_COMPILER_GCC47			0x020000E0
#	define LGE_COMPILER_GCC48			0x020000F0
#	define LGE_COMPILER_GCC49			0x02000100
#	define LGE_COMPILER_GCC5			0x02000200
#	define LGE_COMPILER_GCC6			0x02000300
#	define LGE_COMPILER_GCC7			0x02000400
#	define LGE_COMPILER_GCC8			0x02000500

// CUDA
#	define LGE_COMPILER_CUDA			0x10000000
#	define LGE_COMPILER_CUDA75			0x10000001
#	define LGE_COMPILER_CUDA80			0x10000002
#	define LGE_COMPILER_CUDA90			0x10000004

// SYCL
#	define LGE_COMPILER_SYCL			0x00300000

// Clang
#	define LGE_COMPILER_CLANG			0x20000000
#	define LGE_COMPILER_CLANG34			0x20000050
#	define LGE_COMPILER_CLANG35			0x20000060
#	define LGE_COMPILER_CLANG36			0x20000070
#	define LGE_COMPILER_CLANG37			0x20000080
#	define LGE_COMPILER_CLANG38			0x20000090
#	define LGE_COMPILER_CLANG39			0x200000A0
#	define LGE_COMPILER_CLANG40			0x200000B0
#	define LGE_COMPILER_CLANG41			0x200000C0
#	define LGE_COMPILER_CLANG42			0x200000D0

// Intellisense
#	define LGE_COMPILER_INTELLISENSE	0x200000E0

// Build model
#	define LGE_MODEL_32					0x00000010
#	define LGE_MODEL_64					0x00000020

// Force generic C++ compiler
#	ifdef LGE_FORCE_COMPILER_UNKNOWN
#		define LGE_COMPILER LGE_COMPILER_UNKNOWN

#	elif defined(__INTEL_COMPILER)
#		if __INTEL_COMPILER >= 1700
#			define LGE_COMPILER LGE_COMPILER_INTEL17
#		elif __INTEL_COMPILER >= 1600
#			define LGE_COMPILER LGE_COMPILER_INTEL16
#		elif __INTEL_COMPILER >= 1500
#			define LGE_COMPILER LGE_COMPILER_INTEL15
#		elif __INTEL_COMPILER >= 1400
#			define LGE_COMPILER LGE_COMPILER_INTEL14
#		elif __INTEL_COMPILER < 1400
#			error "LGE requires ICC 2013 SP1 or newer"
#		endif

// CUDA
#	elif defined(__CUDACC__)
#		if !defined(CUDA_VERSION) && !defined(LGE_FORCE_CUDA)
#			include <cuda.h>  // make sure version is defined since nvcc does not define it itself!
#		endif
#		if CUDA_VERSION >= 8000
#			define LGE_COMPILER LGE_COMPILER_CUDA80
#		elif CUDA_VERSION >= 7500
#			define LGE_COMPILER LGE_COMPILER_CUDA75
#		elif CUDA_VERSION >= 7000
#			define LGE_COMPILER LGE_COMPILER_CUDA70
#		elif CUDA_VERSION < 7000
#			error "LGE requires CUDA 7.0 or higher"
#		endif

// SYCL
#	elif defined(__SYCL_DEVICE_ONLY__)
#		define LGE_COMPILER LGE_COMPILER_SYCL

// Clang
#	elif defined(__clang__)
#		if defined(__apple_build_version__)
#			if (__clang_major__ < 6)
#				error "LGE requires Clang 3.4 / Apple Clang 6.0 or higher"
#			elif __clang_major__ == 6 && __clang_minor__ == 0
#				define LGE_COMPILER LGE_COMPILER_CLANG35
#			elif __clang_major__ == 6 && __clang_minor__ >= 1
#				define LGE_COMPILER LGE_COMPILER_CLANG36
#			elif __clang_major__ >= 7
#				define LGE_COMPILER LGE_COMPILER_CLANG37
#			endif
#		else
#			if ((__clang_major__ == 3) && (__clang_minor__ < 4)) || (__clang_major__ < 3)
#				error "LGE requires Clang 3.4 or higher"
#			elif __clang_major__ == 3 && __clang_minor__ == 4
#				define LGE_COMPILER LGE_COMPILER_CLANG34
#			elif __clang_major__ == 3 && __clang_minor__ == 5
#				define LGE_COMPILER LGE_COMPILER_CLANG35
#			elif __clang_major__ == 3 && __clang_minor__ == 6
#				define LGE_COMPILER LGE_COMPILER_CLANG36
#			elif __clang_major__ == 3 && __clang_minor__ == 7
#				define LGE_COMPILER LGE_COMPILER_CLANG37
#			elif __clang_major__ == 3 && __clang_minor__ == 8
#				define LGE_COMPILER LGE_COMPILER_CLANG38
#			elif __clang_major__ == 3 && __clang_minor__ >= 9
#				define LGE_COMPILER LGE_COMPILER_CLANG39
#			elif __clang_major__ == 4 && __clang_minor__ == 0
#				define LGE_COMPILER LGE_COMPILER_CLANG40
#			elif __clang_major__ == 4 && __clang_minor__ == 1
#				define LGE_COMPILER LGE_COMPILER_CLANG41
#			elif __clang_major__ == 4 && __clang_minor__ >= 2
#				define LGE_COMPILER LGE_COMPILER_CLANG42
#			elif __clang_major__ >= 4
#				define LGE_COMPILER LGE_COMPILER_CLANG42
#			endif
#		endif

// Visual C++
#	elif defined(_MSC_VER)
#		if _MSC_VER >= 1920
#			define LGE_COMPILER LGE_COMPILER_VC16
#		elif _MSC_VER >= 1916
#			define LGE_COMPILER LGE_COMPILER_VC15_9
#		elif _MSC_VER >= 1915
#			define LGE_COMPILER LGE_COMPILER_VC15_8
#		elif _MSC_VER >= 1914
#			define LGE_COMPILER LGE_COMPILER_VC15_7
#		elif _MSC_VER >= 1913
#			define LGE_COMPILER LGE_COMPILER_VC15_6
#		elif _MSC_VER >= 1912
#			define LGE_COMPILER LGE_COMPILER_VC15_5
#		elif _MSC_VER >= 1911
#			define LGE_COMPILER LGE_COMPILER_VC15_3
#		elif _MSC_VER >= 1910
#			define LGE_COMPILER LGE_COMPILER_VC15
#		elif _MSC_VER >= 1900
#			define LGE_COMPILER LGE_COMPILER_VC14
#		elif _MSC_VER >= 1800
#			define LGE_COMPILER LGE_COMPILER_VC12
#		elif _MSC_VER < 1800
#			error "LGE requires Visual C++ 12 - 2013 or higher"
#		endif//_MSC_VER

// G++
#	elif defined(__GNUC__) || defined(__MINGW32__)
#		if __GNUC__ >= 8
#			define LGE_COMPILER LGE_COMPILER_GCC8
#		elif __GNUC__ >= 7
#			define LGE_COMPILER LGE_COMPILER_GCC7
#		elif __GNUC__ >= 6
#			define LGE_COMPILER LGE_COMPILER_GCC6
#		elif __GNUC__ >= 5
#			define LGE_COMPILER LGE_COMPILER_GCC5
#		elif __GNUC__ == 4 && __GNUC_MINOR__ >= 9
#			define LGE_COMPILER LGE_COMPILER_GCC49
#		elif __GNUC__ == 4 && __GNUC_MINOR__ >= 8
#			define LGE_COMPILER LGE_COMPILER_GCC48
#		elif __GNUC__ == 4 && __GNUC_MINOR__ >= 7
#			define LGE_COMPILER LGE_COMPILER_GCC47
#		elif __GNUC__ == 4 && __GNUC_MINOR__ >= 6
#			define LGE_COMPILER LGE_COMPILER_GCC46
#		elif ((__GNUC__ == 4) && (__GNUC_MINOR__ < 6)) || (__GNUC__ < 4)
#			error "LGE requires GCC 4.6 or higher"
#		endif

// Intellisense
#	elif defined(__INTELLISENSE__)
#		define LGE_COMPILER LGE_COMPILER_INTELLISENSE

#	else
#		define LGE_COMPILOR_ERROR_UNKNOWNCOMPILER
#		define LGE_COMPILER LGE_COMPILER_UNKNOWN
#	endif

#	ifndef LGE_COMPILER
#		define LGE_COMPILER_ERROR_FLAG
#		error "LGE_COMPILER undefined, your compiler may not be supported by LGE. Add #define LGE_COMPILER 0 to ignore this message."
#	endif

#	if  LGE_COMPILER & LGE_COMPILER_CUDA 
#		define LGE_CUDA_FUNC_DEF  				__device__ __host__
#		define LGE_CUDA_FUNC_DECL 				__device__ __host__
#	else
#		define LGE_CUDA_FUNC_DEF
#		define LGE_CUDA_FUNC_DECL
#	endif

// =====================================================================
// Built in platform support
// =====================================================================

#	define LGE_PLATFORM_UNKNOWN			0x00000000
#	define LGE_PLATFORM_WINDOWS			0x00010000
#	define LGE_PLATFORM_LINUX			0x00020000
#	define LGE_PLATFORM_APPLE			0x00040000
#	define LGE_PLATFORM_IOS				0x00080000
#	define LGE_PLATFORM_ANDROID			0x00100000
#	define LGE_PLATFORM_CHROME_NACL		0x00200000
#	define LGE_PLATFORM_UNIX			0x00400000
#	define LGE_PLATFORM_QNXNTO			0x00800000
#	define LGE_PLATFORM_WINCE			0x01000000
#	define LGE_PLATFORM_CYGWIN			0x02000000

#	ifdef LGE_FORCE_PLATFORM_UNKNOWN
#		define LGE_PLATFORM LGE_PLATFORM_UNKNOWN
#	elif defined(__CYGWIN__)
#		define LGE_PLATFORM LGE_PLATFORM_CYGWIN
#	elif defined(__QNXNTO__)
#		define LGE_PLATFORM LGE_PLATFORM_QNXNTO
#	elif defined(__APPLE__)
#		define LGE_PLATFORM LGE_PLATFORM_APPLE
#	elif defined(WINCE)
#		define LGE_PLATFORM LGE_PLATFORM_WINCE
#	elif defined(_WIN64) || defined(_WIN32)
#		define LGE_PLATFORM LGE_PLATFORM_WINDOWS
#	elif defined(__native_client__)
#		define LGE_PLATFORM LGE_PLATFORM_CHROME_NACL
#	elif defined(__ANDROID__)
#		define LGE_PLATFORM LGE_PLATFORM_ANDROID
#	elif defined(__linux)
#		define LGE_PLATFORM LGE_PLATFORM_LINUX
#	elif defined(__unix) || defined(unix) || defined(__unix__)
#		define LGE_PLATFORM LGE_PLATFORM_UNIX
#	else
#		define LGE_PLATFORM LGE_PLATFORM_UNKNOWN
#	endif

#	ifndef LGE_PLATFORM
#		define LGE_PLATFORM_ERROR_FLAG
#		error "LGE_PLATFORM undefined, your platform may not be supported by LGE. Add #define LGE_PLATFORM 0 to ignore this message."
#	endif

// =====================================================================
// Configurations
// =====================================================================

#include "lge_config.h"

#	define LGE_LISTENERS_GLFW
//#	define LGE_LISTENERS_CMD

#	if LGE_PLATFORM == LGE_PLATFORM_WINDOWS
#		include <Windows.h>
#	elif LGE_PLATFORM == LGE_PLATFORM_LINUX
#		include <X11/Xlib.h>
#	endif

#	if LGE_PLATFORM == LGE_PLATFORM_WINDOWS
#		if defined(LGE_DYNAMIC_LINK)
#			if defined(LGE_BUILD_DLL)
#				define LGE_API __declspec(dllexport)
#			else
#				define LGE_API __declspec(dllimport)
#			endif
#		else
#			define LGE_API
#		endif
#	else
#		error LGE only supports Windows as of this moment
#	endif

// Check in which build distribution the app is running

#	define LGE_DEBUG_BUILD				0x00000001
#	define LGE_RELEASE_BUILD			0x00000002
#	define LGE_DIST_BUILD				0x00000003

#	if defined(LGE_DEBUG)
#		define LGE_BUILD LGE_DEBUG_BUILD
#	elif defined(LGE_RELEASE)
#		define LGE_BUILD LGE_RELEASE_BUILD
#	elif defined(LGE_DIST)
#		define LGE_BUILD LGE_DIST_BUILD
#	else
#		error Unknown build type configured!
#	endif

// Namespace declarations
#	define _LGE_BEGIN_NP_LGE 		namespace lge {
#	define _LGE_END_NP_LGE 			}

#	define _LGE_BEGIN_NP_LGE_CORE 	namespace lge { namespace core {
#	define _LGE_END_NP_LGE_CORE 	}}

#	define _LGE_BEGIN_NP_LGE_GFX 	namespace lge { namespace gfx {
#	define _LGE_END_NP_LGE_GFX 		}}

#	define _LGE_BEGIN_NP_LGE_HID 	namespace lge { namespace hid {
#	define _LGE_END_NP_LGE_HID 		}}

// C++ needs to know that types and declarations are C, not C++.
#	ifdef	__cplusplus
#		define _LGE_BEGIN_C_DECLS	extern "C" {
#		define _LGE_END_C_DECLS		}
#	else
#		define _LGE_BEGIN_DECLS
#		define _LGE_END_DECLS
#	endif

// =====================================================================
// Macro-like functions & variables
// =====================================================================

// Internal

#	define __lge_len(array) ((sizeof(array)) / (sizeof(array[0])))
#	define __lgePREDEF_VERSION(v, r, p) (((v) << 24) + ((r) << 16) + (p))

// External 

#	if LGE_BUILD == LGE_DEBUG_BUILD
#		include "lgeLogging.hpp"

// Core logging macro's
#		define LGE_CORE_ERROR(...)        	lge::Log::getCoreLogger()->error(__VA_ARGS__)
#		define LGE_CORE_INFO(...)         	lge::Log::getCoreLogger()->info(__VA_ARGS__)
#		define LGE_CORE_WARN(...)         	lge::Log::getCoreLogger()->warn(__VA_ARGS__)
#		define LGE_CORE_TRACE(...)        	lge::Log::getCoreLogger()->trace(__VA_ARGS__)
#		define LGE_CORE_CRITICAL(...)     	lge::Log::getCoreLogger()->critical(__VA_ARGS__)
	
// Client logging macro's	    	
#		define LGE_CLIENT_ERROR(...)      	lge::Log::getClientLogger()->error(__VA_ARGS__)
#		define LGE_CLIENT_INFO(...)       	lge::Log::getClientLogger()->info(__VA_ARGS__)
#		define LGE_CLIENT_WARN(...)       	lge::Log::getClientLogger()->warn(__VA_ARGS__)
#		define LGE_CLIENT_TRACE(...)      	lge::Log::getClientLogger()->trace(__VA_ARGS__)
#		define LGE_CLIENT_CRITICAL(...)   	lge::Log::getClientLogger()->critical(__VA_ARGS__)
#	elif defined(LGE_DIST_BUILD)
// Core logging macro's
#		define LGE_CORE_ERROR(...)  
#		define LGE_CORE_INFO(...)   
#		define LGE_CORE_WARN(...)   
#		define LGE_CORE_TRACE(...)  
#		define LGE_CORE_CRITICAL(...) 

// Client logging macro's	 
#		define LGE_CLIENT_ERROR(...)
#		define LGE_CLIENT_INFO(...) 
#		define LGE_CLIENT_WARN(...) 
#		define LGE_CLIENT_TRACE(...)
#		define LGE_CLIENT_CRITICAL(...) 
#	endif

#	ifdef LGE_BUILD == LGE_DEBUG_BUILD
#		define lgeASSERT(x) 				if (!(x)) __debugbreak();
#		define lgeCLIENT_ASSERT(x, ...) 	if (!(x)) { LGE_CLIENT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } 
#		define lgeCORE_ASSERT(x, ...) 		if (!(x)) { LGE_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak();   } 
#	else
#		define lgeASSERT(x)
#		define lgeCLIENT_ASSERT(x, ...)
#		define lgeCORE_ASSERT(x, ...) 
#	endif

#	define lgeBIT(x) 						(1 << (x))
#	define lgeBindEvent(x) 					(std::bind(&x, this, std::placeholders::_1))
#	define lgeARRAY_LEN(array)				(__lge_len(array))

// Internal LGE macro Variables.

#	define lgeB								1
#	define lgeKB							1024
#	define lgeMB							(lgeKB * lgeKB)
#	define lgeGB							(lgeMB * lgeMB)
#	define lgeTB							(lgeGB * lgeGB)
#	define lgePB							(lgeTB * lgeTB)

#	define lgeBIT_AND 						&
#	define lgeBIT_OR  						|
#	define lgeBIT_XOR						^

// Screen resolution
#	if LGE_PLATFORM == LGE_PLATFORM_WINDOWS
#		define lgeSRXW (GetSystemMetrics(SM_CXSCREEN))
#		define lgeSRYH (GetSystemMetrics(SM_CYSCREEN))
#	endif

// Handy anti-boilerplate class macro's

/* 
Defines default constructor 
 Auomates the boilerplate code for classes
*/
#	define LGE_CLS_CTOR_DEFAULT(name) name() = default;

/* 
Defines default destructor 
 Auomates the boilerplate code for classes
*/
#	define LGE_CLS_DTOR_DEFAULT(name) ~name() = default;

/* 
Defines default de-/constructor 
 Auomates the boilerplate code for classes
*/
#	define LGE_CLS_DCTOR_DEFAULT(name) LGE_CLS_CTOR_DEFAULT(name) LGE_CLS_DTOR_DEFAULT(name) 

/* 
Defines constructor 
 Auomates the boilerplate code for classes
*/
#	define LGE_CLS_CTOR(name) name();

/* 
Defines destructor 
 Auomates the boilerplate code for classes
*/
#	define LGE_CLS_DTOR(name) ~name();

/* 
Defines de- & constructor 
 Auomates the boilerplate code for classes
*/
#	define LGE_CLS_DCTOR(name) LGE_CLS_CTOR(name) LGE_CLS_DTOR(name)

/* 
Makes a class non copiable. 
 Auomates the boilerplate code for  
 declaring a class as non-copiable 
 */
#	define LGE_CLS_NON_COPIABLE(name) name(const name&) = delete;\
									  LGE_CUDA_FUNC_DECL name& operator= (const name&) = delete;

/*
Makes a class movable.
Automates the boilerplate code for 
declaring default move constructor and 
and move operator. 
*/
#	define LGE_CLS_CTOR_MOVE_DEFAULT(name) name(name&&) = default;\
										   LGE_CUDA_FUNC_DECL name& operator = (name&&) = default;                 

/*
Makes a class only movable, but non-copiable.
*/
#	define LGE_CLS_MOVABLE_ONLY(name) LGE_CLS_NON_COPIABLE(name) LGE_CLS_CTOR_DEFAULT(name) 

/*
Declare default copy constructor explicitly
*/
#	define LGE_CLS_CTOR_COPY_DEFAULT(name) name(const name&) = default;\
										   LGE_CUDA_FUNC_DECL name& operator = (const name&) = default;

/*
Defines io operators for a class
 Auomates the boilerplate code for classes
*/
#	define LGE_CLS_IOSTREAM_OV(name) LGE_CUDA_FUNC_DECL friend std::ostream& operator << (std::ostream&, const name&);\
								  	 LGE_CUDA_FUNC_DECL friend std::istream& operator >> (std::istream&, const name&);

// =====================================================================
// LGE custom data types
// =====================================================================

#	ifdef __cplusplus
_LGE_BEGIN_NP_LGE
#	else
_LGE_BEGIN_C_DECLS
#	endif

/// <summary>
/// Custom LGE data types
/// </summary>

typedef signed char				int8;
typedef short					int16;
typedef int						int32;
typedef long long				int64;
typedef unsigned char			uint8;
typedef unsigned short			uint16;
typedef unsigned int			uint32;
typedef unsigned long long		uint64;

typedef short					f16;
typedef float					f32;
typedef double					f64;
typedef long double				f128;

typedef signed char*			int8_ptr;
typedef short*					int16_ptr;
typedef int*					int32_ptr;
typedef long long*				int64_ptr;
typedef unsigned char*			uint8_ptr;
typedef unsigned short*			uint16_ptr;
typedef unsigned int*			uint32_ptr;
typedef unsigned long long*		uint64_ptr;

typedef short*					f16_ptr;
typedef float*					f32_ptr;
typedef double*					f64_ptr;
typedef long double*			f128_ptr;

typedef const char*				istr;
typedef char*					str;

#	ifdef __cplusplus
_LGE_END_NP_LGE
#	else
_LGE_END_C_DECLS
#	endif

// =====================================================================
// C/C++ Language standards
// =====================================================================

// ISO/IEC C standards

#	if defined(__STDC__)
#		define LGE_PREDEF_C
#		define LGE_PREDEF_STANDARDS_C_1989
#		if defined(__STDC_VERSION__)
#			if __STDC_VERSION__ >= 199409L
#				define LGE_PREDEF_STANDARDS_C_1994
#				define LGE_C_VERSION __STDC_VERSION__
#			endif
#			if __STDC_VERSION__ >= 199901L
#				define LGE_PREDEF_STANDARDS_C_1999
#				define LGE_C_VERSION __STDC_VERSION__
#			endif
#			if __STDC_VERSION__ >= 201112L
#				define LGE_PREDEF_STANDARDS_C_2011
#				define LGE_C_VERSION __STDC_VERSION__
#			endif
#			if __STDC_VERSION__ >= 201710L
#				define LGE_PREDEF_STANDARDS_C_2018
#				define LGE_C_VERSION __STDC_VERSION__
#			endif
#		else
#			error "LGE predefined ISO/IEC C standards unknown."
#		endif
#	endif

// ISO/IEC C++ standards

#	if defined(__cplusplus)
#		define LGE_PREDEF_CPP
#		if __cplusplus == 1
#			define LGE_PREDEF_STANDARD_CPP_PRE_1989
#			define LGE_CPP_VERSION __cplusplus
#		endif
#		if __cplusplus >= 199711L
#			define LGE_PREDEF_STANDARD_CPP_1998
#			define LGE_CPP_VERSION __cplusplus
#		endif
#		if __cplusplus >= 201103L
#			define LGE_PREDEF_STANDARD_CPP_2011
#			define LGE_CPP_VERSION __cplusplus
#		endif
#		if __cplusplus >= 201402L
#			define LGE_PREDEF_STANDARD_CPP_2014
#			define LGE_CPP_VERSION __cplusplus
#		endif
#		if __cplusplus >= 201703L
#			define LGE_PREDEF_STANDARD_CPP_2017
#			define LGE_CPP_VERSION __cplusplus
#		endif
#		if __cplusplus_cli  >= 200406L
#			define LGE_PREDEF_STANDARD_CPP_CLI
#			define LGE_CPP_VERSION __cplusplus_cli
#		endif
#		if defined(__embedded_cplusplus)
#			define LGE_PREDEF_STANDARD_ECPP
#			define LGE_CPP_VERSION __embedded_cplusplus
#		endif
#	else
#		error "LGE predefined ISO/IEC C++ standards unknown."
#	endif

// UNIX standards

#	if LGE_PLATFORM == 0x00400000
#		include <unistd.h>
#		 if defined(_XOPEN_VERSION)
#			if _XOPEN_VERSION >= 3
#				define LGE_PREDEF_STANDARD_XOPEN_1989
#			endif
#			if _XOPEN_VERSION >= 4
#				define LGE_PREDEF_STANDARD_XOPEN_1992
#			endif
#			if _XOPEN_VERSION >= 4 && defined(_XOPEN_UNIX)
#				define LGE_PREDEF_STANDARD_XOPEN_1995
#			endif
#			if _XOPEN_VERSION >= 500
#				define LGE_PREDEF_STANDARD_XOPEN_1998
#			endif
#			if _XOPEN_VERSION >= 600
#				define LGE_PREDEF_STANDARD_XOPEN_2003
#			endif
#			if _XOPEN_VERSION >= 700
#				define LGE_PREDEF_STANDARD_XOPEN_2008
#			endif
#			if _POSIX_VERSION >= 198808L
#				define LGE_PREDEF_STANDARDS_POSIX1_1988
#			endif
#			if _POSIX_VERSION >= 199009L
#				define LGE_PREDEF_STANDARDS_POSIX1_1990
#			endif
#			if _POSIX2_C_VERSION  >= 199209L
#				define LGE_PREDEF_STANDARDS_POSIX2_1992
#			endif
#			if _POSIX_VERSION >= 199309L
#				define LGE_PREDEF_STANDARDS_POSIX1_1993
#			endif
#			if _POSIX_VERSION >= 199506L
#				define LGE_PREDEF_STANDARDS_POSIX1_1995
#			endif
#			if _POSIX_VERSION >= 200112L
#				define LGE_PREDEF_STANDARDS_POSIX1_2001
#			endif
#			if _POSIX_VERSION >= 200809L
#				define LGE_PREDEF_STANDARDS_POSIX1_2008
#			endif
#		else
#			error "LGE predefined POSIX/XOPEN UNIX standards unknown."
#		endif
#	endif


// =====================================================================
// System architectures
// =====================================================================

// ALPHA

#	if defined(_M_ALPHA) || defined(__alpha) || defined(__alpha__)
#		if defined(__alpha_ev4__)
#			define LGE_SYS_ARCH_ALPHA_EV4
#		endif
#		if defined(__alpha_ev5__)
#			define LGE_SYS_ARCH_ALPHA_EV5
#		endif
#		if defined(__alpha_ev6__)
#			define LGE_SYS_ARCH_ALPHA_EV6
#		endif
#		if defined(__alpha_ev7__)
#			define LGE_SYS_ARCH_ALPHA_EV7
#		endif
#	else
#		define LGE_SYS_ARCH_ALPHA_UNKNOWN
#	endif

// AMD x64

#	if defined(_M_AMD64) || defined(_M_X64) || defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64)
#		define LGE_SYS_ARCH_AMD_x64
#	else
#		define LGE_SYS_ARCH_AMD_x64_UNKNOWN
#	endif

// ARM

#	if defined(__arm__) || defined(__thumb__) || defined(_ARM) || defined(_M_ARM) || defined(_M_ARMT) || defined(__arm)
#		if defined(__ARM_ARCH_2__)
#			define LGE_SYS_ARCH_ARM2
#		endif
#		if defined(__ARM_ARCH_3__) || defined(__ARM_ARCH_3M__)
#			define LGE_SYS_ARCH_ARM3
#		endif
#		if defined(__ARM_ARCH_4T__) || defined(__TARGET_ARM_4T)
#			define LGE_SYS_ARCH_ARM4T
#		endif
#		if defined(__ARM_ARCH_5__) || defined(__ARM_ARCH_5E__)
#			define LGE_SYS_ARCH_ARM5
#		endif
#		if defined(__ARM_ARCH_5T__) || defined(__ARM_ARCH_5TE__) || defined(__ARM_ARCH_5TEJ__)
#			define LGE_SYS_ARCH_ARM5T
#		endif
#		if defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__) 
#			define LGE_SYS_ARCH_ARM6
#		endif
#		if defined(__ARM_ARCH_6T2__)
#			define LGE_SYS_ARCH_ARM6T2
#		endif
#		if defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__) 
#			define LGE_SYS_ARCH_ARM7
#		endif
#	else
#		define LGE_SYS_ARCH_ARM_UNKNOWN
#	endif

// ARM x64

#	if defined(__aarch64__)
#		define LGE_SYS_ARCH_ARM_x64
#	else
#		define LGE_SYS_ARCH_AMD_x64_UNKNOWN
#	endif


// Intel x86

// =====================================================================
// Compiler version normalization
// =====================================================================

// GNUC

#	if defined(__GNUC__)
#		if defined(__GNUC_PATCHLEVEL__)
#			define LGE_PREDEF_COMPILER_GNUC __lgePREDEF_VERSION(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
#		else
#			define LGE_PREDEF_COMPILER_GNUC __lgePREDEF_VERSION(__GNUC__, __GNUC_MINOR__, 0)
#		endif
#	endif

// MSVC VC++

#	if defined(_MSC_FULL_VER)
#		define LGE_PREDEF_COMPILER_MSC __lgePREDEF_VERSION(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, _MSC_FULL_VER % 10000)
#	else
#		if defined(_MSC_VER)
#			define LGE_PREDEF_COMPILER_MSC CDETECT_MKVER(_MSC_VER / 100, _MSC_VER % 100, 0)
#		endif
#	endif

// Clang

#	if defined(__clang__)
#		if defined(__clang_patchlevel__)
#			define LGE_PREDEF_COMPILER_CLANG __lgePREDEF_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#		else
#			define __clang_patchlevel__ __lgePREDEF_VERSION(__clang_major__, __clang_minor__, 0)
#		endif
#	endif

/* Example: GNUC 
-----------------*/

//	#if defined(LGE_PREDEF_COMPILER_GNUC) && LGE_PREDEF_COMPILER_GNUC >= __lgePREDEF_VERSION(4, 6, 0)
//			Place compiler specific code here.
//	#endif

// =====================================================================
// language/compiler c++ specific version specific features
// =====================================================================

#	if defined(__INTEL_COMPILER) || defined(__GNUC__) || defined(__clang__) || defined(_MSC_VER) || defined(__CUDACC__) || defined(__INTELLISENSE__) || defined(LGE_FORCE_CPP_2011)
		// c++ 11
		// ------
#		if LGE_CPP_VERSION >= 201103L || defined(LGE_FORCE_STANDARD_CPP_2011)

			// N1720
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_STATIC_ASSERT 1
#			else
#				define LGE_HAS_STATIC_ASSERT 0
#			endif
			// N1757
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_RIGHT_ANGLE_BRACKETS 1
#			else
#				define LGE_HAS_RIGHT_ANGLE_BRACKETS 0
#			endif
			// N1791
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_EXTENDED_DECLARATIONS 1
#			else
#				define LGE_HAS_EXTENDED_DECLARATIONS 0
#			endif
			// N1811
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_LONG_LONG 1
#			else
#				define LGE_HAS_LONG_LONG 0
#			endif
			// N1836 | N2518 | N2984 | N3142
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_TYPE_TRAITS 1
#			else
#				define LGE_HAS_TYPE_TRAITS 0
#			endif
			// N1984
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_AUTO 1
#			else
#				define LGE_HAS_AUTO 0
#			endif
			// N1986
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_DELEGATING_CONSTRUCTORS 1
#			else
#				define LGE_HAS_DELEGATING_CONSTRUCTORS 0
#			endif
			// N1987
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_EXTERNAL_TEMPLATE 1
#			else
#				define LGE_HAS_EXTERNAL_TEMPLATE 0
#			endif
			// N2235
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_CONSTEXPR 1
#			else
#				define LGE_HAS_CONSTEXPR 0
#			endif
			// N2258
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_TEMPLATE_ALIASSES 1
#			else
#				define LGE_HAS_TEMPLATE_ALIASSES 0
#			endif
			// N2249
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_CHAR16t_CHAR32t 1
#			else
#				define LGE_HAS_CHAR16t_CHAR32t 0
#			endif
			// N2341
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_ALIGNAS 1
#				define LGE_HAS_ALIGNOF 1
#			else
#				define LGE_HAS_ALIGNAS 0
#				define LGE_HAS_ALIGNOF 0
#			endif
			// N2347
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_STRONGLY_TYPED_ENUM 1
#			else
#				define LGE_HAS_STRONGLY_TYPED_ENUM 0
#			endif
			// N2427
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_ATOMIC_OPERATIONS 1
#			else
#				define LGE_HAS_ATOMIC_OPERATIONS 0
#			endif
			// N2431
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_NULLPTR 1
#			else
#				define LGE_HAS_NULLPTR 0
#			endif
			// N2437
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_EXPLICIT_CONVERSION_OPERATORS 1
#			else
#				define LGE_HAS_EXPLICIT_CONVERSION_OPERATORS 0
#			endif
			// N2535
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_INLINE_NAMESPACES 1
#			else
#				define LGE_HAS_INLINE_NAMESPACES 0
#			endif
			// N2540
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_CONSTRUCTOR_INHERITANCE 1
#			else
#				define LGE_HAS_CONSTRUCTOR_INHERITANCE 0
#			endif
			// N2544
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_UNRESTRICTED_UNIONS 1
#			else
#				define LGE_HAS_UNRESTRICTED_UNIONS 0
#			endif
			// N2242 | N2555
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_VARIADIC_TEMPLATES 1
#			else
#				define LGE_HAS_VARIADIC_TEMPLATES 0
#			endif
			// N2672
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_INITIALIZER_LIST 1
#			else
#				define LGE_HAS_INITIALIZER_LIST 0
#			endif
			// N2550 | N658 | N2927
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_LAMBDA_EXPRESSION 1
#			else
#				define LGE_HAS_LAMBDA_EXPRESSION 0
#			endif
			// N2930 | N3271
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_RANGED_FOR_LOOP 1
#			else
#				define LGE_HAS_RANGED_FOR_LOOP 0
#			endif
			// N3050
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_NOEXCEPT 1
#			else
#				define LGE_HAS_NOEXCEPT 0
#			endif
			// N2928 | N3206 | N3272
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_OVERRIDE 1
#				define LGE_HAS_FINAL	1
#			else
#				define LGE_HAS_OVERRIDE 0
#				define LGE_HAS_FINAL	0
#			endif
			// N2343 | N3276
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_DECLTYPE 1
#			else
#				define LGE_HAS_DECLTYPE 0
#			endif
#		endif

		// c++ 14
		// ------
#		if LGE_CPP_VERSION >= 201402L || defined(LGE_FORCE_STANDARD_CPP_2014)
			// N3323
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_CONTEXTUAL_CONVERSIOS 1
#			else
#				define LGE_HAS_CONTEXTUAL_CONVERSIOS 0
#			endif
			// N3472
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_BINARY_LITERALS 1
#			else
#				define LGE_HAS_BINARY_LITERALS 0
#			endif
			// N3638
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_DECLTYPE_AUTO 1
#			else
#				define LGE_HAS_DECLTYPE_AUTO 0
#			endif
			// N3649
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_GENERIC_LAMBDA_EXPRESSIONS 1
#			else
#				define LGE_HAS_GENERIC_LAMBDA_EXPRESSIONS 0
#			endif
			// N3651
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_VARIABLE_TEMPLATES 1
#			else
#				define LGE_HAS_VARIABLE_TEMPLATES 0
#			endif
			// N3652
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_EXTENDED_CONSTEXPR 1
#			else
#				define LGE_HAS_EXTENDED_CONSTEXPR 0
#			endif
			// N3653
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_DEFAULT_MEMBER_INITIALIZERS 1
#			else
#				define LGE_HAS_DEFAULT_MEMBER_INITIALIZERS 0
#			endif
			// N3760
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_DEPRECATED_ATTR 1
#			else
#				define LGE_HAS_DEPRECATED_ATTR 0
#			endif
			// N3778
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_SIZED_DEALLOCATION 1
#			else
#				define LGE_HAS_SIZED_DEALLOCATION 0
#			endif
#		endif

		// c++ 17
		// ------
#		if LGE_CPP_VERSION >= 201703L || defined(LGE_FORCE_STANDARD_CPP_2017)
			// N3928
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_NOMSG_STATIC_ASSERT 1
#			else
#				define LGE_HAS_NOMSG_STATIC_ASSERT 0
#			endif
			// N4051
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_TYPENAME_TEMP_PARAMETER 1
#			else
#				define LGE_HAS_TYPENAME_TEMP_PARAMETER 0
#			endif
			// N4086
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_REMOVED_TRIGRAPHS 1
#			else
#				define LGE_HAS_REMOVED_TRIGRAPHS 0
#			endif
			// N4230
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_NESTED_NAMESPACE_DEFS 1
#			else
#				define LGE_HAS_NESTED_NAMESPACE_DEFS 0
#			endif
			// N4266
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_ATTR_NAMESPACES_ENUMERATORS 1
#			else
#				define LGE_HAS_ATTR_NAMESPACES_ENUMERATORS 0
#			endif
			// N4267
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_CHAR_LITERALS 1
#			else
#				define LGE_HAS_CHAR_LITERALS 0
#			endif
			// N4295 
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_FOLD_EXPRESSIONS 1
#			else
#				define LGE_HAS_FOLD_EXPRESSIONS 0
#			endif
			// P0036R0
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_UNARY_FOLD_EXPRESSIONS 1
#			else
#				define LGE_HAS_UNARY_FOLD_EXPRESSIONS 0
#			endif
			// P0001R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_REMOVED_REGISTER_USAGE 1
#			else
#				define LGE_HAS_REMOVED_REGISTER_USAGE 0
#			endif
			// P0002R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_REMOVED_DEPRECATED_PP 1
#			else
#				define LGE_HAS_REMOVED_DEPRECATED_PP 0
#			endif
			// P00017R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_AGGCLASSES_BASECLASSES 1
#			else
#				define LGE_HAS_AGGCLASSES_BASECLASSES 0
#			endif
			// P0061R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_PP__HAS_INCLUDE 1
#			else
#				define LGE_HAS_PP__HAS_INCLUDE 0
#			endif
			// P0136R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_NEW_CONSTRUCTOR_INHERITANCE 1
#			else
#				define LGE_HAS_NEW_CONSTRUCTOR_INHERITANCE 0
#			endif
			// P0018R3
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_LAMBDA_CAP_THIS 1
#			else
#				define LGE_HAS_LAMBDA_CAP_THIS 0
#			endif
			// P0170R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_CONSTEXPR_LAMBDA_EXPR 1
#			else
#				define LGE_HAS_CONSTEXPR_LAMBDA_EXPR 0
#			endif
			// P0188R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_FALLTHROUGH_ATTR 1
#			else
#				define LGE_HAS_FALLTHROUGH_ATTR 0
#			endif
			// P0189R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_NODISCARD_ATTR 1
#			else
#				define LGE_HAS_NODISCARD_ATTR 0
#			endif
			// P0212R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_MAYBE_UNUSED_ATTR 1
#			else
#				define LGE_HAS_MAYBE_UNUSED_ATTR 0
#			endif
			// P0245R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_HEX_LITERALS 1
#			else
#				define LGE_HAS_HEX_LITERALS 0
#			endif
			// POO35R4
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_DMALLOCA_ALIGNED_DATA 1
#			else
#				define LGE_HAS_DMALLOCA_ALIGNED_DATA 0
#			endif
			// P0091R3
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_CLASS_TEMPLATE_ARGUMENT_DEDUCTION 1
#			else
#				define LGE_HAS_CLASS_TEMPLATE_ARGUMENT_DEDUCTION 0
#			endif
			// P0127R2
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_NONTYPE_TEMPPARAMETERS_AUTO_TYPE 1
#			else
#				define LGE_HAS_NONTYPE_TEMPPARAMETERS_AUTO_TYPE 0
#			endif
			// P0135R1
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_GUARANTEED_COPY_ELISION 1
#			else
#				define LGE_HAS_GUARANTEED_COPY_ELISION 0
#			endif
			// PO283R2
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_IGNORE_UNKNOWN_ATTR 1
#			else
#				define LGE_HAS_IGNORE_UNKNOWN_ATTR 0
#			endif
			// P0292R2
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_CONSTEXPR_IF 1
#			else
#				define LGE_HAS_CONSTEXPR_IF 0
#			endif
			// P0386R2
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_INLINE_VARIABLES 1
#			else
#				define LGE_HAS_INLINE_VARIABLES 0
#			endif
			// P0003R5
#			if LGE_COMPILER & LGE_COMPILER_VC
#				define LGE_HAS_REMOVED_DYNAMIC_EXCEPTION_SPECIFICATIONS 1
#			else
#				define LGE_HAS_REMOVED_DYNAMIC_EXCEPTION_SPECIFICATIONS 0
#			endif
#		endif
#	endif

// =====================================================================
// C++ language dependent features
// =====================================================================

#	ifndef INLINE
#		if __GNUC__ && !__GNUC_STDC_INLINE__
#		 define LGE_INLINE 						extern inline
#		 define LGE_STATIC_INLINE 				extern static inline
#		else		
#		 define LGE_INLINE 						inline
#		 define LGE_STATIC_INLINE 				static inline
#		endif		
#	endif		
		
#	define LGE_STATIC 							static
		
#	define LGE_TRUE  							1
#	define LGE_FALSE 							0
		
#	define LGE_VOID 							void
		
	//	c++ 11		
	// -------		
		
#	ifdef LGE_HAS_CONSTEXPR		
#		define LGE_CONSTEXPR 					constexpr;
#	endif

#	ifdef LGE_HAS_STATIC_ASSERT
#		define LGE_STATIC_ASSERT_M 				static_assert
#		ifdef LGE_PREDEF_STANDARD_CPP_2017
#			define LGE_STATIC_ASSERT 			static_assert
#		endif
#	endif

#	ifdef LGE_HAS_TYPE_TRAITS
#		include <type_traits>
#	endif

#	ifdef LGE_HAS_AUTO
#		define LGE_AUTO 						auto
#	endif

#	ifdef LGE_HAS_EXTERNAL_TEMPLATE
#		define LGE_EX_TEMP 						extern template
#	endif

#	ifdef LGE_HAS_TEMPLATE_ALIASSES
#		define LGE_TEMP_ALLIAS 					using
#	endif

//#	ifdef LGE_HAS_ATOMIC_OPERATIONS
//#		include <atomic>
//#	endif

 #	ifdef LGE_HAS_ALIGNAS || LGE_HAS_ALIGNOF
#		define LGE_ALIGNOF 						alignof
#		define LGE_ALIGNAS 						alignas
#	endif

#	ifdef LGE_HAS_NULLPTR
#		define LGE_NULLPTR 						nullptr
#	endif

#	ifdef LGE_HAS_INLINE_NAMESPACES
#		define LGE_INLINE_NSP 					inline namespace
#	endif

#	ifdef LGE_HAS_NOEXCEPT
#		define LGE_NOEXCEPT 					noexcept
#	endif

#	ifdef LGE_HAS_OVERRIDE
#		define LGE_OVERRIDE 					override
#	endif

#	ifdef LGE_HAS_FINAL
#		define LGE_FINAL 						final
#	endif

#	ifdef LGE_HAS_DECLTYPE
#		define LGE_DECLTYPE 					decltype
#	endif

	//	c++ 14
	// -------
#	ifdef LGE_HAS_DECLTYPE_AUTO
#		define LGE_DAUTO 						decltype(auto)
#	endif

#	ifdef LGE_HAS_DEPRECATED_ATTR
#		define LGE_DEPRECATED 					[[deprecated]]
#	endif

	//	c++ 17
	// -------
#	ifdef LGE_HAS_FALLTHROUGH_ATTR
#		define LGE_FALLTHROUGH 					[[fallthrough]]
#	endif

#	ifdef LGE_HAS_NODISCARD_ATTR
#		define LGE_NODISCARD 					[[nodiscard]]
#	endif

#	ifdef LGE_HAS_MAYBE_UNUSED_ATTR
#		define LGE_MAYBE_UNUSED 				[[maybe_unused]]
#	endif

#	ifdef LGE_HAS_CONSTEXPR_IF
#		define LGE_CONSTEXPR_IF 				constexpr if
#	endif

#	ifdef LGE_HAS_PP__HAS_INCLUDE
#		define LGE_HAS_INCLUDE 					__has_include
#	endif


// =====================================================================
// Machine endianness
// =====================================================================

#	include <stdint.h>
#	include <limits.h>

// This code is made c/c++ compatible.
// -----------------------------------
#	ifdef __cplusplus
_LGE_BEGIN_NP_LGE
#	else
_LGE_BEGIN_C_DECLS
#	endif

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (network byte-order)
/// </summary>
/// <param name="net_number"></param>
/// <returns>uint8</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API unsigned char endian_native_uint8(unsigned char net_number) {
	unsigned char result = 0;
	int i;

	for (i = 0; i < (int)sizeof(result); i++) {
		result <<= CHAR_BIT-1;
		result += (((unsigned char*)&net_number)[i] & UCHAR_MAX);
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (native byte-order)
/// </summary>
/// <param name="native_number"></param>
/// <returns>uint8</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API unsigned char endian_net_uint8(unsigned char native_number) {
	unsigned char result = 0;
	int i;

	for (i = (int)sizeof(result) - 1; i >= 0; i--) {
		((unsigned char*)&result)[i] = native_number & UCHAR_MAX;
		native_number >>= CHAR_BIT-1;
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (network byte-order)
/// </summary>
/// <param name="net_number"></param>
/// <returns>uint16</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API unsigned short endian_native_uint16(unsigned short net_number) {
	unsigned short result = 0;
	int i;

	for (i = 0; i < (int)sizeof(result); i++) {
		result <<= CHAR_BIT;
		result += (((unsigned short*)&net_number)[i] & UCHAR_MAX);
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (native byte-order)
/// </summary>
/// <param name="native_number"></param>
/// <returns>uint16</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API unsigned short endian_net_uint16(unsigned short native_number) {
	unsigned short result = 0;
	int i;

	for (i = (int)sizeof(result) - 1; i >= 0; i--) {
		((unsigned short*)&result)[i] = native_number & UCHAR_MAX;
		native_number >>= CHAR_BIT;
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (network byte-order)
/// </summary>
/// <param name="net_number"></param>
/// <returns>uint32</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API unsigned int endian_native_uint32(unsigned int net_number) {
	unsigned int result = 0;
	int i;

	for (i = 0; i < (int)sizeof(result); i++) {
		result <<= CHAR_BIT;
		result += (((unsigned char*)&net_number)[i] & UCHAR_MAX);
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (native byte-order)
/// </summary>
/// <param name="native_number"></param>
/// <returns>uint32</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API unsigned int endian_net_uint32(unsigned int native_number) {
	unsigned int result = 0;
	int i;

	for (i = (int)sizeof(result) - 1; i >= 0; i--) {
		((unsigned char*)&result)[i] = native_number & UCHAR_MAX;
		native_number >>= CHAR_BIT;
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (network byte-order)
/// </summary>
/// <param name="net_number"></param>
/// <returns>uint64</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API unsigned long long endian_native_uint64(unsigned long long net_number) {
	unsigned long long result = 0;
	int i;

	for (i = 0; i < (int)sizeof(result); i++) {
		result <<= CHAR_BIT;
		result += (((unsigned char*)&net_number)[i] & UCHAR_MAX);
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (native byte-order)
/// </summary>
/// <param name="native_number"></param>
/// <returns>uint64</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API unsigned long long endian_net_uint64(unsigned long long native_number) {
	unsigned long long result = 0;
	int i;

	for (i = (int)sizeof(result) - 1; i >= 0; i--) {
		((unsigned char*)&result)[i] = native_number & UCHAR_MAX;
		native_number >>= CHAR_BIT;
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (network byte-order)
/// </summary>
/// <param name="net_number"></param>
/// <returns>int8</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API signed char endian_native_int8(signed char net_number) {
	signed char result = 0;
	int i;

	for (i = 0; i < (int)sizeof(result); i++) {
		result <<= CHAR_BIT-1;
		result += (((signed char*)&net_number)[i] & UCHAR_MAX);
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (native byte-order)
/// </summary>
/// <param name="native_number"></param>
/// <returns>int8</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API signed char endian_net_int8(signed char native_number) {
	signed char result = 0;
	int i;

	for (i = (int)sizeof(result) - 1; i >= 0; i--) {
		((signed char*)&result)[i] = native_number & UCHAR_MAX;
		native_number >>= CHAR_BIT;
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (network byte-order)
/// </summary>
/// <param name="net_number"></param>
/// <returns>int16</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API short endian_native_int16(short net_number) {
	short result = 0;
	int i;

	for (i = 0; i < (int)sizeof(result); i++) {
		result <<= CHAR_BIT;
		result += (((short*)&net_number)[i] & UCHAR_MAX);
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (native byte-order)
/// </summary>
/// <param name="native_number"></param>
/// <returns>int16</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API short endian_net_int16(short native_number) {
	short result = 0;
	int i;

	for (i = (int)sizeof(result) - 1; i >= 0; i--) {
		((short*)&result)[i] = native_number & UCHAR_MAX;
		native_number >>= CHAR_BIT;
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (network byte-order)
/// </summary>
/// <param name="net_number"></param>
/// <returns>int32</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API int endian_native_int32(int net_number) {
	int result = 0;
	int i;

	for (i = 0; i < (int)sizeof(result); i++) {
		result <<= CHAR_BIT;
		result += (((char*)&net_number)[i] & UCHAR_MAX);
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (native byte-order)
/// </summary>
/// <param name="native_number"></param>
/// <returns>int32</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API int endian_net_int32(int native_number) {
	int result = 0;
	int i;

	for (i = (int)sizeof(result) - 1; i >= 0; i--) {
		((char*)&result)[i] = native_number & UCHAR_MAX;
		native_number >>= CHAR_BIT;
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (network byte-order)
/// </summary>
/// <param name="net_number"></param>
/// <returns>int64</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API long long endian_native_int64(long long net_number) {
	long long result = 0;
	int i;

	for (i = 0; i < (int)sizeof(result); i++) {
		result <<= CHAR_BIT;
		result += (((char*)&net_number)[i] & UCHAR_MAX);
	}
	return result;
}

/// <summary>
///  This function can be used for (de)marshalling binary data. 
///  Please notice that the code assume that the exchange format is big-endian (native byte-order)
/// </summary>
/// <param name="native_number"></param>
/// <returns>int64</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API long long endian_net_int64(long long native_number) {
	long long result = 0;
	int i;

	for (i = (int)sizeof(result) - 1; i >= 0; i--) {
		((char*)&result)[i] = native_number & UCHAR_MAX;
		native_number >>= CHAR_BIT;
	}
	return result;
}

/// <summary>
/// The five different endian types a machine can support.
/// </summary>
LGE_API enum endian_types {
	ENDIAN_UNKNOWN,
	ENDIAN_BIG,
	ENDIAN_LITTLE,
	ENDIAN_BIG_WORD,   /* Middle-endian, Honeywell 316 style */
	ENDIAN_LITTLE_WORD /* Middle-endian, PDP-11 style */
};

/// <summary>
/// Detects machine endianness at run-time.
/// </summary>
/// <param name=""></param>
/// <returns>Returns integer corresponding to specific endian type, see enum "endian_types" for different endian types.</returns>
LGE_CUDA_FUNC_DEF LGE_INLINE LGE_API int endianness(void) {
	if (sizeof(uint_least32_t) != 4 && sizeof(uint_least8_t) != 1)
		return ENDIAN_UNKNOWN;

	union {
		uint_least32_t value;
		uint_least8_t data[sizeof(uint32_t)];
	} number;

	number.data[0] = 0x00;
	number.data[1] = 0x01;
	number.data[2] = 0x02;
	number.data[3] = 0x03;

	switch (number.value) {
	case UINT32_C(0x00010203):
		return ENDIAN_BIG;
		break;
	case UINT32_C(0x03020100):
		return ENDIAN_LITTLE;
		break;
	case UINT32_C(0x02030001):
		return ENDIAN_BIG_WORD;
		break;
	case UINT32_C(0x01000302):
		return ENDIAN_LITTLE_WORD;
		break;
	default:
		return ENDIAN_UNKNOWN;
		break;
	}
}

#	ifdef __cplusplus
_LGE_END_NP_LGE
#	else
_LGE_END_C_DECLS
#	endif

#endif

