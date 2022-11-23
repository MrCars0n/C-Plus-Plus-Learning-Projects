#include<iostream>
using namespace std;

int main()
{
	int num1;
	cout << "Enter at 5 digit number: ";
	cin >> num1;

	cout << int(num1 * 0.0001) << "   ";

	num1 = num1 - int(num1 * 0.0001) * 10000;

	cout << int(num1 * 0.001) << "   ";

	num1 = num1 - int(num1 * 0.001) * 1000;

	cout << int(num1 * 0.01) << "   ";

	num1 = num1 - int(num1 * 0.01) * 100;

	cout << int(num1 * 0.1) << "   ";

	num1 = num1 - int(num1 * 0.1) * 10;

	cout << num1 << endl;
	return 0;
}