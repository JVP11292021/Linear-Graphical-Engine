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

_LGE_BEGIN_NP_LGE_CORE

template<typename T>
class UniquePtr {
public:
    explicit UniquePtr(T* ptr = nullptr) : this->ptr(ptr) {}

    ~UniquePtr() {
        reset();
    }

    LGE_CLS_NON_COPIABLE(UniquePtr)

    UniquePtr(UniquePtr&& other) {
        this->ptr = other.this->ptr;
        other.this->ptr = nullptr;
    }

    UniquePtr& operator=(UniquePtr&& other) {
        if (this != &other) {
            reset();
            this->ptr = other.this->ptr;
            other.this->ptr = nullptr;
        }
        return *this;
    }

    LGE_CUDA_FUNC_DECL LGE_INLINE T& operator*() const {
        return *this->ptr;
    }

    LGE_CUDA_FUNC_DECL LGE_INLINE T* operator->() const {
        return this->ptr;
    }

    LGE_CUDA_FUNC_DECL LGE_INLINE T* get() const {
        return this->ptr;
    }

    LGE_CUDA_FUNC_DECL LGE_INLINE explicit operator bool() const {
        return this->ptr != nullptr;
    }

    LGE_CUDA_FUNC_DECL LGE_INLINE void reset(T* ptr = nullptr) {
        if (this->ptr != nullptr) {
            delete this->ptr;
        }
        this->ptr = ptr;
    }

private:
    T* ptr;
};

template <typename T>
LGE_CUDA_FUNC_DECL LGE_INLINE 
UniquePtr<T>& make_unique(T* t_ptr = nullptr) {
    return UniquePtr<T>(t_ptr);
}

_LGE_END_NP_LGE_CORE


#endif
