#include<stdint.h>
#include<iostream>
#include "Set.h"

Set::Set(const char* str)
{
	m_set = new BoolVector(capacity);
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= offset && str[i] <= offset+capacity)
			m_set->Set1((int)str[i] - 32);
		//m_set->Print(); std::cout << "\n";
		
	}

}

Set::Set(const Set& other) {

	m_set = new BoolVector(capacity);
	*m_set |= *other.m_set;

}

void Set::Print()
{
	if (isEmpty())
	{
		std::cout << "[ ]";
		return;
	}
	std::cout << "[ ";
	for (char i = offset; i <= m_set->Lenght()+offset; i++)
	{
		if (m_set->operator[](i - offset))
			std::cout << i << " ";
	}
	std::cout << "]";
}

bool Set::isEmpty()
{
	if (m_set == 0) return true;
	return false;
}
int  Set::Weight()
{
	return m_set->Weight();
}
bool Set::isPresent(const char c)
{
	if (c >= offset && c <= offset + capacity)
		return false;
	int cell = ((int)c - offset) / m_cellSize;
	int pos = ((int)c - offset) % m_cellSize;
	uint8_t mask = 1;
	mask = mask << 7-pos;
	if (m_set->operator[]((int)c - offset) && mask)
		return true;
	return false;
	
}