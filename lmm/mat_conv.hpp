#pragma once
//#include "cMatrix.h
#include "mat.hpp"
#include "types.h"

template <typename T>
LMM_FUNC_DECL Mat<T, 3, 3> convert(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> convert(const Mat<T, 2, 2>&);

template <typename T>
LMM_FUNC_DECL Mat<T, 4, 4> convert(const Mat<T, 3, 3>&);

#ifndef LMM_EXTERNAL_TEMPLATE
#include "mat_conv.inl"
#endif