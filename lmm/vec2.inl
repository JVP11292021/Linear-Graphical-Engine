#pragma once

#include "vec2.hpp"

// =====================================================================
// c++ vector constructors & destructors
// =====================================================================


template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 2>::Vec()
	: x(0), y(0), size(sizeof(x) + sizeof(y))
{

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 2>::Vec(T x, T y)
	: x(x), y(y), size(sizeof(x) + sizeof(y))
{

}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 2>::Vec(const Vec<T, 2>& v) {
	this->x = v.x;
	this->y = v.y;
	this->size = sizeof(T) * 2;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 2>::Vec(const Vec<T, 3>& v) {
	this->x = v.x;
	this->y = v.y;
	this->size = sizeof(T) * 2;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR Vec<T, 2>::Vec(const Vec<T, 4>& v) {
	this->x = v.x;
	this->y = v.y;
	this->size = sizeof(T) * 2;
}


// =====================================================================
// c++ vector operator overloaded functions
// =====================================================================

template <typename T>
LMM_FUNC_DECL Vec<T, 2> Vec<T, 2>::operator += (const Vec<T, 2>& v) {
	return Vec<T, 2>(this->x += v.x, this->y += v.y);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> Vec<T, 2>::operator -= (const Vec<T, 2>& v) {
	return Vec<T, 2>(this->x -= v.x, this->y -= v.y);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> Vec<T, 2>::operator /= (const Vec<T, 2>& v) {
	return Vec<T, 2>(this->x /= v.x, this->y /= v.y);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> Vec<T, 2>::operator *= (const Vec<T, 2>& v) {
	return Vec<T, 2>(this->x *= v.x, this->y *= v.y);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> Vec<T, 2>::operator += (const T& v) {
	return Vec<T, 2>(this->x += v, this->y += v);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> Vec<T, 2>::operator -= (const T& v) {
	return Vec<T, 2>(this->x -= v, this->y -= v);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> Vec<T, 2>::operator /= (const T& v) {
	return Vec<T, 2>(this->x /= v, this->y /= v);
}

template <typename T>
LMM_FUNC_DECL Vec<T, 2> Vec<T, 2>::operator *= (const T& v) {
	return Vec<T, 2>(this->x *= v, this->y *= v);
}