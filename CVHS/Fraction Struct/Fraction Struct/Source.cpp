#include<iostream>
#include"Fractions.h"
using namespace std;

int main()
{
	Fraction f1, f2;

	f1.n = 5;
	f1.d = 6;

	f2.n = 3;
	f2.d = 8;
	
	printFrac(add(f1, f2));
	printFrac(subtract(f1, f2));
	printFrac(multiply(f1, f2));
	printFrac(divide(f1, f2));

	//printFrac(simplify(f2));
	//printFrac(multiply(f1, f2));
	//simplify(multiply(f1, f2));
	//printFrac(f1);
	return 0;
}