#pragma once
#include<stdint.h>
class BoolVector
{
public:
	using UI = unsigned int;
	using UC = unsigned char;
	const uint8_t m_size = 8;

	BoolVector();
	BoolVector(const UI length, const bool value = 0);
	~BoolVector();
	void PrintCell(const int& number_cell)const;
	void Print()const;

private:
	UI m_length=0;
	UI m_cellcount = 0;
	uint8_t m_insignificantpart = 0;
	UC *m_data = nullptr;
};
//UI m_cellcount = m_length/8+(m_length%8>0);
