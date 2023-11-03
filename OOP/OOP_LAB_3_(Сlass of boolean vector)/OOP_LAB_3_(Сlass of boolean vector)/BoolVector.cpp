#include "BoolVector.h"
#include<stdint.h>
#include<iostream>
#include <assert.h>

using UI = unsigned int;
using UC = unsigned char;

BoolVector::BoolVector()
{
	m_length = m_size;
    m_cellcount = m_length / 8 + (m_length % 8 > 0);
	m_data = new UC[m_cellcount];
	m_data[0] = false;
	
}

BoolVector::~BoolVector()
{
	delete[]m_data;
}

BoolVector::BoolVector(const UI length, const bool value)
{
	m_length = length;
	m_cellcount = m_length / 8 + (m_length % 8 > 0);
	m_insignificantpart = m_size * m_cellcount - m_length;
	m_data = new UC[m_cellcount];
	uint8_t mask = 0;
	for (int i = 0; i < m_cellcount; i++)
	{
		if (value)
			m_data[i] = m_data[i] | ~mask;
		else
			m_data[i] = m_data[i] & mask;
	}

	m_data[m_cellcount - 1] = m_data[m_cellcount - 1] >> m_insignificantpart;
	m_data[m_cellcount - 1] = m_data[m_cellcount - 1] << m_insignificantpart;
}

BoolVector::BoolVector(const char* data)
{
	m_length = strlen(data);
	m_cellcount = m_length / 8 + (m_length % 8 > 0);
	m_insignificantpart = m_size * m_cellcount - m_length;
	m_data = new UC[m_cellcount];
	for (int i = 0; i < m_length; i++)
	{
		if (data[i] == '1')
			Set1(i / m_size, i % m_size);
		else
			Set0(i / m_size, i % m_size);
	}
	m_data[m_cellcount - 1] = m_data[m_cellcount - 1] >> m_insignificantpart;
	m_data[m_cellcount - 1] = m_data[m_cellcount - 1] << m_insignificantpart;
}

BoolVector::BoolVector(const BoolVector& other)
	:m_length(other.m_length)
{
	m_cellcount = other.m_cellcount;
	m_data = new UC[m_cellcount];
	m_insignificantpart = (m_cellcount * m_size) - m_length;
	for (int i = 0; i < m_cellcount; i++)
	{
		m_data[i] = other.m_data[i];
	}
}

void BoolVector::PrintCell(const int& cell)const
{
	
	for (uint8_t i = 128; i > 0; i >>= 1)
	{
		if (m_data[cell] & i)
			std::cout << "1 ";
		else
			std::cout << "0 ";
	}
}

void BoolVector::Print()const
{
	for (int i = 0; i < m_cellcount; i++)
	{
		std::cout << "[ ";
		PrintCell(i);
		std::cout << "]";
	}
	std::cout << std::endl;
}

int BoolVector::Lenght() const
{
	return m_length;
}

int BoolVector::CellCount() const
{
	return m_cellcount;
}

void  BoolVector::Set1(const int& cell, const int& pos)const
{
	uint8_t mask = 1;
	mask = mask << 7-pos;
	m_data[cell] = m_data[cell] | mask;
}

void  BoolVector::Set0(const int& cell, const int& pos)const
{
	uint8_t mask = 1;
	mask = mask<< 7-pos;
	m_data[cell] = m_data[cell] & ~mask;
}

void BoolVector::Swap(BoolVector& other)
{
	std::swap(m_length, other.m_length);
	std::swap(m_cellcount, other.m_cellcount);
	std::swap(m_insignificantpart, other.m_insignificantpart);
	std::swap(m_data, other.m_data);
}

UC& BoolVector::operator[](const int index)
{
	assert(index >= 0 && index < m_size);
	return m_data[index];
}

const UC& BoolVector::operator[](const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_data[index];
}

std::ostream& operator<<(std::ostream& stream, const BoolVector& bvec)
{
	for (int i = 0; i < bvec.CellCount(); i++)
	{
		stream << "[ ";
		for (uint8_t j = 128; j > 0; j >>= 1)
		{
			if (bvec[i] & j)
				std::cout << "1 ";
			else
				std::cout << "0 ";
		}
		stream << "]";
	}
	std::cout << std::endl;
	return stream;
}

std::istream& operator >> (std::istream& stream, BoolVector& bvec)
{
	char s;
	for (int i = 0; i < bvec.Lenght(); i++)
	{
		stream >> s;
		if (s == '1')
			bvec.Set1(i / bvec.m_size, i % bvec.m_size);
		else
			bvec.Set0(i / bvec.m_size, i % bvec.m_size);
	}
	return stream;
}

/*std::ostream& operator<<(std::ostream& stream, const Array<ItemType>& arr)
{
	stream << "[";
	for (int i = 0; i < arr.Size() - 1; i++)
		stream << arr[i] << ",";

	stream << arr[arr.Size() - 1] << "]\n";
	return stream;
}

template <typename ItemType>
std::istream& operator >> (std::istream& stream, Array<ItemType>& arr)
{
	for (int i = 0; i < arr.Size(); i++)
		stream >> arr[i];

	return stream;
}*/
