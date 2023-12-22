#pragma once
#include<stdint.h>
#include<iostream>
#include "..\..\..\OOP\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.h"
#include "..\..\..\OOP\OOP_LAB_4_(Ñlass of boolean matrix)\BoolMatrix\BoolMatrix.h"
class Set:  public BoolVector
{
public:
	Set()
		: BoolVector(capacity)
	{}

	Set(const char* str);
	Set(const Set& other);
	~Set()
	{
	}

	void Print() const;
	bool isEmpty() const;
	int Weight()const;
	bool isPresent(const char c) const;
	static const int offset = 32;
	static const int capacity = 94;
	
};

std::ostream& operator << (std::ostream& stream, const Set& other);
std::istream& operator >> (std::istream& stream, Set& other);
