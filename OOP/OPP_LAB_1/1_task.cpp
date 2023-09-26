#include "Fraction.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
	setlocale(0, "");
	int n, d;
	cout << "enter first fraction: ";
	cin >> n >> d;
	while (d == 0)
	{
		cout << "Denominator can`t be zero! Please, enter a vallid denominator: ";
		cin >> d;
	}
	Fraction a(n, d);

	cout << "enter second fraction: ";
	cin >> n >> d;
	while (d == 0)
	{
		cout << "Denominator can`t be zero! Please, enter a vallid denominator: ";
		cin >> d;
	}
	Fraction b(n, d);

	if (a == b)
	{
		cout << "Fractions is equal";
	}
	else
	{
		cout << "Fractions is not equal";
	}




	/*c = a.sum(b); c.print();
	cout <<" - сумма" << endl;
	c = a.subtraction(b); c.print();
	cout<<" - вычитание" << endl;
	c = a.multiplication(b); c.print();
	cout <<" - умножение" << endl;
	c = a.division(b); c.print();
	cout << " - деление" << endl;*/
}