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

#include "lgeExceptions.hpp"

#include <stdlib.h>

#pragma warning(disable : 4996)

_LGE_BEGIN_NP_LGE

Exception::Exception()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message("")
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = "";
#	endif
}

Exception::Exception(str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

Exception::Exception(uint32 line, istr file, str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: LgeException(line, file), message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

LGE_CUDA_FUNC_DEF std::string Exception::traceback() {
	return lgeFORMAT_EXCEPTION(this->line, this->file, this->message);
}

LGE_CUDA_FUNC_DEF void Exception::printException() {
	std::cout << this->message << "\n";
}


ArrayOutOfBounds::ArrayOutOfBounds()
#	ifdef LGE_HAS_INITIALIZER_LIST
		: message("")
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
		this->message = "";
#	endif
}

ArrayOutOfBounds::ArrayOutOfBounds(str msg) 
#	ifdef LGE_HAS_INITIALIZER_LIST
		: message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
		this->message = const_cast<str>(msg);
#	endif
}

ArrayOutOfBounds::ArrayOutOfBounds(uint32 line, istr file, str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: LgeException(line, file), message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

LGE_CUDA_FUNC_DEF std::string ArrayOutOfBounds::traceback() {
	return lgeFORMAT_EXCEPTION(this->line, this->file, this->message);
}

LGE_CUDA_FUNC_DEF void ArrayOutOfBounds::printException() {
	std::cout << this->message << "\n";
}


NullPtrException::NullPtrException()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message("")
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = "";
#	endif
}

NullPtrException::NullPtrException(str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

NullPtrException::NullPtrException(uint32 line, istr file, str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: LgeException(line, file), message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

LGE_CUDA_FUNC_DEF std::string NullPtrException::traceback() {
	return lgeFORMAT_EXCEPTION(this->line, this->file, this->message);
}

LGE_CUDA_FUNC_DEF void NullPtrException::printException() {
	std::cout << this->message << "\n";
}


MemoryException::MemoryException()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message("")
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = "";
#	endif
}

MemoryException::MemoryException(str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

MemoryException::MemoryException(uint32 line, istr file, str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: LgeException(line, file), message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

LGE_CUDA_FUNC_DEF std::string MemoryException::traceback() {
	return lgeFORMAT_EXCEPTION(this->line, this->file, this->message);
}

LGE_CUDA_FUNC_DEF void MemoryException::printException() {
	std::cout << this->message << "\n";
}


NumberFormatException::NumberFormatException()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message("")
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = "";
#	endif
}

NumberFormatException::NumberFormatException(str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

NumberFormatException::NumberFormatException(uint32 line, istr file, str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: LgeException(line, file), message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

LGE_CUDA_FUNC_DEF std::string NumberFormatException::traceback() {
	return lgeFORMAT_EXCEPTION(this->line, this->file, this->message);
}

LGE_CUDA_FUNC_DEF void NumberFormatException::printException() {
	std::cout << this->message << "\n";
}


FileSystemException::FileSystemException()
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message("")
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = "";
#	endif
}

FileSystemException::FileSystemException(str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

FileSystemException::FileSystemException(uint32 line, istr file, str msg)
#	ifdef LGE_HAS_INITIALIZER_LIST
	: LgeException(line, file), message(const_cast<str>(msg))
#	endif
{
#	ifndef LGE_HAS_INITIALIZER_LIST
	this->message = const_cast<str>(msg);
#	endif
}

LGE_CUDA_FUNC_DEF std::string FileSystemException::traceback() {
	return lgeFORMAT_EXCEPTION(this->line, this->file, this->message);
}

LGE_CUDA_FUNC_DEF void FileSystemException::printException() {
	std::cout << this->message << "\n";
}

_LGE_END_NP_LGE