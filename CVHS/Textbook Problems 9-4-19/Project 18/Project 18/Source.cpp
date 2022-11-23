#include<iostream>
using namespace std;

int main()
{
	int num1, num2;

	cout << "Please enter two numbers: ";
	cin >> num1 >> num2;

	if (num1 > num2) 
	{
		cout << num1 << " is larger than " << num2 << endl;
	}
	else if (num2 > num1) 
	{
		cout << num2 << " is larger than " << num1 << endl;
	}
	else 
	{
		cout << "These numbers are equal" << endl;
	}
	return 0;
}