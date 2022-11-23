// Arrays
// 11-22-19

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

/*
	Variable - can hold one single element of one data type
	Data Structure - collection of related data items

	Array - data structure with a fixed size (static)
		Once size of array set, can’t change

	Dynamic Structures - structures that can be changed (opposite of static)

	Element - actual contents of a given array location
		Subscript / Index - location of the element, starting with 0 (zeroth element)

	Off-By-One Errors - be careful of loop boundaries
		Never include length of the array
		Beware of (x-1) or (x+1) as subscripts
*/

int main()
{
	srand(time(0));

	// If you know the values in the array
	int nums[] = { 1, 4, 9, 16, 25 };

	// To traverse the array, we use a for loop
	//	In an array of size 5, the location are 0 to 4
	for (int n = 0; n < 5; n++)
		cout << n << "\t" << nums[n] << endl;

	// Fill an array with random numbers 0 - 9
	// NOTE - ARRAYS IN C++ DO NOT DEFAULT TO ZERO!

	// This sets all values in the array to zero (but only works with zero)
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 10;
		cout << i << "\t" << arr[i] << endl;
	}

	// C++ does nto allow you to enter the array size during runtime
	//		can't say -- int a[size] = { 0 };

	char word[] = "carson dwight kramer";

	for (int x = 19; x >= 0; x--)
		cout << word[x];
	cout << endl;

	return 0;
}