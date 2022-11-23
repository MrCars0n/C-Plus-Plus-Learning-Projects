#pragma once
#include<iostream>
using namespace std;

struct Fraction
{
	int n, d;
};

Fraction add(Fraction f1, Fraction f2)
{
	Fraction temp;

	f1.n *= f2.d;
	f2.n *= f1.d;

	temp.n = f1.n + f2.n;
	temp.d = f1.d * f2.d;

	return temp;
}

Fraction subtract(Fraction f1, Fraction f2)
{
	Fraction temp;

	f1.n *= f2.d;
	f2.n *= f1.d;

	temp.n = f1.n - f2.n;
	temp.d = f1.d * f2.d;

	return temp;
}

Fraction multiply(Fraction f1, Fraction f2)
{
	Fraction temp;

	temp.n = f1.n * f2.n;
	temp.d = f1.d * f2.d;

	return temp;
}

Fraction divide(Fraction f1, Fraction f2)
{
	Fraction tempF2;

	tempF2.n = f2.d;
	tempF2.d = f2.n;

	return multiply(f1, tempF2);
}

Fraction simplify(Fraction f)
{
	Fraction temp;
	for (int x = f.d; x >= 1; x--)
	{
		if (f.n % x == 0 && f.d % x == 0)
		{
			temp.n = f.n / x;
			temp.d = f.d / x;
			break;
		}
	}

	return temp;

	/*
	Fraction temp;

	for (int i = 1; i < (f.n > f.d ? f.d : f.n); i++)
	{
		if (f.n % i == 0 && f.d % i == 0)
		{
			temp.n = f.n / i;
			temp.d = f.d / i;
			return simplify(temp);
		}
	}

	return f;
	*/
}

void printFrac(Fraction f)
{
	Fraction simp = simplify(f);
	cout << simp.n << "/" << simp.d << endl;
}