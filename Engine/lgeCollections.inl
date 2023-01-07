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

#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

#include "lgeCollections.h"
#include "lgeExceptions.hpp"

_LGE_BEGIN_NP_LGE_CORE

// =====================================================================
// Couple class
// =====================================================================

template <typename TF, typename TL>
Couple<TF, TL>::Couple(TF first, TL last) 
#ifdef LGE_HAS_INITIALIZER_LIST
	: first(first), last(last)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->first = first;
	this->last = last;
#endif
}

template <typename TF, typename TL>
Couple<TF, TL>::Couple(const Couple& couple)
#ifdef LGE_HAS_INITIALIZER_LIST
	: first(couple.first), last(couple.last)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->first = couple.first;
	this->last = couple.last;
#endif
}

// =====================================================================
// Tuple class
// =====================================================================

template <typename T>
Tuple<T>::Tuple()
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(0), len(0)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = 0;
	this->len = 0;
#endif
}

template <typename T>
Tuple<T>::Tuple(int32 f, ...) {
	this->size = 0;
	this->len = 0;

	va_list arguments;
	va_start(arguments, f);

	for (int i = 0; i < f; ++i) {
		//if (i == 0)
		//	this->data[i] = f;
		//else
		this->data[i] = va_arg(arguments, T);
		this->len++;
		this->size += sizeof(T);
	}

	va_end(arguments);
}

template <typename T>
Tuple<T>::Tuple(const std::initializer_list<T>& ilist)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(0), len(0)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = 0;
	this->len = 0;
#endif
	for (const T item : ilist) {
		this->data[this->len] = item;
		this->len++;
		this->size += sizeof(T);
	}
}

template <typename T>
Tuple<T>::Tuple(const Tuple<T>& t)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(t.size), len(t.len)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = t.size;
	this->len = t.len;
#endif
	for (int i = 0; i < t.len; i++)
		this->data[i] = t.data[i];

}

template <typename T>
LGE_CUDA_FUNC_DECL const T Tuple<T>::operator [] (uint32 index) const {
	if (index < this->len)
		return this->data[index];
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}

// =====================================================================
// Array class methods
// =====================================================================

static const uint32 undefinedVal = -93232002;

// Constructors

template <typename T, uint32 E>
Array<T, E>::Array()
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(sizeof(arr)), a_begin(0), a_end(curr_pos)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = sizeof(arr);
	this->a_begin = arr[0];
	this->a_end = arr[E];
#endif

}

template <typename T, uint32 E>
Array<T, E>::Array(Array& a)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(sizeof(a.arr)), a_begin(0), a_end(a.curr_pos)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = sizeof(a.arr);
	this->a_begin = a.arr[0];
	this->a_end = a.arr[E];
#endif

	if (a.len > this->len)
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));

	for (int32 x = 0; x < this->len; x++)
		this->arr[x] = a.arr[x];
}

template <typename T, uint32 E>
Array<T, E>::Array(const Array& a)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(sizeof(a.arr)), a_begin(0), a_end(a.curr_pos)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = sizeof(a.arr);
	this->a_begin = a.arr[0];
	this->a_end = a.arr[E];
#endif

	if (a.len > this->len)
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));

	for (int32 x = 0; x < this->len; x++)
		this->arr[x] = a.arr[x];

}

template <typename T, uint32 E>
Array<T, E>::Array(const std::initializer_list<T>& ilist)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(sizeof(arr)), a_begin(0), a_end(curr_pos)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = sizeof(arr);
	this->a_begin = arr[0];
	this->a_end = curr_end;
#endif

	for (T item : ilist) {
		this->arr[this->curr_pos] = item;
		this->curr_pos++;
	}
}


