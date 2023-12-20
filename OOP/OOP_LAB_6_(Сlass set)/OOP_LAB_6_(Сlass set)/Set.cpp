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