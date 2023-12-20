#pragma once
#include<stdint.h>
#include<iostream>
#include "..\..\..\OOP\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.h"
#include "..\..\..\OOP\OOP_LAB_4_(Ñlass of boolean matrix)\BoolMatrix\BoolMatrix.h"
class Set:  public BoolVector
{
public:
	Set()
		:m_set(new BoolVector(capacity))
	{}
	Set(const char* str);
	Set(const Set& other);
	~Set()
	{
		delete m_set;
	}
	void Print();
	bool isEmpty();
private:
	BoolVector* m_set = nullptr;
	const int offset= 32;
	const int capacity=94;
	

};


