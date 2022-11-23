#include<iostream>
using namespace std;

int main()
{
	int num1, num2, num3, num4, num5, smallest, largest;

	cout << "Enter 5 numbers: ";

	cin >> num1 >> num2 >> num3 >> num4 >> num5;

	if ((num1 < num2) && (num1 < num3) && (num1 < num4) && (num1 < num5))
	{
		smallest = num1;
	}
	else if ((num2 < num1) && (num2 < num3) && (num2 < num4) && (num2 < num5))
	{
		smallest = num2;
	}
	else if ((num3 < num1) && (num3 < num2) && (num3 < num4) && (num3 < num5))
	{
		smallest = num3;
	}
	else if ((num4 < num1) && (num4 < num3) && (num4 < num2) && (num4 < num5))
	{
		smallest = num4;
	}
	else if ((num5 < num1) && (num5 < num3) && (num5 < num4) && (num5 < num2))
	{
		smallest = num5;
	}


	if ((num1 > num2) && (num1 > num3) && (num1 > num4) && (num1 > num5))
	{
		largest = num1;
	}
	else if ((num2 > num1) && (num2 > num3) && (num2 > num4) && (num2 > num5))
	{
		largest = num2;
	}
	else if ((num3 > num1) && (num3 > num2) && (num3 > num4) && (num3 > num5))
	{
		largest = num3;
	}
	else if ((num4 > num1) && (num4 > num3) && (num4 > num2) && (num4 > num5))
	{
		largest = num4;
	}
	else if ((num5 > num1) && (num5 > num3) && (num5 > num4) && (num5 > num2))
	{
		largest = num5;
	}

	cout << "The largest is " << largest << endl;
	cout << "The smallest is " << smallest << endl;

	return 0;
}