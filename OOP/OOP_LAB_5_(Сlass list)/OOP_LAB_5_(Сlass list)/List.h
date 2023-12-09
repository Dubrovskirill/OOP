#ifndef IS_TEMPLATE_LIST_DECLARED
#define IS_TEMPLATE_LIST_DECLARED

#pragma once
//#define guards
#include <iostream>
#include <algorithm>
#include <assert.h>
//#include "..//..//OOP_LAB_2//OOP_LAB_2//Array.h"




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
	void PopBack();
	void PushFront(const ItemType& value);
	void PopFront();

	void Print() const;
	UI Size() const;
	void Swap(List& other);
	bool isEmpty() const;
	void Clear();

	ItemType& operator[](const UI index);
	const ItemType& operator[](const UI index) const;
	bool operator==(const List& other) const;
	bool operator!=(const List& other) const;
	List& operator=(List&& other);
	List& operator=(const List& other);

private:
	
	UI m_size;
	Node* m_head;
	Node* m_tail;
};
template <typename ItemType>
std::ostream& operator<<(std::ostream& stream, const List<ItemType>& list);
template <typename ItemType>
std::istream& operator >> (std::istream& stream, List<ItemType>& list);

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

