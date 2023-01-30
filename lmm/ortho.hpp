#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "mat.hpp"
#include "RenderState.hpp"

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> ortho(T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> ortho(T, T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> orthoLH_DX(T, T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> orthoLH_GL(T, T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> orthoRH_DX(T, T, T, T, T, T) noexcept;

template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> orthoRH_GL(T, T, T, T, T, T) noexcept;


#ifndef LMM_EXTERNAL_TEMPLATE
#	include "ortho.inl"
#endif