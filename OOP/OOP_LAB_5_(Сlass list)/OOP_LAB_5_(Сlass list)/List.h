#ifndef IS_TEMPLATE_LIST_DECLARED
#define IS_TEMPLATE_LIST_DECLARED

#pragma once
#include <iostream>
#include <algorithm>
#include <assert.h>
#include "..//..//OOP_LAB_2//OOP_LAB_2//Array.h"




template<typename ItemType>
class List
{
	using UI = unsigned int;
public:
	class Node;

	void FormHeadTail();
	void DelHeadTail();
	List(const List& other);
	List(UI size=0, const ItemType value = ItemType());
	//List(const Array<ItemType>& arr);
	~List();

	void PushBack(const ItemType &value);
	void Print();
private:
	
	UI m_size;
	Node* m_head;
	Node* m_tail;
};


template<typename ItemType>
class List<ItemType>::Node
{
public:
	friend class List;
private:
	Node(const ItemType& data)
		:data(data)
	{}

	ItemType data = ItemType();
	Node* prev = nullptr;
	Node* next = nullptr;
};

#include "List.cpp"
#endif

