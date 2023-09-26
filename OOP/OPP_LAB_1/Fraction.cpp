#include "Fraction.h"
#include <iostream>

//Fraction::Fraction()
//{
//	m_numerator = 1;
//	m_denominator = 1;
//}
Fraction::Fraction(const int numerator, const int denominator)
	: m_numerator(numerator)
{
	if (denominator == 0)
	{
		std::cerr << "Fraction::Fraction: error: denominator is 0, result will be numerator/1.\n";
	}
	else
	{
		m_denominator = denominator;
	}
	if (denominator < 0)
	{
		m_denominator *= -1;
		m_numerator *= -1;
	}

}

int Fraction::getNumerator()const
{
	return m_numerator;
}

int Fraction::getDenominator()const
{
	return m_denominator;
}

void Fraction::setNumerator(const int value)
{
	m_numerator = value;
}

void Fraction::setDenominator(const int value)
{
	if (value == 0) 
	{
		std::cerr << "Fraction::setDenominator: error: value is 0, won't assign.\n";
		return;
	}

	m_denominator = value;
}

void Fraction::print()const
{
	std::cout << m_numerator << '/' << m_denominator << std::endl;
}

Fraction Fraction::sum(const Fraction b)const
{
	Fraction c;
	c.m_numerator = m_numerator * b.m_denominator + b.m_numerator * m_denominator;
	c.m_denominator = m_denominator * b.m_denominator;
	return c;
}
Fraction Fraction::subtraction(const Fraction b)const
{
	Fraction c;
	c.m_numerator = m_numerator * b.m_denominator - b.m_numerator * m_denominator;
	c.m_denominator = m_denominator * b.m_denominator;
	return c;
}
Fraction Fraction::multiplication(const Fraction b)const
{
	Fraction c;
	c.m_numerator = m_numerator * b.m_numerator;
	c.m_denominator = m_denominator * b.m_denominator;
	return c;
}
Fraction Fraction::division(const Fraction b)const
{
	Fraction c;
	c.m_numerator = m_numerator * b.m_denominator;
	c.m_denominator = m_denominator * b.m_numerator;
	return c;
}

bool Fraction:: operator == (const Fraction other)
{
	return(m_numerator == other.m_numerator && m_denominator == other.m_denominator);
}
bool Fraction:: operator != (const Fraction other)
{
	return !operator == (other);
}
