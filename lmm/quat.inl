#pragma once

#include "quat.hpp"
#include "quat_transform.hpp"

// =====================================================================
// c++ quaternion constructors.  
// =====================================================================

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T>::Quaternion() {
	this->s = 0;
	this->size = this->v.getSize() + sizeof(T);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T>::Quaternion(T s, const Vec<T, 3>& ijk) {
	this->s = s;
	this->v = ijk;
	this->size = this->v.getSize() + sizeof(T);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T>::Quaternion(T s, const Vec<T, 4>& ijk) {
	this->s = s;
	this->v = ijk;
	this->size = this->v.getSize() + sizeof(T);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T>::Quaternion(T s, T i, T j, T k) {
	this->s = s;
	this->v = Vec<T, 3>(i, j, k);
	this->size = sizeof(T) * 4;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Quaternion<T>::Quaternion(const Quaternion<T>& quat) {
	this->s = quat.s;
	this->v = quat.v;
	this->size = quat.size;
}

// =====================================================================
// c++ quaternion operations.  
// =====================================================================

template <typename T>
LMM_FUNC_DECL Quaternion<T> Quaternion<T>::operator += (const Quaternion<T>& quat) {
	this->s += quat.s;
	this->v += quat.v;
	return *this;
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> Quaternion<T>::operator -= (const Quaternion<T>& quat) {
	this->s -= quat.s;
	this->v -= quat.v;
	return *this;
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> Quaternion<T>::operator *= (const Quaternion<T>& quat) {
	(*this) = mul(this, quat);
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> Quaternion<T>::operator *= (const T s) {
	this->s *= s;
	this->v *= s;
	return *this;
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> Quaternion<T>::operator + (const Quaternion<T>& quat) {
	this->s += quat.s;
	this->v += quat.v;
	return *this;
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> Quaternion<T>::operator - (const Quaternion<T>& quat) {
	this->s -= quat.s;
	this->v -= quat.v;
	return *this;
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> Quaternion<T>::operator * (const Quaternion<T>& quat) {
	//Quaternion<T> multiplied;
	*this = mul(*this, quat);
	return *this;
}

template <typename T>
LMM_FUNC_DECL Quaternion<T> Quaternion<T>::operator * (const T s) {
	this->s *= s;
	this->v *= s;
	return *this;
}

