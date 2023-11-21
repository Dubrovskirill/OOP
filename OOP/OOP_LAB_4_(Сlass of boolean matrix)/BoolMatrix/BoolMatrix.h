#pragma once
#include "..\..\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.h"
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
	int Weight(const UI index);
	BoolVector LogAnd();
	BoolVector LogOr();
	void Inverse(const UI i, const UI j, const UI count=0);
	void Set1(const UI i, const UI j, const UI count=0);
	void Set0(const UI i, const UI j, const UI count=0);


	BoolVector& operator[](const UI i);
	const BoolVector& operator[](const UI i)const;
	BoolMatrix operator=(const BoolMatrix& other);
	BoolMatrix operator&(const BoolMatrix& other) const;
	BoolMatrix operator&=(const BoolMatrix& other);
	BoolMatrix operator|(const BoolMatrix& other) const;
	BoolMatrix operator|=(const BoolMatrix& other);
	BoolMatrix operator^(const BoolMatrix& other) const;
	BoolMatrix operator^=(const BoolMatrix& other);
	BoolMatrix operator~();

private:
	UI m_rows = 0;
	UI m_cols = 0;
    BoolVector* m_bm=nullptr;
};

std::ostream& operator<<(std::ostream& stream, const BoolMatrix& bmatr);
std::istream& operator>>(std::istream& stream, BoolMatrix& bmatr);

