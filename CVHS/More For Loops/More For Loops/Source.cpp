/*
	Carson Kramer
	10-9-19
	Period 5
	More For Loop Examples
*/

#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	// Other ways to redirect flow in loops - break and continue
	for (int x = 1; x <= 10; x++)
	{
		cout << x << " ";

		if (x == 7)
			break;
	}
	cout << endl;

	// break with nested loops - break only exits the current loop
	for (int x = 1; x <= 10; x++)
	{
		cout << "X = " << x << endl;

		for (int y = 1; y <= 10; y++)
		{
			cout << "\tY = " << y << endl;
			if (y == 3)
			{
				// To stop the entire set of loops, add x = 10;
				break;
			}
		}
	}

	// break stops the loop altogether, but continue only skips one step
	for(int x = -5; x <= 5; x++)
	{
		if (x == 0)
			continue;

		cout << 1.0 / x << endl;
	}
	cout << endl;

	/*
		Factors of a number (leads up to finding primes)
		Enter a number and print all of the factors
		Ex: 24 = 1, 2, 3, 4, 6, 8, 12, 24
	*/ 

	int num;

	cout << "Enter a number: ";
	cin >> num;
	cout << num << " = ";
	for(int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			cout << i;
			if (i == num)
				break;
			cout << ", ";
		}
	}
	cout << endl;

	for (int freq = 500; freq <= 10000; freq += 500)
	{
		Beep(freq, 250);
	}

	return 0;
}