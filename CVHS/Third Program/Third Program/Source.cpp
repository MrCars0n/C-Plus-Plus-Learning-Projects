/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	Carson Kramer
	8-21-2019
	Period 5
	Basic Math & If-Then
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

#include<iostream>
using namespace std;

int main() {
	double a, b;

	cout << "Please enter your first number: ";
	cin >> a;

	cout << "Please enter your second number: ";
	cin >> b;

	cout << "The sum is " << a + b << endl;
	cout << "The difference is " << a - b << endl;
	cout << "The product is " << a * b << endl;
	cout << "The quotient is " << a / b << endl;

	if (a > b) {
		cout << a << " is greater than " << b << endl;
	}
	if (a < b) {
		cout << a << " is less than " << b << endl;
	}
	if (a == b) {
		cout << a << " is equal to " << b << endl;
	}

	return 0;
}