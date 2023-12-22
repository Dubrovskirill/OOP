#pragma once
#include<stdint.h>
#include<iostream>
#include "..\..\..\OOP\OOP_LAB_3_(Ñlass of boolean vector)\OOP_LAB_3_(Ñlass of boolean vector)\BoolVector.h"
#include "..\..\..\OOP\OOP_LAB_4_(Ñlass of boolean matrix)\BoolMatrix\BoolMatrix.h"
class Set:  protected BoolVector
{
public:
	Set()
		: BoolVector(capacity)
	{}

	Set(const char* str);
	Set(const Set& other);

	static const int offset = 32;
	static const int capacity = 94;

	void Print() const;
	bool isEmpty() const;
	int Weight()const;
	bool isPresent(const char c) const;
	char Max() const;
	char Min() const;
	Set& operator= (Set&& other);
	Set& operator= (const Set& other);
	bool operator==(const Set& other) const;
	bool operator!=(const Set& other) const;
	Set operator|(const Set& other) const;
	Set operator|=(const Set& other);
	Set operator&(const Set& other) const;
	Set operator&=(const Set& other);
	Set operator/(const Set& other) const;
	Set operator/=(const Set& other);
	Set operator~() const;
	Set operator+(const char& str) const;
	Set operator+=(const char& str);
	Set operator-(const char& str) const;
	Set operator-=(const char& str);

	friend std::ostream& operator << (std::ostream& stream, const Set& other);
	friend std::istream& operator >> (std::istream& stream, Set& other);

};

