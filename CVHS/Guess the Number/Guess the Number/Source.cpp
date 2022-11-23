/*
	Carson Kramer
	11-1-19
	Period 5
	Guess the Number
		Computer picsk and random 1-100. You enter guesses until you get it correct.
		The computer will tell you higher or lower after each guess.
		When you are finished, print a count of the number of guesses.
*/

#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
	srand(time(0));

	int guess, count = 0, low = 1, high = 1000000000, num = rand() % high + low;

	do
	{
		//cout << "Guess between 1-100: ";
		//cin >> guess;

		guess = (low + high) / 2;
		cout << "My guess is " << guess << endl;

		count++;

		if (guess < num)
		{
			//cout << "Your guess is too low" << endl << endl;
			low = guess + 1;
		}
		else if (guess > num)
		{
			//cout << "Your guess is too high" << endl << endl;;
			high = guess - 1;
		}

	} while (guess != num);

	cout << "I guessed it! My number was " << num << endl << "My number of tries was " << count << endl;

	return 0;
}