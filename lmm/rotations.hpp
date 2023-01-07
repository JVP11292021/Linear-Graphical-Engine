#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "mat.hpp"
#include "vec.hpp"
template <typename T>
LMM_FUNC_DECL LMM_CONSTEXPR
Mat<T, 4, 4> rotate(const Mat<T, 4, 4>&, T, const Vec<T, 3>&);

#ifndef LMM_EXTERNAL_TEMPLATE
#include "rotations.inl"
#endif