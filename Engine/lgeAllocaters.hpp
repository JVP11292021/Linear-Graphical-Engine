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

#ifndef __LGE_CMEM_ALLOCA__
#define __LGE_CMEM_ALLOCA__

#include "engine_setup.h"
#include "lgeCollections.h"

_LGE_BEGIN_NP_LGE_CORE

		// =====================================================================
		// Memory allocater classes
		// =====================================================================

class LGE_API IAllocater {
protected:
	void* _start;
	size_t _size;
	size_t _used_memory;
	size_t _num_allocations;
	uint8 _alignment;


public:

	IAllocater() {
		this->_start = NULL;
		this->_size = 0;
		this->_used_memory = 0;
		this->_num_allocations = 0;
		this->_alignment = 0;
	}


	IAllocater(size_t size) {
		this->_start = NULL;
		this->_size = size;
		this->_used_memory = 0;
		this->_num_allocations = 0;
		this->_alignment = 0;
	}

	IAllocater(size_t size, void* start) {
		this->_start = start;
		this->_size = size;
		this->_used_memory = 0;
		this->_num_allocations = 0;
		this->_alignment = 0;
	}

	~IAllocater() {
		lgeASSERT(this->_num_allocations == 0 && this->_used_memory == 0);
		this->_size = 0;
		this->_start = NULL;
		this->_alignment = 0;
	}

	LGE_CUDA_FUNC_DECL virtual void* alloc(size_t nBytes) { return NULL; }
	LGE_CUDA_FUNC_DECL virtual void* alloc(size_t nBytes, uint8 alignment = 4) { return NULL; }
	//LGE_CUDA_FUNC_DECL LGE_INLINE virtual void free(void* block) = 0;
	LGE_CUDA_FUNC_DECL LGE_INLINE virtual void clear() {}

	LGE_CUDA_FUNC_DECL LGE_INLINE void setAlignment(uint8 alignment) { this->_alignment = alignment; }

	LGE_CUDA_FUNC_DECL LGE_INLINE void* getStart() { return this->_start; }
	LGE_CUDA_FUNC_DECL LGE_INLINE size_t getSize() { return this->_size; }
	LGE_CUDA_FUNC_DECL LGE_INLINE size_t getUsedMemory() { return this->_used_memory; }
	LGE_CUDA_FUNC_DECL LGE_INLINE size_t getNumAllocations() { return this->_num_allocations; }
	LGE_CUDA_FUNC_DECL LGE_INLINE uint8 getAllignment() { return this->_alignment; }

};

/// <summary>
/// This is a custom built stack allocater class, specificly built for the lg engine.
/// </summary>
class LGE_API StackAllocater : public IAllocater {

	/* Stack marker: Represents the current top of the
	stack. You can only roll back to a marker, not to
	arbitrary locations within the stack. */
	typedef uint32* Marker;

private:
	Marker marker;
	Stack<void*, 8> stack = Stack<void*, 8>();

public:

	/// <summary>
	/// Default stack allocater constructor.
	/// </summary>
	StackAllocater();

	/// <summary>
	/// Constructs a stack allocator with the given total size.
	/// </summary>
	/// <param name="stackSize_bytes"></param>
	explicit StackAllocater(uint32 nBytes);


	/// <summary>
	/// Constructs a stack allocator with the given total size and starting position.
	/// </summary>
	/// <param name="stackSize_bytes"></param>
	explicit StackAllocater(uint32 nBytes, void* start_pos);

	/// <summary>
	/// Constructs a stack allocator with the given total size and alignement.
	/// </summary>
	/// <param name="stackSize_bytes"></param>
	explicit StackAllocater(uint32 nBytes, uint8 alignment);

	// Allocates a new block of the given size from stack top.
	LGE_CUDA_FUNC_DECL void* alloc(uint32 nBytes);
//#ifdef LGE_HAS_OVERRIDE
//		override;
//#else
//		;
//#endif

	// Allocates a new block of the given size from stack top.
	LGE_CUDA_FUNC_DECL void* alloc(uint32 nBytes, uint8 alignment = 4);
//#ifdef LGE_HAS_OVERRIDE
//		override;
//#else
//		;
//#endif

	/// <summary>
	/// Returns a marker to the current stack top.
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DECL LGE_INLINE Marker getMarker();

	/// <summary> 
	/// Rolls the stack back to a previous marker.
	/// </summary>
	/// <param name="marker"></param>
	/// <returns></returns>
	LGE_CUDA_FUNC_DECL void freeToMarker(Marker marker);

	/// <summary>
	/// Clears the entire stack (rolls the stack back to zero).
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DECL void clear()
#ifdef LGE_HAS_OVERRIDE
		override;
#else
		;
#endif

	LGE_CUDA_FUNC_DECL void* operator [] (uint32 index) const;
	LGE_CUDA_FUNC_DECL void*& operator [] (uint32 index);

};

/// <summary>
/// This is a custom built Double-buffered allocater class, specificly built for the lg engine.
/// </summary>
class LGE_API DoubleBufferedAllocater : public IAllocater {
private:
	uint32 currStack;
	StackAllocater stallocater;

public:
	DoubleBufferedAllocater();
	DoubleBufferedAllocater(uint32 nBytes);
	DoubleBufferedAllocater(uint32 nBytes, uint8 alignment);


	// Swap the active and inactive buffers of the double-buffered allocator.
	LGE_CUDA_FUNC_DECL void swapBuffers();

	// Clears the newly active buffer, leaving last frame's buffer intact.
	LGE_CUDA_FUNC_DECL void clearCurrentBuffer();

	// Allocate out of the current buffer, without disturbing last frame's data. Only use this data this frame or next frame. Again, this memory never needs to be freed.
	LGE_CUDA_FUNC_DECL void* alloc(uint32 nBytes);
//#ifdef LGE_HAS_OVERRIDE
//		override;
//#else
//		;
//#endif

	LGE_CUDA_FUNC_DECL void* alloc(uint32 nBytes, uint8 alignment = 4);
//#ifdef LGE_HAS_OVERRIDE
//		override;
//#else
//		;
//#endif

	/// <summary>
	/// Clears the entire stack (rolls the stack back to zero).
	/// </summary>
	/// <returns></returns>
	LGE_CUDA_FUNC_DECL void clear()
#ifdef LGE_HAS_OVERRIDE
		override;
#else
		;
#endif

	LGE_CUDA_FUNC_DECL void* operator [] (int32 index) const;
	LGE_CUDA_FUNC_DECL void*& operator [] (int32 index);

};


class LGE_API FreelistAllocater : public IAllocater {

};

_LGE_END_NP_LGE_CORE

#endif