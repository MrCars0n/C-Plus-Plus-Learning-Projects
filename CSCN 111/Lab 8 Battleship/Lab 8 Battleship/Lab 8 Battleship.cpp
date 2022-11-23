/*
	Imagine we are using a two-dimensional array as the basis for creating the game battle- ship. In the game of battleship a ‘~’ character entry in the array represents ocean (i.e., not a ship), a ‘#’ character represents a place in the ocean where part of a ship is present, and a ‘H’ character represents a place in the ocean where part of a ship is present and has been hit by a torpedo. Thus, a ship with all ‘H’ characters means the ship has been sunk. Declare a two-dimensional char array that is 25 by 25 that represents the entire ocean and an If statement that prints “HIT” if a torpedo hits a ship given the coordinates X and Y. Write a C++ program that will read in a file representing a game board with 25 lines where each line has 25 characters corresponding to the description above.

	You should write a function called fire() that will take an X and Y coordinate and print “HIT” if a ship is hit and “MISS” if a ship is missed. If a ship is HIT you should update the array with an ‘H’ character to indicate the ship was hit. If a ship is hit that has already been hit at that location you should print “HIT AGAIN”. You should write a second function called fleetSunk that will determine if all the ships have been sunk. Your C++ program must then call these functions until all the ships have been sunk at which point the program should display “The fleet was destroyed!”.

	Your game loop logic (the main logic of a game) should like like the following:

	do {
		fire(x, y, gameBoard);
	} while(!fleetSunk(gameBoard));
*/
//CSCN 111-03
//Public Domain

//Include statements
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();
void fire(int, int, char[25][25]);
bool fleetSunk(char[25][25]);
void printBoard(char[25][25]);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Carson Kramer -- Lab 8" << endl << endl;

	//Variable declarations
	int x, y;
	char gameBoard[25][25];
	ifstream in;

	//Program logic
	in.open("input.dat");
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			in >> gameBoard[x][y];
		}
	}

	//printBoard(gameBoard);
	
	do {
		cout << "Enter row: ";
		cin >> x;
		cout << "Enter column: ";
		cin >> y;
		fire(x, y, gameBoard);
		//printBoard(gameBoard);
	} while (!fleetSunk(gameBoard));

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

//Function Definitions
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer 
	}
	cout << "Press the Enter key to continue ... ";
	cin.get();
}

// Print function for troubleshooting
void printBoard(char gameBoard[25][25])
{
	cout << "\t";
	for (int x = 0; x < 25; x++)
		cout << x % 10;
	cout << endl;
	for (int x = 0; x < 25; x++)
	{
		cout << x << "\t";
		for (int y = 0; y < 25; y++)
		{
			cout << gameBoard[x][y];
		}
		cout << endl;
	}
}

void fire(int x, int y, char gameBoard[25][25])
{
	if (gameBoard[x][y] == '~')
	{
		cout << "MISS" << endl;
	}
	else if (gameBoard[x][y] == '#')
	{
		cout << "HIT" << endl;
		gameBoard[x][y] = 'H';
	}
	else if (gameBoard[x][y] == 'H')
	{
		cout << "HIT AGAIN" << endl;
	}
	cout << endl;
}

bool fleetSunk(char gameBoard[25][25])
{
	for (int x = 0; x < 25; x++)
	{
		for (int y = 0; y < 25; y++)
		{
			if (gameBoard[x][y] == '#')
				return false;
		}
	}
	cout << "The fleet was destroyed!" << endl;
	return true;
}