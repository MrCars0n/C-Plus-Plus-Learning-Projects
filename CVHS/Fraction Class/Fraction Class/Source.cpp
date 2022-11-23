// Fraction Class Test
// Period 5
// Carson Kramer
// 1-30-20
#include<iostream>
#include"Fraction.h"
using namespace std;

int main()
{
	Fraction f1(1, -2), f2(2, 4), sum, diff, prod, quot;

	f1.printFrac();
	f2.printFrac();

	sum.add(f1, f2).printFrac();
	diff.subtract(f1, f2).printFrac();
	prod.multiply(f1, f2).printFrac();
	quot.divide(f1, f2).printFrac();

	return 0;
}