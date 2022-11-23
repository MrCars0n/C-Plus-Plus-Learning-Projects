/*
	Carson Kramer
	10-29-19
	Period 5
	Function Examples (with Math) 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int minimum(int, int, int);

int main()
{
	cout << abs(-5) << endl;
	cout << sqrt(5) << endl;
	cout << pow(2, 3) << endl;
	cout << cbrt(5) << endl;
	cout << hypot(5, 12) << endl;

	cout << ceil(9.2) << endl;
	cout << floor(9.2) << endl;
	cout << round(9.2) << endl;

	cout << sin(3.14159) << endl;
	cout << cos(3.14159) << endl;
	cout << tan(3.14159) << endl;

	cout << acos(0) << endl;
	cout << asin(0) << endl;
	cout << atan(0) << endl;

	cout << log(4) << endl;		//ln(4) - natrual log
	cout << log10(4) << endl;	// log(4) - common log

	// From <algorithm>
	cout << min(3, 5) << endl; //3
	cout << max(3, 5) << endl; //5

	cout << minimum(7, 3, 5) << endl;

	return 0;
}

int minimum(int a, int b, int c)
{
	return min(a, min(b, c));
}