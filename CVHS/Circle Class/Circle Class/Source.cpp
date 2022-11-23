// Circle Class Test
// Period 5
// Carson Kramer
// 1-29-20

#include<iostream>
#include"Circle.h"
using namespace std;

int main()
{
	Circle c(0, -3, 4);

	cout << "Area = " << c.area() << endl;
	cout << "Perimeter = " << c.circumference() << endl;
	c.printEquation();
	return 0;
}