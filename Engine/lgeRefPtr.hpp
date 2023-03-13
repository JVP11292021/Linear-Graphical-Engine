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

#ifndef __LGE_REF_PTR__
#define __LGE_REF_PTR__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE_CORE

template<typename T>
class RefPtr {
public:
    RefPtr() : ptr(nullptr), ref_count(new size_t(0)) {}
    RefPtr(T* p) : ptr(p), ref_count(new size_t(1)) {}

    // Copy constructor
    RefPtr(const RefPtr<T>& other) : ptr(other.ptr), ref_count(other.ref_count) {
        ++(*this->ref_count);
    }

    // Move constructor
    RefPtr(RefPtr<T>&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // Copy assignment operator
    RefPtr<T>& operator=(const RefPtr<T>& other) {
        if (this != &other) {
            if (--(*this->ref_count) == 0) {
                delete this->ptr;
                delete this->ref_count;
            }

            this->ptr = other.ptr;
            this->ref_count = other.ref_count;
            ++(*this->ref_count);
        }
        return *this;
    }

    // Move assignment operator
    RefPtr<T>& operator=(RefPtr<T>&& other) noexcept {
        if (this != &other) {
            if (--(*this->ref_count) == 0) {
                delete this->ptr;
                delete this->ref_count;
            }

            this->ptr = other.ptr;
            this->ref_count = other.ref_count;
            this->other.ptr = nullptr;
            this->other.ref_count = nullptr;
        }
        return *this;
    }

    // Destructor
    ~RefPtr() {
        this->release();
    }

    // Dereference operator
    LGE_CUDA_FUNC_DECL LGE_INLINE T& operator*() const {
        return *this->ptr;
    }

    // Arrow operator
    LGE_CUDA_FUNC_DECL LGE_INLINE T* operator->() const {
        return this->ptr;
    }

    // Boolean operator
    LGE_CUDA_FUNC_DECL LGE_INLINE operator bool() const {
        return this->ptr != nullptr;
    }

    // Getter for the reference count
    LGE_CUDA_FUNC_DECL LGE_INLINE size_t use_count() const {
        return *this->ref_count;
    }

    LGE_CUDA_FUNC_DECL LGE_INLINE T* get() const {
        return this->ptr;
    }

    LGE_CUDA_FUNC_DECL LGE_INLINE T use() const {
        return *this->ptr;
    }

    void reset(T* ptr = nullptr) {
        if (this->ptr != ptr) {
            this->release();
            this->ptr = ptr;
            if (this->ptr) {
                this->ref_count = new size_t(1);
            }
        }
    }

    void reset(const RefPtr& other) {
        this->release();
        this->ptr = other.m_ptr;
        this->ref_count = other.ref_count;
        if (this->ref_count) {
            (*this->ref_count)++;
        }
    }

private:
    LGE_CUDA_FUNC_DECL LGE_INLINE void release() {
        if (--(*this->ref_count) == 0) {
            delete this->ptr;
            delete this->ref_count;
        }

        this->ptr = nullptr;
        this->ref_count = nullptr;
    }

    T* ptr;
    size_t* ref_count;
};

template <typename T>
LGE_CUDA_FUNC_DECL LGE_INLINE 
RefPtr<T>& make_ref(T* ptr = nullptr) {
    return RefPtr<T>(ptr);
}

_LGE_END_NP_LGE_CORE


#endif
