#ifndef ARE_TEMPLATE_LIST_METHODS_DEFINED
#define ARE_TEMPLATE_LIST_METHODS_DEFINED
#include "List.h"
#include<stdint.h>
#include<iostream>

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
List<ItemType>::List(const List& other)
    :m_size(other.m_size)
{
    m_head = other.m_head;
    m_tail = other.m_tail;
    m_size = other.m_size;
    Node* cur = m_head->next;
    while (cur != m_tail)
    {
        Node* newNode = new Node(cur->data);
       // newNode->data = cur->data;
        newNode->next = cur->next;
        newNode->prev = cur->prev;
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

template <typename ItemType>
List<ItemType>::~List()
{
    Node* cur = m_head;
    while (cur != nullptr) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
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

