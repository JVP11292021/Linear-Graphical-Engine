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

#ifndef __LGE_UNIQUE_PTR__
#define __LGE_UNIQUE_PTR__

#include "engine_setup.h"
#include "lgeExceptions.hpp"

_LGE_BEGIN_NP_LGE_CORE

template <typename T>
class UniquePtr {
private:
	T* t_ptr;
	size_t size;

	LGE_CUDA_FUNC_DECL void destruct() {
		if (this->t_ptr != nullptr) {
			if (sizeof(*t_ptr) == size)
				delete t_ptr;
			else
				delete[] t_ptr;
		}
	}

public:
	UniquePtr() {
		this->t_ptr = nullptr;
		this->size = 0;
	}

	explicit UniquePtr(T* t_ptr) {
		this->t_ptr = t_ptr;
		this->size = sizeof(T);
	}

	explicit UniquePtr(size_t nBytes, T* t_ptr) {
		this->t_ptr = t_ptr;
		this->size = nBytes;
	}

	UniquePtr(const UniquePtr& ptr) = delete;

	UniquePtr(UniquePtr&& d_ptr) {
		this->destruct();

		this->t_ptr = d_ptr.t_ptr;
		this->size = d_ptr.size;
		d_ptr.t_ptr = nullptr;
	}

	~UniquePtr() {
		this->destruct();
		this->t_ptr = nullptr;
	}

	LGE_CUDA_FUNC_DECL void operator = (UniquePtr&& d_ptr) {
		this->destruct();

		this->t_ptr = d_ptr.t_ptr;
		this->size = d_ptr.size;
		d_ptr.t_ptr = nullptr;
	}

	LGE_CUDA_FUNC_DECL UniquePtr<T>& operator = (UniquePtr<T>& ptr) = delete;

	LGE_CUDA_FUNC_DECL T& operator * () {
		return *(this->t_ptr);
	}

	LGE_CUDA_FUNC_DECL T* operator -> () {
		return this->t_ptr;
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
LGE_CUDA_FUNC_DECL LGE_INLINE UniquePtr<T>& make_unique(T* t_ptr) {
	return UniquePtr<T>(t_ptr);
}

template <typename T>
LGE_CUDA_FUNC_DECL LGE_INLINE UniquePtr<T>& make_unique(size_t nBytes, T* t_ptr) {
	return UniquePtr<T>(nBytes, t_ptr);
}

_LGE_END_NP_LGE_CORE


#endif
