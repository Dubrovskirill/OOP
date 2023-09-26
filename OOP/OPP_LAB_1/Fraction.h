#pragma once
class Fraction
{
public:
	Fraction()=default;
	Fraction(const int numerator, const int denominaor);//список инициализации
	~Fraction() = default;

	int getNumerator()const;
	int getDenominator()const;

	void setNumerator(const int value);
	void setDenominator(const int value);

	void print() const;
	Fraction sum(const Fraction b)const;
	Fraction subtraction(const Fraction b)const;
	Fraction multiplication(const Fraction b)const;
	Fraction division(const Fraction b)const;

	void reduce();

	bool operator == (const Fraction other);
	bool operator != (const Fraction other);
private:
	int m_numerator=0;
	int m_denominator=1;
};


