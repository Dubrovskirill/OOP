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
	//m_rank=m_data;

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

	Shift();
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
	Shift();
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

void BoolVector::Shift()
{
	m_data[m_cellcount - 1] = m_data[m_cellcount - 1] >> m_insignificantpart;
	m_data[m_cellcount - 1] = m_data[m_cellcount - 1] << m_insignificantpart;
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
//void BoolVector::Inverse()
//{
//	for (int i = 0; i < m_length; i++)
//	{
//		BoolVector a(*this);
//		if (a[i])
//			Set0(i / m_size, i % m_size);
//		else
//			Set1(i / m_size, i % m_size);
//	}
//}
void BoolVector::Inverse()
{
	
	//BoolVector a(*this);
	
	for (int i = 0; i < m_length; i++)
	{
		//BoolRank r = this->m_rank[i];
		////a.r[i];
		if (m_rank(i).m_value)
			m_rank(i).Set0();
		else
			m_rank(i).Set1();
	}
}

//bool& BoolVector::operator[](const int index)
//{
//	assert(index >= 0 && index < m_size * m_cellcount);
//	uint8_t mask = 1;
//	mask = mask << 7 - index % m_size;
//	bool value = m_data[index/m_size] & mask;
//	return value;
//}
//
//const bool& BoolVector::operator[](const int index) const
//{
//	assert(index >= 0 && index < m_size*m_cellcount);
//	uint8_t mask = 1;
//	mask = mask << 7 - index%m_size;
//	bool value = m_data[index / m_size] & mask;
//	return value;
//}

BoolRank& BoolVector::operator[](const int index)
{
	assert(index >= 0 && index < m_size * m_cellcount);
	BoolRank rank(m_data,index);
	return rank;
}

const BoolRank& BoolVector::operator[](const int index) const
{
	assert(index >= 0 && index < m_size * m_cellcount);
	BoolRank rank(m_data, index);
	return rank;
}

BoolVector& BoolVector::operator= (BoolVector&& other)
{
	Swap(other);
	return *this;
}

BoolVector& BoolVector::operator= (const BoolVector& other)
{
	if (this == &other) return *this;

	if (m_length != other.m_length)
	{
		m_length = other.m_length;
		m_cellcount = other.m_cellcount;
		m_insignificantpart = other.m_insignificantpart;
		delete[] m_data;
		m_data = new UC[m_length];
	}
	for (int i = 0; i < m_cellcount; i++)
		m_data[i] = other.m_data[i];
}

BoolVector BoolVector::operator&(const BoolVector& other) const
{
	BoolVector bvec = (std::max(m_length, other.m_length));
	int min = std::min(m_cellcount, other.m_cellcount);
	for (int i = 0; i < min; i++)
		bvec.m_data[i] = m_data[i] & other.m_data[i];
	return bvec;
}

BoolVector& BoolVector::operator&=(const BoolVector& other)
{
	BoolVector tmp(*this & other);
	Swap(tmp);
	return *this;
}

BoolVector BoolVector::operator|(const BoolVector& other) const
{
	BoolVector bvec = (std::max(m_length, other.m_length));
	int min = std::min(m_cellcount, other.m_cellcount);
	for (int i = 0; i < min; i++)
		bvec.m_data[i] = m_data[i] | other.m_data[i];
	for (int i = min; i < m_cellcount; i++)
		bvec.m_data[i] = m_data[i];
	for (int i = min; i < other.m_cellcount; i++)
		bvec.m_data[i] = other.m_data[i];
	return bvec;
}

BoolVector& BoolVector::operator|=(const BoolVector& other)
{
	BoolVector tmp(*this | other);
	Swap(tmp);
	return *this;
}

BoolVector BoolVector::operator^(const BoolVector& other) const
{
	BoolVector bvec = (std::max(m_length, other.m_length));
	int min = std::min(m_cellcount, other.m_cellcount);
	for (int i = 0; i < min; i++)
		bvec.m_data[i] = m_data[i] ^ other.m_data[i];
	for (int i = min; i < m_cellcount; i++)
		bvec.m_data[i] = m_data[i];
	for (int i = min; i < other.m_cellcount; i++)
		bvec.m_data[i] = other.m_data[i];
	return bvec;
}

BoolVector& BoolVector::operator^=(const BoolVector& other)
{
	BoolVector tmp(*this ^ other);
	Swap(tmp);
	return *this;
}

BoolVector BoolVector::operator~() const
{
	BoolVector bvec(m_length);
	for (int i = 0; i < m_cellcount; i++)
		bvec.m_data[i] = ~m_data[i];
	bvec.Shift();
	return bvec;
}
BoolVector BoolVector::operator<<(const int& count) const
{
	int count_cu = count;
	if (count > m_length)
		count_cu = m_length;

	BoolVector bvec = *this;
	if (count_cu > m_size)
	{
		for (int i = 0; i + (count_cu / m_size) < m_cellcount; i++)
		{
			bvec.m_data[i] = m_data[i + (count_cu / m_size)];
			bvec.m_data[i + (count_cu / m_size)] = false;
		}
	}

	uint8_t mask = 1;
	for (int j = 0; j < (count_cu % m_size); j++)
		mask |= mask << 1;
	mask <<= m_size - (count_cu % m_size);
	for (int i = 0; i < m_cellcount - (count_cu / m_size) - 1; i++)
	{
		uint8_t mask_cu = mask;
		bvec.m_data[i] = bvec.m_data[i] << (count_cu % m_size);
		mask_cu &= bvec.m_data[i + 1];
		mask_cu >>= m_size - (count_cu % m_size);
		bvec.m_data[i] |= mask_cu;
	}
	bvec.m_data[m_cellcount - (count_cu / m_size) - 1] = bvec.m_data[m_cellcount - (count_cu / m_size) - 1] << count_cu;
	return bvec;
}

BoolVector& BoolVector::operator<<=(const int& count)
{
	BoolVector tmp(*this << count);
	Swap(tmp);
	return *this;
}


BoolVector BoolVector::operator>>(const int& count) const
{
	int count_cu = count;
	if (count > m_length)
		count_cu = m_length;

	BoolVector bvec = *this;
	if (count_cu > m_size)
	{
		for (int i = m_cellcount-1; i - (count_cu / m_size) >= 0; i--)
		{
			bvec.m_data[i] = m_data[i - (count_cu / m_size)];
			bvec.m_data[i - (count_cu / m_size)] = false;
		}
	}
	
	uint8_t mask = 1;
	for (int j = 0; j < (count_cu % m_size)-1; j++)
		mask |= mask << 1;

	for (int i = m_cellcount - 1; i >(count_cu / m_size); i--)
	{
		uint8_t mask_cu = mask;
		bvec.m_data[i] = bvec.m_data[i] >> (count_cu % m_size);
		mask_cu &= bvec.m_data[i - 1];
		mask_cu <<= m_size - (count_cu % m_size);
		bvec.m_data[i] |= mask_cu;
	}
	bvec.m_data[ count_cu / m_size] = bvec.m_data[count_cu / m_size] >> count_cu;
	bvec.Shift();
	return bvec;
}

BoolVector& BoolVector::operator>>=(const int& count)
{
	BoolVector tmp(*this >> count);
	Swap(tmp);
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const BoolVector& bvec)
{
	int n = 0;
	for (int i = 0; i < bvec.CellCount(); i++)
	{
		stream << "[ ";
		for (int j = 0; j < bvec.m_size; j++)
			stream << BoolRank(bvec[n++])<<" ";
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



BoolRank BoolVector::m_rank(const int& index)
{
	BoolRank r(m_data, index);
	return r;
}

//BoolRank::
BoolRank::BoolRank()
{
	m_cell = 0;
	m_mask = 0;
	m_data = nullptr;
	m_value =0;
}
BoolRank::BoolRank(UC* data, const int& index)
{
	m_cell = index / 8;
	m_mask = 1;
	m_mask <<= 7 - index % 8;
	m_data = data;
	m_value = m_data[m_cell] & m_mask;
}

void BoolRank::Set1()
{
	m_data[m_cell] = m_data[m_cell] | m_mask;
	m_value = m_data[m_cell] & m_mask;
}

void BoolRank::Set0()
{
	m_data[m_cell] = m_data[m_cell] & ~m_mask;
	m_value = m_data[m_cell] & m_mask;
}

BoolRank& BoolRank::operator= (const int& value)
{

	return *this;
}

std::ostream& operator<<(std::ostream& stream, const BoolRank& rank)
{
	stream << rank.m_value;
	return stream;
}

std::istream& operator >> (std::istream& stream, BoolRank& rank)
{
	char s;
	stream >> s;
	if (s == '1')
		rank.Set1();
	else
		rank.Set0();

	return stream;
}

