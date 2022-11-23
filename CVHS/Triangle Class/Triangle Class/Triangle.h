// Triangle Class
// Period 5
// Carson Kramer
// 1-28-20
#include<iostream>
using namespace std;

#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
private:
	int a;
	int b;
	int c;
public:
	Triangle();
	Triangle(int, int, int);
	void seta(int);
	void setb(int);
	void setc(int);
	int geta();
	int getb();
	int getc();
	int perimeter();
	double area();
	void printType();
};

Triangle::Triangle()
{
	seta(1);
	setb(1);
	setc(1);
}

Triangle::Triangle(int a1, int b1, int c1)
{
	seta(a1);
	setb(b1);
	setc(c1);
}

void Triangle::seta(int a1)
{
	if (a1 > 0)
	{
		a = a1;
	}
	else
	{
		cout << "Invalid \"a\" value - set to 1" << endl;
		a = 1;
	}
}

void Triangle::setb(int b1)
{
	if (b1 > 0)
	{
		b = b1;
	}
	else
	{
		cout << "Invalid \"b\" value - set to 1" << endl;
		b = 1;
	}
}

void Triangle::setc(int c1)
{
	if (c1 > 0)
	{
		c = c1;
	}
	else
	{
		cout << "Invalid \"c\" value - set to 1" << endl;
		c = 1;
	}
}

int Triangle::geta()
{
	return a;
}

int Triangle::getb()
{
	return b;
}

int Triangle::getc()
{
	return c;
}

int Triangle::perimeter()
{
	return geta() + getb() + getc();
}

double Triangle::area()
{
	double s = perimeter() * .5;

	return sqrt(s * (s - geta()) * (s - getb()) * (s - getc()));
}

void Triangle::printType()
{
	if (geta() == getb() && getb() == getc())
		cout << "Equilateral" << endl;
	else if (geta() == getb() || geta() == getc() || getb() == getc())
		cout << "Isosceles" << endl;
	else
		cout << "Scalene" << endl;
}

#endif