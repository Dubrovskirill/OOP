#include "BoolMatrix.h"
//#include "..\..\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.h"
#include "..\..\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.cpp"
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