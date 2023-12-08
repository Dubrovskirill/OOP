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
//template <typename ItemType>
//List<ItemType>::List()
//{
//    m_head = new Node(ItemType());
//    m_tail = new Node(ItemType());
//    m_head->next = m_tail;
//    m_tail->prev = m_head;
//}

template <typename ItemType>
List<ItemType>::List(const List& other)
  :m_size(other.m_size)
{
    m_head = other.m_head;
    m_tail = other.m_tail;
    m_size = other.m_size;
    Node* slider=m_head->next;
    for (int i = 0; i < m_size; i++)
    {
        Node* newNode = new Node();
        newNode->data = slider->data;
        newNode->next = slider->next;
        newNode->prev = slider->prev; 
        slider = slider->next;
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
    Node* current = m_head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
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

#endif