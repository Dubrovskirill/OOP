#pragma once
#include<iostream>
class Array
{
public:
	Array(const int size = 10, const int value = 0);
	Array(const Array &other);
	~Array();

	int Size() const;
	void Print() const;
	int &operator[](const int index);
	const int &operator[](const int index) const;
	Array& operator= ( Array&& other);
	Array& operator = (const Array & other);
	void RandArray(int FirstGap, int LastGap)const;
	void RandArrayIns(int FirstGap, int LastGap)const;
	void RandArrayDes(int FirstGap, int LastGap)const;
	void Swap(Array& other);
	Array operator+(const Array& other) const;
	Array &operator+=(const Array& other);
	bool operator==(const Array& other) const;
	bool operator!=(const Array& other) const;
	Array operator+(const int& item);
	Array operator+=(const int& item);
	void Resize(int size);
	int ISearch(const int &el, int i=0)const;
	void Sort();
	bool Insert(const int &e, const int &in);
	bool DelbyIndex(const int& in);
	bool DelElement(const int& el);
	bool DelElementAll(const int& el);
	int IMax();
	int IMin();

private:
	int* m_array = nullptr;
	int m_size = 0;
};
//потоковый ввод/вывод
std::ostream& operator<<(std::ostream& stream, const Array& arr);
std::istream& operator >> (std::istream& stream, const Array& arr);
