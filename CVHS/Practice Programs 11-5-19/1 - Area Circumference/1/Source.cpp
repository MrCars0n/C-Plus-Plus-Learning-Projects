// Circumference Function

#include<iostream>
using namespace std;

double circumference(double), area(double);

int main()
{
	double r;
	cout << "Enter radius: ";
	cin >> r;

	cout << endl << "Circumference: " << circumference(r) << endl << "Area: " << area(r) << endl;
	return 0;
}

double circumference(double r)
{
	return 3.1415 * 2 * r;
}

double area(double r)
{
	return 3.1415 * r * r;
}