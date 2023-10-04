#pragma once
class Array
{
public:
	Array(const int size = 10, const int value = 0);
	Array(const Array &other);
	~Array();

	int size() const;

	void print() const;

	int &operator[](const int index);
	const int &operator[](const int index) const;
	Array& operator = (const Array & other);
	void RandArray(int FirstGap, int LastGap)const;
	void RandArrayIns(int FirstGap, int LastGap)const;
	void RandArrayDes(int FirstGap, int LastGap)const;
	void swap(Array& other);
	Array operator+(const Array& other) const;
	Array &operator+=(const Array& other);

private:
	int* m_array = nullptr;
	int m_size = 0;
};

