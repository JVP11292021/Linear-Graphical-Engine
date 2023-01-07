#ifndef LMM_MATH
#define LMM_MATH

#include "types.h"
#include "lmm_defs.h"
#include <math.h>

#ifdef LMM_CPP

// =====================================================================
// Geometric functions
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T sqrt_t(T _X) noexcept {
	if (_X < 0)
		LMM_EXCEPTION("LMM::Exception sqrt(_X) cannot take a negative number as argument!");
	return (T)sqrt((f64)_X);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
T cbrt_t(T _X) noexcept {
	if (_X < 0)
		LMM_EXCEPTION("LMM::Exception cbrt(_X) cannot take a negative number as argument!");
	return (T)cbrt((f64)_X);
}

#endif

#ifdef LMM_CPP
extern "C" {
#endif

	LMM_FUNC_DECL f64 fast_inv_sqrt(f64);
	LMM_FUNC_DECL f64 nPr(f64, f64);
	LMM_FUNC_DECL f64 nCr(f64, f64);
	LMM_FUNC_DECL f64 fact(f64);
	LMM_FUNC_DECL f64 sum_r(f64);
	LMM_FUNC_DECL f64 min(f64, f64);
	LMM_FUNC_DECL f64 max(f64, f64);

#ifdef LMM_CPP
}
#endif

#endif