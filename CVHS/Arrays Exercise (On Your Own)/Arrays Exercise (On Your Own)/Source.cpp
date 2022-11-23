// Arrays Exercise (On Your Own)
// 11-26-19

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

void generateList(int[], const int);
int smallestValue(int[], const int);
int largestValue(int[], const int);
void printList(int[], const int);
bool hasDuplicates(int[], const int);

int main()
{
	srand(time(0));
	int arr[40];
	const int SIZE = 40;

	generateList(arr, SIZE);

	cout << "Smallest Value:" << smallestValue(arr, SIZE) << endl;
	cout << "Largest Value: " << largestValue(arr, SIZE) << endl;

	printList(arr, SIZE);

	if (hasDuplicates(arr, SIZE))
		cout << "This list has duplicates" << endl;
	else
		cout << "This list doesn't have duplicates" << endl;

	int yes = 0, no = 0;

	for (int n = 1; n <= 10000; n++)
	{
		generateList(arr, SIZE);

		if (hasDuplicates(arr, SIZE) == true)
			yes++;
		else
			no++;
	}

	cout << yes << endl << no << endl;

	return 0;
}

void generateList(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % SIZE + 1;
	}
}

int smallestValue(int arr[], const int SIZE)
{
	int smallest = INT_MAX;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
		}
	}
	return smallest;
}

int largestValue(int arr[], const int SIZE)
{
	int largest = INT_MIN;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] > largest)
		{
			largest = arr[i];
		}
	}

	return largest;
}

void printList(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << "\t";
		for (int a = 1; a <= arr[i]; a++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

bool hasDuplicates(int arr[], const int SIZE)
{
	for (int i = 0; i < SIZE-1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			return arr[i] == arr[j];
		}
	}

	return false;
}