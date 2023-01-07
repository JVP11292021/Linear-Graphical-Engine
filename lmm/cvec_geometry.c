#include "cvec_geometry.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// =====================================================================
// Vector arithmatic
// =====================================================================

 Vec2f addVec2f( Vec2f a,  Vec2f b) {
	return ( Vec2f) { a.x + b.x, a.y + b.y };
}

 Vec2d addVec2d( Vec2d a,  Vec2d b) {
	return ( Vec2d) { a.x + b.x, a.y + b.y };
}
	
 Vec3f addVec3f( Vec3f a,  Vec3f b) {
	return ( Vec3f) { a.x + b.x, a.y + b.y, a.z + b.z };
}
	
 Vec3d addVec3d( Vec3d a,  Vec3d b) {
	return ( Vec3d) { a.x + b.x, a.y + b.y, a.z + b.z };
}

 Vec4f addVec4f( Vec4f a,  Vec4f b) {
	return ( Vec4f) { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

 Vec4d addVec4d( Vec4d a,  Vec4d b) {
	return ( Vec4d) { a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}
														  													  
 Vec2f subVec2f( Vec2f a,  Vec2f b) {
	return ( Vec2f) { a.x - b.x, a.y - b.y };
}
														  
 Vec2d subVec2d( Vec2d a,  Vec2d b) {
	return ( Vec2d) { a.x - b.x, a.y - b.y };
}
														  
 Vec3f subVec3f( Vec3f a,  Vec3f b) {
	return ( Vec3f) { a.x - b.x, a.y - b.y, a.z - b.z };
}

 Vec3d subVec3d( Vec3d a,  Vec3d b) {
	return ( Vec3d) { a.x - b.x, a.y - b.y, a.z - b.z };
}											  

 Vec4f subVec4f( Vec4f a,  Vec4f b) {
	return ( Vec4f) { a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}
														  
 Vec4d subVec4d( Vec4d a,  Vec4d b) {
	return ( Vec4d) { a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w };
}

 Vec2f mulVec2f( Vec2f a,  Vec2f b) {
	return ( Vec2f) { a.x * b.x, a.y * b.y };
}

 Vec2d mulVec2d( Vec2d a,  Vec2d b) {
	return ( Vec2d) { a.x * b.x, a.y * b.y };
}

 Vec3f mulVec3f( Vec3f a,  Vec3f b) {
	return ( Vec3f) { a.x * b.x, a.y * b.y, a.z * b.z };
}

 Vec3d mulVec3d( Vec3d a,  Vec3d b) {
	return ( Vec3d) { a.x * b.x, a.y * b.y, a.z * b.z };
}

 Vec4f mulVec4f( Vec4f a,  Vec4f b) {
	return ( Vec4f) { a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}

 Vec4d mulVec4d( Vec4d a,  Vec4d b) {
	return ( Vec4d) { a.x * b.x, a.y * b.y, a.z * b.z, a.w * b.w };
}

 Vec2f divVec2f( Vec2f a,  Vec2f b) {
	return ( Vec2f) {
		(a.x / b.x),
		(a.y / b.y)
	};
}

 Vec2d divVec2d( Vec2d a,  Vec2d b) {
	return ( Vec2d) {
		(a.x / b.x),
		(a.y / b.y)
	};
}

 Vec3f divVec3f( Vec3f a,  Vec3f b) {
	return ( Vec3f) {
		(a.x / b.x),
		(a.y / b.y),
		(a.z / b.z)
	};
}

 Vec3d divVec3d( Vec3d a,  Vec3d b) {
	return ( Vec3d) {
		(a.x / b.x),
		(a.y / b.y),
		(a.z / b.z)
	};
}

 Vec4f divVec4f( Vec4f a,  Vec4f b) {
	return ( Vec4f) { 
		(a.x / b.x),
		(a.y / b.y),
		(a.z / b.z),
		(a.w / b.w)
	};
}

 Vec4d divVec4d( Vec4d a,  Vec4d b) {
	return ( Vec4d) { 
		(a.x / b.x),
		(a.y / b.y),
		(a.z / b.z),
		(a.w / b.w)
	};
}


 Vec2f negateVec2f(Vec2f v) {
	 return (Vec2f) {
		 -v.x,
			 -v.y
	 };
 }

 Vec2d negateVec2d(Vec2d v) {
	 return (Vec2d) {
		 -v.x,
			 -v.y
	 };
 }

 Vec3f negateVec3f(Vec3f v) {
	 return (Vec3f) {
		 -v.x,
			 -v.y,
			 -v.z
	 };
 }

 Vec3d negateVec3d(Vec3d v) {
	 return (Vec3d) {
		 -v.x,
			 -v.y,
			 -v.z
	 };
 }

 Vec4f negateVec4f(Vec4f v) {
	 return (Vec4f) {
		 -v.x,
			 -v.y,
			 -v.z,
			 -v.w
	 };
 }

 Vec4d negateVec4d(Vec4d v) {
	 return (Vec4d) {
		 -v.x,
			 -v.y,
			 -v.z,
			 -v.w
	 };
 }

// =====================================================================
// Vector length calculations
// =====================================================================

f32 Vec2fMagnitude( Vec2f v) {
	return (f32)sqrt((f64)(v.x) * v.x + (f64)(v.y) * v.y);
}

f64 Vec2dMagnitude( Vec2d v) {
	return sqrt((v.x) * v.x + (v.y) * v.y);
}

f32 Vec3fMagnitude( Vec3f v) {
	return (f32)sqrt((f64)(v.x) * v.x + (f64)(v.y) * v.y + (f64)(v.z) * v.z);
}

f64 Vec3dMagnitude( Vec3d v) {
	return sqrt((v.x) * v.x + (v.y) * v.y + (v.z) * v.z);
}

f32 Vec4fMagnitude( Vec4f v) {
	return (f32)sqrt((f64)(v.x) * v.x + (f64)(v.y) * v.y + (f64)(v.z) * v.z + (f64)(v.w) * v.w);

}

f64 Vec4dMagnitude( Vec4d v) {
	return sqrt((v.x) * v.x + (v.y) * v.y + (v.z) * v.z + (v.w) * v.w);
}

// =====================================================================
// Vector s operations
// =====================================================================

 Vec2f Vec2fsMul( Vec2f v, f32 s) {
	return ( Vec2f) { v.x * s, v.y * s };
}

 Vec2d Vec2dsMul( Vec2d v, f64 s) {
	return ( Vec2d) { v.x * s, v.y * s };
}

 Vec3f Vec3fsMul( Vec3f v, f32 s) {
	return ( Vec3f) { v.x * s, v.y * s, v.z * s };
}

 Vec3d Vec3dsMul( Vec3d v, f64 s) {
	return ( Vec3d) { v.x * s, v.y * s, v.z * s};
}

 Vec4f Vec4fsMul( Vec4f v, f32 s) {
	return ( Vec4f) { v.x* s, v.y* s, v.z* s, v.w * s };
}

 Vec4d Vec4dsMul( Vec4d v, f64 s) {
	return ( Vec4d) { v.x* s, v.y* s, v.z* s, v.w * s };
}

 Vec2f Vec2fsAdd( Vec2f v, f32 s) {
	return ( Vec2f) { v.x + s, v.y + s };
}

 Vec2d Vec2dsAdd( Vec2d v, f64 s) {
	return ( Vec2d) { v.x + s, v.y + s };
}

 Vec3f Vec3fsAdd( Vec3f v, f32 s) {
	return ( Vec3f) { v.x + s, v.y + s, v.z + s };
}

 Vec3d Vec3dsAdd( Vec3d v, f64 s) {
	return ( Vec3d) { v.x + s, v.y + s, v.z + s };
}

 Vec4f Vec4fsAdd( Vec4f v, f32 s) {
	return ( Vec4f) { v.x + s, v.y + s, v.z + s, v.w + s };
}

 Vec4d Vec4dsAdd( Vec4d v, f64 s) {
	return ( Vec4d) { v.x + s, v.y + s, v.z + s, v.w + s };
}

 Vec2f Vec2fsSub( Vec2f v, f32 s) {
	return ( Vec2f) { v.x - s, v.y - s };
}

 Vec2d Vec2dsSub( Vec2d v, f64 s) {
	return ( Vec2d) { v.x - s, v.y - s };
}

 Vec3f Vec3fsSub( Vec3f v, f32 s) {
	return ( Vec3f) { v.x - s, v.y - s, v.z - s };
}

 Vec3d Vec3dsSub( Vec3d v, f64 s) {
	return ( Vec3d) { v.x - s, v.y - s, v.z - s };
}

 Vec4f Vec4fsSub( Vec4f v, f32 s) {
	return ( Vec4f) { v.x + s, v.y + s, v.z + s, v.w + s };
}

 Vec4d Vec4dsSub( Vec4d v, f64 s) {
	return ( Vec4d) { v.x - s, v.y - s, v.z - s, v.w - s };
}

 Vec2f Vec2fsDiv( Vec2f v, f32 s) {
	return ( Vec2f) { v.x / s, v.y / s };
}

 Vec2d Vec2dsDiv( Vec2d v, f64 s) {
	return ( Vec2d) { v.x / s, v.y / s };
}

 Vec3f Vec3fsDiv( Vec3f v, f32 s) {
	return ( Vec3f) { v.x / s, v.y / s, v.z / s };
}

 Vec3d Vec3dsDiv( Vec3d v, f64 s) {
	return ( Vec3d) { v.x / s, v.y / s, v.z / s };
}

 Vec4f Vec4fsDiv( Vec4f v, f32 s) {
	return ( Vec4f) { v.x / s, v.y / s, v.z / s, v.w / s };
}

 Vec4d Vec4dsDiv( Vec4d v, f64 s) {
	return ( Vec4d) { v.x / s, v.y / s, v.z / s, v.w / s };
}

// =====================================================================
// Vector dot product
// =====================================================================

f32 vecfDot(f32 aMagnitude, f32 bMagnitude, f32 angleRad) {
	return (f32)aMagnitude * bMagnitude * cos(angleRad);
}

f64 vecdDot(f64 aMagnitude, f64 bMagnitude, f64 angleRad) {
	return aMagnitude * bMagnitude * cos(angleRad);
}

// =====================================================================
// Vector cross product
// =====================================================================

f32 crossUnitf(f32 aMagnitude, f32 bMagnitude, f32 angleRad,  Vec3f unitVec) {
	return aMagnitude * bMagnitude * sin(angleRad) * Vec3fMagnitude(unitVec);
} 

f64 crossUnitd(f64 aMagnitude, f64 bMagnitude, f64 angleRad,  Vec3d unitVec) {
	return aMagnitude * bMagnitude * sin(angleRad) * Vec3dMagnitude(unitVec);
}

 Vec3f crossVec3fVec3f( Vec3f a,  Vec3f b) {
	return ( Vec3f) {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
}

 Vec3d crossVec3dVec3d( Vec3d a,  Vec3d b) {
	return ( Vec3d) {
		(a.y * b.z) - (a.z * b.y),
		(a.z * b.x) - (a.x * b.z),
		(a.x * b.y) - (a.y * b.x)
	};
}

// =====================================================================
// Vector conversions
// =====================================================================

 Vec3f Vec2fToVec3f( Vec2f v, f32 z) {
	return ( Vec3f) { v.x, v.y, z };
}

 Vec3d Vec2dToVec3d( Vec2d v, f64 z) {
	return ( Vec3d) { v.x, v.y, z };
}

 Vec4f Vec3fToVec4f( Vec3f v, f32 w) {
	return ( Vec4f) { v.x, v.y, v.z, w };
}

 Vec4d Vec3dToVec4d( Vec3d v, f64 w) {
	return ( Vec4d) { v.x, v.y, v.z, w };
}

 Vec2f Vec3fToVec2f( Vec3f v) {
	return ( Vec2f) { v.x, v.y };
}

 Vec2d Vec3dToVec2d( Vec3d v) {
	return ( Vec2d) { v.x, v.y };
}

 Vec3f Vec4fToVec3f( Vec4f v) {
	return ( Vec3f) { v.x, v.y, v.z };
}

 Vec3d Vec4dToVec3d( Vec4d v) {
	return ( Vec3d) { v.x, v.y, v.z };
}

// =====================================================================
// Vector normalization
// =====================================================================

 Vec2f normalizeVec2f( Vec2f v) {
	return ( Vec2f) {
		(v.x / Vec2fMagnitude(v)),
		(v.y / Vec2fMagnitude(v))
	};
}

 Vec2d normalizeVec2d( Vec2d v) {
	return ( Vec2d) {
		(v.x / Vec2dMagnitude(v)),
		(v.y / Vec2dMagnitude(v))
	};
}

 Vec3f normalizeVec3f( Vec3f v) {
	return ( Vec3f) {
		(v.x / Vec3fMagnitude(v)),
		(v.y / Vec3fMagnitude(v)),
		(v.z / Vec3fMagnitude(v))
	};
}

 Vec3d normalizeVec3d( Vec3d v) {
	return ( Vec3d) {
		(v.x / Vec3dMagnitude(v)),
		(v.y / Vec3dMagnitude(v)),
		(v.z / Vec3dMagnitude(v))
	};
}

 Vec4f normalizeVec4f( Vec4f v) {
	return ( Vec4f) {
		(v.x / Vec4fMagnitude(v)),
		(v.y / Vec4fMagnitude(v)),
		(v.z / Vec4fMagnitude(v)),
		0.0
	};
}

 Vec4d normalizeVec4d( Vec4d v) {
	return ( Vec4d) {
		(v.x / Vec4dMagnitude(v)),
		(v.y / Vec4dMagnitude(v)),
		(v.z / Vec4dMagnitude(v)),
		0.0
	};
}

 // =====================================================================
 // Vector printing
 // =====================================================================

int32 printVec2f(Vec2f* v) {
	return printf("x: %f, y: %f\n", v->x, v->y);
}

int32 printVec2d(Vec2d* v) {
	return printf("x: %f, y: %f\n", v->x, v->y);
}

int32 printVec3f(Vec3f* v) {
	return printf("x: %f, y: %f, z: %f\n", v->x, v->y, v->z);
}

int32 printVec3d(Vec3d* v) {
	return printf("x: %f, y: %f, z: %f\n", v->x, v->y, v->z);
}

int32 printVec4f(Vec4f* v) {
	return printf("x: %f, y: %f, z: %f, w: %f\n", v->x, v->y, v->z, v->w);
}

int32 printVec4d(Vec4d* v) {
	return printf("x: %f, y: %f, z: %f, w: %f\n", v->x, v->y, v->z, v->w);
}

