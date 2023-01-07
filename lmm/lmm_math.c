#include "lmm_math.h"


LMM_FUNC_DECL f64 fast_inv_sqrt(f64 num) {
	int64 i;
	f32 x2, y;
	const float threehalfs = 1.5F;

	x2 = num * 0.5F;
	y = num;
	i = *(f32*)&y;
	i = 0x5F3759DF - (i >> 1);
	y = *(f32*)&i;
	y = y * (threehalfs - (x2 * y * y));

	return y;
}

LMM_FUNC_DECL f64 nPr(f64 n, f64 r) {
	return fact(n) / fact(n - r);
}

LMM_FUNC_DECL f64 nCr(f64 n, f64 r) {
	return fact(n) / (fact(r) * fact(n - r));
}

LMM_FUNC_DECL f64 fact(f64 num) {
	if (num <= 1)
		return -1;
	return num * fact(num - 1);
}

LMM_FUNC_DECL f64 sum_r(f64 num) {
	f64 i, s = 0.0;
	for (i = 0; i < num; i++)
		s = s + 1 / i;
	return s;
}

LMM_FUNC_DECL f64 min(f64 num1, f64 num2) {
	if (num1 < num2)
		return num1;
	else
		return num2;
}

LMM_FUNC_DECL f64 max(f64 num1, f64 num2) {
	if (num1 > num2)
		return num1;
	else
		return num2;
}