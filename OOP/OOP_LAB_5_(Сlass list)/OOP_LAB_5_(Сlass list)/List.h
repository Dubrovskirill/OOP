#ifndef IS_TEMPLATE_LIST_DECLARED
#define IS_TEMPLATE_LIST_DECLARED

//pragma once

#include <iostream>
#include <algorithm>
#include <assert.h>
#include "../../OOP_LAB_2/OOP_LAB_2/Array.h"




template<typename ItemType>
class List
{
	using UI = unsigned int;
public:
	class Node;

	template <typename IT, typename LT>
	class TemplateIterator;
	using Iterator = TemplateIterator<ItemType, List>;
	using ConstIterator = TemplateIterator<const ItemType, const List>;

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


template <typename ItemType>
template <typename IT, typename LT>
class List<ItemType>::TemplateIterator
{
public:
	friend class List;
	TemplateIterator(Node* node = nullptr);
	IT& operator*();
	TemplateIterator& operator++();
	TemplateIterator& operator--();
	TemplateIterator& operator++(int);
	TemplateIterator& operator--(int);
	TemplateIterator& operator+(const int& index);
	TemplateIterator& operator-(const int& index);


	bool operator == (const TemplateIterator& other) const;
	bool operator != (const TemplateIterator& other) const;
	/*bool operator < (const TemplateIterator& other) const;
	bool operator > (const TemplateIterator& other) const;
	bool operator >= (const TemplateIterator& other) const;
	bool operator <= (const TemplateIterator& other) const;*/
private:
	Node* m_node = nullptr;
};

#include "List.cpp"
#endif 