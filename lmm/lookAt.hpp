#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "vec.hpp"
#include "mat.hpp"

/// <summary>
/// Build a left handed look at view matrix.
/// 
/// @param eye Position of the camera
/// @param center Position where the camera is looking at
/// @param up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eye"></param>
/// <param name="center"></param>
/// <param name="up"></param>
/// <returns>lmm::mat4</returns>
template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR 
Mat<T, 4, 4> lookAtLh(
	const Vec<T, 3>&, const Vec<T, 3>&, const Vec<T, 3>&) noexcept;

/// <summary>
/// Build a right handed look at view matrix.
/// 
/// @param eye Position of the camera
/// @param center Position where the camera is looking at
/// @param up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eye"></param>
/// <param name="center"></param>
/// <param name="up"></param>
/// <returns>lmm::mat4</returns>
template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> lookAtRh(
	const Vec<T, 3>&, const Vec<T, 3>&, const Vec<T, 3>&) noexcept;

/// <summary>
/// Function decides wether to return a right or left handed view matrix.
/// If "LMM_RH_COORD_SYSTEM" is defined than lookAt uses right handed coordinate system else left handed.
/// 
/// eye Position of the camera
/// center Position where the camera is looking at
/// up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="eye"></param>
/// <param name="center"></param>
/// <param name="up"></param>
/// <returns>lmm::mat4</returns>
template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> lookAt(
	const Vec<T, 3>&, const Vec<T, 3>&, const Vec<T, 3>&) noexcept;

#ifndef LMM_EXTERNAL_TEMPLATE
#	include "lookAt.inl"
#endif


