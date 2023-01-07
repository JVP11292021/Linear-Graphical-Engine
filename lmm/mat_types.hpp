#pragma once

#include "types.h"

// forward declaration Mat class
template <typename T, uint32 R, uint32 C>
class Mat;

template <typename T>
class Mat<T, 2, 2>;

template <typename T>
class Mat<T, 3, 3>;

template <typename T>
class Mat<T, 4, 4>;

// =====================================================================
// c++ matrix specific data type matrices.
// =====================================================================

typedef class Mat<f32, 2, 2>		mat2f;
typedef class Mat<f32, 3, 3>		mat3f;
typedef class Mat<f32, 4, 4>		mat4f;

typedef class Mat<f64, 2, 2>		mat2d;
typedef class Mat<f64, 3, 3>		mat3d;
typedef class Mat<f64, 4, 4>		mat4d;

typedef class Mat<f128, 2, 2>		mat2ld;
typedef class Mat<f128, 3, 3>		mat3ld;
typedef class Mat<f128, 4, 4>		mat4ld;

typedef class Mat<uint32, 2, 2>		mat2ui;
typedef class Mat<uint32, 3, 3>		mat3ui;
typedef class Mat<uint32, 4, 4>		mat4ui;

typedef class Mat<int32, 2, 2>		mat2i;
typedef class Mat<int32, 3, 3>		mat3i;
typedef class Mat<int32, 4, 4>		mat4i;

typedef class Mat<int64, 2, 2>		mat2l;
typedef class Mat<int64, 3, 3>		mat3l;
typedef class Mat<int64, 4, 4>		mat4l;

// =====================================================================
// c++ matrix default types
// =====================================================================

typedef class Mat<f32, 2, 2>		mat2;
typedef class Mat<f32, 3, 3>		mat3;
typedef class Mat<f32, 4, 4>		mat4;

// =====================================================================
// c++ matrix odd types
// =====================================================================

//typedef class Mat<f32, 2, 3>		mat2x3;
//typedef class Mat<f32, 2, 4>		mat2x4;
//typedef class Mat<f32, 3, 2>		mat3x2;
//typedef class Mat<f32, 3, 4>		mat3x4;
//typedef class Mat<f32, 4, 2>		mat4x2;
//typedef class Mat<f32, 4, 3>		mat4x3;