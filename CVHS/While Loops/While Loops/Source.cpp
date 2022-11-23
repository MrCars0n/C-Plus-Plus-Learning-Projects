/*
	Carson Kramer
	9-16-2019
	Period 5
	While Loops
*/

/* Styles of repetition (loops)
		Infinite loop - goes on forever (until program closes)
		Definite loop - roll a pair of dice ten times (know ending)
		Indefinite loop - roll a pair of dice until you get doubles (know when ending if prompted)
*/

#include<iostream>
using namespace std;

int main()
{
	/*
	// Counts from 1 - 10 (Definite)
	for (int x = 1; x <= 10; x++)
	{
		cout << x << endl;
	}

	int n = 1;
	while (true)
	{
		cout << char(n) << " | ";
		n++;
	}

	/* Requirements for a definite loop
		1) Initial value
		2) Loop control/counter variable (LCV)
		3) Loop continuation condition - true/false when the loop runs/stops
		4) Increment/decrement (step)
	*/

	// Indefinite

	int num;
	cin >> num;

	while (num > 1)
	{
		if (num % 2 == 0)
			num = num / 2;
		else
			num = 3 * num + 1;

		cout << num << endl;
	}


	return 0;
}