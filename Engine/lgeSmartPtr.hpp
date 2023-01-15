/*
 ________________________________________________________________________________________
| This source code is from the Github repo: Linear Graphical Engine (LGE)                |
|  Created by: JVP11292021 (J. van Polanen)                                              |
|  Started on: 06-01-2023                                                                |
|                                                                                        |
| Copyright (c) Jessy van Polanen                                                        |
|                                                                                        |
| NOTICE:                                                                                |
|   This notice must remain at the top of each file.                                     |
|________________________________________________________________________________________|
*/

#ifndef __LGE_SMART_PTR__
#define __LGE_SMART_PTR__

#include "engine_setup.h"
#include "lgeExceptions.hpp"
#include "lgePtrMath.inl"


_LGE_BEGIN_NP_LGE_CORE


/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class SmartPtr {
private:
	T* t_ptr;
	size_t size;

public:

	SmartPtr() {
		this->t_ptr = nullptr;
		this->size = 0;
	}

	explicit SmartPtr(T* t_ptr)
#	ifdef LGE_HAS_INITIALIZER_LIST
		: t_ptr(t_ptr), size(sizeof(T))
#	endif
	{
#	ifndef LGE_HAS_INITIALIZER_LIST
		this->t_ptr = t_ptr;
		this->size = sizeof(T);
#	endif
	}

	explicit SmartPtr(uint32 nBytes, T* t_ptr)
#	ifdef LGE_HAS_INITIALIZER_LIST
		: size(nBytes)
#	endif
	{
#	ifndef LGE_HAS_INITIALIZER_LIST
		this->t_ptr = t_ptr;
		this->size = nBytes;
#	endif
	}

	SmartPtr(const SmartPtr& sp)
#	ifdef LGE_HAS_INITIALIZER_LIST
		: size(sp.size)
#	endif
	{
#	ifndef LGE_HAS_INITIALIZER_LIST
		this->t_ptr = sp.t_ptr;
		this->size = sp.size;
#	endif
	}

	~SmartPtr() {
		this->destruct(); 
		this->t_ptr = nullptr;
	}
	
	// functions addSize & subSize debugging
	LGE_CUDA_FUNC_DECL LGE_INLINE SmartPtr& addSize(size_t nBytes) {
		this->t_ptr = (T*)add(reinterpret_cast<void*>(this->t_ptr), nBytes);
		this->size += nBytes;

		return *this;
	}

	LGE_CUDA_FUNC_DECL LGE_INLINE SmartPtr& subSize(size_t nBytes) {
		this->t_ptr = (T*)sub(reinterpret_cast<void*>(this->t_ptr), nBytes);
		this->size -= nBytes;

		return *this;
	}

	LGE_CUDA_FUNC_DECL LGE_INLINE void destruct() {
		if (this->t_ptr != nullptr) {
			if (sizeof(*t_ptr) == size)
				delete t_ptr;
			else
				delete[] t_ptr;
		}
	}

	LGE_CUDA_FUNC_DECL LGE_INLINE T* getPtr() {
		return this->t_ptr;
	}

	LGE_CUDA_FUNC_DECL LGE_INLINE size_t getSize() {
		return this->size;
	}

	LGE_CUDA_FUNC_DECL T& operator * () {
		return *(this->t_ptr);
	}

	LGE_CUDA_FUNC_DECL T* operator -> () {
		return this->t_ptr;
	}

	LGE_CUDA_FUNC_DECL SmartPtr<T>& operator = (SmartPtr<T>& ptr) {
		this->t_ptr = ptr.t_ptr;
		this->size = ptr.size;
		return *this;
	}

	LGE_CUDA_FUNC_DECL T& operator [] (uint32 index) {
		if (this->size > sizeof(T))
			return this->t_ptr[index];
		else
			throw MemoryException(const_cast<char*>("LGE::MemoryException\n Pointer is not pointing to an array of data."));
 	}

	LGE_CUDA_FUNC_DECL const T operator [] (uint32 index) const {
		if (this->size < sizeof(T))
			return this->t_ptr[index];
		else
			throw MemoryException(const_cast<char*>("LGE::MemoryException\n Pointer is not pointing to an array of data."));
	}
};

template <typename T>
LGE_CUDA_FUNC_DECL LGE_INLINE SmartPtr<T>& make_smart(size_t size, T* ptr) {
	return SmartPtr<T>(size, ptr);
}

template <typename T>
LGE_CUDA_FUNC_DECL LGE_INLINE SmartPtr<T>& make_smart(T* ptr) {
	return SmartPtr<T>(ptr);
}

_LGE_END_NP_LGE_CORE

#endif