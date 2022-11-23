/*
	Carson Kramer
	10-28-19
	Period 5
	Introduction to Functions
*/

#include<iostream>
using namespace std;

/* Function declaration / prototype
		We give the function a name, what we're sending in and what we're getting out	*/
int f(int);

int main()
{
	// To use function, we "call" it
	cout << f(3) << endl;

	for (int x = -10; x <= 10; x++)
	{
		cout << x << "\t" << f(x) << endl;
	}

	return 0;
}

// Function definitions - waht the functions actually do
int f(int x)
{
	return 2 * x - 1;
}