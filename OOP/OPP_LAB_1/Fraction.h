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
	void input();
	Fraction summation(const Fraction b)const;
	Fraction subtraction(const Fraction b)const;
	Fraction multiplication(const Fraction b)const;
	Fraction division(const Fraction b)const;
	void reduce();

	bool operator == (const Fraction other) const;
	bool operator != (const Fraction other) const;
	bool operator < (const Fraction other)const;
	bool operator > (const Fraction other)const;
	Fraction operator +(const Fraction other)const;
	Fraction operator -(const Fraction other)const;
	Fraction operator *(const Fraction other)const;
	Fraction operator /(const Fraction other)const;

	//my methods
	void int_to_frac(const int a);
	Fraction summation_fracbyint(const int a)const;
	void exponentiation(const int degree);
private:
	int m_numerator=0;
	int m_denominator=1;
};


