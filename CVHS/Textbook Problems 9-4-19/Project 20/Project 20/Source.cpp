#include<iostream>
using namespace std;

int main()
{
	double rad, diam, circ, area;
	cout << "Enter the radius of a circle: ";
	cin >> rad;

	diam = 2 * rad;
	circ = diam * 3.14159;
	area = pow(rad, 2) * 3.14159;

	cout << "The diameter is " << diam << endl;
	cout << "The circumference is " << circ << endl;
	cout << "The area is " << area << endl;
	return 0;
}