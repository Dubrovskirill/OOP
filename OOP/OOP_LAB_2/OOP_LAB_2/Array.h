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

private:
	int* m_array = nullptr;
	int m_size = 0;
};

