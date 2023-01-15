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

#pragma once

#include "engine_setup.h"
#include "lgeExceptions.hpp"

#include <iostream>

// =====================================================================
// Declarations
// =====================================================================

_LGE_BEGIN_NP_LGE_CORE

/// <summary>
/// Unaligned allocation function. Memory address is unaligned when not divisible by N bytes.
/// IMPORTANT: This function may/may not cause undefined behavior.
/// </summary>
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* mallocUnaligned(size_t);

/// <summary>
/// Frees specified unaligned memory block.
/// </summary>
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void freeUnaligned(void*);

/// <summary>
/// Aligned allocation function. 
/// IMPORTANT: 'alignment' must be a power of 2 (typically 4 or 16).
/// </summary>
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* mallocAligned(size_t, size_t);

/// <summary>
/// Frees specified alligned memory block.
/// </summary>
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void freeAligned(void*);

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API bool isAligned(const void*, uint8);
//LGE_CUDA_FUNC_DECL LGE_INLINE bool isAligned(const void*);

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* alignForward(void*, uint8);
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API const void* alignForward(const void*, uint8);
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API uint8* alignForwardAdjustment(const void*, uint8);
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* add(void*, size_t);
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API const void* add(const void*, size_t);
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* sub(void*, size_t);
LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API const void* sub(const void*, size_t);

_LGE_END_NP_LGE_CORE

// =====================================================================
// Definitions
// =====================================================================

_LGE_BEGIN_NP_LGE_CORE

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API bool isAligned(const void* address, uint8 alignment) {
	return alignForwardAdjustment(address, alignment) == 0;
}

//LGE_CUDA_FUNC_DECL LGE_INLINE bool isAligned(const void* address) {
//	return alignForwardAdjustment(address, alignof()) == 0;
//}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* alignForward(void* address, uint8 alignment) {
	return (void*)((reinterpret_cast<uintptr_t>(address) + static_cast<uintptr_t>(alignment - 1)) & static_cast<uintptr_t>(~(alignment - 1)));
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API const void* alignForward(const void* address, uint8 alignment) {
	return (void*)((reinterpret_cast<uintptr_t>(address) + static_cast<uintptr_t>(alignment - 1)) & static_cast<uintptr_t>(~(alignment - 1)));
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API uint8* alignForwardAdjustment(const void* address, uint8 alignment) {
	uint8 adjustment = alignment - (reinterpret_cast<uintptr_t>(address) & static_cast<uintptr_t>(alignment - 1));

	if (adjustment == alignment)
		return 0;

	return reinterpret_cast<uint8*>(adjustment);
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* add(void* ptr, size_t x) {
	return (void*)(reinterpret_cast<uintptr_t>(ptr) + x);
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API const void* add(const void* ptr, size_t x) {
	return (const void*)(reinterpret_cast<uintptr_t>(ptr) + x);
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* sub(void* ptr, size_t x) {
	return (void*)(reinterpret_cast<uintptr_t>(ptr) - x);
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API const void* sub(const void* ptr, size_t x) {
	return (const void*)(reinterpret_cast<uintptr_t>(ptr) - x);
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* mallocUnaligned(size_t size_bytes) {
	uintptr_t rawAddress = (uintptr_t)size_bytes;

	uint8* pUalignedMem = reinterpret_cast<uint8*>(rawAddress);
	return static_cast<void*>(pUalignedMem);
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void freeUnaligned(void* pMem) {
	uint8* pUalignedMem = reinterpret_cast<uint8*>(pMem);
	void* pRawMem = reinterpret_cast<void*>(pUalignedMem);

	pRawMem = nullptr;
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void* mallocAligned(size_t size_bytes, size_t alignment) {
	if (alignment <= 1)
		throw MemoryException(const_cast<char*>("LGE::MemoryException\n Aligment can't be smaller or equal to 1 byte."));
	else if ( alignment >= 128)
		throw MemoryException(const_cast<char*>("LGE::MemoryException\n Aligment can't be larger or equal to 128 bytes."));
	else if ((alignment & (alignment - 1)) != 0)
		throw MemoryException(const_cast<char*>("LGE::MemoryException\n Aligment is zero."));

	size_t expandedSize_bytes = size_bytes + alignment;

	uintptr_t rawAddress = reinterpret_cast<uintptr_t>(mallocUnaligned(expandedSize_bytes));

	size_t mask = (alignment - 1);
	uintptr_t misalignment = (rawAddress & mask);
	ptrdiff_t adjustment = alignment - misalignment;

	uintptr_t alignedAddress = rawAddress + adjustment;
	if (adjustment > 256)
		throw MemoryException(const_cast<char*>("LGE::MemoryException\n Adjustment is larger than 256 bytes."));

	int8* pAlignedMem = reinterpret_cast<int8*>(alignedAddress);
	return add(static_cast<void*>(pAlignedMem), adjustment);
}

LGE_CUDA_FUNC_DECL LGE_INLINE LGE_API void freeAligned(void* pMem) {
	const uint8* pAlignedMem = reinterpret_cast<const uint8*>(pMem);
	uintptr_t alignedAddress = reinterpret_cast<uintptr_t>(pMem);
	ptrdiff_t adjustment = reinterpret_cast<ptrdiff_t>(sub(reinterpret_cast<void*>(alignedAddress), sizeof(int)));
	uintptr_t rawAddress = alignedAddress - adjustment;
	void* pRawMem = reinterpret_cast<void*>(rawAddress);
	freeUnaligned(pRawMem);
}

_LGE_END_NP_LGE_CORE