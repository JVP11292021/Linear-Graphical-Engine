
#pragma once

#include "types.h"
#include "vutils.hpp"

// forward declarations

template <typename T, uint32 len>
class Vec;

template <typename T>
class Vec<T, 2>;

template <typename T>
class Vec<T, 3>;

template <typename T>
class Vec<T, 4>;

// =====================================================================
// c++ vector specific data type.
// =====================================================================

typedef class Vec<f32, 2> vec2f;
typedef class Vec<f32, 3> vec3f;
typedef class Vec<f32, 4> vec4f;

typedef class Vec<f64, 2> vec2d;
typedef class Vec<f64, 3> vec3d;
typedef class Vec<f64, 4> vec4d;

typedef class Vec<int32, 2> vec2i;
typedef class Vec<int32, 3> vec3i;
typedef class Vec<int32, 4> vec4i;

typedef class Vec<uint32, 2> vec2ui;
typedef class Vec<uint32, 3> vec3ui;
typedef class Vec<uint32, 4> vec4ui;

typedef class Vec<int64, 2> vec2l;
typedef class Vec<int64, 3> vec3l;
typedef class Vec<int64, 4> vec4l;

// =====================================================================
// c++ vector default types
// =====================================================================

typedef class Vec<f32, 2> vec2;
typedef class Vec<f32, 3> vec3;
typedef class Vec<f32, 4> vec4;