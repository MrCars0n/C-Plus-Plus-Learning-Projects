/*	2D Arrays and Functions in C++
	12-9-19

	Pass by value - when you send a variable into a functions, it's a copy
	Any change you make to the copy is NOT kept when you exit

	Passing by reference - when you pass an array into a function, it's NOT just a copy
	It's the original array, so any change made is kept
	To pass a variable by reference (to keep changes), we use the ampersand (&)
*/

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

void fill(int[3][3]);
void print(int[3][3]);

void doubleElement(int);

void properDouble(int&);

// Passing by reference - & tells compter to keep any change
void swapCorners(int&, int&);

int sumArray(int[3][3]);

int main()
{
	srand(time(0));
	
	int grid[3][3];
	fill(grid);
	print(grid);

	//	Double the number in the top left
	//		* NOTE: only sending one element. We are NOT sending in the array - so it's passed by value (CHANGE NOT KEPT)
	doubleElement(grid[0][0]);
	print(grid);

	properDouble(grid[0][0]);
	print(grid);

	swapCorners(grid[0][0], grid[2][2]);
	print(grid);

	cout << "The sum of the elements in the array is: " << sumArray(grid) << endl;

	return 0;
}

int sumArray(int arr[3][3])
{
	int total = 0;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			total += arr[r][c];
		}
	}
	return total;
}

void swapCorners(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void properDouble(int &num)
{
	num *= 2;
}

//	NOTE - THIS WILL NOT ACTUALLY WORK
void doubleElement(int num)
{
	num *= 2;
}

//	We name the parameter "arr", not grid, but it doesn't matter
//		Any changes we make will be kept regardless (pass by reference)
void fill(int arr[3][3])
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			arr[r][c] = rand() % 10;
		}
	}
}

void print(int arr[3][3])
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			cout << arr[r][c] << " ";
		}
		cout << endl;
	}
	cout << endl;
}