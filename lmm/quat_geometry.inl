#pragma once

#include "quat_geometry.hpp"
#include "quat_transform.hpp"

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator + (const Quaternion<T>& quat1, const Quaternion<T>& quat2) {
	Quaternion<T> result;
	result.s = quat1.s + quat2.s;
	result.v = quat1.v + quat2.v;
	return result;
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator - (const Quaternion<T>& quat1, const Quaternion<T>& quat2) {
	Quaternion<T> result;
	result.s = quat1.s - quat2.s;
	result.v = quat1.v - quat2.v;
	return result;
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator * (const Quaternion<T>& quat1, const Quaternion<T>& quat2) {
	return mul(quat1, quat2);
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator * (const Quaternion<T>& quat, const T scalar) {
	quat.s *= scalar;
	quat.v *= quat.v;
	return quat;
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> operator * (const T scalar, const Quaternion<T>& quat) {
	quat.s *= scalar;
	quat.v *= quat.v;
	return quat;
}