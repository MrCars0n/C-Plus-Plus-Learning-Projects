// Complex Number Source

#include<iostream>
#include"Complex.h"
using namespace std;

int main()
{
	Complex c1;
	c1.imag = -2;
	c1.real = 3;
	cout << "Number 1: ";
	printComplex(c1);

	Complex c2;
	c2.real = 4;
	c2.imag = 5;
	cout << "Number 2: ";
	printComplex(c2);

	// (3-2i) + (4+5i) = 7 + 3i
	Complex sum = addComplex(c1, c2);
	cout << "Added: ";
	printComplex(sum);

	Complex diff = subtractComplex(c1, c2);
	cout << "Subtracted: ";
	printComplex(diff);

	Complex prod = multiplyComplex(c1, c2);
	cout << "Multiplied: ";
	printComplex(prod);

	Complex quot = divideComplex(c1, c2);
	cout << "Divided: ";
	printComplex(quot);

	return 0;
}