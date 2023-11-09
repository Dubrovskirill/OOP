#include "BoolVector.h"
#include<stdint.h>
#include<iostream>
#include <assert.h>

using UI = unsigned int;
using UC = unsigned char;

BoolVector::BoolVector()
	: BoolVector(8, false)
{}

BoolVector::~BoolVector()
{
	delete[]m_data;
}

BoolVector::BoolVector(const UI length, const bool value)
{
	m_length = length;
	m_cellcount = m_length / 8 + (m_length % 8 > 0);
	m_insignificantpart = m_cellSize * m_cellcount - m_length;
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
	m_insignificantpart = m_cellSize * m_cellcount - m_length;
	m_data = new UC[m_cellcount];
	for (int i = 0; i < m_length; i++)
	{
		if (data[i] == '1')
			Set1(i);
		else
			Set0(i);
	}
	Shift();
}

BoolVector::BoolVector(const BoolVector& other)
	:m_length(other.m_length)
{
	m_cellcount = other.m_cellcount;
	m_data = new UC[m_cellcount];
	m_insignificantpart = (m_cellcount * m_cellSize) - m_length;
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

void BoolVector::PrintCell(const int cell)const
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


void  BoolVector::Set1(const int i)
{
	int cell = i / m_cellSize;
	int pos = i % m_cellSize;
	uint8_t mask = 1;
	mask = mask << 7-pos;
	m_data[cell] = m_data[cell] | mask;
}

void  BoolVector::Set0(const int i)
{
	int cell = i / m_cellSize;
	int pos = i % m_cellSize;
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

void BoolVector::Inverse()
{
	for (int i = 0; i < m_cellcount; i++)
		m_data[i] = ~m_data[i];
	Shift();
}

void BoolVector::Inverse(const int i)
{
		if ((*this)[i])
			Set0(i);
		else
			Set1(i);
}

int BoolVector::Weight()
{
	int w = 0;
	for (int i = 0; i < m_cellcount; i++)
	{
		uint8_t mask = 1;
		mask <<= 7;
		for (int j = 0; j < m_cellSize; j++) 
		{
			if (m_data[i] & mask)
				w++;
			mask >>= 1;
		}
	}
	return w;
}

void BoolVector::Set1(const int pos, const int count)
{
	for (int i = pos; i < m_length && i < pos + count; i++)
		(*this)[i] = 1;
}

void BoolVector::Set0(const int pos, const int count)
{
	for (int i = pos; i < m_length && i < pos + count; i++)
		(*this)[i] = 0;
}

void BoolVector::Set1()
{
	uint8_t mask = 0;
	for (int i = 0; i < m_cellcount; i++)
		m_data[i] = ~mask;
	Shift();
}

void BoolVector::Set0()
{
	uint8_t mask = 0;
	for (int i = 0; i < m_cellcount; i++)
		m_data[i] = mask;
}

BoolRank BoolVector::operator[](const int index)
{
	assert(index >= 0 && index < m_cellSize * m_cellcount);
	BoolRank rank(m_data,index);
	return rank;
}

const BoolRank BoolVector::operator[](const int index) const
{
	assert(index >= 0 && index < m_cellSize * m_cellcount);
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
	return *this;
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
	bvec.Inverse();
	return bvec;
}

BoolVector BoolVector::operator<<(int count) const
{
	if (count > m_length)
		count = m_length;

	BoolVector bvec = *this;
	if (count >= m_cellSize)
	{
		for (int i = 0; i + (count / m_cellSize) < bvec.m_cellcount; i++)
			bvec.m_data[i] = m_data[i + (count / m_cellSize)];
		
		for (int i = bvec.m_cellcount-1; i >= bvec.m_cellcount-(count / m_cellSize); i--)
			bvec.m_data[i] = false;

		count = count % m_cellSize;
	}

	//count: [0, m_cellSize);
	if (count > 0)
	{
		uint8_t mask = 0;
		mask = ~mask;
		mask <<= m_cellSize - count;
		for (int i = 0; i < m_cellcount - 1; i++)
		{
			uint8_t mask_cu = mask;
			bvec.m_data[i] = bvec.m_data[i] << count;
			mask_cu &= bvec.m_data[i + 1];
			mask_cu >>= m_cellSize - count;
			bvec.m_data[i] |= mask_cu;
		}
		bvec.m_data[m_cellcount - 1]  <<= count;
	}
	return bvec;
}

BoolVector& BoolVector::operator<<=(const int count)
{
	BoolVector tmp(*this << count);
	Swap(tmp);
	return *this;
}

BoolVector BoolVector::operator>>(int count) const
{
	if (count > m_length)
		count = m_length;

	BoolVector bvec = *this;
	int n = 1;
	if (count >= m_cellSize)
	{
		for (int i = m_cellcount - 1; i - (count / m_cellSize) >= 0; i--)
			bvec.m_data[i] = m_data[i - (count / m_cellSize)];

		for (int i = 0; i <= count / m_cellSize -1; i++)
			bvec.m_data[i] = false;

		count = count % m_cellSize;
	}

	if (count)
	{
		uint8_t mask = 0;
		mask = ~mask;
		mask >>= m_cellSize - count;

		for (int i = m_cellcount - 1; i > 0; i--)
		{
			uint8_t mask_cu = mask;
			bvec.m_data[i] = bvec.m_data[i] >> count;
			mask_cu &= bvec.m_data[i - 1];
			mask_cu <<= m_cellSize - count;
			bvec.m_data[i] |= mask_cu;
		}
		bvec.m_data[0] >>= count;
	}
	bvec.Shift();
	return bvec;
}

BoolVector& BoolVector::operator>>=(const int count)
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
		for (int j = 0; j < bvec.m_cellSize; j++)
			stream << bvec[n++] << " ";
			
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
		if (s == '0')
			bvec.Set0(i);
		else
			bvec.Set1(i);
	}
	return stream;
}


