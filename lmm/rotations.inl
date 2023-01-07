#pragma once

#include "rotations.hpp"
#include "trigonometry.h"
#include "vec_geometry.hpp"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> rotate(const Mat<T, 4, 4>& m, T angle, const Vec<T, 3>& v) {
	T const a = angle;
	T const c = cos_t<T>(a);
	T const s = sin_t<T>(a);

	Vec<T, 3> axis = normalize(v);
	Vec<T, 3> temp = (T(1) - c) * axis;

	Mat<T, 4, 4> rotated;
	rotated[0][0] = c + temp[0] * axis[0];
	rotated[0][1] = temp[0] * axis[1] + s * axis[2];
	rotated[0][2] = temp[0] * axis[2] - s * axis[1];

	rotated[1][0] = temp[1] * axis[0] - s * axis[2];
	rotated[1][1] = c + temp[1] * axis[1];
	rotated[1][2] = temp[1] * axis[2] + s * axis[0];

	rotated[2][0] = temp[2] * axis[0] + s * axis[1];
	rotated[2][1] = temp[2] * axis[1] - s * axis[0];
	rotated[2][2] = c + temp[2] * axis[2];

	Mat<T, 4, 4> result;
	result[0] = m[0] * rotated[0][0] + m[1] * rotated[0][1] + m[2] * rotated[0][2];
	result[1] = m[0] * rotated[1][0] + m[1] * rotated[1][1] + m[2] * rotated[1][2];
	result[2] = m[0] * rotated[2][0] + m[1] * rotated[2][1] + m[2] * rotated[2][2];
	result[3] = m[3];
	return result;
}