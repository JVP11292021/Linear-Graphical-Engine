#pragma once

#include "ortho.hpp"
#include "manipulations.hpp"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> ortho(T left, T right, T bottom, T top) noexcept {
	Mat<T, 4, 4> result((T)LMM_TRUE);
	result[0][0] = (T)2 / (right - left);
	result[1][1] = (T)2 / (top - bottom);
	result[2][2] = -(T)1;
	result[3][0] = -(right + left) / (right - left);
	result[3][1] = -(top + bottom) / (top - bottom);

	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> ortho(T left, T right, T bottom, T top, T zNear, T zFar) noexcept {
#if defined(LMM_RH)
	if (RenderState::api == _API::GL)
		return orthoRH_GL(left, right, bottom, top, zNear, zFar);;
	else if (RenderState::api == _API::DX)
		return orthoRH_DX(left, right, bottom, top, zNear, zFar);;
	else if (RenderState::api == _API::VK)
		return Mat<T, 4, 4>();
#elif defined(LMM_LH)
	//if (RenderState::isEqual(LMM_STATE_GL))
		return orthoLH_GL(left, right, bottom, top, zNear, zFar);
	//else if (RenderState::api == _API::DX)
	//	return orthoLH_DX(left, right, bottom, top, zNear, zFar);
	//else if (RenderState::api == _API::VK)
	//	return Mat<T, 4, 4>();
#endif
	
	//return Mat<T, 4, 4>();
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> orthoLH_DX(T left, T right, T bottom, T top, T zNear, T zFar) noexcept {
	Mat<T, 4, 4> result((T)LMM_TRUE);
	result[0][0] = (T)2 / (right - left);
	result[1][1] = (T)2 / (top - bottom);
	result[2][2] = (T)1 / (zFar - zNear);
	result[3][0] = -(right + left) / (right - left);
	result[3][1] = -(top + bottom) / (top - bottom);
	result[3][2] = -zNear / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> orthoLH_GL(T left, T right, T bottom, T top, T zNear, T zFar) noexcept {
	Mat<T, 4, 4> result((T)LMM_TRUE);
	result[0][0] = (T)2 / (right - left);
	result[1][1] = (T)2 / (top - bottom);
	result[2][2] = (T)2 / (zFar - zNear);
	result[3][0] = -(right + left) / (right - left);
	result[3][1] = -(top + bottom) / (top - bottom);
	result[3][2] = -(zFar + zNear) / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> orthoRH_DX(T left, T right, T bottom, T top, T zNear, T zFar) noexcept {
	Mat<T, 4, 4> result((T)LMM_TRUE);
	result[0][0] = (T)2 / (right - left);
	result[1][1] = (T)2 / (top - bottom);
	result[2][2] = -(T)1 / (zFar - zNear);
	result[3][0] = -(right + left) / (right - left);
	result[3][1] = -(top + bottom) / (top - bottom);
	result[3][2] = -zNear / (zFar - zNear);
	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> orthoRH_GL(T left, T right, T bottom, T top, T zNear, T zFar) noexcept {
	Mat<T, 4, 4> result((T)LMM_TRUE);
	result[0][0] = (T)2 / (right - left);
	result[1][1] = (T)2 / (top - bottom);
	result[2][2] = -(T)2 / (zFar - zNear);
	result[3][0] = -(right + left) / (right - left);
	result[3][1] = -(top + bottom) / (top - bottom);
	result[3][2] = -(zFar + zNear) / (zFar - zNear);
	return result;
}
