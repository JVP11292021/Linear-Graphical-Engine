#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "mat.hpp"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspective(T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveRH_DX(T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveRH_GL(T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveLH_DX(T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveLH_GL(T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFov(T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFovRH_DX(T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFovRH_GL(T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFovLH_DX(T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> perspectiveFovLH_GL(T, T, T, T, T) noexcept;

#ifndef LMM_EXTERNAL_TEMPLATE
#include "projection.inl"
#endif