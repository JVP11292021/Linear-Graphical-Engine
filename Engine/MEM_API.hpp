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

#ifndef MEMORY_API
#define MEMORY_API

#if defined(LGE_DEBUG) || defined(LGE_REALEASE) || defined(LGE_DIST)
#   define LGE_MEM
#endif

#ifdef LGE_MEM
#include "engine_setup.h"
#include "lgeExceptions.hpp" // lge::BadAlloc()
#endif

#include <cstdint>
#include <cstdio>
#ifndef LGE_MEM
#include <stdexcept> // std::bad_alloc()
#endif

#ifdef LGE_MEM
#   define MEMAPI LGE_API
#else
#   define MEMAPI
#endif

#ifdef LGE_MEM
#   define _MEM_BEGIN_NP _LGE_BEGIN_NP_LGE_CORE
#   define _MEM_END_NP   _LGE_END_NP_LGE_CORE
#else
#   define _MEM_BEGIN_NP namespace memory {
#   define _MEM_END_NP   }
#endif

#ifdef LGE_MEM
#   define CUDA_FUNC    LGE_CUDA_FUNC_DECL
#   define CUDA_FUNC_D  LGE_CUDA_FUNC_DEF
#else
#   define CUDA_FUNC    
#   define CUDA_FUNC_D 
#endif

#define BYTE						1
#define KB							1024
#define MB							(KB * KB)
#define GB							(MB * MB)
#define TB							(GB * GB)
#define PB							(TB * TB)

_MEM_BEGIN_NP

// Define a struct to represent a memory block.
struct MEMAPI Block {
    uint32_t size;
    bool is_free;
    Block* next;
};

MEMAPI const uint32_t kPoolSize = KB * KB;  // 1 MB
MEMAPI uint8_t memory_pool[kPoolSize];
MEMAPI Block* head = nullptr;

/// <summary>
/// Initialize the memory pool with a single free block that spans the entire pool.
/// </summary>
/// <param name=""></param>
/// <returns></returns>
CUDA_FUNC MEMAPI 
void init_mem_pool() 
noexcept {
    head = reinterpret_cast<Block*>(memory_pool);
    head->size = kPoolSize - sizeof(Block);
    head->is_free = true;
    head->next = nullptr;
}

/// <summary>
/// Find a free block of the requested size in the memory pool.
/// </summary>
/// <param name="size"></param>
/// <returns>Block*</returns>
CUDA_FUNC MEMAPI
Block* find_free_block(const uint32_t size)
noexcept {
    Block* curr = head;
    while (curr != nullptr) {
        if (curr->is_free && curr->size >= size) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

// Allocate a block of memory of the given size.
CUDA_FUNC MEMAPI 
void* alloc_block(const uint32_t size)  {
    // Find a free block of the requested size in the memory pool.
    Block* block = find_free_block(size);
    if (block == nullptr) {
        throw std::bad_alloc();
    }

    // Split the free block if it's larger than the requested size.
    if (block->size > size + sizeof(Block)) {
        Block* new_block = reinterpret_cast<Block*>(reinterpret_cast<uint8_t*>(block) + sizeof(Block) + size);
        new_block->size = block->size - size - sizeof(Block);
        new_block->is_free = true;
        new_block->next = block->next;
        block->size = size;
        block->is_free = false;
        block->next = new_block;
    }
    else {
        block->is_free = false;
    }

    // Return a pointer to the allocated block of memory.
    return reinterpret_cast<uint8_t*>(block) + sizeof(Block);
}

/// <summary>
/// Free a block of memory that was previously allocated with alloc_block.
/// </summary>
CUDA_FUNC MEMAPI
void free_block(void* ptr) 
noexcept {
    if (ptr == nullptr) {
        return;
    }

    // Find the block of memory corresponding to the given pointer.
    Block* block = reinterpret_cast<Block*>(reinterpret_cast<uint8_t*>(ptr) - sizeof(Block));

    // Mark the block as free.
    block->is_free = true;

    // Merge adjacent free blocks.
    Block* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->is_free && curr->next->is_free) {
            curr->size += sizeof(Block) + curr->next->size;
            curr->next = curr->next->next;
        }
        curr = curr->next;
    }
}

CUDA_FUNC MEMAPI
void print_memory_pool() 
noexcept {
    printf("Memory Pool:\n");
    Block* curr = head;
    while (curr != nullptr) {
        printf("  Block: size=%u, is_free=%d, next=%p\n", curr->size, curr->is_free, curr->next);
        curr = curr->next;
    }
}

