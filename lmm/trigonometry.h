
#ifndef LMM_TRIGONOMETRY
#define LMM_TRIGONOMETRY

#include "types.h"
#include "lmm_defs.h"

#define LMM_PI 3.14159265359
#define LMM_RAD 57.29577951

#define LMM_ROT0 0	
#define LMM_ROT_HALF_PI 90
#define LMM_ROT_PI 180
#define LMM_ROT_1HALF_PI 270
#define LMM_ROT_TWO_PI 360

#ifdef LMM_CPP
extern "C" {
#endif
	
	LMM_FUNC_DECL f64 radians(f64);
	LMM_FUNC_DECL f64 degrees(f64);

#ifdef LMM_CPP
}
#endif

#ifdef LMM_CPP

// =====================================================================
// Trigonometric functions
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR 
T cos_t(T _X) noexcept {
	return (T)cos((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T sin_t(T _X) noexcept {
	return (T)sin((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T tan_t(T _X) noexcept {
	return (T)tan((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T acos_t(T _X) noexcept {
	return (T)acos((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T asin_t(T _X) noexcept {
	return (T)asin((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T atan_t(T _X) noexcept {
	return (T)atan((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T atan2_t(T _X) noexcept {
	return (T)atan2((f128)_X);
}

// =====================================================================
// Hyperbolic functions
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T cosh_t(T _X) noexcept {
	return (T)cosh((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T sinh_t(T _X) noexcept {
	return (T)sinh((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T tanh_t(T _X) noexcept {
	return (T)tanh((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T acosh_t(T _X) noexcept {
	return (T)acosh((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T asinh_t(T _X) noexcept {
	return (T)asinh((f128)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T atanh_t(T _X) noexcept {
	return (T)atanh((f128)_X);
}

#endif

#endif