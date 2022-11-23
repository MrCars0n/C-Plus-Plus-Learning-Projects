//	2D Array Exercises
//	12-10-19

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

void fillNoRepeats(int[3][3]);
void fillNoRepeatsV2(int[3][3]);
void print(int[3][3]);

bool isMagic(int[3][3]);

int main()
{
	srand(time(0));

	int a[3][3] = { 0 };
	fillNoRepeats(a);
	print(a);

	cout << endl;

	int b[3][3] = { 0 };
	fillNoRepeatsV2(b);
	print(b);

	return 0;
}

/*
	Option 1 - go through left-right, top-bottom picking a random 1-9
		Before we fill in that number, make sure we haven't already chosen it
*/
void fillNoRepeats(int arr[3][3])
{
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			bool repick;
			int num;

			do
			{
				num = rand() % 9 + 1;
				repick = false;

				for (int r1 = 0; r1 < 3; r1++)
				{
					for (int c1 = 0; c1 < 3; c1++)
					{
						if (num == arr[r1][c1])
						{
							repick = true;
						}
					}
				}

			} while (repick == true);

			arr[r][c] = num;
		}
	}
}

/*
	Option 2 - go through the numbers 1-9, picking a random unfilled location
		(Again, this works because the array is "empty", filled with zeros)
*/
void fillNoRepeatsV2(int arr[3][3])
{
	for (int num = 1; num <= 9; num++)
	{
		int row, col;
		do
		{
			row = rand() % 3;
			col = rand() % 3;
		} while (arr[row][col] != 0);

		arr[row][col] = num;
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
}