//BoolRank::
BoolRank::BoolRank()
{
	m_cell = 0;
	m_mask = 0;
	m_data = nullptr;
	m_value =0;
}

BoolRank::BoolRank(UC* data, const int index)
{
	m_cell = index / 8;
	m_mask = 1;
	m_mask <<= 7 - index % 8;
	m_data = data;
	m_value = m_data[m_cell] & m_mask;
}

BoolRank::BoolRank(const BoolRank& other)
{
	m_cell = other.m_cell;
	m_mask = other.m_mask;
	m_value = other.m_value;
	m_data = other.m_data;
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

BoolRank& BoolRank::operator= (const BoolRank& other)
{
	operator=((int)other);
	return *this;
}

void BoolRank::Swap(BoolRank& other)
{
	std::swap(m_cell, other.m_cell);
	std::swap(m_mask, other.m_mask);
	std::swap(m_value, other.m_value);
	std::swap(m_data, other.m_data);
}

bool BoolRank::Value() const
{
	return m_value;
}

BoolRank& BoolRank::operator= (const int value)
{
	if (bool(value))
		Set1();
	else
		Set0();
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const BoolRank& rank)
{
	stream << rank.Value();
	return stream;
}

std::istream& operator >> (std::istream& stream, BoolRank rank)
{
	char s;
	stream >> s;
	if (s == '0')
		rank.Set0();
	else
		rank.Set1();
	return stream;
}

bool BoolRank::operator==(const bool value)const
{
	if (m_value == value)
		return true;
	return false;
}

bool BoolRank::operator!=(const bool value)const
{
	if (m_value != value)
		return true;
	return false;
}

bool BoolRank::operator>(const bool value)const
{
	if (m_value > value)
		return true;
	return false;
}

bool BoolRank::operator<(const bool value)const
{
	if (m_value < value)
		return true;
	return false;
}

bool BoolRank::operator>=(const bool value)const
{
	if (m_value >= value)
		return true;
	return false;
}

bool BoolRank::operator<=(const bool value)const
{
	if (m_value <= value)
		return true;
	return false;
}

BoolRank::operator int()const
{ 
	int val = int(m_value);
	return val;
}

BoolRank::operator bool()const
{
	bool val = m_value;
	return val;
}

bool BoolRank::operator&(const int value)const
{
	bool ans = m_value && bool(value);
	return ans;
}

BoolRank BoolRank::operator&=(const int value)
{
	bool ans = m_value && bool(value);
	if (ans)
		Set1();
	else 
		Set0();
	return *this;
}

bool BoolRank::operator|(const int value)const
{
	bool ans = m_value || bool(value);
	return ans;
}

BoolRank BoolRank::operator|=(const int value)
{
	bool ans = m_value || bool(value);
	if (ans)
		Set1();
	else
		Set0();
	return *this;
}

bool BoolRank::operator~() const
{
	bool ans = !m_value;
	return ans;
}

bool BoolRank::operator^(const int value)const
{
	bool ans = m_value ^ bool(value);
	return ans;
}

BoolRank BoolRank::operator^=(const int value)
{
	bool ans = m_value ^ bool(value);
	if (ans)
		Set1();
	else
		Set0();
	return *this;
}
