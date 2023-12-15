//#include "..\..\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.cpp"
//#include "..\..\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.h"
#include<stdint.h>
#include<iostream>
#include <assert.h>
#include<vector>
#include <stdlib.h>
#include <string>
#include "BoolMatrix.h"

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

BoolMatrix::BoolMatrix(const std::string& st)
{
	m_rows = sqrt(st.size());
	m_cols = m_rows;
	m_bm = new BoolVector[m_rows];
	int k = 0;
	for (int i = 0; i < m_rows; ++i)
	{
		BoolVector vec(m_cols, 0);
		for (int j = 0; j < m_cols; ++j)
		{
			vec[j] = st[k++] - '0';
		}
		m_bm[i] = vec;
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

int BoolMatrix::Weight() const
{
	int w = 0; 
	for (int i = 0; i < m_rows; i++)
		w += m_bm[i].Weight();
	return w;
}

int BoolMatrix::Weight(const UI index) const
{
	return m_bm[index].Weight();
}

BoolVector BoolMatrix::RowConjunction() const
{
	BoolVector vec=m_bm[0];
	for (int i = 1; i < m_rows; i++)
		vec &= m_bm[i];
	return vec;
}

BoolVector BoolMatrix::RowÂisjunction() const
{
	BoolVector vec = m_bm[0];
	for (int i = 1; i < m_rows; i++)
		vec |= m_bm[i];
	return vec;
}

void BoolMatrix::Inverse(const UI i, const UI j, const UI count)
{
	for(int u=j;u<=j+count && u<m_cols;u++)
	     m_bm[i][u] = ~m_bm[i][u];
}

void BoolMatrix::Set1(const UI i, const UI j, const UI count)
{
	for (int u = j; u <= j + count && u < m_cols; u++)
		m_bm[i][u]=1;
}

void BoolMatrix::Set0(const UI i, const UI j, const UI count)
{
	for (int u = j; u <= j + count && u < m_cols; u++)
		m_bm[i][u]=0;
}

BoolVector& BoolMatrix::operator[](const UI i)
{
	assert(i >= 0 || i < m_rows);
	return m_bm[i];
}
const BoolVector& BoolMatrix::operator[](const UI i) const
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

BoolMatrix BoolMatrix::operator~() const
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

bool BoolMatrix::Empty() const
{
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			if ( (*this)[i][j] != 0)
				return false;
	return true;
}