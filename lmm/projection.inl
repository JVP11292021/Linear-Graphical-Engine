#pragma once

#include "projection.hpp"
#include "RenderState.hpp"
#include "manipulations.hpp"
#include "trigonometry.h"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspective(T fovy, T aspect, T zNear, T zFar) noexcept {
#if defined(LMM_RH)
	if (RenderState::api == _API::GL)
		return perspectiveRH_GL(fovy, aspect, zNear, zFar);
	else if (RenderState::api == _API::DX)
		return perspectiveRH_DX(fovy, aspect, zNear, zFar);
	else if (RenderState::api == _API::VK)
		return Mat<T, 4, 4>();
#elif defined(LMM_LH)
	if (RenderState::api == _API::GL)
		return perspectiveLH_GL(fovy, aspect, zNear, zFar);
	else if (RenderState::api == _API::DX)
		return perspectiveLH_DX(fovy, aspect, zNear, zFar);
	else if (RenderState::api == _API::VK)
		return Mat<T, 4, 4>();
#endif

	return fill<T>((T)1);
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveRH_DX(T fovy, T aspect, T zNear, T zFar) noexcept {
	//assert(abs(aspect - std::numeric_limits<T>::epsilon()) > (T)(0));

	T const tanHalfFovy = tan_T<T>(fovy / (T)(2));

	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = (T)(1) / (aspect * tanHalfFovy);
	result[1][1] = (T)(1) / (tanHalfFovy);
	result[2][2] = zFar / (zNear - zFar);
	result[2][3] = -(T)(1);
	result[3][2] = -(zFar * zNear) / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveRH_GL(T fovy, T aspect, T zNear, T zFar) noexcept {
	//assert(abs(aspect - std::numeric_limits<T>::epsilon()) > (T)(0));

	T const tanHalfFovy = tan_T<T>(fovy / (T)(2));

	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = (T)(1) / (aspect * tanHalfFovy);
	result[1][1] = (T)(1) / (tanHalfFovy);
	result[2][2] = -(zFar + zNear) / (zFar - zNear);
	result[2][3] = -(T)(1);
	result[3][2] = -((T)(2) * zFar * zNear) / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveLH_DX(T fovy, T aspect, T zNear, T zFar) noexcept {
	//assert(abs(aspect - std::numeric_limits<T>::epsilon()) > (T)(0));

	T const tanHalfFovy = tan_T<T>(fovy / (T)(2));

	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = (T)(1) / (aspect * tanHalfFovy);
	result[1][1] = (T)(1) / (tanHalfFovy);
	result[2][2] = zFar / (zFar - zNear);
	result[2][3] = (T)(1);
	result[3][2] = -(zFar * zNear) / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveLH_GL(T fovy, T aspect, T zNear, T zFar) noexcept {
	//assert(abs(aspect - std::numeric_limits<T>::epsilon()) > (T)(0));

	T const tanHalfFovy = tan_T<T>(fovy / (T)(2));

	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = (T)(1) / (aspect * tanHalfFovy);
	result[1][1] = (T)(1) / (tanHalfFovy);
	result[2][2] = (zFar + zNear) / (zFar - zNear);
	result[2][3] = (T)(1);
	result[3][2] = -((T)(2) * zFar * zNear) / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFov(T fov, T width, T height, T zNear, T zFar) noexcept {
#if defined(LMM_RH)
	if (RenderState::api == _API::GL)
		return perspectiveFovRH_GL(fov, width, height, zNear, zFar);
	else if (RenderState::api == _API::DX)
		return perspectiveFovRH_DX(fov, width, height, zNear, zFar);
	else if (RenderState::api == _API::VK)
		return Mat<T, 4, 4>();
#elif defined(LMM_LH)
	if (RenderState::api == _API::GL)
		return perspectiveFovLH_GL(fov, width, height, zNear, zFar);
	else if (RenderState::api == _API::DX)
		return perspectiveFovLH_DX(fov, width, height, zNear, zFar);
	else if (RenderState::api == _API::VK)
		return Mat<T, 4, 4>();
#endif

	return Mat<T, 4, 4>();
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFovRH_DX(T fov, T width, T height, T zNear, T zFar) noexcept {
	assert(width > (T)(0));
	assert(height > (T)(0));
	assert(fov > (T)(0));

	T const rad = fov;
	T const h = cos_t<T>((T)0.5 * rad) / sin_t<T>((T)0.5 * rad);
	T const w = h * height / width; 

	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = w;
	result[1][1] = h;
	result[2][2] = zFar / (zNear - zFar);
	result[2][3] = -(T)1;
	result[3][2] = -(zFar * zNear) / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFovRH_GL(T fov, T width, T height, T zNear, T zFar) noexcept {
	assert(width > (T)(0));
	assert(height > (T)(0));
	assert(fov > (T)(0));

	T const rad = fov;
	T const h = cos_t<T>((T)0.5 * rad) / sin_t<T>((T)0.5 * rad);
	T const w = h * height / width;

	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = w;
	result[1][1] = h;
	result[2][2] = -(zFar + zNear) / (zFar - zNear);
	result[2][3] = -(T)(1);
	result[3][2] = -((T)(2) * zFar * zNear) / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFovLH_DX(T fov, T width, T height, T zNear, T farT) noexcept {
	assert(width > (T)(0));
	assert(height > (T)(0));
	assert(fov > (T)(0));

	T const rad = fov;
	T const h = cos_t<T>((T)0.5 * rad) / sin_t<T>((T)0.5 * rad);
	T const w = h * height / width;

	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = w;
	result[1][1] = h;
	result[2][2] = zFar / (zFar - zNear);
	result[2][3] = (T)(1);
	result[3][2] = -(zFar * zNear) / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFovLH_GL(T fov, T width, T height, T zNear, T zFar) noexcept {
	assert(width > (T)(0));
	assert(height > (T)(0));
	assert(fov > (T)(0));

	T const rad = fov;
	T const h = cos_t<T>((T)0.5 * rad) / sin_t<T>((T)0.5 * rad);
	T const w = h * height / width;

	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = w;
	result[1][1] = h;
	result[2][2] = (zFar + zNear) / (zFar - zNear);
	result[2][3] = (T)(1);
	result[3][2] = -((T)(2) * zFar * zNear) / (zFar - zNear);
	return result;
}