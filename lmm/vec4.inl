#pragma once 

#include "vec4.hpp"

// =====================================================================
// c++ vector constructors & destructors
// =====================================================================


template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec()
	: x(0), y(0), z(0), w(0), size(sizeof(x) + sizeof(y) + sizeof(z) + sizeof(w))
{

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec(T x, T y)
	: x(x), y(y), z(0), w(0), size(sizeof(x) + sizeof(y) + sizeof(z) + sizeof(w))
{

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec(T x, T y, T z)
	: x(x), y(y), z(z), w(0), size(sizeof(x) + sizeof(y) + sizeof(z) + sizeof(w))
{

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec(T x, T y, T z, T w)
	: x(x), y(y), z(z), w(w), size(sizeof(x) + sizeof(y) + sizeof(z) + sizeof(w))
{

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec(const Vec<T, 2>& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = 0;
	this->w = 0;
	this->size = sizeof(T) * 4;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec(const Vec<T, 2>& v, T z) {
	this->x = v.x;
	this->y = v.y;
	this->z = z;
	this->w = 0;
	this->size = sizeof(T) * 4;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec(const Vec<T, 2>& v, T z, T w) {
	this->x = v.x;
	this->y = v.y;
	this->z = z;
	this->w = w;
	this->size = sizeof(T) * 4;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec(const Vec<T, 3>& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = 0;
	this->size = sizeof(T) * 4;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec(const Vec<T, 3>& v, T w) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = w;
	this->size = sizeof(T) * 4;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 4>::Vec(const Vec<T, 4>& v) {
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
	this->size = sizeof(T) * 4;
}


// =====================================================================
// c++ vector operator overloaded functions
// =====================================================================

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator += (const Vec<T, 4>& v) {
	return Vec<T, 4>(this->x += v.x, this->y += v.y, this->z += v.z, this->w += v.w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator -= (const Vec<T, 4>& v) {
	return Vec<T, 4>(this->x -= v.x, this->y -= v.y, this->z -= v.z, this->w -= v.w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator /= (const Vec<T, 4>& v) {
	return Vec<T, 4>(this->x /= v.x, this->y /= v.y, this->z /= v.z, this->w /= v.w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator *= (const Vec<T, 4>& v) {
	return Vec<T, 4>(this->x *= v.x, this->y *= v.y, this->z *= v.z, this->w *= v.w);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator += (const Vec<T, 3>& v) {
	return Vec<T, 4>(this->x += v.x, this->y += v.y, this->z += v.z, this->w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator -= (const Vec<T, 3>& v) {
	return Vec<T, 4>(this->x -= v.x, this->y -= v.y, this->z -= v.z, this->w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator /= (const Vec<T, 3>& v) {
	return Vec<T, 4>(this->x /= v.x, this->y /= v.y, this->z /= v.z, this->w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator *= (const Vec<T, 3>& v) {
	return Vec<T, 4>(this->x *= v.x, this->y *= v.y, this->z *= v.z, this->w);
}


template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator += (const Vec<T, 2>& v) {
	return Vec<T, 4>(this->x += v.x, this->y += v.y, this->z, this->w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator -= (const Vec<T, 2>& v) {
	return Vec<T, 4>(this->x -= v.x, this->y -= v.y, this->z, this->w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator /= (const Vec<T, 2>& v) {
	return Vec<T, 4>(this->x /= v.x, this->y /= v.y, this->z, this->w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator *= (const Vec<T, 2>& v) {
	return Vec<T, 4>(this->x *= v.x, this->y *= v.y, this->z, this->w);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator += (const T& v) {
	return Vec<T, 4>(this->x += v, this->y += v, this->z += v, this->w += v);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator -= (const T& v) {
	return Vec<T, 4>(this->x -= v, this->y -= v, this->z -= v, this->w -= v);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator /= (const T& v) {
	return Vec<T, 4>(this->x /= v, this->y /= v, this->z /= v, this->w /= v);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 4> Vec<T, 4>::operator *= (const T& v) {
	return Vec<T, 4>(this->x *= v, this->y *= v, this->z *= v, this->w *= v);
}