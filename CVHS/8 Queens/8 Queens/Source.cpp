// Carson Kramer & Carter Kornfeld
// Period 5
// 1-8-20
// 8 Queens

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

bool validBoard();
bool openSpaces();
void fillQueens();
void resetBoard();
void printBoard();
void blockUnavailibleSpaces(int, int);

// Used in printing to convert 0 = "-", 1 = "*", and 2 = "Q"
char pieces[] = { '-', '*', 'Q' };

int board[8][8];

int main()
{
	// Set random seed
	srand(time(0));

	int count = 0;

	do
	{
		fillQueens();

		// Resets the random number seed after certain number of tries
		if (count > 30000)
		{
			count = 0;
			srand(time(0));
		}
		count += 1;

	} while (validBoard() == false);
	printBoard();
}

// Places the queens on the board. The first queen is placed randomly and the
// rest of the queens are randomly placed in spaces not in the path of previously places queens
void fillQueens()
{
	resetBoard();
	int count = 0, x, y;

	// Runs while 8 queens have not been places and there are still open spaces
	while (openSpaces() && count < 8)
	{
		// Keep picking random locations until one is found that is open
		do
		{
			x = rand() % 8;
			y = rand() % 8;
		} while (board[x][y] != 0);

		// Places queen in open slot
		board[x][y] = 2;
		
		// Blocks possible places on grid the queen could move
		blockUnavailibleSpaces(x, y);
		count++;
	}
}

// This function blocks all spaces on the board that the
// newly places queen at location (x, y) could cross
void blockUnavailibleSpaces(int x, int y)
{
	// Runs through every slot on board
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			// Skips the queen location as to not overwrite
			if (c != y && r != x)
			{
				// Blocks queen column
				board[r][y] = 1;

				// Blocks queen row
				board[x][c] = 1;

				// Blocks queen rightward diagonal
				if (r + c == x + y)
					board[r][c] = 1;

				// Blocks queen leftward diagonal
				if (r - c + 7 == x - y + 7)
					board[r][c] = 1;
			}

		}
	}
}

// Sets all board slots to zero
void resetBoard()
{
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			board[row][col] = 0;
		}
	}
}

// Prints the 8x8 Board
void printBoard()
{
	// Column numbering along top
	cout << "\t  ";

	for (int i = 1; i <= 8; i++)
	{
		cout << i << " ";
	}

	cout << endl;

	// Printing the grid
	for (int r = 0; r < 8; r++)
	{
		// Row numbering along side
		cout << "\t" << r + 1 << " ";

		// Prints array
		for (int c = 0; c < 8; c++)
		{
			cout << pieces[board[r][c]] << " ";
		}
		cout << endl;
	}
}

bool openSpaces()
{
	// Checks to see if there are any open spaces left on the board
	for (int r = 0; r < 8; r++)
		for (int c = 0; c < 8; c++)
			if (board[r][c] == 0)
				return true;

	return false;
}

// Checks the number of queens on the board
bool validBoard()
{
	int count = 0;
	for (int row = 0; row < 8; row++)
	{
		for (int col = 0; col < 8; col++)
		{
			// While going through every board slot, add 1 to a count if a queen is found
			if (board[row][col] == 2)
				count += 1;
		}
	}

	// Return true is there are 8 queens or false is there arn't
	return count == 8;
}