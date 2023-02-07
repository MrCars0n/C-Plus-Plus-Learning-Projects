// In-Class Exercise:  Participation Lab 1
// Professor M 
// CSCN 112 Spring 2023

#include <iostream> // used for cout/cin input and output streams
#include <string> // necessary to use getline
#include "basketballGame.h"

using namespace std;

// Brings in opponent score, error check, and returns
int getAndCheckOppScore();

// This function is void function that passes in parameter by value, brings value value from user, error checks
void getAndCheckOurScore(int& oScore);

int main()
{
	// Let's say I want to store the information for a basketball game
	// Local variables 
	basketballGame game1("LU", "BYU");
	/*
	cout << "What is the name of our team? " << endl;
	string temp_Name;
	getline(cin, temp_Name);

	game1.setTeamName(temp_Name);

	cout << "What is the opponent you are currently facing? " << endl;
	getline(cin, temp_Name);

	game1.setOpponentName(temp_Name);
	*/

	game1.setOppScore(getAndCheckOppScore());

	int temp_score;
	getAndCheckOurScore(temp_score);

	game1.setOurScore(temp_Score);

	game1.print();

	basketballGame game2("LU", "VT", 23, 101);
	cout << endl;
	game2.print();

	system("pause");
	return 0;
}

// Brings in opponent score, error check, and returns
int getAndCheckOppScore(int oScore)
{
	cout << "At the end of the game, what is the opponent's score? " << endl;
	int temp_Score;
	cin >> temp_Score;

	while (cin.fail() || temp_Score < 0 || temp_Score > 100)
	{
		cin.clear(); // clear out the error state from the cin stream
		cin.ignore(10000, '\n'); // ignore anything else in the input stream
		cout << "Error retrieving score.  Please enter the opponent's score for the game : " << endl;
		cin >> temp_Score;
	}

	return temp_Score;
}

// This function is void function that passes in parameter by value, brings value value from user, error checks
void getAndCheckOurScore(int& oScore)
{
	cout << "At the end of the game, what is our current team's score? " << endl;
	cin >> oScore;
	while (cin.fail() || oScore < 0 || oScore > 100)
	{
		cin.clear();  // clear out the error state from the cin stream
		cin.ignore(1000, '\n'); // ignore anything else in the input stream
		cout << "Error retrieving score.  Please enter our team's score for the game: " << endl;
		cin >> oScore;
	}
}