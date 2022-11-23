// Complex Number Class Header File

#include<iostream>
using namespace std;

#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
	double real;
	double imag;
public:
	Complex();
	Complex(double, double);
	void setReal(double);
	void setImag(double);
	double getReal();
	double getImag();
	void print();
	Complex add(Complex, Complex);
};

Complex::Complex()
{
	setReal(0);
	setImag(0);
}

Complex::Complex(double r, double i)
{
	setReal(r);
	setImag(i);
}

void Complex::setReal(double r)
{
	real = r;
}

void Complex::setImag(double i)
{
	imag = i;
}

double Complex::getReal()
{
	return real;
}

double Complex::getImag()
{
	return imag;
}

void Complex::print()
{
	cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
}

// Return type = Complex
// Class = Complex
// Parameters = Complex
Complex Complex::add(Complex c1, Complex c2)
{
	Complex temp;

	temp.setReal(c1.getReal() + c2.getReal());
	temp.setImag(c1.getImag() + c2.getImag());

	return temp;
}

#endif
