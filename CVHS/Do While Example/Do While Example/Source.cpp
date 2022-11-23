/*
	Carson Kramer
	10-15-19
	Period 5
	Do While Example
*/

#include<iostream>
using namespace std;

int main()
{
	// Sum numbers until we enter 0
	int num, total = 0;

	do
	{
		cin >> num;
		total += num;
	} while (num != 0);

	cout << "Total = " << total << endl;

	return 0;
}