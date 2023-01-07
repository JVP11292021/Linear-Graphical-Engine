#ifndef LMM_DYN_ARRAY
#define LMM_DYN_ARRAY

#include "types.h"
#include "lmm_defs.h"

#ifdef LMM_CPP
extern "C" {
#endif

	LMM_FUNC_DECL f32* arrange_f(uint32, uint32);
	LMM_FUNC_DECL f64* arrange_d(uint32, uint32);
	LMM_FUNC_DECL f32* zeros_f(uint32, uint32);
	LMM_FUNC_DECL f64* zeros_d(uint32, uint32);
	LMM_FUNC_DECL f32* ones_f(uint32, uint32);
	LMM_FUNC_DECL f64* ones_d(uint32, uint32);
	LMM_FUNC_DECL f32* fill_f(uint32, uint32, f32);
	LMM_FUNC_DECL f64* fill_d(uint32, uint32, f64);
	LMM_FUNC_DECL f32* identity_f(uint32, uint32);
	LMM_FUNC_DECL f64* identity_d(uint32, uint32);

#ifdef LMM_CPP 
}
#endif

#endif