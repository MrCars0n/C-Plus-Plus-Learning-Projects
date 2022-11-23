// Pointers
// 2-24-20

#include<iostream>
using namespace std;

int main()
{
	int x;				// Delcaring an integer variable called x
	x = 5;				// Assign the value 5 to the integer variable x

	int *xPtr;			// Declares an integer pointer
	xPtr = &x;			// Set the pointer to the address of x

	cout << x << endl;
	cout << xPtr << endl;

	/* 
	Recall:
		Passing by value - sending a copy to the function, any changes you make are not kept, 
			because your modifying a copy not the original

		Passing by reference - sending the actual variable's contents to the function
			any changes you make are kept. We use the & to do this. Arrays are always passed by reference
	*/
	int arr[] = { 10, 20, 30, 40, 50 };
	int *arrPtr = arr;

	cout << sizeof(int) << endl;
	cout << sizeof(arr) << endl;
	int length = sizeof(arr) / sizeof(int);

	for (int x = 0; x < length; x++)
	{
		cout << arr[x] << "\t" << &arrPtr[x] << endl;
	}



	return 0;
}