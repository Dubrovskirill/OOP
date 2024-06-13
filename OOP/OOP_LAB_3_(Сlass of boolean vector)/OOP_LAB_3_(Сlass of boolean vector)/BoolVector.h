#pragma once
#include<stdint.h>
#include<iostream>
#include <assert.h>

class BoolVector
{
private:
	class BoolRank;
public:
	using UI = unsigned int;
	using UC = unsigned char;
	const uint8_t m_cellSize = 8;

	BoolVector();
	BoolVector(const UI length, const bool value = 0);
	BoolVector(const char* data);
	BoolVector(const BoolVector& other);
	~BoolVector();
	void PrintCell(const int number_cell)const;
	void Print()const;
	int Lenght()const;
	int CellCount()const;
	void Set1(const int i);
	void Set0(const int i);
	void Swap(BoolVector& other);
	void Inverse();
	void Inverse(const int i);
	int Weight() const;
	void Set1(const int pos, const int count);
	void Set0(const int pos, const int count);
	void Set1();
	void Set0();
	bool Full() const;
	UC* Data() const {
		return m_data;
	}
	void addSymbol(const UC symbol, int index) {
		assert(index < m_cellcount);
		m_data[index] = symbol;
	}
	BoolRank operator[](const int index);
	const BoolRank operator[](const int index)const;
	BoolVector& operator= (BoolVector&& other);
	BoolVector& operator= (const BoolVector& other);
	BoolVector& operator += (const char value);
	BoolVector operator&(const BoolVector& other) const;
	BoolVector& operator&=(const BoolVector& other);
	BoolVector operator|(const BoolVector& other) const;
	BoolVector& operator|=(const BoolVector& other);
	BoolVector operator^(const BoolVector& other) const;
	BoolVector& operator^=(const BoolVector& other);
	BoolVector operator~() const;
	BoolVector operator<<(int count) const;
	BoolVector& operator<<=(const int count);
	BoolVector operator>>(int count) const;
	BoolVector& operator>>=(const int count);
	bool operator==(const BoolVector& other) const; 
	bool operator!=(const BoolVector& other)const;
	bool operator==(BoolVector&& other);
	bool operator!=(BoolVector&& other);

	int findfirstset() const;

	

	friend std::ostream& operator<<(std::ostream& stream, const BoolRank& rank);
	friend std::istream& operator>>(std::istream& stream, BoolRank rank);
protected:
UC* m_data = nullptr;

private:
	UI m_length=0;
	UI m_cellcount = 0;
	uint8_t m_insignificantpart = 0;
	//UC *m_data = nullptr;
	void Shift();
};
std::ostream& operator<<(std::ostream& stream, const BoolVector& bvec);
std::istream& operator>>(std::istream& stream, BoolVector& bvec);

class BoolVector::BoolRank
{
	using UC = unsigned char;
private:
	uint8_t m_mask = 0;
	int m_cell = 0;
	UC* m_data = nullptr;
	bool m_value = 0;
	
public:
	
	BoolRank();
	BoolRank(UC* data, const int index=0); 
	BoolRank(const BoolRank& other);

	void Set1();
	void Set0();
	bool Value() const;

	BoolRank& operator= (const BoolRank& other);
	BoolRank& operator= (const int value);
	bool operator==(const bool value)const;
	bool operator>(const bool value)const;
	bool operator<(const bool value)const;
	bool operator>=(const bool value)const;
	bool operator<=(const bool value)const;
	operator int()const;
	bool operator&(const int value)const;
	BoolRank operator&=(const int value);
	bool operator|(const int value)const;
	BoolRank operator|=(const int value);
	bool operator~() const;
	bool operator^(const int value)const;
	BoolRank operator^=(const int value);
};

