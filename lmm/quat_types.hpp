#pragma once

#include "types.h"

template <typename T>
class Quaternion;

// =====================================================================
// c++ quaternion specific data type.
// =====================================================================

typedef Quaternion<int8>		quatc;
typedef Quaternion<int16>		quats;
typedef Quaternion<int32>		quati;
typedef Quaternion<int64>		quatli;

typedef Quaternion<uint8>		quatuc;
typedef Quaternion<uint16>		quatus;
typedef Quaternion<uint32>		quatui;
typedef Quaternion<uint64>		quatuli;

typedef Quaternion<f16>			quatsf;
typedef Quaternion<f32>			quatf;
typedef Quaternion<f64>			quatd;
typedef Quaternion<f128>		quatld;

// =====================================================================
// c++ quaternion default data type.
// =====================================================================

typedef Quaternion<f32>			quat;