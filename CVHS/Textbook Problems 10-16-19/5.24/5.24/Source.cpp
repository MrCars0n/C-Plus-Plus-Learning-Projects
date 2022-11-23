#include<iostream>
using namespace std;

int main()
{
	int rows, numberOfStars; //numberOfStars is odd number checker for number of stars on bottom. Each line is just the next odd number
	cin >> rows;

	numberOfStars = rows - 1; //minus one because rows is equal to number of stars in middle row. 
	//One below that is next odd number, so minus one removes chance of using middle row number of stars

	for (int i = 1; i <= rows; i++)
	{
		if (i < ((rows/2)) + 2) //top part
		{
			for (int a = 1; a <= (rows / 2) - i + 1; a++)
			{
				cout << " ";
			}
			for (int a = 1; a <= i + i - 1; a++)
			{
				cout << "*";
			}
		}
		else //bottom part
		{
			for (int a = 1; a <= i - (rows / 2) - 1; a++)
			{
				cout << " ";
			}
			for (int i = numberOfStars; i > 0; i--)
			{
				if (not(i % 2 == 0))
				{
					numberOfStars = i - 1;
					break;
				}
			}
			for (int i = 1; i <= numberOfStars + 1; i++)
			{
				cout << "*";
			}
		}
		
		cout << endl;
	}


	//adds extra star at end for specific numbers as they don't print last line
	for (int i = 1; i <= rows / 2; i++)
	{
		if (not(rows % 9 == 0) && rows - ((int)(rows / 10) * 10) != 9) //check to make sure number is not factor of 9 or ends in 9
		{
			cout << " ";
		}	
	}

	if (not(rows % 9 == 0) && rows - ((int)(rows / 10) * 10) != 9) //check to make sure number is not factor of 9 or ends in 9
		cout << "*" << endl;

	return 0;
}