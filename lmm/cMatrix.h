#ifndef LMM_MATRIX_C
#define LMM_MATRIX_C

#include "types.h"
#include "cvec.h"
#include "lmm_defs.h"

#include <stdio.h>

#ifdef LMM_CPP
extern "C" {
#endif

	struct cMat {
		f32* items;
		uint32 rows;
		uint32 cols;
		size_t size;
		uint32 totalItems;
	};

	typedef struct cMat mat;


	// =====================================================================
	// Custom matrix functions
	// =====================================================================

	LMM_FUNC_DECL mat constructMat(f32* items, uint32 rows, uint32 cols);
	LMM_FUNC_DECL mat* constructDynMat(f32* items, uint32 rows, uint32 cols, uint16 nBytes);
	LMM_FUNC_DECL int8 destructMat(mat* m);
	LMM_FUNC_DECL int8 destructDynMat(mat* m);

	LMM_FUNC_DECL mat addMat(mat a, mat b);
	LMM_FUNC_DECL mat subMat(mat a, mat b);
	LMM_FUNC_DECL mat negate(mat m);

	LMM_FUNC_DECL mat sSub(mat m, f32 s);
	LMM_FUNC_DECL mat sAdd(mat m, f32 s);
	LMM_FUNC_DECL mat sDiv(mat m, f32 s);
	LMM_FUNC_DECL mat sMul(mat m, f32 s);

	LMM_FUNC_DECL mat adjoint(mat m);
	LMM_FUNC_DECL mat inverse(mat m);
	LMM_FUNC_DECL f32 determinant(mat m, uint32 n);
	LMM_FUNC_DECL mat cofactor(mat m, uint32 p, uint32 q);

	LMM_FUNC_DECL mat dot(mat a, mat b);

	LMM_FUNC_DECL mat transpose(mat m);
	LMM_FUNC_DECL mat reverse(mat m);

	LMM_FUNC_DECL mat identityMat(uint32 rows, uint32 cols);
	LMM_FUNC_DECL mat zerosMat(uint32 rows, uint32 cols);
	LMM_FUNC_DECL mat onesMat(uint32 rows, uint32 cols);

	LMM_FUNC_DECL mat translate(mat m, vec4f v);
	LMM_FUNC_DECL void printMat(mat* m);

#ifdef LMM_CPP
}
#endif

#endif