/// <summary>
/// The LinearAllocator class takes a pointer to the start of the memory pool and the size of the memory pool as constructor arguments.
/// The allocate method allocates a block of memory of the given size from the memory pool, 
/// and the reset method resets the internal offset to the start of the memory pool,
/// effectively deallocating all previously allocated memory.
/// </summary>
class MEMAPI LinearAllocator {
public:
    LinearAllocator(uint8_t* pool, const uint32_t pool_size)
        : m_pool(pool), m_pool_size(pool_size), m_offset(0) {
    }

    CUDA_FUNC void* allocate(const uint32_t size) {
        if (m_offset + size > m_pool_size) {
            throw std::bad_alloc();
        }

        void* ptr = &m_pool[m_offset];
        m_offset += size;
        return ptr;
    }

    CUDA_FUNC void reset() {
        m_offset = 0;
    }

private:
    uint8_t* m_pool;
    const uint32_t m_pool_size;
    uint32_t m_offset;
};

template <typename T>
class MEMAPI StackAllocator {
public:
    // Define the public types required by the C++ standard for an allocator.
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    // Construct a stack allocator with a given size.
    explicit StackAllocator(const size_type size)
        : size_(size) {
        // Initialize the memory pool if necessary.
        if (head == nullptr) {
            init_mem_pool();
        }

        // Check if the requested size is larger than the size of a memory block.
        if (size_ > sizeof(Block)) {
            // Allocate a block of memory to serve as the initial free block.
            Block* block = reinterpret_cast<Block*>(alloc_block(size_ - sizeof(Block)));
            block->size = size_ - sizeof(Block);
            block->is_free = true;
            block->next = head;
            head = block;
        }
    }

    // Copy constructor.
    template <typename U>
    StackAllocator(const StackAllocator<U>& other) noexcept
        : size_(other.size_) {}

    // Allocate a block of memory for n objects of type T.
    CUDA_FUNC pointer allocate(const size_type n) {
        // Calculate the size of the memory block to be allocated.
        const uint32_t size = n * sizeof(T);

        // Allocate a block of memory from the memory pool.
        Block* block = find_free_block(size);
        if (block == nullptr) {
            throw std::bad_alloc();
        }

        // Split the free block if it's larger than the requested size.
        if (block->size > size + sizeof(Block)) {
            Block* new_block = reinterpret_cast<Block*>(reinterpret_cast<uint8_t*>(block) + sizeof(Block) + size);
            new_block->size = block->size - size - sizeof(Block);
            new_block->is_free = true;
            new_block->next = block->next;
            block->size = size;
            block->is_free = false;
            block->next = new_block;
        }
        else {
            block->is_free = false;
        }

        // Return a pointer to the allocated block of memory.
        return reinterpret_cast<pointer>(reinterpret_cast<uint8_t*>(block) + sizeof(Block));
    }

    // Deallocate the block of memory pointed to by ptr.
    CUDA_FUNC void deallocate(pointer ptr, const size_type n) noexcept {
        free_block(ptr);
    }

    // Return the maximum size that can be allocated.
    CUDA_FUNC size_type max_size() const noexcept {
        return size_ / sizeof(T);
    }

    // Construct an object of type T at the specified memory location.
    template <typename... Args>
    CUDA_FUNC void construct(pointer ptr, Args&&... args) {
        new (ptr) T(std::forward<Args>(args)...);
    }

    // Destroy the object of type T at the specified memory location.
    CUDA_FUNC void destroy(pointer ptr) {
        ptr->~T();
    }
private:
    // The size of the memory pool.
    const uint32_t size_;
};

// Define equality and inequality operators for StackAllocator objects.
template <typename T, typename U>
CUDA_FUNC MEMAPI 
bool operator==(const StackAllocator<T>& lhs, const StackAllocator<U>& rhs) 
noexcept {
    return lhs.max_size() == rhs.max_size();
}

template <typename T, typename U>
CUDA_FUNC MEMAPI 
bool operator!=(const StackAllocator<T>& lhs, const StackAllocator<U>& rhs)
noexcept {
    return !(lhs == rhs);
}

// // Define a custom allocator that uses a free list to allocate memory from a fixed-size pool.
template <typename T>
class MEMAPI FreeListAllocator {
public:
    // Define the public types required by the C++ standard for an allocator.
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

    // Construct a free list allocator with a given size.
    explicit FreeListAllocator(const size_type size) :
        m_pool(reinterpret_cast<uint8_t*>(alloc_block(size))),
        m_pool_size(size),
        m_free_list(nullptr)
    {}

