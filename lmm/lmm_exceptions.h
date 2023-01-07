#pragma once

#ifdef __cplusplus
#include <cstdio>
#else
#include <stdio.h>
#endif

#define LMM_ERROR_CODE

//#ifdef LMM_C
//typedef enum lmm_errors {
//	OOM,
//	MPN,
//	MCO,
//	MDE,
//	MAR,
//	MRAN,
//	MLEN,
//	MAE,
//	MERR
//} lmm_enum_errors;
//#endif
//
//
//#ifdef LMM_C
//#define LMM_ERRORS(errCode) {\
//	if (errCode == 0) { \
//		LMM_ERROR_CODE OOM \
//		fputs("ERROR::LMM:: Matrix out of memory error.", stderr); \
//		abort(); \
//	}\
//	else if (errCode == 1) {\
//		LMM_ERROR_CODE MPN \
//		fputs("ERROR::LMM:: Matrix array pointer is null.", stderr); \
//		abort(); \
//	}\
//	else if (errCode == 2) {\
//		LMM_ERROR_CODE MCO \
//		fputs("ERROR::LMM:: Matrix construction error.", stderr); \
//		abort(); \
//	}\
//	else if (errCode == 3) {\
//		LMM_ERROR_CODE MDE \
//		fputs("ERROR::LMM:: Matrix destruction error.", stderr); \
//		abort(); \
//	}\
//	else if (errCode == 4) {\
//		LMM_ERROR_CODE MAR \
//		fputs("ERROR::LMM:: Matrix arithmatic error", stderr); \
//		abort(); \
//	}\
//	else if (errCode == 5) {\
//		LMM_ERROR_CODE MRAN \
//		fputs("ERROR::LMM:: Out of valid dynamic matrix array position error.", stderr); \
//		abort(); \
//	}\
//	else if (errCode == 6) {\
//		LMM_ERROR_CODE MLEN \
//		fputs("ERROR::LMM:: Dynamic matrix array length error", stderr); \
//		abort(); \
//	}\
//	else if (errCode == 7) {\
//		LMM_ERROR_CODE MAE \
//		fputs("ERROR::LMM:: Invalid dynamic matrix array element.", stderr); \
//		abort(); \
//	}\
//};
//
////Out of memory error.
//#define LMM_OOM_ERROR() (LMM_ERRORS(OOM))
//
////Matrix array pointer is null.
//#define	LMM_MPN_ERROR() (LMM_ERRORS(MPN))
//
////Matrix construction error.
//#define LMM_MCO_ERROR() (LMM_ERRORS(MCO))
//
////Matrix destruction error.
//#define LMM_MDE_ERROR() (LMM_ERRORS(MDE))
//
////Matrix arithmatic error.
//#define LMM_MAR_ERROR() (LMM_ERRORS(MAR))
//
////Out of valid dynamic matrix array position error.
//#define LMM_MRAN_ERROR() (LMM_ERRORS(MRAN))
//
////Dynamic matrix array length error
//#define LMM_MLEN_ERROR() (LMM_ERRORS(MLEN))
//
////Invalid dynamic matrix array element.
//#define LMM_MAE_ERROR() (LMM_ERRORS(MAE))
//#endif

#ifdef LMM_C
#define LMM_TYPE_CHECK(T) _Generic((T), int:1, long:2, long long:3, float:4, double:5, long double:6, short:7, char:8, default:-1)
#endif

#if defined(__GNUC__) || defined(__MINGW32__)
#define LMM_WARNING(message) {\
	#warning message \
	abort();
};
#endif


#define LMM_EXCEPTION(message) { \
	fputs(message, stderr); \
	abort(); \
};