//	2d Arrays in C++
//	12-6-19

/*
	5 4 6	Rows = 2
	7 1 2	Columns = 3

	arr[1][2] = 2
*/

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

// In C++, we're forced to specify the 2d array size in functions. C++ thinks of a 2d array as an array of arrayss

// We can "overload" a function - same name, different inputs
//		But as long as the array columns are different

void print2dArray(int[2][3]);
void print2dArray(int[4][4]);
void fill2dArray(int[4][4]);

int main()
{
	srand(time(0));

	//	Declare a 2x3 with pre-set values
	int a[2][3] = { {5, 4, 6}, {7, 1, 2} };

	// Call the function using name of array, no brackets
	print2dArray(a);
	cout << endl;
	
	// Create an empty 4x4 array (remember, these are not zeros!)
	int grid[4][4];
	fill2dArray(grid);
	print2dArray(grid);

	return 0;
}

void fill2dArray(int arr[4][4])
{
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			arr[r][c] = rand() % 10;
		}
	}
}

void print2dArray(int arr[4][4])
{
	for (int r = 0; r < 4; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			cout << arr[r][c] << " ";
		}
		cout << endl;
	}
}

void print2dArray(int arr[2][3])
{
	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			cout << arr[r][c] << " ";
		}
		cout << endl;
	}
}