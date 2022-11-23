// Magic Square ("any" size)

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int SIZE = 4;
 
void fillNoRepeats(int[SIZE][SIZE]);
void print(int[SIZE][SIZE]);
bool isMagic(int [SIZE][SIZE]);
void clearArray(int [SIZE][SIZE]);
int sumRow(int [SIZE][SIZE], int);
int sumCol(int [SIZE][SIZE], int);

int main()
{
	srand(time(0));

	int grid[SIZE][SIZE] = { 0 };
	int count = 0;
	int goalSum = SIZE * (SIZE * SIZE + 1) / 2;
	cout << "GOAL = " << goalSum << endl;

	do
	{
		clearArray(grid);
		fillNoRepeats(grid);

		count++;
		if (count > 30000)
		{
			srand(time(0));
			count = 0;
		}

	} while (isMagic(grid) == false);  // do they all add up to 65?

	print(grid);

	return 0;
}

bool isMagic(int grid[SIZE][SIZE])
{
	int goalSum = SIZE * (SIZE * SIZE + 1) / 2;

	// Diagonals Top Left to Bottom Right
	int total = 0;
	for (int d = 0; d < SIZE; d++)
		total = total + grid[d][d];

	if (total != goalSum)
		return false;

	// Diagonal Top Right to Bottom Left
	total = 0;
	for (int d = 0; d < SIZE; d++)
		total = total + grid[SIZE - d - 1][d];

	if (total != goalSum)
		return false;

	for (int r = 0; r < SIZE; r++)
		if (sumRow(grid, r) != goalSum)
			return false;

	for (int c = 0; c < SIZE; c++)
		if (sumCol(grid, c) != goalSum)
			return false;



	return true;
}

int sumRow(int grid[SIZE][SIZE], int row)
{
	int total = 0;
	for (int n = 0; n < SIZE; n++)
		total = total + grid[row][n];

	return total;
}

int sumCol(int grid[SIZE][SIZE], int col)
{
	int total = 0;
	for (int n = 0; n < SIZE; n++)
		total = total + grid[n][col];

	return total;
}

void clearArray(int grid[SIZE][SIZE])
{
	for (int r = 0; r < SIZE; r++)
		for (int c = 0; c < SIZE; c++)
			grid[r][c] = 0;
}

void fillNoRepeats(int arr[SIZE][SIZE])
{
	for (int count = 1; count <= SIZE * SIZE; count++)
	{
		int row, col;
		do
		{
			row = rand() % SIZE;
			col = rand() % SIZE;
		} while (arr[row][col] != 0);

		arr[row][col] = count;
	}
}

void print(int arr[SIZE][SIZE])
{
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			cout << arr[r][c] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}