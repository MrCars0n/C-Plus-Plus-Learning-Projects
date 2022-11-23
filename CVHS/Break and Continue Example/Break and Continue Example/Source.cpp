/*
	Carson Kramer
	10-15-19
	Period 5
	Break and Continue
*/

#include<iostream>
using namespace std;

int main()
{
	for (int x = 1; x <= 10; x++)
	{
		cout << x << endl;

		if (x % 2 == 0)
			break;
	}

	for (int x = -5; x <= 5; x++)
	{
		if (x == 0)
			continue;

		cout << 1.0 / x << endl;
	}

	return 0;
}