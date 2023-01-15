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

#ifndef __LGE_COLLECTIONS__
#define __LGE_COLLECTIONS__

#include "engine_setup.h"
#include "lgeSmartPtr.hpp"

#include <istream>
#include <ostream>
#include <iostream>
#include <initializer_list>

#define LGE_LIST_DS 1
#define LGE_LIST_US 0


_LGE_BEGIN_NP_LGE_CORE

// =====================================================================
// Couple class
// =====================================================================

template <typename TF, typename TL>
class Couple {
private:
	TF first;
	TF last;

public:
	Couple(TF, TL);
	Couple(const Couple&);

	LGE_CUDA_FUNC_DECL LGE_INLINE TF getFirst() const { return this->first; }
	LGE_CUDA_FUNC_DECL LGE_INLINE TL getLast() const { return this->last; }

#ifdef LGE_FORCE_IO_COUPLE
	LGE_CUDA_FUNC_DECL friend std::ostream& operator << (std::ostream&, const Couple&);
	LGE_CUDA_FUNC_DECL friend std::istream& operator >> (std::istream&, const Couple&);
#endif
};

// =====================================================================
// Tuple class
// =====================================================================


template <typename T>
class Tuple {
private:
	T data[12];
	size_t size;

public:
	uint32 len;

	Tuple();
	Tuple(int32, ...);
	Tuple(const std::initializer_list<T>&);
	Tuple(const Tuple&);

	// operator overloading
	LGE_CUDA_FUNC_DECL const T operator [] (uint32) const;

#ifdef LGE_FORCE_IO_TUPLE
	LGE_CUDA_FUNC_DECL friend std::ostream& operator << (std::ostream&, const Tuple&);
	LGE_CUDA_FUNC_DECL friend std::istream& operator >> (std::istream&, const Tuple&);
#endif

};

// =====================================================================
// Array class
// =====================================================================

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T, uint32 E>
class Array {
private:
	T arr[E];
	size_t size;
	uint32 a_begin = 0;
	uint32 a_end = 0;

public:
	uint32 len = E;
	uint32 curr_pos = 0;

	/// <summary>
	/// 
	/// </summary>
	Array();

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	Array(Array&);

	/// <summary>
	/// 
	/// </summary>
	/// <param name=""></param>
	Array(const Array&);

	Array(const std::initializer_list<T>&);

	LGE_CUDA_FUNC_DECL Array& append(T);
	LGE_CUDA_FUNC_DECL Array<T, E>& insertAt(T, uint32);
	LGE_CUDA_FUNC_DECL Array<T, E>& removeAt(uint32);
	LGE_CUDA_FUNC_DECL Array<T, E>& del(T);
	LGE_CUDA_FUNC_DECL Array<T, E>& shift();
	LGE_CUDA_FUNC_DECL Array<T, E>& pop();
	LGE_CUDA_FUNC_DECL T getItemAt(uint32);
	LGE_CUDA_FUNC_DECL T largestItem();
	LGE_CUDA_FUNC_DECL T smallestItem();
	LGE_CUDA_FUNC_DECL Array<T, E>& reverse();
	LGE_CUDA_FUNC_DECL void rotate(int32);
	LGE_CUDA_FUNC_DECL bool isOdd(uint32);
	LGE_CUDA_FUNC_DECL bool isEven(uint32);
	LGE_CUDA_FUNC_DECL bool includes(T);
	LGE_CUDA_FUNC_DECL void pprint();

	// Operator overloaded functions

	LGE_CUDA_FUNC_DECL T& operator [] (uint32);
	LGE_CUDA_FUNC_DECL T operator [] (uint32) const;
	LGE_CUDA_FUNC_DECL Array operator = (T a[]);
	LGE_CUDA_FUNC_DECL Array operator = (const Array&);
	LGE_CUDA_FUNC_DECL Array operator = (Array&);

#ifdef LGE_FORCE_IO_ARRAY
	LGE_CUDA_FUNC_DECL friend std::ostream& operator << (std::ostream&, const Array&);
	LGE_CUDA_FUNC_DECL friend std::istream& operator >> (std::istream&, const Array&);
#endif

};

