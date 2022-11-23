//	Carson Kramer & Josh George
//	Period 5
//	March 9th, 2020
//	Bucket Sort Algorithm

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

using namespace std;

void fillArray(int[]);
void printArray(int[]);

void bucketSort(int[]);
int getMax(int[]);

const int SIZE = 20;

int main()
{
	srand(time(0));
	int nums[SIZE];

	fillArray(nums);
	printArray(nums);

	bucketSort(nums);
	printArray(nums);

	return 0;
}

// Fills array with random numbers
void fillArray(int arr[])
{
	for (int x = 0; x < SIZE; x++)
		arr[x] = rand() % 100 + 1;
}

// Prints the array
void printArray(int arr[])
{
	for (int x = 0; x < SIZE; x++)
		cout << arr[x] << " ";
	cout << endl;
}

// Returns the largest number in a list
int getMax(int arr[])
{
	int max = arr[0];
	for (int i = 1; i < SIZE; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

// Sorts the list using Bucket Sort
void bucketSort(int arr[])
{
	int bucket[101];
	const int max = getMax(arr);
	
	// Sets bucket array to 0
	for (int i = 0; i <= max; i++)
	{
		bucket[i] = 0;
	}

	// Increases corresponding buckets to each number of a list
	for (int i = 0; i < SIZE; i++)
	{
		bucket[arr[i]]++;
	}

	// Sorts array based on buckets in order
	for (int i = 0, j = 0; i <= max; i++)
	{
		while (bucket[i] > 0)
		{
			arr[j++] = i;
			bucket[i]--;
		}
	}
}