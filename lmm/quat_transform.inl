#pragma once

#include "quat_transform.hpp"
#include "trigonometry.h"
//#include "lmm_math.h"

// =====================================================================
// c++ quaternion operations.  
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> mul(const Quaternion<T>& quat1, const Quaternion<T>& quat2) {
	T s = quat1.s * quat2.s - dot(quat1.v, quat2.v);
	Vec<T, 3> imaginary = (quat2.v * quat1.s) + (quat1.v * quat2.s) + cross(quat1.v, quat2.v);

	return Quaternion<T>(s, imaginary);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR T norm(const Quaternion<T>& quat) {
	T s = quat.s * quat.s;
	T imaginary = dot(quat.v, quat.v);

	return (T)sqrt(s + imaginary);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> normalize(const Quaternion<T>& quat) {
	if (norm(quat) != 0) {
		Quaternion<T> q;
		T normVal = 1 / norm(quat);

		q.s = quat.s * normVal;
		q.v = quat.v * normVal;

		return q;
	}

	return quat;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> make_unitnorm(const Quaternion<T>& quat) {
	f64 angle = radians(quat.s);
	quat.v = normalize(quat.v);
	quat.s = cos_t<T>(angle * 0.5);
	quat.v = quat.v * sin_t<T>(angle * 0.5);

	return quat;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> conjugate(const Quaternion<T>& quat) {
	T s = quat.s;
	Vec<T, 3> imaginary = quat.v * (T)(-1);

	return Quaternion<T>(s, imaginary);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T> inverse(const Quaternion<T>& quat) {
	T absolute = norm(quat);
	absolute = absolute * absolute;
	absolute = 1 / absolute;

	Quaternion<T> conjugated = conjugate(quat);
	T s = conjugated.s * absolute;
	Vec<T, 3> imaginary = conjugated.v * absolute;

	return  Quaternion<T>(s, imaginary);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3> rotateBy(const Vec<T, 3>& _start, f32 _A, const Vec<T, 3>& _axis) {
	Quaternion<T> p(0, _start);				// Pure quaternion
	_axis = normalize(_axis);
	Quaternion<T> r(_A, _axis);				// Real quaternion
	Quaternion<T> r = make_unitnorm(r);
	Quaternion<T> qinv = inverse(r);
	Quaternion<T> rotated = r * p * qinv;	// rotate quaternion

	return rotated.v;
}
