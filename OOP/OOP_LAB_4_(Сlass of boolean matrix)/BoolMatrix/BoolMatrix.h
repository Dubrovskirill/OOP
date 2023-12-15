#pragma once
//#include"BoolVector.h"
#include<stdint.h>
#include<iostream>
#include<vector>
#include<iostream>
#include "..\..\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.h"
using UI = unsigned int;
class BoolMatrix
{

public:
	BoolMatrix();
	BoolMatrix(UI rows, UI cols, bool value);
	BoolMatrix(const BoolMatrix& other);
	BoolMatrix(char**matr, UI rows, UI cols);
	//template<typename type>
	BoolMatrix(const std::string& st);
	~BoolMatrix();
	void Print()const;
	int Rows() const;
	int Cols() const;
	void Swap(BoolMatrix& other);
	int Weight()const;
	int Weight(const UI index) const;
	BoolVector RowConjunction() const;
	BoolVector RowÂisjunction() const;
	void Inverse(const UI i, const UI j, const UI count=0);
	void Set1(const UI i, const UI j, const UI count=0);
	void Set0(const UI i, const UI j, const UI count=0);
	bool Empty() const;


	BoolVector& operator[](const UI i);
	const BoolVector& operator[](const UI i)const;
	BoolMatrix operator=(const BoolMatrix& other);
	BoolMatrix operator&(const BoolMatrix& other) const;
	BoolMatrix operator&=(const BoolMatrix& other);
	BoolMatrix operator|(const BoolMatrix& other) const;
	BoolMatrix operator|=(const BoolMatrix& other);
	BoolMatrix operator^(const BoolMatrix& other) const;
	BoolMatrix operator^=(const BoolMatrix& other);
	BoolMatrix operator~()const;

private:
	UI m_rows = 0;
	UI m_cols = 0;
    BoolVector* m_bm=nullptr;
};

std::ostream& operator<<(std::ostream& stream, const BoolMatrix& bmatr);
std::istream& operator>>(std::istream& stream, BoolMatrix& bmatr);

