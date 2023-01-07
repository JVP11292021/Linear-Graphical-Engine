//#include "mat.hpp"
//#include <stdio.h>
//
//#pragma once
//
//static const uint32 mat2_N = 2;
//static const uint32 mat3_N = 3;
//static const uint32 mat4_N = 4;
//
//
//// =====================================================================
//// c++ matrix constructors & destructors
//// =====================================================================
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat()
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows * cols * sizeof(T)), totalItems(this->rows * this->cols)
//{
//	for (int r = 0; r < this->rows; r++) 
//		for (int c = 0; c < this->cols; c++) 
//			this->items[r * this->cols + c] = 0;
//}
//
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(T* items)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	for (int r = 0; r < this->rows; r++) 
//		for (int c = 0; c < this->cols; c++) 
//			this->items[r * this->cols + c] = items[r * this->cols + c];
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(T num) 
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	for (int r = 0; r < this->rows; r++) 
//		for (int c = 0; c < this->cols; c++) 
//			this->items[r * this->cols + c] = num;
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(bool id)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	for (int r = 0; r < this->rows; r++) {
//		for (int c = 0; c < this->cols; c++) {
//			if (id == true) {
//				if (r == c)
//					this->items[r * this->cols + c] = 1;
//				else
//					this->items[r * this->cols + c] = 0;
//			}
//			else {
//				this->items[r * this->cols + c] = 0;
//			}
//		}
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(const Mat<T, 2, 2>& m) 
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	for (int r = 0; r < this->rows; r++) {
//		for (int c = 0; c < this->cols; c++) {
//			if (c < mat2_N && r < mat2_N)
//				this->items[r * this->cols + c] = m.items[r * mat2_N + c];
//			else
//				this->items[r * this->cols + c] = 0;
//		}
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(const  Mat<T, 3, 3>& m)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	for (int r = 0; r < this->rows; r++) {
//		for (int c = 0; c < this->cols; c++) {
//			if (c < mat3_N && r < mat3_N)
//				this->items[r * this->cols + c] = m.items[r * mat3_N + c];
//			else
//				this->items[r * this->cols + c] = 0;
//		}
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(const Mat<T, 4, 4>& m)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	for (int r = 0; r < this->rows; r++) {
//		for (int c = 0; c < this->cols; c++) {
//			if (c < mat4_N && r < mat4_N)
//				this->items[r * this->cols + c] = m.items[r * mat4_N + c];
//			else
//				this->items[r * this->cols + c] = 0;
//		}
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(const Mat<T, 2, 3>& m)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	if (this->rows >= mat2_N && this->cols >= mat3_N) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				if (c < mat3_N && r < mat2_N)
//					this->items[r * this->cols + c] = m.items[r * mat3_N + c];
//				else
//					this->items[r * this->cols + c] = 0;
//			}
//		}
//	}
//	else {
//		LMM_EXCEPTION("ERROR::LMM:: Matrix conversion not compatible.");
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(const Mat<T, 2, 4>& m)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	if (this->rows >= mat2_N && this->cols >= mat4_N) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				if (c < mat4_N && r < mat2_N)
//					this->items[r * this->cols + c] = m.items[r * mat4_N + c];
//				else
//					this->items[r * this->cols + c] = 0;
//			}
//		}
//	}
//	else {
//		LMM_EXCEPTION("ERROR::LMM:: Matrix conversion not compatible.");
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(const Mat<T, 3, 2>& m)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	if (this->rows >= mat3_N && this->cols >= mat2_N) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				if (c < mat2_N && r < mat3_N)
//					this->items[r * this->cols + c] = m.items[r * mat2_N + c];
//				else
//					this->items[r * this->cols + c] = 0;
//			}
//		}
//	}
//	else {
//		LMM_EXCEPTION("ERROR::LMM:: Matrix conversion not compatible.");
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(const Mat<T, 3, 4>& m)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	if (this->rows >= mat3_N && this->cols >= mat4_N) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				if (c < mat4_N && r < mat3_N)
//					this->items[r * this->cols + c] = m.items[r * mat4_N + c];
//				else
//					this->items[r * this->cols + c] = 0;
//			}
//		}
//	}
//	else {
//		LMM_EXCEPTION("ERROR::LMM:: Matrix conversion not compatible.");
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(const Mat<T, 4, 2>& m)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	if (this->rows >= mat4_N && this->cols >= mat2_N) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				if (c < mat2_N && r < mat4_N)
//					this->items[r * this->cols + c] = m.items[r * mat2_N + c];
//				else
//					this->items[r * this->cols + c] = 0;
//			}
//		}
//	}
//	else {
//		LMM_EXCEPTION("ERROR::LMM:: Matrix conversion not compatible.");
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_CONSTEXPR Mat<T, R, C>::Mat(const Mat<T, 4, 3>& m)
//	: rows(R), cols(C), items(new T[this->rows * this->cols]), size(rows* cols * sizeof(T)), totalItems(this->rows* this->cols)
//{
//	if (this->rows >= mat4_N && this->cols >= mat3_N) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				if (c < mat3_N && r < mat4_N)
//					this->items[r * this->cols + c] = m.items[r * mat3_N + c];
//				else
//					this->items[r * this->cols + c] = 0;
//			}
//		}
//	}
//	else {
//		LMM_EXCEPTION("ERROR::LMM:: Matrix conversion not compatible.");
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_INLINE
//LMM_FUNC_DECL Mat<T, R, C>::~Mat() {
//	delete[] this->items;
//	this->items = nullptr;
//}
//
//// =====================================================================
//// c++ matrix operator overloaded functions
//// =====================================================================
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL Mat<T, R, C> Mat<T, R, C>::operator = (const Mat& m) {
//	this->rows = m.rows;
//	this->cols = m.cols;
//	this->size = m.size;
//	this->totalItems = m.totalItems;
//
//	for (int r = 0; r < this->rows; r++) {
//		for (int c = 0; c < this->cols; c++) {
//			this->items[r * this->cols + c] = m.items[r * this->cols + c];
//		}
//	}
//
//	return this;
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL Mat<T, R, C> Mat<T, R, C>::operator += (const Mat<T, R, C>& m) {
//	if (this->totalItems == m.totalItems) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				this->items[r * this->cols + c] += m.items[r * this->cols + c];
//			}
//		}
//
//		return this;
//	}
//	else {
//
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL Mat<T, R, C> Mat<T, R, C>::operator -= (const Mat<T, R, C>& m) {
//	if (this->totalItems == m.totalItems) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				this->items[r * this->cols + c] -= m.items[r * this->cols + c];
//			}
//		}
//
//		return this;
//	}
//	else {
//		LMM_EXCEPTION("ERROR::LMM:: Matrices aren't equal.");
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL Mat<T, R, C> Mat<T, R, C>::operator /= (const Mat<T, R, C>& m) {
//	if (this->totalItems == m.totalItems) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				this->items[r * this->cols + c] /= m.items[r * this->cols + c];
//			}
//		}
//
//		return this;
//	}
//	else {
//		LMM_EXCEPTION("ERROR::LMM:: Matrices aren't equal.");
//	}
//}
//
//template <typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL Mat<T, R, C> Mat<T, R, C>::operator *= (const Mat<T, R, C>& m) {
//	if (this->totalItems == m.totalItems) {
//		for (int r = 0; r < this->rows; r++) {
//			for (int c = 0; c < this->cols; c++) {
//				this->items[r * this->cols + c] *= m.items[r * this->cols + c];
//			}
//		}
//
//		return this;
//	}
//	else {
//		LMM_EXCEPTION("ERROR::LMM:: Matrices aren't equal.");
//	}
//}
//
//template<typename T, uint32 R, uint32 C>
//LMM_INLINE
//LMM_FUNC_DECL T Mat<T, R, C>::operator [] (uint32 index) {
//	if (index >= this->totalItems)
//		LMM_EXCEPTION("ERROR::LMM:: Matrix out of bounds.");
//
//	return this->items[index];
//}
//
//// =====================================================================
//// c++ matrix utility functions
//// =====================================================================
//
//template<typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL void Mat<T, R, C>::print() {
//	for (int r = 0; r < this->rows; r++) {
//		for (int c = 0; c < this->cols; c++) {
//			printf("%f ", *(this->items + r * this->cols + c));
//		}
//		printf("\n");
//	}
//	printf("\n");
//}
//
//template<typename T, uint32 R, uint32 C>
//LMM_FUNC_DECL LMM_INLINE void Mat<T, R, C>::copyValueAt(uint32 row, uint32 col, T val) {
//	this->items[row * this->cols + col] = val;
//}
