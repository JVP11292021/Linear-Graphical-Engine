#pragma once

#include "lmm_defs.h"
#include "types.h"
#include "vec.hpp"

#include <ostream>

template <typename T>
class Mat<T, 2, 2> {
private:
	uint32 rows;
	uint32 cols;
	size_t size;

public:
	Vec<T, 2> __elem[2];

	LMM_FUNC_DECL LMM_CONSTEXPR Mat();
	LMM_FUNC_DECL LMM_CONSTEXPR Mat(bool);
	LMM_FUNC_DECL LMM_CONSTEXPR Mat(T);
	LMM_FUNC_DECL LMM_CONSTEXPR Mat(const Vec<T, 2>&);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		const Vec<T, 2>&,
		T);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		T, T,
		T, T);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(
		const Vec<T, 2>&,
		const Vec<T, 2>&);

	LMM_FUNC_DECL LMM_CONSTEXPR Mat(const Mat<T, 2, 2>&);

	LMM_FUNC_DECL LMM_INLINE Mat<T, 2, 2> operator = (const Mat<T, 2, 2>& m) {
		this->rows = m.rows;
		this->cols = m.cols;
		this->size = m.size;

		this->__elem[0] = m.__elem[0];
		this->__elem[1] = m.__elem[1];
	}

	LMM_FUNC_DECL LMM_INLINE Vec<T, 2>& operator [] (uint32 index) {
		if (index < this->rows)
			return this->__elem[index];
		LMM_EXCEPTION("LMM::Exception Given index was too large");
	}

	LMM_FUNC_DECL LMM_INLINE Vec<T, 2> operator [] (uint32 index) const {
		if (index < this->rows)
			return this->__elem[index];
		LMM_EXCEPTION("LMM::Exception Given index was too large");
	}

	LMM_FUNC_DECL Mat<T, 2, 2> operator += (const Mat<T, 2, 2>&);
	LMM_FUNC_DECL Mat<T, 2, 2> operator -= (const Mat<T, 2, 2>&);
	LMM_FUNC_DECL Mat<T, 2, 2> operator += (const T);
	LMM_FUNC_DECL Mat<T, 2, 2> operator -= (const T);
	LMM_FUNC_DECL Mat<T, 2, 2> operator /= (const T);
	LMM_FUNC_DECL Mat<T, 2, 2> operator *= (const T);

	LMM_FUNC_DECL LMM_INLINE uint32 getRows() const { return this->rows; }
	LMM_FUNC_DECL LMM_INLINE uint32 getCols() const { return this->cols; }
	LMM_FUNC_DECL LMM_INLINE uint32 getSize() const { return this->size; }

	//LMM_FUNC_DECL LMM_INLINE friend std::ostream& operator << (std::ostream&, const Mat<T, 2, 2>&);
};

template <typename T>
LMM_FUNC_DECL LMM_INLINE std::ostream& operator << (std::ostream& out, const Mat<T, 2, 2>& m) {
	for (int32 r = 0; r < m.getRows(); r++) {
		for (int32 c = 0; c < m.getCols(); c++) 
			out << "A" << r + 1 << c + 1 << ": " << m[r][c] << "    ";
		out << "\n";
	}

	return out;
}

#ifndef LMM_EXTERNAL_TEMPLATE
#include "mat2x2.inl"
#endif