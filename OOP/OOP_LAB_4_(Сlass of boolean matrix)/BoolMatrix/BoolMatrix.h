#pragma once
#include "..\..\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.h"
//#include "..\..\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.cpp"
#include<stdint.h>
#include<iostream>
using UI = unsigned int;
class BoolMatrix
{

public:
	BoolMatrix();
	BoolMatrix(UI rows, UI cols, bool value);
	BoolMatrix(const BoolMatrix& other);
	BoolMatrix(char**matr, UI rows, UI cols);
	~BoolMatrix();
	void Print()const;
	int Rows() const;
	int Cols() const;
	void Swap(BoolMatrix& other);
	int Weight();
	BoolVector LogAnd();
	BoolVector LogOr();


	BoolVector& operator[](const int i);
	const BoolVector& operator[](const int i)const;

private:
	UI m_rows = 0;
	UI m_cols = 0;
    BoolVector* m_bm=nullptr;
};

std::ostream& operator<<(std::ostream& stream, const BoolMatrix& bmatr);
std::istream& operator>>(std::istream& stream, BoolMatrix& bmatr);

