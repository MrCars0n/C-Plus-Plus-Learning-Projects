/*
	Carson Kramer
	10-8-2019
	Period 5
	For Loop Examples
*/

#include<iostream>
using namespace std;

int main()
{
	// Loop from 1 to 10 by 1s
	for (int i = 1; i <= 10; i++){}

	// Loop from 10 to 1 by 1s
	for (int i = 10; i >= 1; i--){}

	// Loop from 0 to 50 by 5s
	for (int i = 0; i <= 50; i += 5){}


	// Add all of the integers from 1 to 1000
	int total = 0;
	for (int x = 1; x <= 1000; x++)
	{
		total += x;
	}
	cout << total << endl;

	// Print my name 20 times
	for (int i = 1; i <= 20; i++)
	{
		cout << "Sming" << endl;
	}

	// Print an 8x8 checkerboard (4.28)

	for (int v = 1; v <= 8; v++)
	{
		if (v % 2 == 0)
		{
			cout << " ";
		}
		for (int h = 1; h <= 8; h++) 
		{
			cout << "* ";
		}
		cout << endl;
	}

	return 0;
}