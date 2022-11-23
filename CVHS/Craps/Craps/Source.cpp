/*
	Carson Kramer
	Period 5
	11-4-19
	Craps Simulation (Casino Always Winds in the End)

	Player throws pair of dice and adds total
		Roll a 7 or 11, win
		Roll a 2, 3, or 12, lose
		Roll anything else, reroll until...
			Roll a 7, lose
			Roll original number, win
		Keep rerolling until either happen
*/

#include<iostream>
#include<time.h>
#include<stdlib.h>

using namespace std;

int rollDice();

int main()
{
	srand(time(0));

	double winCount = 0, lossCount = 0, accuracy;

	// Enumerated Data Type = some cosntants can be matched with values
	//	Ex: months / days of week (Sunday = 0, Monday = 1, etc...)
	enum Status {REROLL, WON, LOST};
	Status gameStatus; // can hold three values (words) above

	cout << "Enter accuracy: ";
	cin >> accuracy;

	for (int n = 1; n <= accuracy; n++)
	{
		int myRoll = rollDice(), oldRoll;

		switch (myRoll)
		{
		case 7:
		case 11:
			gameStatus = WON;
			break;
		case 2:
		case 3:
		case 12:
			gameStatus = LOST;
			break;
		default:
			gameStatus = REROLL;
			oldRoll = myRoll;
			//cout << "You need a " << oldRoll << endl;
			break;
		}

		while (gameStatus == REROLL)
		{
			myRoll = rollDice();

			if (myRoll == oldRoll)
				gameStatus = WON;
			else if (myRoll == 7)
				gameStatus = LOST;
		}

		if (gameStatus == WON)
		{
			//cout << "You Win!" << endl;
			winCount++;
		}
		else
		{
			//cout << "You Lose!" << endl;
			lossCount++;
		}
	}

	cout << "Win: " << (winCount * 100) / (lossCount + winCount) << "%" << endl;
	cout << "Loss: " << (lossCount * 100) / (lossCount + winCount) << "%" << endl;

	return 0;
}

int rollDice()
{
	int d1 = rand() % 6 + 1, d2 = rand() % 6 + 1;

	//cout << d1 << " + " << d2 << " = " << d1 + d2 << endl;

	return d1 + d2;
}