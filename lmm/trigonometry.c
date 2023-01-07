#include "trigonometry.h"

LMM_FUNC_DECL f64 radians(f64 degrees) {
	return ((2 * LMM_PI) / 360) * degrees;
}

LMM_FUNC_DECL f64 degrees(f64 radians) {
	return (360 / (2 * LMM_PI)) * radians;
}