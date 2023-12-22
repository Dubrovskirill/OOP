#include<stdint.h>
#include<string>
#include<iostream>
#include "Set.h"

Set::Set(const char* str)
	:Set()
{
	for (int i = 0; i < strlen(str); i++)
	{
		if ( str[i] >= offset && str [i] <= offset+capacity && !operator[](str[i] - offset))
			Set1((int)str[i] - offset);
		
	}

}

Set::Set(const Set& other) 
	:BoolVector(other)
{}

void Set::Print() const
{
	std::cout << "{ ";
	if(!isEmpty())
		for (char i = offset; i <= Lenght()+offset; i++)
	    {
			if (operator[](i - offset))
			std::cout << i << " ";
	    }
	std::cout << "}"<<std::endl;
}

bool Set::isEmpty() const
{
	if (!Weight())
		return true;
	return false;
}

int Set::Weight() const
{
	return BoolVector::Weight();
}

//bool Set::isPresent(const char c) const
//{
//	if (c >= offset && c <= offset + capacity)
//		return false;
//	int cell = ((int)c - offset) / m_cellSize;
//	int pos = ((int)c - offset) % m_cellSize;
//	uint8_t mask = 1;
//	mask = mask << 7-pos;
//	if (m_set->operator[]((int)c - offset) && mask)
//		return true;
//	return false;
//	
//}

std::ostream& operator << (std::ostream& stream, const Set& other)
{
	if (other.isEmpty())
	{
		std::cout << "[ ]";
		return stream;
	}

	std::cout << "[ ";

	for (char i = other.offset; i <= other.Lenght() + other. offset; i++)
	{
		if (other.operator[](i - other.offset))
			std::cout << i << " ";
	}
	/*for (char i = offset; i <= m_set->Lenght() + offset; i++)
	{
		if (m_set->operator[](i - offset))
			std::cout << i << " ";
	}*/
	std::cout << "]";
	std::cout << std::endl;
	return stream;

}
//std::istream& operator >> (std::istream& stream, Set& other)
//{
//
//
//	/*char s;
//	for (int i = 0; i < bvec.Lenght(); i++)
//	{
//		stream >> s;
//		if (s == '0')
//			bvec.Set0(i);
//		else
//			bvec.Set1(i);
//	}*/
//	return stream;
//}