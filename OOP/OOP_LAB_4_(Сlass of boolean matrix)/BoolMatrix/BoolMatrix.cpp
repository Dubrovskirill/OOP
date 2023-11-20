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

BoolVector& BoolMatrix::operator[](const int i)
{
	assert(i >= 0 || i < m_rows);
	return m_bm[i];
}

