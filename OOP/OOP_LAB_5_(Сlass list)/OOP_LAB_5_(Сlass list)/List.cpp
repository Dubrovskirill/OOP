#ifndef ARE_TEMPLATE_LIST_METHODS_DEFINED
#define ARE_TEMPLATE_LIST_METHODS_DEFINED


#include<stdint.h>
#include<iostream>
#include "List.h"
using UI = unsigned int;


template <typename ItemType>
void List<ItemType>::FormHeadTail()
{
    m_head = new Node(ItemType());
    m_tail = new Node(ItemType());
    m_head->next = m_tail;
    m_tail->prev = m_head;
}
template <typename ItemType>
void List<ItemType>::DelHeadTail()
{
    delete m_head;
    delete m_tail;
}

template <typename ItemType>
List<ItemType>::List(const List& other)
{
    FormHeadTail();
    Node* cur = other.m_head->next;
    while (cur != other.m_tail)
    {
        PushBack(cur->data);
        cur = cur->next;
    }
}


template <typename ItemType>
List<ItemType>::List(UI size, const ItemType value)
{
    FormHeadTail();
    for (int i = 0; i < size; i++)
        PushBack(value);
}

//template <typename ItemType>
//List<ItemType>::List(const Array<ItemType>& arr)
//{
//    FormHeadTail();
//    for (int i = 0; i < arr.Size(); i++)
//        PushBack(arr[i]);
//}

template <typename ItemType>
List<ItemType>::~List()
{
    Node* cur = m_head->next;
    while (cur != m_tail) 
    {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
    DelHeadTail();
}

template <typename ItemType>
void List<ItemType> ::PushBack(const ItemType& value) 
{
    Node* newNode = new Node(value);
    newNode->prev = m_tail->prev;
    newNode->next = m_tail;
    m_tail->prev->next = newNode;
    m_tail->prev = newNode;
    m_size++;
}

template <typename ItemType>
void List<ItemType> ::PopBack() 
{
    Node* delNode = m_tail->prev;
    delNode->prev->next = m_tail;
    m_tail->prev = delNode->prev;
    m_size--;
    delete delNode;
}

template <typename ItemType>
void List<ItemType> ::PushFront(const ItemType& value)
{
    Node* newNode = new Node(value);
    newNode->prev = m_head;
    newNode->next= m_head->next;
    m_head->next = newNode;
    newNode->next->prev = newNode;
    m_size++;
}

template <typename ItemType>
void List<ItemType> ::PopFront()
{
    Node* delNode = m_head->next;
    delNode->next->prev = m_head;
    m_head->next = delNode->next;
    m_size--;
    delete delNode;
}

template<typename ItemType>
void List<ItemType>::Print() const
{
    if (m_head->next == m_tail)
        return;
    Node* cur = m_head->next;
    std::cout << "[ ";
    while (cur != m_tail->prev) 
    {
        std::cout<< cur->data << ", ";
        cur = cur->next;
    }
    std::cout << cur->data << " ]";
    std::cout << std::endl;
}

template<typename ItemType>
UI List<ItemType>::Size() const
{
    return m_size;
}

template<typename ItemType>
void List<ItemType>::Swap(List& other)
{
    std::swap(m_head, other.m_head);
    std::swap(m_size, other.m_size);
    std::swap(m_tail, other.m_tail);
}

template<typename ItemType>
bool List<ItemType>::isEmpty() const
{
    if (m_head->next == m_tail)
        return true;
    return false;
}

template<typename ItemType>
void List<ItemType>::Clear()
{
    while (!isEmpty())
        PopBack();
}

template<typename ItemType>
void  List<ItemType>::Insert(const int pos, const ItemType& value)
{
    assert(m_size >= pos && pos>=0);
    Node* newNode = new Node(value);
    Node* cur = m_head->next;
    for (int i=0; i < pos; i++)
        cur = cur->next;
    newNode->prev = cur->prev;
    newNode->next = cur;
    cur->prev->next = newNode;
    cur->prev = newNode;
    m_size++;
}

template<typename ItemType>
void  List<ItemType>::Remove(const int pos)
{
    assert(m_size >= pos && pos >= 0);
    Node* cur = m_head->next;
    for (int i = 0; i < pos; i++)
        cur = cur->next;
    Node* delNode = cur;
    cur = cur->next;
    delNode->prev->next = cur;
    cur->prev = delNode->prev;
    m_size--;
    delete delNode;

}
template<typename ItemType>
ItemType  List<ItemType>::Max() const
{
    if (m_size <= 0)
        return ItemType();
    ItemType max = (*this)[0];
    for (int i = 1; i < m_size; i++)
        if ((*this)[i] > max)
            max = (*this)[i];
    return max;
}

template<typename ItemType>
ItemType  List<ItemType>::Min() const
{
    if (m_size <= 0)
        return ItemType();
    ItemType min = (*this)[0];
    for (int i = 1; i < m_size; i++)
        if ((*this)[i] < min)
            min = (*this)[i];
    return min;
}

template<typename ItemType>
List<ItemType>::Node *List<ItemType>::Search(const ItemType& key) const
{
    Node* cur = m_head->next;
    while(cur!=m_tail)
    {
        if (cur->data == key)
            return  cur;
        cur = cur->next;
    }

    return nullptr;

}

template<typename ItemType>
ItemType& List<ItemType>::operator[](const UI index)
{
    assert(index < m_size);
    int i = 0;
    Node* cur = m_head->next;
    while (i != index)
    {
        cur = cur->next;
        i++;
    }
    return cur->data;
}

template<typename ItemType>
const ItemType& List<ItemType>::operator[](const UI index) const
{
    assert(index < m_size);
    int i = 0;
    Node* cur = m_head->next;
    while (i != index)
    {
        cur = cur->next;
        i++;
    }
    return cur->data;
}

template<typename ItemType>
bool List<ItemType>::operator==(const List& other) const
{
    if (m_size != other.m_size)
        return false;
    for (int i = 0; i < m_size; i++)
        if ((*this)[i] != other[i])
            return false;

    return true;
}

template<typename ItemType>
bool List<ItemType>::operator!=(const List& other) const
{
    if (*this == other)
        return false;

    return true;
}

template<typename ItemType>
List<ItemType>& List<ItemType>::operator=(List&& other)
{
    Swap(other);
    return *this;
}

template<typename ItemType>
List<ItemType>& List<ItemType>::operator=(const List& other)
{
    if (*this == other) return *this;
    if (m_size != other.m_size)
    {
        Clear();
        for (int i = 0; i < other.m_size; i++)
            PushBack(other[i]);
    }
    Node* cur = m_head->next;
    for (int i = 0; i < m_size; i++)
    {
        cur->data = other[i];
        cur = cur->next;
    }

    return *this;
}

template <typename ItemType>
std::ostream& operator<<(std::ostream& stream, const List<ItemType>& list)
{
    stream << "[";
    for (int i = 0; i < list.Size()-1; i++)
        stream << list[i] << ",";

    stream << list[list.Size() - 1] << "]\n";
    return stream;
}

template <typename ItemType>
std::istream& operator >> (std::istream& stream, List<ItemType>& list)
{
    for (int i = 0; i < list.Size(); i++)
        stream >> list[i];

    return stream;
}
#endif

