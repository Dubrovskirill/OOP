#include "BoolVector.h"
#include<stdint.h>
#include<iostream>

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

