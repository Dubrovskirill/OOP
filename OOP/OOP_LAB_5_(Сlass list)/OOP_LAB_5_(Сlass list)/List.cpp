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
void List<ItemType> ::PushBack(const ItemType& value) {
    Node* newNode = new Node(value);
    newNode->prev = m_tail->prev;
    newNode->next = m_tail;
    m_tail->prev->next = newNode;
    m_tail->prev = newNode;
    m_size++;
}

template<typename ItemType>
void List<ItemType>::Print()
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
#endif

//�������� ������������ �� ���������, � ����������, �����������. ����� Pushback, Print