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

bool Set::isPresent(const char c) const
{
	const int charCode = static_cast<int>(c);
	if (!(c >= offset && c <= offset + capacity))
		return false;

	if (operator[]((int)c - offset))
		return true;
	return false;
	
}

char Set::Max() const
{
	if (isEmpty())
		return char(0);

	for (int i = CellCount()-1; i >= 0; i--)
	{
		uint8_t mask = 1;
		for (int j = m_cellSize-1; j >= 0; j--)
		{
			if (m_data[i] & mask)
			{
				return char(i * m_cellSize + j + offset);
			}
			mask <<= 1;
		}
	}
	return char(0);

}

char Set::Min() const
{
	if(isEmpty())
		return char(0);
	
	for (int i = 0; i < CellCount(); i++)
	{
		uint8_t mask = 1;
		mask <<= 7;
		for (int j = 0; j < m_cellSize; j++)
		{
			if (m_data[i] & mask)
			{
				return char(i * m_cellSize + j+offset);
			}
			mask >>= 1;
		}
	}
	return char(0);
}

Set& Set::operator= (Set&& other)
{
	Swap(other);
	return *this;
}

Set& Set::operator= (const Set& other)
{
	if (this == &other) return *this;
	for (int i = 0; i < CellCount(); i++)
		if (m_data[i] != other.m_data[i])
			m_data[i] = other.m_data[i];
}

bool Set::operator==(const Set& other) const
{
	for (int i = 0; i < CellCount(); i++)
		if (m_data[i] != other.m_data[i])
			return false;
	return true;
}

bool Set::operator!=(const Set& other) const
{
	return !operator==(other);
}

Set& Set::operator|(const Set& other) const
{
	Set tmp;
	for (int i = 0; i < CellCount(); i++)
		tmp.m_data[i] = m_data[i] | other.m_data[i];
	return tmp;
}

Set& Set::operator|=(const Set& other)
{
	*this = operator|(other);
	return *this;
}

Set& Set::operator&(const Set& other) const
{   
	Set tmp;
	for (int i = 0; i < CellCount(); i++)
		tmp.m_data[i] = m_data[i] & other.m_data[i];
	return tmp;
}

Set& Set::operator&=(const Set& other)
{
	*this = operator&(other);
	return *this;
}

Set& Set::operator/(const Set& other) const
{
	Set tmp;
	for (int i = 0; i < CellCount(); i++)
		tmp.m_data[i] = m_data[i] & ~other.m_data[i];
	return tmp;
}

Set& Set::operator/=(const Set& other)
{
	*this = operator/(other);
	return *this;
}

Set& Set::operator~() const
{
	Set set(*this);
	set.Inverse();
	return set;
	
}

Set& Set::operator+(const char& str) const
{
	Set tmp (*this);
	if (str >= offset && str <= offset + capacity && !operator[](str - offset))
		tmp.Set1((int)str - offset);

	return tmp;
}

Set& Set::operator+=(const char& str)
{
	*this = operator+(str);
	return *this;
}

Set& Set::operator-(const char& str) const
{
	Set tmp(*this);
	if (str >= offset && str <= offset + capacity && operator[](str - offset))
		tmp.Set0((int)str - offset);

	return tmp;
}

Set& Set::operator-=(const char& str)
{
	*this = operator-(str);
	return *this;
}
std::ostream& operator << (std::ostream& stream, const Set& other)
{
	stream << "{ ";

	if (!other.isEmpty())
		for (char i = Set::offset; i <= Set::capacity + Set::offset; i++)
			if (other[i - other.offset])
				stream << i << " ";

	stream << "}" << std::endl;
	return stream;
}

std::istream& operator >> (std::istream& stream, Set& other)
{
	char s=0;
	while(stream.get(s) && s != '\n')
	{
		
		if (s >= other.offset && s <= other.offset + other.capacity && !other[s - other.offset])
			other[(int)s - other.offset] = 1;
	}
	return stream;
}