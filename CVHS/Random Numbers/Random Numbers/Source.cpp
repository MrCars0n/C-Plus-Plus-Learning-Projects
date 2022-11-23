/*
	Carson Kramer
	10-31-19
	Period 5
	Random Numbers
*/

#include<iostream>
#include<stdlib.h>		// rand() and srand()
#include<time.h>		// time()
using namespace std;

int main()
{
	// Unix Timestamp - number of seconds since 1/1/70
	cout << "The time is " << time(0) << endl;

	// Put thsi at the top of any program using random numbers
	srand(time(0));

	for (int i = 1; i<= 10; i++)
		cout << rand() << endl;

	// rand() generates a random integer from 0 to RAND_MAX (32,767)
	cout << "Random Maximum = " << RAND_MAX << endl;

	// Use % to scale a random number down to the range you want
	cout << rand() % 6 + 1<< endl;

	// rand() % range + lowest number -- range = (high - low) + 1

	// Find the average of ten random numbers from 0 to 100
	int total = 0;
	for (int i = 1; i <= 10; i++)
	{
		int num = rand() % 101;// +0;
		cout << num << " ";
		total += num;
	}

	cout << "The average is " << total / 10.0 << endl;

	return 0;
}