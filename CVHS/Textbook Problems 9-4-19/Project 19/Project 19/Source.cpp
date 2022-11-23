#include<iostream>
using namespace std;

int main()
{
	int num1, num2, num3, sum, avg, prod, smallest, largest;
	
	cout << "Input three numbers: ";
	cin >> num1 >> num2 >> num3;

	sum = num1 + num2 + num3;
	avg = (num1 + num2 + num3) / 3;
	prod = num1 * num2 * num3;

	cout << "The sum is " << sum << endl;
	cout << "The average is " << avg << endl;
	cout << "The product is " << prod << endl;

	if (num1 < num2) 
	{
		if (num1 < num3) 
		{
			smallest = num1;
		}
		else 
		{
			smallest = num3;
		}
	}
	else 
	{
		if (num2 < num3)
		{
			smallest = num2;
		}
		else 
		{
			smallest = num3;
		}
	}
	cout << "The smallest is " << smallest << endl;

	if (num1 > num2)
	{
		if (num1 > num3)
		{
			largest = num1;
		}
		else
		{
			largest = num3;
		}
	}
	else
	{
		if (num2 > num3)
		{
			largest = num2;
		}
		else
		{
			largest = num3;
		}
	}
	cout << "The largest is " << largest << endl;

	return 0;
}