// Array Exercoses
// 11-25-19

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

// In C++, arrays are passed into functions "as reference"
//		any changes made to them are kept - you aren't sending a copy
void fillArray(int[], const int);
void printArray(int[], const int);
int totalArray(int[], const int);
double averageArray(int[], const int);

int main()
{
	srand(time(0));

	// To not use same number in code, use constant variable for array size
	//		(Const variables capitalized)
	const int SIZE = 10;
	int nums[SIZE];

	// Fill an array of size 10 with random numbers from 1 to 30
	//		When you send an array to the function, don't use []
	fillArray(nums, SIZE);

	// Print the array
	printArray(nums, SIZE);

	// Total the elements of the array
	cout << "Total = " << totalArray(nums, SIZE) << endl;

	// Find the average of the elements in the array
	cout << "Average = " << averageArray(nums, SIZE) << endl;

	return 0;
}

void fillArray(int arr[], const int SIZE)
{
	for (int x = 0; x < SIZE; x++)
	{
		arr[x] = rand() % 30 + 1;
	}
}

void printArray(int arr[], const int SIZE)
{
	for (int x = 0; x < SIZE; x++)
	{
		cout << x << "\t" << arr[x] << endl;
	}
}

int totalArray(int arr[], const int SIZE)
{
	int total = 0;
	for (int x = 0; x < SIZE; x++)
	{
		total = total + arr[x];
	}

	return total;
}

double averageArray(int arr[], const int SIZE)
{
	return (double)totalArray(arr, SIZE) / (double)SIZE;
}