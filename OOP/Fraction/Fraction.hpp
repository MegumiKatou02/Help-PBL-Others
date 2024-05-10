#pragma once
#include <iostream>

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
public:
	Fraction(int numerator = 0, int denominator = 1);
	Fraction(const Fraction &fraction);
	~Fraction();
	void setNumerator(int numerator);
	int getNumerator() const;	
	void setDenominator(int denominator);
	int getDenominator() const;	
	bool isReduced();
	Fraction reduce();
	Fraction operator=(const Fraction &fraction);
	Fraction operator+(const Fraction &fraction) const;
	Fraction operator-(const Fraction &fraction) const;
	Fraction operator*(const Fraction &fraction) const;
	Fraction operator/(const Fraction &fraction) const;
	bool operator==(const Fraction &fraction) const;
	bool operator>(const Fraction &fraction) const;
	bool operator<(const Fraction &fraction) const;
	bool operator!=(const Fraction &fraction) const;
	friend Fraction operator+(const int &soNguyen, const Fraction &fraction);
	friend istream &operator>>(istream &in, Fraction &fraction);
	friend ostream &operator<<(ostream &out, const Fraction &fraction);
	Fraction& operator+=(const Fraction &fraction);
	Fraction& operator-=(const Fraction &fraction);
	Fraction& operator*=(const Fraction &fraction);
	Fraction& operator/=(const Fraction &fraction);
};

int gCD(int, int);
