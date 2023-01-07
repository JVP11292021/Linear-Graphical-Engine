#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "vec.hpp"

#include <ostream>

/*
Quaternion multiplication rules:
- i^2 = j^2 = k^2 = -1 | Does commute
			   _
- ij = -ji = k  |
- jk = -kj = i  | Do not commute
- ki = -ik = j _|
*/

template <typename T>
class Quaternion {
private:
	size_t size;

public:
	union {
		T __scalar;
		T s;
	};

	union {
		Vec<T, 3> __ijk;
		Vec<T, 3> v;
	};

	LMM_FUNC_DECL LMM_CONSTEXPR Quaternion();
	LMM_FUNC_DECL LMM_CONSTEXPR Quaternion(T, const Vec<T, 3>&);
	LMM_FUNC_DECL LMM_CONSTEXPR Quaternion(T, const Vec<T, 4>&);
	LMM_FUNC_DECL LMM_CONSTEXPR Quaternion(T, T, T, T);
	LMM_FUNC_DECL LMM_CONSTEXPR Quaternion(const Quaternion<T>&);

	LMM_FUNC_DECL LMM_INLINE Quaternion<T> operator = (const Quaternion<T>& quat) {
		this->__scalar = quat.__scalar;
		this->__ijk = quat.__ijk;
		this->size = quat.size;
		return *this;
	}

	LMM_FUNC_DECL LMM_INLINE T operator [] (uint32 index) {
		if (index > 3)
			LMM_EXCEPTION("LMM::Exception Quaternion Index out of bounds");
		else if (index == 0)
			return this->__scalar;
		return this->__ijk[index];
	}

	LMM_FUNC_DECL Quaternion<T> operator += (const Quaternion<T>&);
	LMM_FUNC_DECL Quaternion<T> operator -= (const Quaternion<T>&);
	LMM_FUNC_DECL Quaternion<T> operator *= (const Quaternion<T>&);
	LMM_FUNC_DECL Quaternion<T> operator *= (const T);

	LMM_FUNC_DECL Quaternion<T> operator + (const Quaternion<T>&);
	LMM_FUNC_DECL Quaternion<T> operator - (const Quaternion<T>&);
	LMM_FUNC_DECL Quaternion<T> operator * (const Quaternion<T>&);
	LMM_FUNC_DECL Quaternion<T> operator * (const T);

	LMM_FUNC_DECL LMM_INLINE size_t getSize() const { return this->size; }
	LMM_FUNC_DECL LMM_INLINE Vec<T, 3> getVec() const { return this->__ijk; }
	LMM_FUNC_DECL LMM_INLINE T gets() const { return this->__scalar; }

	LMM_FUNC_DECL LMM_INLINE void setVec(const Vec<T, 3>& ijk) { this->__ijk = ijk; }
	LMM_FUNC_DECL LMM_INLINE void sets(T s) { this->__scalar = s; }

};

template <typename T>
LMM_FUNC_DECL LMM_INLINE std::ostream& operator << (std::ostream& out, const Quaternion<T>& quat) {
	return out << "real: " << quat.gets() << " vector(i: " << quat.getVec()[0] << ", j: " << quat.getVec()[1] << ", k: " << quat.getVec()[2] << ")" << "\n";
}

#ifndef LMM_EXTERNAL_TEMPLATE
#include "quat.inl"
#endif