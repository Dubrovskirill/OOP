#include "Fraction.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
	setlocale(0, "");
	Fraction a; Fraction b; Fraction c;
	a.numerator = 5;
	a.denominator = 2;
	b.numerator = 6;
	b.denominator = 7;
	c = a.sum(b); c.print();
	cout <<" - �����" << endl;
	c = a.subtraction(b); c.print();
	cout<<" - ���������" << endl;
	c = a.multiplication(b); c.print();
	cout <<" - ���������" << endl;
	c = a.division(b); c.print();
	cout << " - �������" << endl;
}