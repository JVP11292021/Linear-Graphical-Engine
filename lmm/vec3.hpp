#pragma once

#include "types.h"
#include "lmm_defs.h"
#include "vec.hpp"
#include "vutils.hpp"

#include <ostream>

template <typename T>
class Vec<T, 3> {
private:
	typedef std::size_t vec_size;
	vec_size size;

public:
	union {
		T x;
		T r;
	};

	union {
		T y;
		T g;
	};

	union {
		T z;
		T b;
	};

	const uint32 vec_len = 3;

	// Vec2 constructors

	LMM_FUNC_DECL LMM_CONSTEXPR Vec();
	LMM_FUNC_DECL LMM_CONSTEXPR Vec(T, T);
	LMM_FUNC_DECL LMM_CONSTEXPR Vec(T, T, T);

	// Vector conversions

	LMM_FUNC_DECL LMM_CONSTEXPR Vec(const Vec<T, 2>&);
	LMM_FUNC_DECL LMM_CONSTEXPR Vec(const Vec<T, 2>&, T);
	LMM_FUNC_DECL LMM_CONSTEXPR Vec(const Vec<T, 3>&);
	LMM_FUNC_DECL LMM_CONSTEXPR Vec(const Vec<T, 4>&);

	//Vector class operator overloads

	LMM_FUNC_DECL Vec<T, 3> operator += (const Vec<T, 3>&);
	LMM_FUNC_DECL Vec<T, 3> operator -= (const Vec<T, 3>&);
	LMM_FUNC_DECL Vec<T, 3> operator /= (const Vec<T, 3>&);
	LMM_FUNC_DECL Vec<T, 3> operator *= (const Vec<T, 3>&);
	LMM_FUNC_DECL Vec<T, 3> operator += (const Vec<T, 2>&);
	LMM_FUNC_DECL Vec<T, 3> operator -= (const Vec<T, 2>&);
	LMM_FUNC_DECL Vec<T, 3> operator /= (const Vec<T, 2>&);
	LMM_FUNC_DECL Vec<T, 3> operator *= (const Vec<T, 2>&);

	LMM_FUNC_DECL Vec<T, 3> operator += (const T&);
	LMM_FUNC_DECL Vec<T, 3> operator -= (const T&);
	LMM_FUNC_DECL Vec<T, 3> operator /= (const T&);
	LMM_FUNC_DECL Vec<T, 3> operator *= (const T&);

	LMM_FUNC_DECL Vec<T, 3> operator = (const Vec<T, 3>& v) {
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->size = v.size;

		return *this;
	}

	LMM_FUNC_DECL T operator [] (uint32 index) const {
		if (index < this->vec_len)
			if (index == 0)
				return this->x;
			else if (index == 1)
				return this->y;
			else if (index == 2)
				return this->z;
			else
				LMM_EXCEPTION("ERROR::LMM:: Vector out of bounds.");
	}

	LMM_FUNC_DECL T& operator [] (uint32 index) {
		if (index < this->vec_len)
			if (index == 0)
				return this->x;
			else if (index == 1)
				return this->y;
			else if (index == 2)
				return this->z;
			else
				LMM_EXCEPTION("ERROR::LMM:: Vector out of bounds.");
	}

	//friend std::ostream& operator << (std::ostream&, const Vec&);
	//friend std::istream& operator >> (std::istream&, const Vec&);

	LMM_FUNC_DECL LMM_INLINE T getX() const { return this->x; }
	LMM_FUNC_DECL LMM_INLINE T getY() const { return this->y; }
	LMM_FUNC_DECL LMM_INLINE T getZ() const { return this->z; }
	LMM_FUNC_DECL LMM_INLINE vec_size getSize() const { return this->size; }

	LMM_FUNC_DECL LMM_INLINE void setX(T x) { this->x = x; }
	LMM_FUNC_DECL LMM_INLINE void setY(T y) { this->y = y; }
	LMM_FUNC_DECL LMM_INLINE void setZ(T z) { this->z = z; }
};

template <typename T>
LMM_FUNC_DECL LMM_INLINE std::ostream& operator << (std::ostream& out, const Vec<T, 3>& v) {
	return out << "x: " << v.x << " y: " << v.y << " z: " << v.z << "\n";
}

#ifndef LMM_EXTERNAL_TEMPLATE
#	include "vec3.inl"
#endif
