#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "vec.hpp"

#include <ostream>

template <typename T>
class Mat<T, 3, 3> {
private:
	uint32 rows;
	uint32 cols;
	size_t size;

public:
	Vec<T, 3> __elem[3];

	LMM_FUNC_DECL LMM_CONSTEXPR Mat();
	LMM_FUNC_DECL LMM_CONSTEXPR Mat(bool);
	LMM_FUNC_DECL LMM_CONSTEXPR Mat(T);
	LMM_FUNC_DECL LMM_CONSTEXPR Mat(const Vec<T, 3>&);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		const Vec<T, 3>&,
		T);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		const Vec<T, 3>&,
		T, T);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		const Vec<T, 3>&,
		const Vec<T, 3>&);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		const Vec<T, 3>&,
		const Vec<T, 3>&,
		T);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		const Vec<T, 3>&,
		const Vec<T, 3>&,
		T, T);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		T, T, T,
		T, T, T,
		T, T, T);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		const Vec<T, 3>&,
		const Vec<T, 3>&,
		const Vec<T, 3>&);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(const Mat<T, 2, 2>&);
	LMM_FUNC_DECL LMM_CONSTEXPR Mat(const Mat<T, 3, 3>&);
	LMM_FUNC_DECL LMM_CONSTEXPR Mat(const Mat<T, 3, 3>&, int32);

	LMM_FUNC_DECL LMM_INLINE Mat<T, 3, 3> operator = (const Mat<T, 3, 3>& m) {
		this->rows = m.rows;
		this->cols = m.cols;
		this->size = m.size;

		this->__elem[0] = m.__elem[0];
		this->__elem[1] = m.__elem[1];
		this->__elem[2] = m.__elem[2];

		return *this;
	}

	LMM_FUNC_DECL LMM_INLINE Mat<T, 3, 3> operator = (const Mat<T, 2, 2>& m) {
		this->rows = 3;
		this->cols = 3;
		this->size = this->rows * this->cols * sizeof(T);

		this->__elem[0] = Vec<T, 4>(m.__elem[0][0], m.__elem[0][1], (T)0, (T)0);
		this->__elem[1] = Vec<T, 4>(m.__elem[1][0], m.__elem[1][1], (T)0, (T)0);
		this->__elem[2] = Vec<T, 4>();

		return *this;
	}

	LMM_FUNC_DECL LMM_INLINE Vec<T, 3>& operator [] (uint32 index) {
		if (index < this->rows)
			return this->__elem[index];
		LMM_EXCEPTION("LMM::Exception Given index was too large");
	}

	LMM_FUNC_DECL LMM_INLINE Vec<T, 3> operator [] (uint32 index) const {
		if (index < this->rows)
			return this->__elem[index];
		LMM_EXCEPTION("LMM::Exception Given index was too large");
	}

	LMM_FUNC_DECL Mat<T, 3, 3> operator += (const Mat<T, 3, 3>&);
	LMM_FUNC_DECL Mat<T, 3, 3> operator -= (const Mat<T, 3, 3>&);
	LMM_FUNC_DECL Mat<T, 3, 3> operator += (const T);
	LMM_FUNC_DECL Mat<T, 3, 3> operator -= (const T);
	LMM_FUNC_DECL Mat<T, 3, 3> operator /= (const T);
	LMM_FUNC_DECL Mat<T, 3, 3> operator *= (const T);

	LMM_FUNC_DECL LMM_INLINE uint32 getRows() const { return this->rows; }
	LMM_FUNC_DECL LMM_INLINE uint32 getCols() const { return this->cols; }
	LMM_FUNC_DECL LMM_INLINE uint32 getSize() const { return this->size; }

	//LMM_FUNC_DECL LMM_INLINE friend std::ostream& operator << (std::ostream&, const Mat<T, 3, 3>&);
};

template <typename T>
LMM_FUNC_DECL LMM_INLINE std::ostream& operator << (std::ostream& out, const Mat<T, 3, 3>& m) {
	for (int32 r = 0; r < m.getRows(); r++) {
		for (int32 c = 0; c < m.getCols(); c++) 
			out << "A" << r + 1 << c + 1 << ": " << m[r][c] << "    ";
		out << "\n";
	}

	return out;
}

#ifndef LMM_EXTERNAL_TEMPLATE
#include "mat3x3.inl"
#endif