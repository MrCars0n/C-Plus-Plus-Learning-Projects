/* Circle Struct
	store as integers the (h, k) center and radius

	make functions for diameter, area, circumference, print		
		(x - _)^2 + (y - _)^2 = _^2
*/
#pragma once
#include<iostream>
using namespace std;

struct Circle 
{
	double h, k, r;
};

double diameter(Circle c)
{
	return c.r * 2;
}

double area(Circle c)
{
	return 3.14 * pow(c.r, 2);
}

double circumference(Circle c)
{
	return 3.14 * diameter(c);
}

void print(Circle c)
{
	cout << "(x" << (c.h < 0 ? "+" : "") << -1 * c.h << ")^2 + (y" << (c.k < 0 ? "+" : "") << -1*  c.k << ")^2 = " << c.r * c.r << "^2" << endl;
}