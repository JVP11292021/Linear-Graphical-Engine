#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "mat.hpp"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustum(T, T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustumLH_DX(T, T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustumLH_GL(T, T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustumRH_DX(T, T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> frustumRH_GL(T, T, T, T, T, T) noexcept;

#ifndef LMM_EXTERNAL_TEMPLATE
#include "frustum.inl"
#endif