// =====================================================================
// List class
// =====================================================================

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class  List {
private:
	T* l = (T*)malloc(sizeof(T) * 10);
	size_t size;

	LGE_CUDA_FUNC_DECL T* resize(T* oldArr, size_t, size_t);


public:
	uint32 len;


	List();
	List(List&);
	List(const List&);
	List(const std::initializer_list<T>&);
	~List();

	LGE_CUDA_FUNC_DECL List<T>& append(T);
	LGE_CUDA_FUNC_DECL List<T>& append(T) const ;

	LGE_CUDA_FUNC_DECL uint32 emplace(uint32, T);

	LGE_CUDA_FUNC_DECL List<T>& pop();
	LGE_CUDA_FUNC_DECL List<T>& shift();
	LGE_CUDA_FUNC_DECL List<T>& del(T);

	LGE_CUDA_FUNC_DECL void pprint();

	LGE_CUDA_FUNC_DECL LGE_INLINE T first() const { return this->l[0]; }
	LGE_CUDA_FUNC_DECL LGE_INLINE T last() const { return this->l[this->len]; }
	LGE_CUDA_FUNC_DECL LGE_INLINE uint32 begin() const { return 0; }
	LGE_CUDA_FUNC_DECL LGE_INLINE uint32 end() const { return this->len; }

	LGE_CUDA_FUNC_DECL T& operator [] (uint32);
	LGE_CUDA_FUNC_DECL T operator [] (uint32) const;
	LGE_CUDA_FUNC_DECL List operator = (T a[]);
	LGE_CUDA_FUNC_DECL List operator = (const List&);
	LGE_CUDA_FUNC_DECL List operator = (List&);

#ifdef LGE_FORCE_IO_LIST
	LGE_CUDA_FUNC_DECL friend std::ostream& operator << (std::ostream&, const List&);
	LGE_CUDA_FUNC_DECL friend std::istream& operator >> (std::istream&, const List&);
#endif
};

// =====================================================================
// Linked-list class
// =====================================================================

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
struct  sNode {
	T data;
	struct sNode<T>* link;
	size_t size;
};

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
struct  dNode {
	struct dNode<T>* h_link;
	T data;
	struct dNode<T>* t_link;
	size_t size;
};

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class  sLinkedList {
private:
	size_t size;
	struct sNode<T>* head;

public:
	uint32 len;

	sLinkedList();
	sLinkedList(const sLinkedList&);
	~sLinkedList();

	LGE_CUDA_FUNC_DECL void push(T data);
	LGE_CUDA_FUNC_DECL void insertAt(T data, uint32 index);
	LGE_CUDA_FUNC_DECL void append(T data);
	LGE_CUDA_FUNC_DECL void shift();
	LGE_CUDA_FUNC_DECL void removeAt(uint32 index);
	LGE_CUDA_FUNC_DECL sNode<T>* getNodeAt(uint32 index);
	LGE_CUDA_FUNC_DECL T getItemAt(uint32 index);
	LGE_CUDA_FUNC_DECL void reverse();
	LGE_CUDA_FUNC_DECL void removeDuplicates();
	LGE_CUDA_FUNC_DECL T searchItem(T item);
	LGE_CUDA_FUNC_DECL sLinkedList& pprint();

	LGE_CUDA_FUNC_DECL T& operator [] (uint32);
	LGE_CUDA_FUNC_DECL T operator [] (uint32) const;
	LGE_CUDA_FUNC_DECL sLinkedList operator = (const sLinkedList&);

#ifdef LGE_FORCE_IO_SLINKEDLIST
	LGE_CUDA_FUNC_DECL friend std::ostream& operator << (std::ostream&, const sLinkedList&);
	LGE_CUDA_FUNC_DECL friend std::istream& operator >> (std::istream&, const sLinkedList&);
#endif

};

