//		*****************************************************************************************
//		* This source code is from the Github repo: Linear Graphical Engine (LGE)				*
//		*	Created by: JVP11292021 (J. van Polanen)											*
//		*	Started on: 06-01-2023																*
//		*																						*
//		* Copyright (c) Jessy van Polanen														*
//		*																						*
//		* NOTICE:																				*
//		*	This notice must remain at the top of each file, any alterations to this notice		*
//		*	strictly breaks the license the user aggreed upon when using this software.			*
//		*****************************************************************************************

#ifndef __LGE_EXCEPTIONS__
#define __LGE_EXCEPTIONS__

#include "engine_setup.h"

#include <exception>
#include <assert.h>
#include <stdio.h>

_LGE_BEGIN_NP_LGE

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class LGE_API LgeException {
protected:
	T* _root;

public: 

	/// <summary>
	/// 
	/// </summary>
	LgeException() {
		this->_root = static_cast<T*>(this);
	}

	~LgeException() {
		this->_root = 0;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF static T& getException() {
		lgeASSERT(this->_root);
		return (this->_root);
	}

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF static T* getExceptionPtr() {
		return this->_root;
	}

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE virtual char* traceback() = 0;

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE virtual void printException() {
		this->_root->printException();
	}

};

/// <summary>
/// 
/// </summary>
class LGE_API Exception : public LgeException<Exception> {
private:
	char* message;

public:
	/// <summary>
	/// 
	/// </summary>
	Exception();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	Exception(char* msg);

	~Exception();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE char* traceback()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE void printException()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif
};

/// <summary>
/// 
/// </summary>
class LGE_API ArrayOutOfBounds : public LgeException<ArrayOutOfBounds> {
private:
	char* message;

public:
	/// <summary>
	/// 
	/// </summary>
	ArrayOutOfBounds();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	ArrayOutOfBounds(char* msg);

	~ArrayOutOfBounds();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE char* traceback()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE void printException()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif
};

/// <summary>
/// 
/// </summary>
class LGE_API NullPtrException : public LgeException<NullPtrException> {
private:
	char* message;

public:
	/// <summary>
	/// 
	/// </summary>
	NullPtrException();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	NullPtrException(char* msg);

	~NullPtrException();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE char* traceback()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE void printException()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif
};

/// <summary>
/// 
/// </summary>
class LGE_API MemoryException : public LgeException<MemoryException> {
private:
	char* message;

public:
	/// <summary>
	/// 
	/// </summary>
	MemoryException();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	MemoryException(char* msg);

	~MemoryException();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE char* traceback()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE void printException()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif
};


/// <summary>
/// 
/// </summary>
class LGE_API NumberFormatException : public LgeException<NumberFormatException> {
private:
	char* message;

public:
	/// <summary>
	/// 
	/// </summary>
	NumberFormatException();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	NumberFormatException(char* msg);

	~NumberFormatException();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE char* traceback()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE void printException()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif
};


/// <summary>
/// 
/// </summary>
class LGE_API FileSystemException : public LgeException<FileSystemException> {
private:
	char* message;

public:
	/// <summary>
	/// 
	/// </summary>
	FileSystemException();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	FileSystemException(char* msg);

	~FileSystemException();

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE char* traceback()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE void printException()
#	ifdef LGE_HAS_OVERRIDE
		override;
#	else
		;
#	endif
};

_LGE_END_NP_LGE

#endif