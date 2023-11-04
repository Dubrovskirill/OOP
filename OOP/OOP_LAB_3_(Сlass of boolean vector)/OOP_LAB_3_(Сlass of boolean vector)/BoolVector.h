#pragma once
#include<stdint.h>
#include<iostream>


class BoolRank;
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
	void Shift();
	void PrintCell(const int& number_cell)const;
	void Print()const;
	int Lenght()const;
	int CellCount()const;
	void Set1(const int& cell, const int& pos)const;
	void Set0(const int& cell, const int& pos)const;
	void Swap(BoolVector& other);
	void Inverse();

	/*bool&operator[](const int index);
	const bool& operator[](const int index)const;*/

	
	BoolRank& operator[](const int index);
	const BoolRank& operator[](const int index)const;
	BoolVector& operator= (BoolVector&& other);
	BoolVector& operator= (const BoolVector& other);
	BoolVector operator&(const BoolVector& other) const;
	BoolVector& operator&=(const BoolVector& other);
	BoolVector operator|(const BoolVector& other) const;
	BoolVector& operator|=(const BoolVector& other);
	BoolVector operator^(const BoolVector& other) const;
	BoolVector& operator^=(const BoolVector& other);
	BoolVector operator~() const;
	BoolVector operator<<(const int& count) const;
	BoolVector& operator<<=(const int& count);
	BoolVector operator>>(const int& count) const;
	BoolVector& operator>>=(const int& count);
	
	//BoolRank Rank(const int& index);
private:
	UI m_length=0;
	UI m_cellcount = 0;
	uint8_t m_insignificantpart = 0;
	UC *m_data = nullptr;
	BoolRank m_rank( const int& index=0);
	//BoolRank m_rank;
	friend BoolRank;
};

std::ostream& operator<<(std::ostream& stream, const BoolVector& bvec);
std::istream& operator>>(std::istream& stream, BoolVector& bvec);



class BoolRank
{
	using UC = unsigned char;
private:
	uint8_t m_mask = 0;
	int m_cell = 0;
	UC* m_data = nullptr;
public:
	bool m_value = 0;
	BoolRank();
	BoolRank(UC* data, const int& index=0);

	void Set1();
	void Set0();
	BoolRank& operator= (const int& value);

};
std::ostream& operator<<(std::ostream& stream, const BoolRank& rank);
std::istream& operator>>(std::istream& stream, BoolRank& rank);
