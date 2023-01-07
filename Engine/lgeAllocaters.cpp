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

#include "lgeAllocaters.hpp"
#include "lgePtrMath.inl"

_LGE_BEGIN_NP_LGE_CORE

		// =====================================================================
		// Stackallocater source code
		// =====================================================================

StackAllocater::StackAllocater()
	: IAllocater()
{
	this->_used_memory = 0;
	this->_alignment = NULL;
	this->marker = 0;
}

StackAllocater::StackAllocater(uint32 nBytes)
	: IAllocater(nBytes)
{
	this->_used_memory = nBytes;
	this->_alignment = NULL;
	this->marker = 0;
}

StackAllocater::StackAllocater(uint32 nBytes, uint8 alignment) 
	: IAllocater(nBytes, malloc(nBytes))
{
	this->_used_memory = nBytes;
	this->_alignment = alignment;
	this->marker = 0;
}

StackAllocater::StackAllocater(uint32 nBytes, void* start_pos) 
	: IAllocater(nBytes, start_pos)
{
	this->_used_memory = nBytes;
	this->_alignment = 1;
	this->marker = 0;
}

LGE_CUDA_FUNC_DECL void* StackAllocater::alloc(uint32 nBytes) {
	void* rawMem = malloc(nBytes);
	if (!isAligned(rawMem, this->_alignment)) throw MemoryException(const_cast<char*>("LGE::MemoryException\n Memory block is not aligned."));
	this->stack[((uint32)this->marker++)/4] = rawMem;
	this->_num_allocations++;
	this->_used_memory += nBytes;
	return rawMem;
}

LGE_CUDA_FUNC_DECL void* StackAllocater::alloc(uint32 nBytes, uint8 alignment) {
	this->_alignment = alignment;
	void* rawMem = malloc(nBytes);
	this->stack[(uint32)this->marker++] = rawMem;
	this->_num_allocations++;
	this->_used_memory += nBytes;
	return rawMem;
}

LGE_CUDA_FUNC_DECL StackAllocater::Marker StackAllocater::getMarker() {
	return this->marker;
}

LGE_CUDA_FUNC_DECL void StackAllocater::freeToMarker(Marker marker) {
	for (uint32 i = (uint32)this->marker; i > (uint32)marker; i--) {
		free(this->stack[i]);
		this->stack[i] = nullptr;
		this->stack.pop();
		this->_num_allocations--;
	}
}

LGE_CUDA_FUNC_DECL void StackAllocater::clear() {
	for (int32 i = this->stack.top; i > 0; i--) {
		free(this->stack[i]);
		this->stack[i] = nullptr;
		this->stack.pop();
		this->_num_allocations--;
	}
	this->_used_memory = 0;
}

LGE_CUDA_FUNC_DECL void* StackAllocater::operator [] (uint32 index) const {
	return this->stack[index];
}

LGE_CUDA_FUNC_DECL void*& StackAllocater::operator [] (uint32 index) {
	return this->stack[index];
}

// =====================================================================
// Double buffered allocater source code
// =====================================================================

DoubleBufferedAllocater::DoubleBufferedAllocater() 
	: IAllocater()
{
	this->stallocater = StackAllocater();
	this->currStack = 0;
}

DoubleBufferedAllocater::DoubleBufferedAllocater(uint32 nBytes) 
	: IAllocater(nBytes)
{
	this->stallocater = StackAllocater();
	this->currStack = 0;
}

DoubleBufferedAllocater::DoubleBufferedAllocater(uint32 nBytes, uint8 alignment) 
	: IAllocater(nBytes, malloc(nBytes))
{
	this->stallocater = StackAllocater();
	this->currStack = 0;
}

LGE_CUDA_FUNC_DECL void DoubleBufferedAllocater::swapBuffers() {
	this->currStack = (uint32)!this->currStack;
}

LGE_CUDA_FUNC_DECL void DoubleBufferedAllocater::clearCurrentBuffer() {
	if (isAligned(this->stallocater[this->currStack], this->_alignment))
		free(this->stallocater[this->currStack]);
	else 
		throw MemoryException(const_cast<char*>("LGE::MemoryException\n Memory block is not aligned."));
}

LGE_CUDA_FUNC_DECL void* DoubleBufferedAllocater::alloc(uint32 nBytes) {
	return this->stallocater[this->currStack] = malloc(nBytes);
}

LGE_CUDA_FUNC_DECL void* DoubleBufferedAllocater::alloc(uint32 nBytes, uint8 alignment) {
	this->_alignment = alignment;
	return this->stallocater[this->currStack] = malloc(nBytes);
}

LGE_CUDA_FUNC_DECL void DoubleBufferedAllocater::clear() {
	this->stallocater.clear();
}

LGE_CUDA_FUNC_DECL void*& DoubleBufferedAllocater::operator [] (int32 index) {
	return this->stallocater[index];
}

LGE_CUDA_FUNC_DECL void* DoubleBufferedAllocater::operator [] (int32 index) const {
	return this->stallocater[index];
}

_LGE_END_NP_LGE_CORE