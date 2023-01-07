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

#include "lgeExceptions.hpp"

#include <stdlib.h>

#pragma warning(disable : 4996)

_LGE_BEGIN_NP_LGE

Exception::Exception()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(""))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>("");
#	endif
}

Exception::Exception(char* msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>(msg);
#	endif
}

Exception::~Exception() {
	this->message = NULL;
}

LGE_CUDA_FUNC_DEF char* Exception::traceback() {
	char* result = (char*)calloc(strlen(this->message) + strlen((char*)__LINE__) + 1, sizeof(char));
	if (result != NULL) {
		strcpy(result, this->message);
		strcat(result, (char*)__LINE__);
		return result;
	}
	else
		throw NullPtrException(const_cast<char*>(""));
}

LGE_CUDA_FUNC_DEF void Exception::printException() {
	printf(this->message);
}


ArrayOutOfBounds::ArrayOutOfBounds()
#	ifdef LGE_HAS_INITIALIZER_LIST
		: message(const_cast<char*>(""))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
		this->message = const_cast<char*>("");
#	endif
}

ArrayOutOfBounds::ArrayOutOfBounds(char* msg) 
#	ifdef LGE_HAS_INITIALIZER_LIST
		: message(const_cast<char*>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
		this->message = const_cast<char*>(msg);
#	endif
}

ArrayOutOfBounds::~ArrayOutOfBounds() {
	this->message = NULL;
}

LGE_CUDA_FUNC_DEF char* ArrayOutOfBounds::traceback() {
	char* result = (char*)calloc(strlen(this->message) + strlen((char*)__LINE__) + 1, sizeof(char));
	if (result != NULL) {
		strcpy(result, this->message);
		strcat(result, (char*)__LINE__);
		return result;
	}
	else
		throw NullPtrException(const_cast<char*>(""));
}

LGE_CUDA_FUNC_DEF void ArrayOutOfBounds::printException() {
	printf(this->message);
}


NullPtrException::NullPtrException()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(""))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>("");
#	endif
}

NullPtrException::NullPtrException(char* msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>(msg);
#	endif
}

NullPtrException::~NullPtrException() {
	this->message = NULL;
}

LGE_CUDA_FUNC_DEF char* NullPtrException::traceback() {
	char* result = (char*)calloc(strlen(this->message) + strlen((char*)__LINE__) + 1, sizeof(char));
	if (result != NULL) {
		strcpy(result, this->message);
		strcat(result, (char*)__LINE__);
		return result;
	}
	else
		throw NullPtrException(const_cast<char*>(""));
}

LGE_CUDA_FUNC_DEF void NullPtrException::printException() {
	printf(this->message);
}


MemoryException::MemoryException()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(""))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>("");
#	endif
}

MemoryException::MemoryException(char* msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>(msg);
#	endif
}

MemoryException::~MemoryException() {
	this->message = NULL;
}

LGE_CUDA_FUNC_DEF char* MemoryException::traceback() {
	char* result = (char*)calloc(strlen(this->message) + strlen((char*)__LINE__) + 1, sizeof(char));
	if (result != NULL) {
		strcpy(result, this->message);
		strcat(result, (char*)__LINE__);
		return result;
	}
	else
		throw NullPtrException(const_cast<char*>(""));
}

LGE_CUDA_FUNC_DEF void MemoryException::printException() {
	printf(this->message);
}


NumberFormatException::NumberFormatException()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(""))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>("");
#	endif
}

NumberFormatException::NumberFormatException(char* msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>(msg);
#	endif
}

NumberFormatException::~NumberFormatException() {
	this->message = NULL;
}

LGE_CUDA_FUNC_DEF char* NumberFormatException::traceback() {
	char* result = (char*)calloc(strlen(this->message) + strlen((char*)__LINE__) + 1, sizeof(char));
	if (result != NULL) {
		strcpy(result, this->message);
		strcat(result, (char*)__LINE__);
		return result;
	}
	else
		throw NullPtrException(const_cast<char*>(""));
}

LGE_CUDA_FUNC_DEF void NumberFormatException::printException() {
	printf(this->message);
}


FileSystemException::FileSystemException()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(""))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>("");
#	endif
}

FileSystemException::FileSystemException(char* msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<char*>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<char*>(msg);
#	endif
}

FileSystemException::~FileSystemException() {
	this->message = NULL;
}

LGE_CUDA_FUNC_DEF char* FileSystemException::traceback() {
	char* result = (char*)calloc(strlen(this->message) + strlen((char*)__LINE__) + 1, sizeof(char));
	if (result != NULL) {
		strcpy(result, this->message);
		strcat(result, (char*)__LINE__);
		return result;
	}
	else
		throw NullPtrException(const_cast<char*>(""));
}

LGE_CUDA_FUNC_DEF void FileSystemException::printException() {
	printf(this->message);
}

_LGE_END_NP_LGE