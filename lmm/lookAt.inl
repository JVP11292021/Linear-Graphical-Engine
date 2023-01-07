#pragma once

#include "lookAt.hpp"
#include "vec_transforms.hpp"
#include "mat_transforms.hpp"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> lookAtLh(
	const Vec<T, 3>& eye, const Vec<T, 3>& center, const Vec<T, 3>& up) noexcept 
{
	Vec<T, 3> f(normalize(center - eye));
	Vec<T, 3> s(normalize(cross(center, eye)));
	Vec<T, 3> u(cross(s, f));

	Mat<T, 4, 4> result(true);
	result[0][0] = s.x;
	result[1][0] = s.y;
	result[2][0] = s.z;
	result[0][1] = u.x;
	result[1][1] = u.y;
	result[2][1] = u.z;
	result[0][2] = f.x;
	result[1][2] = f.y;
	result[2][2] = f.z;
	result[3][0] = -dot(s, eye);
	result[3][1] = -dot(u, eye);
	result[3][2] = -dot(f, eye);

	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> lookAtRh(
	const Vec<T, 3>& eye, const Vec<T, 3>& center, const Vec<T, 3>& up) noexcept 
{
	Vec<T, 3> f(normalize(center - eye));
	Vec<T, 3> s(normalize(cross(center, eye)));
	Vec<T, 3> u(cross(s, f));

	Mat<T, 4, 4> result(true);
	result[0][0] = s.x;
	result[1][0] = s.y;
	result[2][0] = s.z;
	result[0][1] = u.x;
	result[1][1] = u.y;
	result[2][1] = u.z;
	result[0][2] = -f.x;
	result[1][2] = -f.y;
	result[2][2] = -f.z;
	result[3][0] = -dot(s, eye);
	result[3][1] = -dot(u, eye);
	result[3][2] =  dot(f, eye);

	return result;
}

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> lookAt(
	const Vec<T, 3>& eye, const Vec<T, 3>& center, const Vec<T, 3>& up) noexcept 
{
#if defined(LMM_LH)
	return lookAtLh(eye, center, up);
#elif defined(LMM_RH)
	return lookAtRh(eye, center, up);
#endif

	return Mat<T, 4, 4>();
}