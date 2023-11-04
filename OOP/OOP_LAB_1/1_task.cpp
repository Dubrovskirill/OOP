#include "Fraction.h"
#include <iostream>

int main()
{
	Fraction a; Fraction b; Fraction c;
	a.numerator = 5;
	a.denominator = 2;
	b.numerator = 6;
	b.denominator = 7;
	c = a.sum(b);
	c.print();
	c = a.subtraction(b); c.print();
	c = a.multiplication(b); c.print();

}