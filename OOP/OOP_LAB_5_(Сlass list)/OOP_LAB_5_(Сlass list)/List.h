#ifndef IS_TEMPLATE_LIST_DECLARED
#define IS_TEMPLATE_LIST_DECLARED

//pragma once

#include <iostream>
#include <algorithm>
#include <assert.h>
#include "../../OOP_LAB_2/OOP_LAB_2/Array.h"
#include "../../../OOP/OOP_LAB_4_(Ñlass of boolean matrix)/BoolMatrix/BoolMatrix.h"



template<typename ItemType>
class List
{
	using UI = unsigned int;
public:
	friend class Graph;
	class Node;

	template <typename IT>
	class TemplateIterator;
	using Iterator = TemplateIterator<ItemType>;
	using ConstIterator = TemplateIterator<const ItemType>;

	void FormHeadTail();
	void DelHeadTail();
	List(const List& other);
	List(UI size=0, const ItemType value = ItemType());
	List(const Array<ItemType>& arr);
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
	void Insert(const int pos, const ItemType& value);
	void Insert(const Iterator& it, const ItemType& value);
	void InsertAfter(const ItemType& key, const ItemType& value);
	void Remove(const int pos);
	Iterator Remove(Iterator it);
	bool RemoveKey(const ItemType& key);
	void RemoveRange(Iterator first, Iterator last);
	ItemType Max()const;
	ItemType Min()const;
	Iterator Search(const ItemType& key);
	ConstIterator Search(const ItemType& key) const;
	void Sort();

	ItemType& operator[](const UI index);
	const ItemType& operator[](const UI index) const;
	bool operator==(const List& other) const;
	bool operator!=(const List& other) const;
	List& operator=(List&& other);
	List& operator=(const List& other);
	List operator+(const List& other) const;
	List& operator+=(const List& other);

	Iterator begin();
	Iterator end();
	ConstIterator begin() const;
	ConstIterator end() const;
	Iterator pos(const int index);
	ConstIterator pos(const int index) const;
	//friend Array<int> TSortList(BoolMatrix matrix);

private:
	void TakeNode(Iterator& it);
	//ConstIterator TakeNode(ConstIterator& it) const;
	void InsertNode(Iterator& current, const Iterator& other);
	void SwapNode(Iterator& current, Iterator& other);
	int PosNode(Iterator& current);

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
	friend class Graph;
	//friend Array<int> TSortList(BoolMatrix matrix);
private:
	Node(const ItemType& data)
		:data(data)
	{}

	ItemType data = ItemType();
	Node* prev = nullptr;
	Node* next = nullptr;
};


template <typename ItemType>
template <typename IT>
class List<ItemType>::TemplateIterator
{
public:
	friend class List;
	friend class Graph;
	TemplateIterator(Node* node = nullptr);
	//TemplateIterator(const TemplateIterator& other);
	IT& operator*();
	const IT& operator*() const;
	TemplateIterator& operator++();
	TemplateIterator& operator--();
	TemplateIterator& operator++(int);
	TemplateIterator& operator--(int);
	TemplateIterator& operator+(const int& index);
	TemplateIterator& operator-(const int& index);


	bool operator == (const TemplateIterator& other) const;
	bool operator != (const TemplateIterator& other) const;
	//friend Array<int> TSortList(BoolMatrix matrix);
private:
	Node* m_node = nullptr;
};

#include "List.cpp"
#endif 