// =====================================================================
// Stack class
// =====================================================================

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T, uint32 C>
class  Stack {
private:
	size_t size;
	Array<T, C> sarr = Array<T, C>();

public:
	uint32 max_capacity = C;
	int32 top;

	Stack();
	Stack(const Stack&);

	LGE_CUDA_FUNC_DECL Stack& push(T v);
	LGE_CUDA_FUNC_DECL void pop();
	LGE_CUDA_FUNC_DECL LGE_INLINE bool isEmpty();
	LGE_CUDA_FUNC_DECL T peek();
	LGE_CUDA_FUNC_DECL Stack& sort();
	LGE_CUDA_FUNC_DECL Stack& pprint();

	LGE_CUDA_FUNC_DECL T& operator [] (uint32);
	LGE_CUDA_FUNC_DECL T operator [] (uint32) const;
	LGE_CUDA_FUNC_DECL Stack operator = (const Stack&);

#ifdef LGE_FORCE_IO_STACK
	LGE_CUDA_FUNC_DECL friend std::ostream& operator << (std::ostream&, const Stack&);
	LGE_CUDA_FUNC_DECL friend std::istream& operator >> (std::istream&, const Stack&);
#endif
};

// =====================================================================
// Queue/Dequeue class
// =====================================================================

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T, uint32 C>
class  Queue {
private:
	uint32 max_capacity = C;
	size_t size;
	Array<T, C> qarr = Array<T, C>();
	int32 front;
	int32 rear;

public:
	int32 len;

	Queue();
	Queue(const Queue&);

	LGE_CUDA_FUNC_DECL void enqueue(T item);
	LGE_CUDA_FUNC_DECL T dequeue();
	LGE_CUDA_FUNC_DECL LGE_INLINE bool isFull();
	LGE_CUDA_FUNC_DECL LGE_INLINE bool isEmpty();
	LGE_CUDA_FUNC_DECL T getFront();
	LGE_CUDA_FUNC_DECL T getRear();
	LGE_CUDA_FUNC_DECL void pprint();

	LGE_CUDA_FUNC_DECL Queue operator = (const Queue&);

#ifdef LGE_FORCE_IO_QUEUE
	LGE_CUDA_FUNC_DECL friend std::ostream& operator << (std::ostream&, const Queue&);
	LGE_CUDA_FUNC_DECL friend std::istream& operator >> (std::istream&, const Queue&);
#endif
};

// =====================================================================
// Dictionary class
// =====================================================================

/// <summary>
/// 
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T> 
class  Dictionary {

};


// =====================================================================
// Functional paradigm functions
// =====================================================================

template <typename T>
LGE_CUDA_FUNC_DECL int32 ifind(List<T>, T);

template <typename T>
LGE_CUDA_FUNC_DECL T find(List<T>, T);

//template <typename T, uint32 E>
//Array<T, E> filter(bool(*callBack)(T, uint32), Array<T, E>);
//
//template <typename T, uint32 E>
//Array<T, E> iter(Array<T, E>&);
//
//template <typename Func>
//LGE_CUDA_FUNC_DECL void forEach(Func);
//
//template <typename Func>
//LGE_CUDA_FUNC_DECL void map(Func);

//template <typename T, uint32 E>
//LGE_CUDA_FUNC_DECL Dictionary<T> zip(Array<T, E>&, Array<T, E>&);

//template <typename T, uint32 E>
//LGE_CUDA_FUNC_DECL Array<T, E> toArray(Str&);

//template <typename T>
//LGE_CUDA_FUNC_DECL Str toString(T);

_LGE_END_NP_LGE_CORE

#	ifndef LGE_FORCE_EXTERNAL_TEMPLATE
#		include "lgeCollections.inl"
#	endif
#endif