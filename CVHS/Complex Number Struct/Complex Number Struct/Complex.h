// Complex Number Structure
//	a + bi
//	a = real part; b = imaginary part

#pragma once
#include<iostream>
using namespace std;

struct Complex
{
	double real, imag;
};

// printComplex
void printComplex(Complex c)
{
	cout << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i" << endl;
}

// addComplex
Complex addComplex(Complex c1, Complex c2)
{
	Complex temp;

	temp.real = c1.real + c2.real;
	temp.imag = c1.imag + c2.imag;

	return temp;
}

// subtractComplex
Complex subtractComplex(Complex c1, Complex c2)
{
	Complex temp;

	temp.real = c1.real - c2.real;
	temp.imag = c1.imag - c2.imag;

	return temp;
}

// multiplyComplex
Complex multiplyComplex(Complex c1, Complex c2)
{
	Complex temp;

	temp.real = c1.real * c2.real - c1.imag * c2.imag;
	temp.imag = c1.real * c2.imag + c1.imag * c2.real;

	return temp;
}

//divideComplex
Complex divideComplex(Complex c1, Complex c2)
{
	Complex c;

	c2.imag = -c2.imag; // make the conjugate

	c = multiplyComplex(c1, c2);
	c.real /= pow(c2.real, 2) + pow(c2.imag, 2);
	c.imag /= pow(c2.real, 2) + pow(c2.imag, 2);

	return c;
}
