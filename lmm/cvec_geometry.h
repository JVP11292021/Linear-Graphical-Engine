#include "cvec2.h"
#include "cvec3.h"
#include "cvec4.h"
#include "types.h"

#ifndef LMM_VEC_OPP
#define LMM_VEC_OPP

#ifdef __cplusplus
	extern "C" {
#endif
		#ifndef VEC_TYPES
		#define VEC_TYPES
				typedef struct vec2_f32 Vec2f;
				typedef struct vec2_f64 Vec2d;
				typedef struct vec3_f32 Vec3f;
				typedef struct vec3_f64 Vec3d;
				typedef struct vec4_f32 Vec4f;
				typedef struct vec4_f64 Vec4d;

				typedef struct vec2_f32 vec2f;
				typedef struct vec2_f64 vec2d;
				typedef struct vec3_f32 vec3f;
				typedef struct vec3_f64 vec3d;
				typedef struct vec4_f32 vec4f;
				typedef struct vec4_f64 vec4d;
		#endif

		#define UNIT_Vec2f_X {1.0F, 0.0F}
		#define UNIT_Vec2f_Y {0.0F, 1.0F}
		#define UNIT_Vec3f_X {1.0F, 0.0F, 0.0F}
		#define UNIT_Vec3f_Y {0.0F, 1.0F, 0.0F}
		#define UNIT_Vec3f_Z {0.0F, 0.0F, 1.0F}
		#define UNIT_Vec4f_X {1.0F, 0.0F, 0.0F, 0.0F}
		#define UNIT_Vec4f_Y {0.0F, 1.0F, 0.0F, 0.0F}
		#define UNIT_Vec4f_Z {0.0F, 0.0F, 1.0F, 0.0F}

		#define UNIT_Vec2d_X {1.0, 0.0}
		#define UNIT_Vec2d_Y {0.0, 1.0}
		#define UNIT_Vec3d_X {1.0, 0.0, 0.0}
		#define UNIT_Vec3d_Y {0.0, 1.0, 0.0}
		#define UNIT_Vec3d_Z {0.0, 0.0, 1.0}
		#define UNIT_Vec4d_X {1.0, 0.0, 0.0, 0.0}
		#define UNIT_Vec4d_Y {0.0, 1.0, 0.0, 0.0}
		#define UNIT_Vec4d_Z {0.0, 0.0, 1.0, 0.0}

		// =====================================================================
		// Vector arithmatic
		// =====================================================================

		 Vec2f addVec2f( Vec2f a,  Vec2f b);
		 Vec2d addVec2d( Vec2d a,  Vec2d b);
		 Vec3f addVec3f( Vec3f a,  Vec3f b);
		 Vec3d addVec3d( Vec3d a,  Vec3d b);
		 Vec4f addVec4f( Vec4f a,  Vec4f b);
		 Vec4d addVec4d( Vec4d a,  Vec4d b);

		 Vec2f subVec2f( Vec2f a,  Vec2f b);
		 Vec2d subVec2d( Vec2d a,  Vec2d b);
		 Vec3f subVec3f( Vec3f a,  Vec3f b);
		 Vec3d subVec3d( Vec3d a,  Vec3d b);
		 Vec4f subVec4f( Vec4f a,  Vec4f b);
		 Vec4d subVec4d( Vec4d a,  Vec4d b);

		 Vec2f mulVec2f( Vec2f a,  Vec2f b);
		 Vec2d mulVec2d( Vec2d a,  Vec2d b);
		 Vec3f mulVec3f( Vec3f a,  Vec3f b);
		 Vec3d mulVec3d( Vec3d a,  Vec3d b);
		 Vec4f mulVec4f( Vec4f a,  Vec4f b);
		 Vec4d mulVec4d( Vec4d a,  Vec4d b);

		 Vec2f divVec2f( Vec2f a,  Vec2f b);
		 Vec2d divVec2d( Vec2d a,  Vec2d b);
		 Vec3f divVec3f( Vec3f a,  Vec3f b);
		 Vec3d divVec3d( Vec3d a,  Vec3d b);
		 Vec4f divVec4f( Vec4f a,  Vec4f b);
		 Vec4d divVec4d( Vec4d a,  Vec4d b);

		 Vec2f negateVec2f(Vec2f v);
		 Vec2d negateVec2d(Vec2d v);
		 Vec3f negateVec3f(Vec3f v);
		 Vec3d negateVec3d(Vec3d v);
		 Vec4f negateVec4f(Vec4f v);
		 Vec4d negateVec4d(Vec4d v);

		// =====================================================================
		// Vector length calculations
		// =====================================================================

		f32 Vec2fMagnitude( Vec2f v);
		f64 Vec2dMagnitude( Vec2d v);
		f32 Vec3fMagnitude( Vec3f v);
		f64 Vec3dMagnitude( Vec3d v);
		f32 Vec4fMagnitude( Vec4f v);
		f64 Vec4dMagnitude( Vec4d v);

		// =====================================================================
		// Vector s operations
		// =====================================================================

		 Vec2f Vec2fsMul( Vec2f v, f32 s);
		 Vec2d Vec2dsMul( Vec2d v, f64 s);
		 Vec3f Vec3fsMul( Vec3f v, f32 s);
		 Vec3d Vec3dsMul( Vec3d v, f64 s);
		 Vec4f Vec4fsMul( Vec4f v, f32 s);
		 Vec4d Vec4dsMul( Vec4d v, f64 s);

		 Vec2f Vec2fsAdd( Vec2f v, f32 s);
		 Vec2d Vec2dsAdd( Vec2d v, f64 s);
		 Vec3f Vec3fsAdd( Vec3f v, f32 s);
		 Vec3d Vec3dsAdd( Vec3d v, f64 s);
		 Vec4f Vec4fsAdd( Vec4f v, f32 s);
		 Vec4d Vec4dsAdd( Vec4d v, f64 s);

		 Vec2f Vec2fsSub( Vec2f v, f32 s);
		 Vec2d Vec2dsSub( Vec2d v, f64 s);
		 Vec3f Vec3fsSub( Vec3f v, f32 s);
		 Vec3d Vec3dsSub( Vec3d v, f64 s);
		 Vec4f Vec4fsSub( Vec4f v, f32 s);
		 Vec4d Vec4dsSub( Vec4d v, f64 s);

		 Vec2f Vec2fsDiv( Vec2f v, f32 s);
		 Vec2d Vec2dsDiv( Vec2d v, f64 s);
		 Vec3f Vec3fsDiv( Vec3f v, f32 s);
		 Vec3d Vec3dsDiv( Vec3d v, f64 s);
		 Vec4f Vec4fsDiv( Vec4f v, f32 s);
		 Vec4d Vec4dsDiv( Vec4d v, f64 s);

		// =====================================================================
		// Vector dot product
		// =====================================================================
			
		f32 vecfDot(f32 aMagnitude, f32 bMagnitude, f32 angleRad);
		f64 vecdDot(f64 aMagnitude, f64 bMagnitude, f64 angleRad);

		// =====================================================================
		// Vector cross product
		// =====================================================================

		f32 crossUnitf(f32 aMagnitude, f32 bMagnitude, f32 angleRad,  Vec3f unitVec);
		f64 crossUnitd(f64 aMagnitude, f64 bMagnitude, f64 angleRad,  Vec3d unitVec);
		 Vec3f crossVec3fVec3f( Vec3f a,  Vec3f b);
		 Vec3d crossVec3dVec3d( Vec3d a,  Vec3d b);

		// =====================================================================
		// Vector conversions
		// =====================================================================

		 Vec3f Vec2fToVec3f( Vec2f v, f32 z);
		 Vec3d Vec2dToVec3d( Vec2d v, f64 z);
		 Vec4f Vec3fToVec4f( Vec3f v, f32 w);
		 Vec4d Vec3dToVec4d( Vec3d v, f64 w);
		 Vec2f Vec3fToVec2f( Vec3f v);
		 Vec2d Vec3dToVec2d( Vec3d v);
		 Vec3f Vec4fToVec3f( Vec4f v);
		 Vec3d Vec4dToVec3d( Vec4d v);

		// =====================================================================
		// Vector normalization
		// =====================================================================

		 Vec2f normalizeVec2f( Vec2f v);
		 Vec2d normalizeVec2d( Vec2d v);
		 Vec3f normalizeVec3f( Vec3f v);
		 Vec3d normalizeVec3d( Vec3d v);
		 Vec4f normalizeVec4f( Vec4f v);
		 Vec4d normalizeVec4d( Vec4d v);

		// =====================================================================
		// Vector printing
		// =====================================================================

		int32 printVec2f(Vec2f* v);
		int32 printVec2d(Vec2d* v);
		int32 printVec3f(Vec3f* v);
		int32 printVec3d(Vec3d* v);
		int32 printVec4f(Vec4f* v);
		int32 printVec4d(Vec4d* v);

#ifdef __cplusplus
	}
#endif
#endif