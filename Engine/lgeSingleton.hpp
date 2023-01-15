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

#ifndef __LGE_SINGLETON__
#define __LGE_SINGLETON__

#include "engine_setup.h"

_LGE_BEGIN_NP_LGE

template<typename T>
class LGE_API Singleton {

protected:
	T* _root;

public:
	Singleton() {
		lgeASSERT(!this->_root);
		this->_root = static_cast<T*>(this);
	}

	Singleton(const Singleton&) = delete;

	~Singleton() {
		lgeASSERT(this->_root);
		this->_root = 0;
	}

	LGE_CUDA_FUNC_DEF static T& getSingleton() {
		lgeASSERT(this->_root);
		return (this->_root);
	}
	LGE_CUDA_FUNC_DEF static T* getSingletonPtr() {
		return this->_root;
	}
};
	
_LGE_END_NP_LGE

#endif