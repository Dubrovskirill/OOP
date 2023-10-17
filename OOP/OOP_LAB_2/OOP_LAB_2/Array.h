#pragma once
#include<iostream>
class Array
{
public:
	class Iterator;

public:
	Array(const int size = 10, const int value = 0);
	Array(const Array &other);
	Array(Array&& other);
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

	Iterator begin();
	Iterator end();
	bool Insert(const int& el, Iterator &it);
	bool Remove(Iterator& gap1, Iterator& gap2);
	bool Remove(Iterator& it);

private:
	int* m_array = nullptr;
	int m_size = 0;
};

class Array::Iterator
{
public:
	Iterator(Array* array, const int pos);
	
	int& operator*();
	Iterator& operator++();
	Iterator operator++(int);
	Iterator& operator--();
	Iterator operator--(int);

	bool hasNext() const;
	int Pos() const;
	void Repos(int index);

	bool operator==(const Iterator& other) const;
	bool operator!=(const Iterator& other) const;

private:
	Array* m_array = nullptr;
	int m_pos = 0;
};

//потоковый ввод/вывод
std::ostream& operator<<(std::ostream& stream, const Array& arr);
std::istream& operator >> (std::istream& stream, const Array& arr);
