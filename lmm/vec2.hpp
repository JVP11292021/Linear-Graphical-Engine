#pragma once

#include "types.h"
#include "lmm_defs.h"
#include "vec.hpp"
#include "vutils.hpp"

#include <ostream>

template <typename T>
class Vec<T, 2> {
private:
	typedef std::size_t vec_size;
	vec_size size;

public:
	T x;
	T y;

	const uint32 vec_len = 2;

	// Vec2 constructors

	LMM_FUNC_DECL LMM_CONSTEXPR Vec();
	LMM_FUNC_DECL LMM_CONSTEXPR Vec(T, T);

	// Vector conversions

	LMM_FUNC_DECL LMM_CONSTEXPR Vec(const Vec<T, 2>&);
	LMM_FUNC_DECL LMM_CONSTEXPR Vec(const Vec<T, 3>&);
	LMM_FUNC_DECL LMM_CONSTEXPR Vec(const Vec<T, 4>&);

	//Vector class operator overloads

	LMM_FUNC_DECL Vec<T, 2> operator += (const Vec<T, 2>&);
	LMM_FUNC_DECL Vec<T, 2> operator -= (const Vec<T, 2>&);
	LMM_FUNC_DECL Vec<T, 2> operator /= (const Vec<T, 2>&);
	LMM_FUNC_DECL Vec<T, 2> operator *= (const Vec<T, 2>&);

	LMM_FUNC_DECL Vec<T, 2> operator += (const T&);
	LMM_FUNC_DECL Vec<T, 2> operator -= (const T&);
	LMM_FUNC_DECL Vec<T, 2> operator /= (const T&);
	LMM_FUNC_DECL Vec<T, 2> operator *= (const T&);

	LMM_FUNC_DECL Vec<T, 2> operator = (const Vec<T, 2>& v) {
		this->x = v.x;
		this->y = v.y;
		this->size = v.size;

		return *this;
	}

	LMM_FUNC_DECL T operator [] (uint32 index) const {
		if (index < this->vec_len)
			if (index == 0)
				return this->x;
			else if (index == 1)
				return this->y;
			else
				LMM_EXCEPTION("ERROR::LMM:: Vector out of bounds.");
	}

	LMM_FUNC_DECL T& operator [] (uint32 index) {
		if (index < this->vec_len)
			if (index == 0)
				return this->x;
			else if (index == 1)
				return this->y;
			else
				LMM_EXCEPTION("ERROR::LMM:: Vector out of bounds.");
	}

	//friend std::ostream& operator << (std::ostream&, const Vec&);
	//friend std::istream& operator >> (std::istream&, const Vec&);

	LMM_FUNC_DECL LMM_INLINE T getX() const { return this->x; }
	LMM_FUNC_DECL LMM_INLINE T getY() const { return this->y; }
	LMM_FUNC_DECL LMM_INLINE vec_size getSize() const { return this->size; }

	LMM_FUNC_DECL LMM_INLINE void setX(T x) { this->x = x; }
	LMM_FUNC_DECL LMM_INLINE void setY(T y) { this->y = y; }
};

template <typename T>
LMM_FUNC_DECL LMM_INLINE std::ostream& operator << (std::ostream& out, const Vec<T, 2>& v) {
	return out << "x: " << v.x << " y: " << v.y << "\n";
}

#ifndef LMM_EXTERNAL_TEMPLATE
#	include "vec2.inl"
#endif