#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "mat.hpp"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 2, 2> fill2x2(T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 3, 3> fill3x3(T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> fill4x4(T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 2, 2> identity2x2() noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 3, 3> identity3x3() noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> identity4x4() noexcept;

#ifndef LMM_EXTERNAL_TEMPLATE
#include "manipulations.inl"
#endif