#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
	if(denominator == 0) cout << "Invalid Fraction! \n";
}

Fraction::Fraction(const Fraction &fraction)
{
	this->numerator = fraction.numerator;
	this->denominator = fraction.denominator;
}

Fraction::~Fraction()
{
	this->numerator = 0;
	this->denominator = 1;
}

void Fraction::setNumerator(int numerator)
{
	this->numerator = numerator;
}

int Fraction::getNumerator() const 
{
	return numerator;
}

void Fraction::setDenominator(int denominator)
{
	this->denominator = denominator;
	if(denominator == 0) cout << "Invalid Fraction! \n";
}

int Fraction::getDenominator() const
{
	return denominator;
}

bool Fraction::isReduced()
{
	Fraction fractionReduced = this->reduce();
	return *this == fractionReduced;
}

Fraction Fraction::reduce()
{
	int ucln = gCD(numerator, denominator);
	numerator /= ucln;
	denominator /= ucln;
	return *this;
}

Fraction Fraction::operator=(const Fraction &fraction)
{
	this->denominator = fraction.denominator;
	this->numerator = fraction.numerator;
	return *this;
}

Fraction Fraction::operator+(const Fraction &fraction) const
{
	int numerator = this->numerator * fraction.denominator + fraction.numerator * this->denominator;
	int denominator = this->denominator * fraction.denominator;
	return Fraction(numerator, denominator);
} 

Fraction Fraction::operator-(const Fraction &fraction) const
{
	int numerator = this->numerator * fraction.denominator - fraction.numerator * this->denominator;
	int denominator = this->denominator * fraction.denominator;
	return Fraction(numerator, denominator);
} 

Fraction Fraction::operator*(const Fraction &fraction) const
{
	int numerator = this->numerator * fraction.numerator;
	int denominator = this->denominator * fraction.denominator;
	return Fraction(numerator, denominator);
} 

Fraction Fraction::operator/(const Fraction &fraction) const
{
	int numerator = this->numerator * fraction.denominator;
	int denominator = this->denominator * fraction.numerator;
	return Fraction(numerator, denominator);
}

bool Fraction::operator==(const Fraction &fraction) const
{
	return this->numerator * fraction.denominator ==
			fraction.numerator * this->denominator;
}

bool Fraction::operator>(const Fraction &fraction) const
{
	return this->numerator * fraction.denominator >
			fraction.numerator * this->denominator;
}

bool Fraction::operator<(const Fraction &fraction) const
{
	return this->numerator * fraction.denominator <
			fraction.numerator * this->denominator;
}

bool Fraction::operator!=(const Fraction &fraction) const
{
	return this->numerator * fraction.denominator !=
			fraction.numerator * this->denominator;
}

Fraction operator+(const int &soNguyen, const Fraction &fraction)
{
	Fraction fractionChanged(soNguyen);
	return fraction + fractionChanged;	
}

istream &operator>>(istream &in, Fraction &fraction)
{
	cout << "Input the numerator: "; in >> fraction.numerator;
	cout << "Input the denominator: "; in >> fraction.denominator;
	return in;
}

ostream &operator<<(ostream &out, const Fraction &fraction)
{
	if(fraction.denominator == 0)
	{
		out << "Invalid Fraction! ";
	}
	else
	{
		if(fraction.numerator % fraction.denominator == 0)
		{
			out << fraction.numerator / fraction.denominator;
		}
		else
		{
			out << fraction.numerator;
			if(fraction.denominator != 1)
			{
				out << "/" << fraction.denominator;
			}
		}
		//out << fraction.numerator << "/" << fraction.denominator;
	}
	return out;
}

Fraction& Fraction::operator+=(const Fraction &fraction)
{
	*this = *this + fraction;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction &fraction)
{
	*this = *this - fraction;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction &fraction)
{
	*this = *this * fraction;
	return *this;
}

Fraction& Fraction::operator/=(const Fraction &fraction)
{
	*this = *this / fraction;
	return *this;
}

int gCD(int numerator, int denominator)
{
	if(denominator == 0)
	{
		return numerator;
	}
	else return gCD(denominator, numerator % denominator);
}