    // Construct a copy of a free list allocator (not implemented).
    template <typename U>
    explicit FreeListAllocator(const FreeListAllocator<U>& other) {}

    // Allocate a block of memory for n objects of type T.
    CUDA_FUNC pointer allocate(const size_type n) {
        if (n != 1) {
            throw std::invalid_argument("FreeListAllocator only supports allocating single objects");
        }
        // If the free list is non-empty, use the first block in the list.
        if (m_free_list != nullptr) {
            Block* block = m_free_list;
            m_free_list = m_free_list->next;
            return reinterpret_cast<pointer>(block->data);
        }
        // Otherwise, allocate a new block from the pool.
        if (m_pool_size - m_offset < sizeof(Block) + sizeof(T)) {
            throw std::bad_alloc();
        }
        Block* block = reinterpret_cast<Block*>(m_pool + m_offset);
        block->size = sizeof(T);
        block->next = nullptr;
        m_offset += sizeof(Block) + sizeof(T);
        return reinterpret_cast<pointer>(block->data);
    }

    // Deallocate a block of memory previously allocated with allocate.
    CUDA_FUNC void deallocate(pointer ptr, const size_type n) {
        if (n != 1) {
            throw std::invalid_argument("FreeListAllocator only supports deallocating single objects");
        }
        // Add the block to the free list.
        Block* block = reinterpret_cast<Block*>(reinterpret_cast<uint8_t*>(ptr) - sizeof(Block));
        block->next = m_free_list;
        m_free_list = block;
    }

private:
    // Define a struct to represent a memory block.
    struct Block {
        uint32_t size;
        Block* next;
        alignas(T) char data[sizeof(T)];
    };

    // The start of the memory pool.
    uint8_t* m_pool;

    // The size of the memory pool.
    const size_type m_pool_size;

    // The current offset into the memory pool.
    size_type m_offset = 0;

    // The head of the free list.
    Block* m_free_list;
};

// Define operator== and operator!= for FreeListAllocator.
template <typename T1, typename T2>
CUDA_FUNC MEMAPI 
bool operator==(const FreeListAllocator<T1>& lhs, const FreeListAllocator<T2>& rhs) 
noexcept {
    return true;
}

template <typename T1, typename T2>
CUDA_FUNC MEMAPI 
bool operator!=(const FreeListAllocator<T1>& lhs, const FreeListAllocator<T2>& rhs) 
noexcept {
    return false;
}

// Define a class template for a pool allocator.
template<typename T>
class MEMAPI PoolAllocator {
private:
    // Define the public types required by the C++ standard for an allocator.
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = std::size_t;
    using difference_type = std::ptrdiff_t;

public:
    // Constructor to initialize the memory pool.
    PoolAllocator() {
        init_mem_pool();
    }

    // Destructor to free any allocated memory.
    ~PoolAllocator() {
        Block* curr = head;
        while (curr != nullptr) {
            if (!curr->is_free) {
                reinterpret_cast<T*>(reinterpret_cast<uint8_t*>(curr) + sizeof(Block))->~T();
            }
            curr = curr->next;
        }
    }

    // Allocate a block of memory of the given size.
    CUDA_FUNC void* allocate(const uint32_t size) {
        // Find a free block of the requested size in the memory pool.
        Block* block = find_free_block(size);
        if (block == nullptr) {
            throw std::bad_alloc();
        }

        // Split the free block if it's larger than the requested size.
        if (block->size > size + sizeof(Block)) {
            Block* new_block = reinterpret_cast<Block*>(reinterpret_cast<uint8_t*>(block) + sizeof(Block) + size);
            new_block->size = block->size - size - sizeof(Block);
            new_block->is_free = true;
            new_block->next = block->next;
            block->size = size;
            block->is_free = false;
            block->next = new_block;
        }
        else {
            block->is_free = false;
        }

        // Return a pointer to the allocated block of memory.
        return reinterpret_cast<uint8_t*>(block) + sizeof(Block);
    }

    // Free a block of memory that was previously allocated with allocate.
    CUDA_FUNC void deallocate(void* ptr) {
        if (ptr == nullptr) {
            return;
        }

        // Find the block of memory corresponding to the given pointer.
        Block* block = reinterpret_cast<Block*>(reinterpret_cast<uint8_t*>(ptr) - sizeof(Block));

        // Mark the block as free.
        block->is_free = true;

        // Merge adjacent free blocks.
        Block* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->is_free && curr->next->is_free) {
                curr->size += sizeof(Block) + curr->next->size;
                curr->next = curr->next->next;
            }
            curr = curr->next;
        }
    }
};

_MEM_END_NP

#endif

