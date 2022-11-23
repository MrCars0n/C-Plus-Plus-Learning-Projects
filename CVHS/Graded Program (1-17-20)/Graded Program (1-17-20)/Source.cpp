#include<iostream>
#include"Cylinder.h"
#include"Sphere.h"
using namespace std;

int main()
{
	Cylinder c1;
	c1.height = 4;
	c1.radius = 5;

	Sphere s1;
	s1.radius = 5;

	cout << "Surface area of cylinder = " << area(c1) << endl;
	cout << "Volume of cylinder = " << volume(c1) << endl;
	cout << "Surface area of sphere = " << area(s1) << endl;
	cout << "Volume of sphere = " << volume(s1) << endl;

	if (volume(c1) == area(s1))
		cout << "The volume of the cylinder and the area of the sphere are the same!" << endl;

	return 0;
}