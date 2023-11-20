#include "BoolMatrix.h"
//#include "..\..\OOP_LAB_3_(�lass of boolean vector)\OOP_LAB_3_(�lass of boolean vector)\BoolVector.h"
#include "..\..\OOP_LAB_3_(�lass of boolean vector)\OOP_LAB_3_(�lass of boolean vector)\BoolVector.cpp"
#include<stdint.h>
#include<iostream>
#include <assert.h>
using UI = unsigned int;

BoolMatrix::BoolMatrix()
	:BoolMatrix(1, 8, 0)
{}

BoolMatrix::BoolMatrix(UI rows, UI cols, bool value)
	:m_rows(rows), m_cols(cols)
{
	m_rows = rows;
	m_cols = cols;
	m_bm = new BoolVector[m_rows];
	BoolVector vec(m_cols, value);
	for (int i = 0; i < m_rows; i++)
	{
		m_bm[i] = vec;
	}
}

BoolMatrix::BoolMatrix(const BoolMatrix& other)
	:m_rows(other.m_rows), m_cols(other.m_cols)
{
	m_bm = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_bm[i] = other.m_bm[i];
	}
}

BoolMatrix::BoolMatrix(char** matr, UI rows, UI cols)
	:m_rows(rows), m_cols(cols)
{
	m_bm = new BoolVector[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_bm[i] = matr[i];
	}
}

BoolMatrix::~BoolMatrix()
{
	delete[]m_bm;
}

void BoolMatrix::Print()const
{
	for (int i = 0; i < m_rows; i++)
	{
		std::cout << m_bm[i];
	}
}

int BoolMatrix::Rows() const
{
	return m_rows;
}

int BoolMatrix::Cols() const
{
	return m_cols;
}

void BoolMatrix::Swap(BoolMatrix& other)
{
	std::swap(m_rows, other.m_rows);
	std::swap(m_cols, other.m_cols);
	std::swap(m_bm, other.m_bm);
}

int BoolMatrix::Weight()
{
	int w = 0; 
	for (int i = 0; i < m_rows; i++)
		w += m_bm[i].Weight();
	return w;
}

int BoolMatrix::Weight(const UI index)
{
	return m_bm[index].Weight();
}

BoolVector BoolMatrix::LogAnd()
{
	BoolVector vec=m_bm[0];
	for (int i = 1; i < m_rows; i++)
		vec &= m_bm[i];
	return vec;
}

BoolVector BoolMatrix::LogOr()
{
	BoolVector vec = m_bm[0];
	for (int i = 1; i < m_rows; i++)
		vec |= m_bm[i];
	return vec;
}

void BoolMatrix::Inverse(const int i, const int j)
{
	m_bm[i][j] = ~m_bm[i][j];
}

BoolVector& BoolMatrix::operator[](const int i)
{
	assert(i >= 0 || i < m_rows);
	return m_bm[i];
}
const BoolVector& BoolMatrix::operator[](const int i) const
{
	assert(i >= 0 || i < m_rows);
	return m_bm[i];
}

BoolMatrix BoolMatrix::operator=(const BoolMatrix& other)
{
	if (m_bm == other.m_bm) return *this;
	if (m_rows != other.m_rows)
	{
		m_rows = other.m_rows;
		delete[] m_bm;
		m_bm = new BoolVector[m_rows];
	}
	m_cols = other.m_cols;
	for (int i = 0; i < m_rows; i++)
	{
		m_bm[i] = other.m_bm[i];
	}
	return *this;
}

BoolMatrix BoolMatrix::operator&(const BoolMatrix& other) const
{
	UI r = std::min(m_rows, other.m_rows);
    UI c = std::min(m_cols, other.m_cols);
	BoolMatrix bmatr(r, c, 0);
	for (int i = 0; i < r; i++)
		bmatr.m_bm[i] = m_bm[i] & other.m_bm[i];
	return bmatr;

}

BoolMatrix BoolMatrix::operator&=(const BoolMatrix& other)
{
	BoolMatrix tmp(*this & other);
	Swap(tmp);
	return *this;
}

BoolMatrix BoolMatrix::operator|(const BoolMatrix& other) const
{
	UI r = std::max(m_rows, other.m_rows);
	UI c = std::max(m_cols, other.m_cols);
	BoolMatrix bmatr(r, c, 0);
	r = std::min(m_rows, other.m_rows);
	c = std::min(m_cols, other.m_cols);
	for (int i = 0; i < r; i++)
		bmatr.m_bm[i] = m_bm[i] | other.m_bm[i];
	for (int i = r; i < m_rows; i++)
		bmatr.m_bm[i] = m_bm[i];
	for (int i = r; i < other.m_rows; i++)
		bmatr.m_bm[i] = other.m_bm[i];
	return bmatr;
}

BoolMatrix BoolMatrix::operator|=(const BoolMatrix& other)
{
	BoolMatrix tmp(*this | other);
	Swap(tmp);
	return *this;
}

BoolMatrix BoolMatrix::operator^(const BoolMatrix& other) const
{
	UI r = std::max(m_rows, other.m_rows);
	UI c = std::max(m_cols, other.m_cols);
	BoolMatrix bmatr(r, c, 0);
	r = std::min(m_rows, other.m_rows);
	c = std::min(m_cols, other.m_cols);
	for (int i = 0; i < r; i++)
		bmatr.m_bm[i] = m_bm[i] ^ other.m_bm[i];
	for (int i = r; i < m_rows; i++)
		bmatr.m_bm[i] = m_bm[i];
	for (int i = r; i < other.m_rows; i++)
		bmatr.m_bm[i] = other.m_bm[i];
	return bmatr;
}

BoolMatrix BoolMatrix::operator^=(const BoolMatrix& other)
{
	BoolMatrix tmp(*this | other);
	Swap(tmp);
	return *this;
}

BoolMatrix BoolMatrix::operator~()
{
	BoolMatrix bmatr(*this);
	for (int i = 0; i < m_rows; i++)
		bmatr.m_bm[i].Inverse();
	return bmatr;
}

std::ostream& operator<<(std::ostream& stream, const BoolMatrix& bmatr)
{
	for (int i = 0; i < bmatr.Rows(); i++)
		stream << bmatr[i];
	return stream;
}

std::istream& operator>>(std::istream& stream, BoolMatrix& bmatr)
{
	for (int i = 0; i < bmatr.Rows(); i++)
		stream >> bmatr[i];

	return stream;
}