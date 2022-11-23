#include<iostream>
using namespace std;

int main()
{
	int num1, num2;

	cout << "Enter two numbers: ";
	cin >> num1 >> num2;

	if (num2 % num1 == 0)
	{
		cout << "The first number is a multiple of the other" << endl;
	}
	else
	{
		cout << "The first number is not a multiple of the other" << endl;
	}
	return 0;
}