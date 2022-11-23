#include<iostream>
#include"Circles.h"
using namespace std;

int main()
{
	Circle c;
	c.h = 0;
	c.k = 0;
	c.r = 5;

	cout << "Diameter = " << diameter(c) << endl;
	cout << "Circumference = " << circumference(c) << endl;
	cout << "Area = " << area(c) << endl;
	//cout << "(x - " << c.h << ")^2 + (y - " << c.k << ")^2 = " << c.r << "^2" << endl;
	return 0;
}