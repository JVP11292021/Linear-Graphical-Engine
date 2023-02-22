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

#ifndef __LGE_EXCEPTIONS__
#define __LGE_EXCEPTIONS__

#include "engine_setup.h"

#include <iostream>
#include <string>

/*Macro to format the exceptions in a more readable and understandable way.*/
#define lgeFORMAT_EXCEPTION(_L, _F, _M) std::string("Exception thrown at: ") + std::to_string(_L) +\
										std::string("\n------------------------------------------\n") + std::string("File: ") + std::string(	 _F) +\
										std::string("\n------------------------------------------\n") + std::string("Info: ") + std::string(	 _M) +\
										std::string("\n------------------------------------------\n")

_LGE_BEGIN_NP_LGE

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class LGE_API LgeException {
protected:
	T* _root;
	uint32 line;
	istr file;

public: 

	/// <summary>
	/// 
	/// </summary>
	LgeException() {
		this->line = 0;
		this->file = "";
		this->_root = static_cast<T*>(this);
	}

	LgeException(uint32 line, istr file) {
		this->line = line;
		this->file = file;
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
	LGE_CUDA_FUNC_DEF LGE_INLINE virtual std::string traceback() = 0;

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
	std::string message;

public:
	/// <summary>
	/// 
	/// </summary>
	Exception();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	Exception(str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	Exception(uint32 line, istr file, str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE std::string traceback()
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
	std::string message;

public:
	/// <summary>
	/// 
	/// </summary>
	ArrayOutOfBounds();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	ArrayOutOfBounds(str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	ArrayOutOfBounds(uint32 line, istr file, str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE std::string traceback()
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
	std::string message;

public:
	/// <summary>
	/// 
	/// </summary>
	NullPtrException();
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	NullPtrException(str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	NullPtrException(uint32 line, istr file, str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE std::string traceback()
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
	std::string message;

public:
	/// <summary>
	/// 
	/// </summary>
	MemoryException();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	MemoryException(str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	MemoryException(uint32 line, istr file, str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE std::string traceback()
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
	std::string message;

public:
	/// <summary>
	/// 
	/// </summary>
	NumberFormatException();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	NumberFormatException(str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	NumberFormatException(uint32 line, istr file, str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE std::string traceback()
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
	std::string message;

public:
	/// <summary>
	/// 
	/// </summary>
	FileSystemException();

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	FileSystemException(str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="msg"></param>
	FileSystemException(uint32 line, istr file, str msg);

	/// <summary>
	/// 
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DEF LGE_INLINE std::string traceback()
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