// Array utility functions

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E>& Array<T, E>::append(T item) {
	if (this->curr_pos == this->len)
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception\n Array cannot hold more than [n] elements.\n"));
	else
		if (this->curr_pos < this->len) {
			this->arr[this->curr_pos++] = item;
			this->a_end++;
		}
	return *this;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E>& Array<T, E>::insertAt(T i, uint32 index) {
	if (index < this->len)
		this->arr[index] = i;
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));

	return *this;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E>& Array<T, E>::del(T item) {
	uint32 index;
	for (index = 0; index < this->len; index++)
		if (arr[index] == item)
			break;

	if (index < this->len) {
		this->len = this->len - 1;
		for (int32 i = (index == 0 ? 0 : index-1); i < this->len; i++)
			this->arr[i] = this->arr[i + 1];
		this->curr_pos--;
		this->a_end = this->curr_pos;

		return *this;
	}
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E>& Array<T, E>::removeAt(uint32 index) {
	if (index < this->len) {
		this->len = this->len - 1;
		for (int32 i = (index == 0 ? 0 : index-1); i < this->len; i++)
			this->arr[i] = this->arr[i + 1];
		this->curr_pos--;
		this->a_end = this->curr_pos;
	}
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
	return *this;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E>& Array<T, E>::shift() {
	this->len = this->len - 1;
	for (int32 i = 0; i < this->len; i++)
		this->arr[i] = this->arr[i + 1];
	this->curr_pos--;
	this->a_end = this->curr_pos;
	return *this;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E>& Array<T, E>::pop() {
	this->len = this->len - 1;
	for (int32 i = this->len; i > this->len; i--)
		this->arr[i] = this->arr[i - 1];
	this->curr_pos--;
	this->a_end = this->curr_pos;
	return *this;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL T Array<T, E>::getItemAt(uint32 index) {
	if (index < this->len)
		return this->arr[index];
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL T Array<T, E>::largestItem() {
	T lItem = NULL;
	for (int32 x = 0; x < this->len; x++)
		if (this->arr[x] > lItem)
			lItem = this->arr[x];
	return lItem;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL T Array<T, E>::smallestItem() {
	T sItem = INT_MAX - 1;
	for (int32 x = 0; x < this->len; x++)
		if (this->arr[x] < sItem)
			sItem = this->arr[x];
	return sItem;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E>& Array<T, E>::reverse() {
	uint32 begin = this->a_begin;
	uint32 end = this->a_end - 1;

	while (begin < end) {
		T temp = this->arr[begin];
		this->arr[begin] = this->arr[end];
		this->arr[end] = temp;
		begin++;
		end--;
	}

	return *this;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL void Array<T, E>::rotate(int32 rotFactor) {
	auto __inner_reverse__ = [](T arr[], uint32 begin, uint32 end) {
		while (begin < end) {
			T temp = arr[begin];
			arr[begin] = arr[end];
			arr[end] = temp;
			begin++;
			end--;
		}
	};

	if (rotFactor == 0)
		return;

	rotFactor = rotFactor & this->len;

	__inner_reverse__(this->arr, 0, rotFactor - 1);
	__inner_reverse__(this->arr, rotFactor, this->a_end - 1);
	__inner_reverse__(this->arr, 0, this->a_end - 1);
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL bool Array<T, E>::isOdd(uint32 index) {
	if (index < this->len)
		if (this->arr[index] % 2 == 0)
			return false;
		else
			return true;
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL bool Array<T, E>::isEven(uint32 index) {
	if (index < this->len)
		if (this->arr[index] % 2 == 0)
			return true;
		else
			return false;
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL bool Array<T, E>::includes(T item) {
	for (int32 i = 0; i < this->len; i++)
		if (this->arr[i] == item)
			return true;
	return false;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL void Array<T, E>::pprint() {
	for (int32 x = 0; x < this->len; x++)
		printf("Index: %i -> value: %i\n", x, this->arr[x]);
}


// Operator overloaded functions

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL T& Array<T, E>::operator [] (uint32 index) {
	if (index < this->len) {
		return this->arr[index];
	}
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL T Array<T, E>::operator [] (uint32 index) const {
	if (index < this->len)
		return this->arr[index];
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}


template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E> Array<T, E>::operator = (const Array& a) {
	for (int32 i = 0; i < this->len; i++)
		this->arr[i] = a.arr[i];
	this->len = a.len;
	this->a_begin = a.a_begin;
	this->a_end = a.a_end;
	this->size = a.size;
	this->curr_pos = a.curr_pos;
	this->size = a.size;
	return *this;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E> Array<T, E>::operator = (Array& a) {
	for (int32 i = 0; i < this->len - 1; i++)
		this->arr[i] = a.arr[i];
	this->len = a.len;
	this->a_begin = a.a_begin;
	this->a_end = a.a_end;
	this->size = a.size;
	this->curr_pos = a.curr_pos;
	this->size = a.size;
	return *this;
}

template <typename T, uint32 E>
LGE_CUDA_FUNC_DECL Array<T, E> Array<T, E>::operator = (T a[]) {
	if (__lge_len(a) > this->len)
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));

	for (int32 i = 0; i < this->len; i++)
		this->arr[i] = a[i];

	this->curr_pos = __lge_len(this->arr);
	this->a_begin = 0;
	this->a_end = this->curr_pos;
	this->size = sizeof(this->arr);
	return *this;
}

// =====================================================================
// List class
// =====================================================================

template <typename T>
List<T>::List()
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(sizeof(T) * 10), len(0)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = LGE_LIST_BUFFER;
	this->len = 0;
#endif

	//for (uint32 i = 0; i < this->size / sizeof(T); i++)
	//	this->l[i] = 0;
}

template <typename T>
List<T>::List(List& l)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(l.size), len(l.len)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = l.size;
	this->len = l.len;
#endif

	for (uint32 i = 0; i < this->size / sizeof(T); i++)
		this->l[i] = l.l[i];
}

template <typename T>
List<T>::List(const List& l)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(l.size), len(l.len)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = l.size;
	this->len = l.len;
#endif

	for (uint32 i = 0; i < this->len; i++)
		this->l[i] = l.l[i];
}

template <typename T>
List<T>::List(const std::initializer_list<T>& ilist)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(sizeof(T) * 10), len(0)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = sizeof(T) * 10;
	this->len = 0;
#endif

	for (const T item : ilist)
		this->append(item);
}

template <typename T>
List<T>::~List() {
	free(this->l);
	this->l = nullptr;
}

// private functions

template <typename T>
LGE_CUDA_FUNC_DECL T* List<T>::resize(T* oldArr, size_t newSize, size_t oldSize) {
	T* temp = (T*)malloc(newSize);
	for (uint32 i = 0; i < oldSize / sizeof(T); i++)
		temp[i] = oldArr[i];

	return temp;
}

// public functions

template <typename T>
LGE_CUDA_FUNC_DECL List<T>& List<T>::append(T item) {
	if (this->len * sizeof(T) >= this->size) {
		size_t oldSize = this->size;
		this->size += (this->size * this->size) * sizeof(T);
		this->l = this->resize(this->l, this->size, oldSize);
		this->l[this->len++] = item;
	}
	else
		this->l[this->len++] = item;

	return *this;
}

template <typename T>
LGE_CUDA_FUNC_DECL List<T>& List<T>::append(T) const {
	if (this->len * sizeof(T) >= this->size) {
		size_t oldSize = this->size;
		this->size += (this->size * this->size) * sizeof(T);
		this->l = this->resize(this->l, this->size, oldSize);
		this->l[this->len++] = item;
	}
	else
		this->l[this->len++] = item;

	return *this;
}

template <typename T>
LGE_CUDA_FUNC_DECL uint32 List<T>::emplace(uint32 index, T item) {
	LGE_AUTO __shift_items__ = [&](uint32 index, size_t currSize, T item) -> T* {
		T* temp = (T*)malloc(currSize);
		uint32 new_len = len + 1;
		T subbed_item;

		for (uint32 c = 0; c < len; c++)
			temp[c] = l[c];

		for (int32 i = index; i < new_len; i++) {
			if (i == index) 
				temp[i] = item;
			else
				temp[i] = l[i-1];
		}

		return temp;
	};

	if (index < this->len) {
		if (this->len * sizeof(T) >= this->size) {
			size_t oldSize = this->size;
			this->size += (this->size * this->size) * sizeof(T);
			this->l = this->resize(this->l, this->size, oldSize);
		}

		this->l = __shift_items__(index, this->size, item);
		this->len++;

		return index;
	}
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));

}

template <typename T>
LGE_CUDA_FUNC_DECL List<T>& List<T>::pop() {
	this->len--;
	for (int32 i = this->len; i > this->len; i--)
		this->l[i] = this->l[i - 1];

	return *this;
}

template <typename T>
LGE_CUDA_FUNC_DECL List<T>& List<T>::shift() {
	this->len--;
	for (int32 i = 0; i < this->len; i++)
		this->l[i] = this->l[i + 1];

	return *this;

}

template <typename T>
LGE_CUDA_FUNC_DECL List<T>& List<T>::del(T item) {
	uint32 index;
	for (index = 0; index < this->len; index++)
		if (this->l[index] == item)
			break;

	if (index < this->len) {
		this->len--;
		for (int32 i = index; i < this->len; i++)
			this->l[i] = this->l[i + 1];
		return *this;
	}
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}

template <typename T>
LGE_CUDA_FUNC_DECL void List<T>::pprint() {
	for (int32 x = 0; x < this->len; x++)
		printf("Index: %i -> value: %i\n", x, this->l[x]);
}

template <typename T>
LGE_CUDA_FUNC_DECL T& List<T>::operator [] (uint32 index) {
	if (index < this->len)
		return this->l[index];
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}

template <typename T>
LGE_CUDA_FUNC_DECL T List<T>::operator [] (uint32 index) const {
	if (index < this->len)
		return this->l[index];
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));
}

template <typename T>
LGE_CUDA_FUNC_DECL List<T> List<T>::operator = (T a[]) {
	if (__lge_len(a) > this->len)
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception "));

	this->len = __lge_len(a);
	this->size = sizeof(a);

	for (int32 i = 0; i < this->len; i++)
		this->l[i] = a[i];

	return *this;
}

template <typename T>
LGE_CUDA_FUNC_DECL List<T> List<T>::operator = (const List& l) {
	this->len = l.len;
	this->size = l.size;

	for (uint32 i = 0; i < this->size / sizeof(T); i++)
		this->l[i] = l.l[i];

	return *this;
}

template <typename T>
LGE_CUDA_FUNC_DECL List<T> List<T>::operator = (List& l) {
	this->len = l.len;
	this->size = l.size;
	
	for (uint32 i = 0; i < this->size / sizeof(T); i++)
		this->l[i] = l.l[i];

	return *this;
}

// =====================================================================
// Linked-List class methods
// =====================================================================

template <typename T>
sLinkedList<T>::sLinkedList()
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(0), len(0), head(NULL)
#endif
{
#ifndef  LGE_HAS_INITIALIZER_LIST
	this->size = 0;
	this->len = 0;
	this->head = NULL;
#endif

}

template <typename T>
sLinkedList<T>::sLinkedList(const sLinkedList& ll)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(ll.size), len(ll.len), head(ll.head)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = ll.size;
	this->len = ll.len;
	this->head = ll.head;
#endif
}

template <typename T>
sLinkedList<T>::~sLinkedList() {
	sNode<T>* current = this->head;

	while (current != NULL) {
		sNode<T>* next = current->link;
		delete current;
		current = next;
	}

	this->head = nullptr;
	current = nullptr;
}

template <typename T>
LGE_CUDA_FUNC_DECL void sLinkedList<T>::push(T data) {
	sNode<T>* new_node = new sNode<T>();
	new_node->data = data;
	new_node->size = sizeof(T);
	new_node->link = this->head;
	this->head = new_node;
	this->size += sizeof(T);
	this->len++;
}

template <typename T>
LGE_CUDA_FUNC_DECL void sLinkedList<T>::insertAt(T data, uint32 index) {
	if (this->head == NULL)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \nPrevious node cannot be NULL.\n"));

	sNode<T>* new_node = new sNode<T>();
	new_node->data = data;
	new_node->size = sizeof(T);
	new_node->link = this->head;
	this->head = new_node;
	this->len++;

}

template <typename T>
LGE_CUDA_FUNC_DECL void sLinkedList<T>::append(T data) {
	sNode<T>* new_node = new sNode<T>();
	sNode<T>* tail = this->head;

	new_node->data = data;
	new_node->size = sizeof(T);
	new_node->link = NULL;

	if (head == NULL) {
		this->head = new_node;
	}
	else {
		while (tail->link != NULL)
			tail = tail->link;
		tail->link = new_node;
		tail->size = sizeof(T);
	}

	this->size += sizeof(T);
	this->len++;
}

template <typename T>
LGE_CUDA_FUNC_DECL void sLinkedList<T>::shift() {
	if (this->head == NULL)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \nFirst node cannot be removed if Singly LinkedList is empty."));

	sNode<T>* second_node = this->head->link;
	this->head = second_node;
	this->size -= sizeof(T);
	this->len--;
}

template <typename T>
LGE_CUDA_FUNC_DECL void sLinkedList<T>::removeAt(uint32 index) {
	// Needs some debugging
	if (this->head == NULL)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \nFirst node cannot be removed if Singly LinkedList is empty."));

	sNode<T>* t = this->head;

	if (index == 0) {
		this->head = t->link;
		delete t;
		t = NULL;
	}
	else {
		for (int32 i = 0; t != NULL && i < index - 1; i++)
			t = t->link;

		if (t == NULL || t->link == NULL)
			return;

		sNode<T>* next = t->link->link;
		delete t->link;
		t->link = next;

	}
}

template <typename T>
LGE_CUDA_FUNC_DECL sNode<T>* sLinkedList<T>::getNodeAt(uint32 index) {
	if (this->head == NULL)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \nCannot get nTh node, sLinkedList is empty."));

	uint32 count = 0, i;
	sNode<T>* t = this->head;

	while (t != NULL) {
		t = t->link;
		count++;
	}

	if (count < index)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \nIndex error. "));

	t = this->head;

	for (i = 1; i < count - index + 1; i++)
		t = t->link;

	if (t == NULL)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \n"));
	else
		return t;
}

template <typename T>
LGE_CUDA_FUNC_DECL T sLinkedList<T>::getItemAt(uint32 index) {
	if (this->head == NULL)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \nCannot get nTh item, sLinkedList is empty."));

	uint32 count = 0, i;
	sNode<T>* t = this->head;

	while (t != NULL) {
		t = t->link;
		count++;
	}

	if (count < index)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \nIndex error. "));

	t = this->head;

	for (i = 1; i < count - index + 1; i++)
		t = t->link;

	if (t == NULL)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \n"));
	else
		return t->data;
}

template <typename T>
LGE_CUDA_FUNC_DECL void sLinkedList<T>::reverse() {

}

template <typename T>
LGE_CUDA_FUNC_DECL void sLinkedList<T>::removeDuplicates() {

}

template <typename T>
LGE_CUDA_FUNC_DECL T sLinkedList<T>::searchItem(T item) {
	if (this->head == NULL)
		throw NullPtrException(const_cast<char*>("LGE::NullPtrException \nCannot search sLinkedList, list is empty.\n"));

	sNode<T>* t = this->head;
	uint32 count = 1;

	while (t != NULL)
		if (t->data == item)
			return count;
		else {
			t = t->link;
			count++;
		}
	delete t;
}

template <typename T>
LGE_CUDA_FUNC_DECL sLinkedList<T>& sLinkedList<T>::pprint() {
	sNode<T>* copy = this->head;
	while (copy != NULL) {
		std::cout << copy->data << " -> ";
		copy = copy->link;
	}
	printf("\n");
	delete copy;
	return *this;
}

template <typename T>
LGE_CUDA_FUNC_DECL T& sLinkedList<T>::operator [] (uint32 index) {
	if (index < this->len) {
		int16 count = 0;
		sNode<T>* temp = this->head;

		while (count != index) {
			temp = temp->link;
			count++;
		}

		this->len++;
		if (count == index)
			return temp->data;
	}
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception\n Index of linkedlist is out of bounds."));
}

template <typename T>
LGE_CUDA_FUNC_DECL T sLinkedList<T>::operator [] (uint32 index) const {
	if (index < this->len) {
		int16 count = 0;
		sNode<T>* temp = this->head;

		while (count != index) {
			temp = temp->link;
			count++;

			if (temp == NULL)
				return 0;
		}

		if (count == index)
			return temp->data;
	}
	else
		throw ArrayOutOfBounds(const_cast<char*>("LGE::ArrayOutOfBounds Exception\n Index of linkedlist is out of bounds."));
}

template <typename T>
LGE_CUDA_FUNC_DECL sLinkedList<T> sLinkedList<T>::operator = (const sLinkedList& ll) {
	this->size = ll.len;
	this->len = ll.len;
	this->head = ll.head;
}

// =====================================================================
// Stack class methods
// =====================================================================

template <typename T, uint32 C>
Stack<T, C>::Stack()
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(sizeof(T)* C), top(0)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = sizeof(T) * C;
	this->top = 0;
#endif
}

template <typename T, uint32 C>
Stack<T, C>::Stack(const Stack& s)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(s.size), top(s.top)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = s.size;
	this->top = s.top;
#endif
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL Stack<T, C>& Stack<T, C>::push(T v) {
	if (this->top >= C) {
		throw Exception(const_cast<char*>("LGE::Exception\n Reached maximum capacity of the stack.\n"));
	}
	else {
		this->sarr.insertAt(v, top);
		this->top++;
		this->size += sizeof(T);
	}

	return *this;
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL void Stack<T, C>::pop() {
	if (this->top < 0) {
		throw Exception(const_cast<char*>("LGE::Exception\n Reached minimum capacity of the stack.\n"));
	}
	else {
		this->sarr[--top];
		this->size -= sizeof(T);
	}
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL bool Stack<T, C>::isEmpty() {
	return (this->top <= 0);
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL T Stack<T, C>::peek() {
	if (this->isEmpty())
		return 0;
	else
		return this->sarr[top - 1];
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL Stack<T, C>& Stack<T, C>::sort() {
	Stack<T, C> new_stack = Stack<T, C>();

	while (!this->isEmpty()) {
		T tmp = this->peek();
		this->pop();
		while (!new_stack.isEmpty() && new_stack.peek() > tmp) {
			this->push(new_stack.peek());
			new_stack.pop();
		}
		new_stack.push(tmp);
	}
	*this = new_stack;
	return *this;
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL Stack<T, C>& Stack<T, C>::pprint() {
	for (int32 x = 0; x < this->top; x++)
		printf("Index: %i -> value: %i\n", x, this->sarr[x]);
	return *this;
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL T& Stack<T, C>::operator [] (uint32 index) {
	this->top++;
	return this->sarr[index];
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL T Stack<T, C>::operator [] (uint32 index) const {
	return this->sarr[index];
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL Stack<T, C> Stack<T, C>::operator = (const Stack& s) {
	this->sarr = s.sarr;
	this->size = s.size;
	this->max_capacity = s.max_capacity;
	this->top = s.top;
	return *this;
}

// =====================================================================
// Queue/Dequeue class methods
// =====================================================================

template <typename T, uint32 C>
Queue<T, C>::Queue()
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(0), front(0), rear(C - 1), len(0)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = 0;
	this->front = 0;
	this->rear = C - 1;
	this->len = 0;
#endif
}

template <typename T, uint32 C>
Queue<T, C>::Queue(const Queue& q)
#ifdef LGE_HAS_INITIALIZER_LIST
	: size(q.size), front(q.front), rear(q.rear), len(q.len)
#endif
{
#ifndef LGE_HAS_INITIALIZER_LIST
	this->size = q.size;
	this->front = q.front;
	this->rear = q.rear;
	this->len = q.len;
#endif
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL void Queue<T, C>::enqueue(T item) {
	if (this->isFull())
		return;
	this->rear = (this->rear + 1) % this->max_capacity;
	this->qarr.insertAt(item, this->rear);
	this->len = this->len + 1;
	this->size += sizeof(T);
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL T Queue<T, C>::dequeue() {
	if (this->isEmpty())
		return INT_MIN;
	T item = this->qarr[this->front];
	this->front = (this->front + 1) % this->max_capacity;
	this->len = this->len - 1;
	this->size += sizeof(T);
	return item;
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL bool Queue<T, C>::isFull() {
	return this->len == this->max_capacity;
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL bool Queue<T, C>::isEmpty() {
	return this->len <= 0;
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL T Queue<T, C>::getFront() {
	return this->qarr[this->front];
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL T Queue<T, C>::getRear() {
	return this->qarr[this->rear];
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL Queue<T, C> Queue<T, C>::operator = (const Queue& q) {
	for (int32 i = 0; i < max_capacity - 1; i++)
		this->qarr[i] = q.qarr[i];
	this->size = q.size;
	this->front = q.front;
	this->rear = q.rear;
	this->max_capacity = q.max_capacity;
	this->len = q.len;
	return *this;
}

template <typename T, uint32 C>
LGE_CUDA_FUNC_DECL void Queue<T, C>::pprint() {
	this->qarr.pprint();
}

// =====================================================================
// Dictionary class methods 
// =====================================================================


// =====================================================================
// Functional paradigm functions
// =====================================================================

template <typename T>
LGE_CUDA_FUNC_DECL int32 ifind(List<T> list, T value) {
	int32 index;

	for (index = 0; i < list.len; index++)
		if (list[index] == value)
			return index;

	lgeASSERT(LGE_FALSE);
	return NULL;
}


template <typename T>
LGE_CUDA_FUNC_DECL T find(List<T> list, T value) {
	int32 index;

	for (index = 0; index < list.len; index++)
		if (list[index] == value)
			return list[index];

	lgeASSERT(LGE_FALSE);
	return NULL;
}

//template <typename T, uint32 E>
//Array<T, E> filter(bool(*callBack)(T element, uint32 index), Array<T, E> arr) {
//	Array<T, E> new_arr = arr;

//	for (int32 i = 0; i < new_arr.len; i++)
//		if (callBack(arr[i], i))
//			new_arr.removeAt(i);

//	return new_arr;
//}

//template <typename T, uint32 E>
//Array<T, E> iter(Array<T, E>& arr) {

//}

//template <typename Func>
//LGE_CUDA_FUNC_DECL void forEach(Func func) {

//}

//template <typename Func>
//LGE_CUDA_FUNC_DECL void map(Func func) {

//}

_LGE_END_NP_LGE_CORE