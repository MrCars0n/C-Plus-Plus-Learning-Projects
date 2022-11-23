// Equilateral Triangle Function

#include<iostream>
using namespace std;

bool isEquilateral(int, int, int);

int main()
{
	int a, b, c;

	cout << "Enter 3 sides of a triangle: ";
	cin >> a >> b >> c;

	if (isEquilateral(a, b, c))
		cout << "This is an equilateral traingle" << endl;
	else
		cout << "This isn't an equilateral traingle" << endl;
}

bool isEquilateral(int a, int b, int c)
{
	return a == b && b == c;
}