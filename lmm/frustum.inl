#pragma once

#include "frustum.hpp"
#include "RenderState.hpp"
#include "manipulations.hpp"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustum(T left, T right, T bottom, T top, T nearVal, T farVal) noexcept {
#if defined(LMM_RH)
	if (RenderState::api == _API::GL)
		return frustumRH_GL(left, right, bottom, top, nearVal, farVal);;
	else if (RenderState::api == _API::DX)
		return frustumRH_DX(left, right, bottom, top, nearVal, farVal);;
	else if (RenderState::api == _API::VK)
		return Mat<T, 4, 4>();
#elif defined(LMM_LH)
	if (RenderState::api == _API::GL)
		return frustumLH_GL(left, right, bottom, top, nearVal, farVal);
	else if (RenderState::api == _API::DX)
		return frustumLH_DX(left, right, bottom, top, nearVal, farVal);
	else if (RenderState::api == _API::VK)
		return Mat<T, 4, 4>();
#endif

	return Mat<T, 4, 4>();
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustumLH_DX(T left, T right, T bottom, T top, T nearVal, T farVal) noexcept {
	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = ((T)2 * nearVal) / (right - left);
	result[1][1] = ((T)2 * nearVal) / (top - bottom);
	result[2][0] = (right + left) / (right - left);
	result[2][1] = (top + bottom) / (top - bottom);
	result[2][2] = farVal / (farVal - nearVal);
	result[2][3] = (T)1;
	result[3][2] = -(farVal * nearVal) / (farVal - nearVal);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustumLH_GL(T left, T right, T bottom, T top, T nearVal, T farVal) noexcept {
	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = ((T)2 * nearVal) / (right - left);
	result[1][1] = ((T)2 * nearVal) / (top - bottom);
	result[2][0] = (right + left) / (right - left);
	result[2][1] = (top + bottom) / (top - bottom);
	result[2][2] = (farVal + nearVal) / (farVal - nearVal);
	result[2][3] = (T)1;
	result[3][2] = -((T)2 * farVal * nearVal) / (farVal - nearVal);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustumRH_DX(T left, T right, T bottom, T top, T nearVal, T farVal) noexcept {
	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = ((T)2 * nearVal) / (right - left);
	result[1][1] = ((T)2 * nearVal) / (top - bottom);
	result[2][0] = (right + left) / (right - left);
	result[2][1] = (top + bottom) / (top - bottom);
	result[2][2] = farVal / (nearVal - farVal);
	result[2][3] = (T)-1;
	result[3][2] = -(farVal * nearVal) / (farVal - nearVal);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustumRH_GL(T left, T right, T bottom, T top, T nearVal, T farVal) noexcept {
	Mat<T, 4, 4> result((T)LMM_FALSE);
	result[0][0] = ((T)2 * nearVal) / (right - left);
	result[1][1] = ((T)2 * nearVal) / (top - bottom);
	result[2][0] = (right + left) / (right - left);
	result[2][1] = (top + bottom) / (top - bottom);
	result[2][2] = -(farVal + nearVal) / (farVal - nearVal);
	result[2][3] = (T)-1;
	result[3][2] = -((T)2 * farVal * nearVal) / (farVal - nearVal);
	return result;
}
