#pragma once
#include<stdint.h>
#include<iostream>
class BoolVector
{
public:
	using UI = unsigned int;
	using UC = unsigned char;
	const uint8_t m_size = 8;

	BoolVector();
	BoolVector(const UI length, const bool value = 0);
	BoolVector(const char* data);
	BoolVector(const BoolVector& other);
	~BoolVector();
	void PrintCell(const int& number_cell)const;
	void Print()const;
	int Lenght()const;
	int CellCount()const;
	void Set1(const int& cell, const int& pos)const;
	void Set0(const int& cell, const int& pos)const;
	void Swap(BoolVector& other);
	UC&operator[](const int index);
	const UC& operator[](const int index)const;

private:
	UI m_length=0;
	UI m_cellcount = 0;
	uint8_t m_insignificantpart = 0;
	UC *m_data = nullptr;
};

std::ostream& operator<<(std::ostream& stream, const BoolVector& bvec);

std::istream& operator>>(std::istream& stream, BoolVector& bvec);
