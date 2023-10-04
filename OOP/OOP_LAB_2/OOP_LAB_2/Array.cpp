#include "Array.h"
#include<iostream>
#include"assert.h"
Array::Array(const int size, const int value)
{
	if (size < 0)
	{
		std::cerr << "Array::Array: size is negative, invert.";
		m_size = -size;
	}
	else m_size = size;
	m_array = new int[m_size];

	for (int i = 0; i < m_size; i++)
		m_array[i] = value;
}
Array::Array(const Array &other)
	:m_size(other.m_size)
{
	m_array = new int[m_size];
	for (int i = 0; i < m_size; i++)
		m_array[i] = other.m_array[i];
}


Array::~Array()
{
	delete[] m_array;
}

int Array::size() const
{
	return m_size;
}
void Array::print() const
{
	std::cout << "[";
	for (int i = 0; i < m_size - 1; i++)
		std::cout << m_array[i] << ",";

	std::cout << m_array[m_size - 1] << "]\n";

}

int& Array::operator[](const int index)
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

const int& Array::operator[](const int index) const
{
	assert(index >= 0 && index < m_size);
	return m_array[index];
}

//Array& Array::operator= (const Array&& other)
//{
//	if (this == &other) return *this;
//
//	if (m_size != other.m_size)
//	{
//		m_size = other.m_size;
//		delete[]m_array;
//		m_array = new int[m_size];
//	}
//	for (int i = 0; i < m_size; i++)
//		m_array[i] = other.m_array[i];
//
//	return *this;
//
//}

Array&Array::operator= (const Array &other)
{
	if (this == &other) return *this;

	if (m_size != other.m_size)
	{
		m_size = other.m_size;
		delete[]m_array;
		m_array = new int[m_size];
	}
	for (int i = 0; i < m_size; i++)
		m_array[i] = other.m_array[i];

	return *this;

}

void Array::RandArray( int f_gap, int l_gap)const
{
	if (f_gap > l_gap)
	{
		int swap = f_gap; f_gap = l_gap; l_gap = swap;
	}
	srand(time(0));
	for (int i = 0; i < m_size; i++) m_array[i] = rand() % l_gap +f_gap+1;
}

void Array::RandArrayIns(int f_gap, int l_gap)const
{
	if (f_gap > l_gap) std::swap(f_gap, l_gap);
	srand(time(0));
	m_array[0] = rand() % l_gap + f_gap + 1; // ������ ����� �������� ��������
	int i;
	for (i = 1; i < m_size; i++)
	{
		m_array[i] = m_array[i - 1] + rand() % 10 + 1;
		if (m_array[i] > l_gap) break;
	}
	for (; i < m_size; i++)
		m_array[i] = l_gap;
	
}

void Array::RandArrayDes(int f_gap, int l_gap)const
{
	if (f_gap > l_gap) std::swap(f_gap, l_gap);
	srand(time(0));
	m_array[m_size-1] = rand() % l_gap + f_gap + 1; // ������ ����� �������� ��������
	int i;
	for (i = m_size-2; i >= 0; i--)
	{
		m_array[i] = m_array[i + 1] + rand() % 10 + 1;
		if (m_array[i] < f_gap) break;
	}
	for (; i >= 0; i--)
		m_array[i] = f_gap;
}

void Array::swap(Array& other)
{
	std::swap(m_size, other.m_size);
	std::swap(m_array, other.m_array);
}
Array Array::operator+(const Array& other) const
{
   Array res(m_size+other.m_size);
   for (int i = 0; i < m_size; i++)
	   res.m_array[i] = m_array[i];
   for (int i = 0; i < other.m_size; i++)
	   res.m_array[m_size+i] = other.m_array[i];
   return res;
   
	
}
Array &Array::operator+=(const Array& other)
{
	Array tmp(*this + other);
	this->swap(tmp);
	return *this;
}


