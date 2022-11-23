// Fraction Class
// Period 5
// Carson Kramer
// 1-30-20
#include<iostream>
using namespace std;

#pragma once
#ifndef FRACTION_H
#define FRACTION_H
class Fraction
{
private:
	int n;
	int d;
public:
	Fraction();
	Fraction(int, int);
	void setNumerator(int);
	void setDenominator(int);
	int getNumerator();
	int getDenominator();
	Fraction add(Fraction, Fraction);
	Fraction subtract(Fraction, Fraction);
	Fraction multiply(Fraction, Fraction);
	Fraction divide(Fraction, Fraction);
	Fraction simplify();
	void printFrac();
};

Fraction::Fraction()
{
	setNumerator(1);
	setDenominator(1);
}

Fraction::Fraction(int n1, int d1)
{
	setNumerator(n1);
	setDenominator(d1);
}

void Fraction::setNumerator(int n1)
{
	n = n1;
}

void Fraction::setDenominator(int d1)
{
	if (d1 == 0)
	{
		cout << "Invalid denominator value - set to 1" << endl;
		d = 1;
	}
	else
	{
		d = d1;
	}
}

int Fraction::getNumerator()
{
	return n;
}

int Fraction::getDenominator()
{
	return d;
}

Fraction Fraction::add(Fraction f1, Fraction f2)
{
	Fraction temp;

	f1.n *= f2.d;
	f2.n *= f1.d;

	temp.n = f1.n + f2.n;
	temp.d = f1.d * f2.d;

	return temp.simplify();
}

Fraction Fraction::subtract(Fraction f1, Fraction f2)
{
	Fraction temp;

	f1.n *= f2.d;
	f2.n *= f1.d;

	temp.n = f1.n - f2.n;
	temp.d = f1.d * f2.d;

	return temp.simplify();
}

Fraction Fraction::multiply(Fraction f1, Fraction f2)
{
	Fraction temp;

	temp.n = f1.n * f2.n;
	temp.d = f1.d * f2.d;

	return temp.simplify();
}

Fraction Fraction::divide(Fraction f1, Fraction f2)
{
	Fraction tempF2;

	tempF2.n = f2.d;
	tempF2.d = f2.n;

	return multiply(f1, tempF2);
}

Fraction Fraction::simplify()
{
	Fraction temp;

	if (d < 0)
	{
		n *= -1;
		d *= -1;
	}

	for (int x = abs(d); x >= 1; x--)
	{
		if (n % x == 0 && d % x == 0)
		{
			temp.n = n / x;
			temp.d = d / x;
			break;
		}
	}

	return temp;
}

void Fraction::printFrac()
{
	cout << n << "/" << d << endl;
}

#endif