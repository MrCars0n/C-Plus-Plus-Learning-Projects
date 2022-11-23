//	Sorting and Searching Arrays
//	12-3-19

#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

void fillArray(int[], int);
void printArray(int[], int);

//	Sorting an array involves putting the elements in order least to greatest
//		The bubble sort is easy to code algorithm, but is extremely inefficient

void bubbleSort(int[], int);

/* 
	Searching invloves finding an element in an array and returning the index of that element (-1 if not found)

	Linear (Sequential) Search - slow and inefficient, but easy to code
		Looks through array from left to right until key is found

	This can only find the first if there are any duplicates

	"Speed" of the algorithm - number of iterations (steps)

		BEST CASE - 1 step
		WORST CASE - length of the array (n)
		AVERAGE CASE - n/2
*/

int linearSearch(int[], int, int);

/*	
	Binary Search - guess the number, higher/lower algorithm
		Faster than linear, but list must be sorted
	BEST CASE - 1 step
	WORST CASE - log base 2(n)	- round up, n = array size
	AVERAGE CASE - (log base 2(n)) / 2

	Faster to use linear search or sort then use binary search?
*/

int binarySearch(int[], int, int);

/*
	Find the mean of array
	Find the median of array
	Find the smallest value in array
	Find the largest value in array
	Find and print numbers from 1-100 not in list
*/

double mean(int[], int);
int median(int[], int);
int smallest(int[], int);
int largest(int[], int);
void printNonArrayNums(int[], int);

int main()
{
	srand(time(0));
	const int SIZE = 20;
	int nums[SIZE];

	fillArray(nums, SIZE);
	printArray(nums, SIZE);
	bubbleSort(nums, SIZE);
	printArray(nums, SIZE);

	int foundIndex = linearSearch(nums, SIZE, 76);

	if (foundIndex == -1)
		cout << "76 is not in the list" << endl;
	else
		cout << "76 was found using linear search at index: " << foundIndex << endl;


	foundIndex = binarySearch(nums, SIZE, 75);

	if (foundIndex == -1)
		cout << "75 is not in the list" << endl;
	else
		cout << "75 was found using binary search at index: " << foundIndex << endl;

	cout << "Mean: " << mean(nums, SIZE) << endl;
	cout << "Median: " << median(nums, SIZE) << endl;
	cout << "Smallest: " << smallest(nums, SIZE) << endl;
	cout << "Largest: " << largest(nums, SIZE) << endl;

	printNonArrayNums(nums, SIZE);

	return 0;
}

int binarySearch(int arr[], int SIZE, int key)
{
	// Original starting indices (first and last number)
	int left = 0;
	int right = SIZE - 1;

	while (left <= right)
	{
		int middle = (left + right) / 2;

		if (key < arr[middle])
		{
			right = middle - 1;
		}
		else if (key > arr[middle])
		{
			left = middle + 1;
		}
		else
		{
			return middle;
		}
	}

	return -1;
}

int linearSearch(int arr[], int SIZE, int key)
{
	for (int x = 0; x < SIZE; x++)
		if (key == arr[x])
			return x;

	return -1;
}

void bubbleSort(int arr[], int SIZE)
{
	// Outer Loop - number of passes through the array
	for (int a = 0; a < SIZE - 1; a++)
	{
		// Inner loop - comparing adgacent elements during that pass from left to right (stop before we get to already sorted numbers
		for (int b = 0; b < SIZE - a - 1; b++)
		{
			// If the number on the left is bigger than the number to it'sr ight, swap because they're out of place
			if (arr[b] > arr[b + 1])
			{
				//swap(arr[b], arr[b + 1]);

				// Swap Code
				int temp = arr[b]; // Make a "b" backup
				arr[b] = arr[b + 1]; // Make b = b+1
				arr[b + 1] = temp; // Make b+1 = stored copy
			}
		}
	}
}

void fillArray(int arr[], int SIZE)
{
	for (int x = 0; x < SIZE; x++)
		arr[x] = rand() % 100 + 1;
}

void printArray(int arr[], int SIZE)
{
	for (int x = 0; x < SIZE; x++)
		cout << arr[x] << " ";
	cout << endl;
}

double mean(int arr[], int SIZE)
{
	double mean = 0;
	for (int i = 0; i < SIZE; i++)
	{
		mean += arr[i];
	}
	return mean / SIZE;
}

int median(int arr[], int SIZE)
{
	bubbleSort(arr, SIZE);

	if (SIZE % 2 == 0)
	{
		return (arr[SIZE / 2] + arr[(SIZE / 2) - 1]) / 2.0;
	}
	else
	{
		return arr[SIZE / 2];
	}
}

int smallest(int arr[], int SIZE)
{
	int smallest = arr[0];
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
		}
	}
	return smallest;
	//bubbleSort(arr, SIZE);	// n^2 (20^2 = 400 steps)
	//return arr[0];
}

int largest(int arr[], int SIZE)
{
	int largest = arr[0];				// 20 Steps
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > largest)
		{
			largest = arr[i];
		}
	}
	return largest;
	//bubbleSort(arr, SIZE);
	//return arr[SIZE - 1];
}

void printNonArrayNums(int arr[], int SIZE)
{
	int nums[100];
	for (int i = 1; i <= 100; i++)
	{
		nums[i - 1] = i;
	}
	for (int i = 0; i < SIZE; i++)
	{
		nums[arr[i] - 1] = -1;
	}

	for (int i = 0; i < 100; i++)
	{
		if (nums[i] != -1)
		{
			cout << nums[i] << " ";
		}
	}
	cout << endl;
}