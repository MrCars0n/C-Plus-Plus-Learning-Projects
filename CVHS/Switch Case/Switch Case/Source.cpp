/*
	Carson Kramer
	10-15-19
	Period 5
	Switch Case
*/

#include<iostream>
using namespace std;

int main()
{
	double num1, num2;
	char op;

	cout << "Enter the first number: ";
	cin >> num1;

	cout << "Enter the second number: ";
	cin >> num2;

	cout << "Enter the operation (+, -, *, or /): ";
	cin >> op;

	switch (op)
	{
	case '+':
		cout << num1 + num2 << endl;
		break;
	case '-':
		cout << num1 - num2 << endl;
		break;
	case '*':
		cout << num1 * num2 << endl;
		break;
	case '/':
		cout << num1 / num2 << endl;
		break;
	default:	//else
		cout << "Invalid input" << endl;
		break;
	}

	return 0;
}