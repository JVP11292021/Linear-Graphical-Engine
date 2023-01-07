#pragma once 

#include "vec3.hpp"

// =====================================================================
// c++ vector constructors & destructors
// =====================================================================


template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3>::Vec()
	: x(0), y(0), z(0), size(sizeof(x) + sizeof(y) + sizeof(z))
{

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3>::Vec(T x, T y)
	: x(x), y(y), z(0), size(sizeof(x) + sizeof(y) + sizeof(z))
{

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3>::Vec(T x, T y, T z)
	: x(x), y(y), z(z), size(sizeof(x) + sizeof(y) + sizeof(z))
{

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3>::Vec(const Vec<T, 2>& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = 0;
	this->size = sizeof(T) * 3;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3>::Vec(const Vec<T, 2>& v, T z) {
	this->x = v.x;
	this->y = v.y;
	this->z = z;
	this->size = sizeof(T) * 3;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3>::Vec(const Vec<T, 3>& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->size = sizeof(T) * 3;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 3>::Vec(const Vec<T, 4>& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->size = sizeof(T) * 3;
}


// =====================================================================
// c++ vector operator overloaded functions
// =====================================================================

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator += (const Vec<T, 3>& v) {
	return Vec<T, 3>(this->x += v.x, this->y += v.y, this->z += v.z);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator -= (const Vec<T, 3>& v) {
	return Vec<T, 3>(this->x -= v.x, this->y -= v.y, this->z -= v.z);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator /= (const Vec<T, 3>& v) {
	return Vec<T, 3>(this->x /= v.x, this->y /= v.y, this->z /= v.z);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator *= (const Vec<T, 3>& v) {
	return Vec<T, 3>(this->x *= v.x, this->y *= v.y, this->z *= v.z);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator += (const Vec<T, 2>& v) {
	return Vec<T, 3>(this->x += v.x, this->y += v.y, this->z);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator -= (const Vec<T, 2>& v) {
	return Vec<T, 3>(this->x -= v.x, this->y -= v.y, this->z);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator /= (const Vec<T, 2>& v) {
	return Vec<T, 3>(this->x /= v.x, this->y /= v.y, this->z);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator *= (const Vec<T, 2>& v) {
	return Vec<T, 3>(this->x *= v.x, this->y *= v.y, this->z);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator += (const T& v) {
	return Vec<T, 3>(this->x += v, this->y += v, this->z += v);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator -= (const T& v) {
	return Vec<T, 3>(this->x -= v, this->y -= v, this->z -= v);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator /= (const T& v) {
	return Vec<T, 3>(this->x /= v, this->y /= v, this->z /= v);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 3> Vec<T, 3>::operator *= (const T& v) {
	return Vec<T, 3>(this->x *= v, this->y *= v, this->z *= v);
}