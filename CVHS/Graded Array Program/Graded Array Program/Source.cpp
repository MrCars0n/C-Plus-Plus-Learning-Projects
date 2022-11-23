//	Graded Array Program
//	12-11-19

// (n * (n^2+1)) / 2 = 65

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

const int SIZE = 3;
const int magicNumber = (SIZE * (pow(SIZE, 2) + 1)) / 2;

void fillNoRepeats(int[SIZE][SIZE]);
bool isMagic(int[SIZE][SIZE]);
void print(int[SIZE][SIZE]);
void clear(int[SIZE][SIZE]);

int main()
{
	//cout << magicNumber;
	srand(time(0));
	int b[SIZE][SIZE] = { 0 };
	//print(b);

	do
	{
		clear(b);
		fillNoRepeats(b);
	} while (isMagic(b) == false);

	cout << "You did it";

	return 0;
}

bool isMagic(int arr[SIZE][SIZE])
{
	int num = 0;

	// Base Case
	for (int r = 0; r < SIZE; r++)
	{
		num += arr[0][r];
	}

	if (num != magicNumber)
		return false;

	// Check Rows
	for (int r = 1; r < SIZE; r++)
	{
		num = 0;
		for (int c = 0; c < SIZE; c++)
		{
			num += arr[r][c];
		}
		if (num != magicNumber)
		{
			//cout << "*************** Rows No" << endl;
			//print(arr);
			return false;
		}
	}

	// Check Columns
	for (int c = 1; c < SIZE; c++)
	{
		num = 0;
		for (int r = 0; r < SIZE; r++)
		{
			num += arr[r][c];
		}
		if (num != magicNumber)
		{
			//cout << "*************** Columns No" << endl;
			//print(arr);
			return false;
		}
	}

	// Check Diagonals Down
	num = 0;
	for (int r = 0; r < SIZE; r++)
	{
		num += arr[r][r];
	}
	if (num != magicNumber)
	{
		//cout << "*************** Diagonal down No" << endl;
		//print(arr);
		return false;
	}

	//Check Diagonals Up
	num = 0;
	for (int r = 1; r < SIZE; r++)
	{
		for (int c = SIZE-1; c >= 0; c--)
		{
			num += arr[r][c];
		}
	}
	if (num != 65)
	{
		//cout << "*************** Diagonals up No" << endl;
		//print(arr);
		return false;
	}

	return true;
}

void clear(int arr[SIZE][SIZE])
{
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			arr[r][c] = 0;
		}
	}
}

void fillNoRepeats(int arr[SIZE][SIZE])
{
	for (int num = 1; num <= pow(SIZE,2); num++)
	{
		int row, col;
		do
		{
			row = rand() % SIZE;
			col = rand() % SIZE;
		} while (arr[row][col] != 0);

		arr[row][col] = num;
	}
}

void print(int arr[SIZE][SIZE])
{
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			cout << arr[r][c] << " ";
		}
		cout << endl;
	}
}