#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>

using namespace std;

int main()
{
	/*
	// Count controlled loop
	cout << "Count controlled loop example -- build a bar representing the temperature." << endl;
	int value;
	cout << "Enter a value between 1 and 30: ";
	cin >> value;
	while (value > 0)
	{
		cout << '*';
		value--;
	}
	cout << endl << endl;

	cout << "Random number guesing game -- sentinel controlled loop example." << endl;
	int guess, number;
	srand(time(NULL)); // initializes random number generator
	number = rand() % 10 + 1; // select random number between 1 and 10 inclusive
	cout << "Enter your guess (between 1 and 10 inclusive): ";
	cin >> guess;
	while (guess != number) // number represents the sentinel
	{
		cout << "Enter your guess (between 1 and 10 inclusive): ";
		cin >> guess;
	}
	cout << "number == " << number << " and you guessed " << guess << '.' << endl;


	// Flag controlled loop
	cout << "Flag controlled loop example -- out of range value." << endl;
	bool outOfRange = false;
	int input;
	while (!outOfRange)
	{
		cout << "Enter a value between 1 and 10: ";
		cin >> input;
		if (input < 1 || input > 10)
		{
			outOfRange = true;
		}
	}
	cout << "You entered a number that was out of range." << endl << endl;

	// eof controlled loop
	cout << "End of file controlled loop -- cin example." << endl;
	int sum = 0;
	int num;

	cout << "Enter a number (or any character to exit): ";
	cin >> num;

	while (cin)
	{
		sum += num;
		cout << "Enter a number (or any character to exit): ";
		cin >> num;
	}
	cout << "cin reached the end of the file." << endl << endl;


	// Random number guessing game -- sentinel and flag controlled example
	cout << "Random number guessing game -- sentinel and flag controlled loop example." << endl;
	int guess2, number2;
	srand(time(NULL));
	number2 = rand() % 10;
	bool isBroken = false;
	cout << "Enter your guess (a number between 0 and 9 inclusive): ";
	cin >> guess2;
	while (!isBroken && guess2 != number2)
	{
		cout << "Enter your guess: ";
		cin >> guess2;
		if (!cin)
		{
			isBroken = true;
		}
	}
	if (isBroken)
		cout << "You broke cin!!!";
	else
		cout << "You guessed wisely";
	cout << endl << endl;
	

	// Fibonacci For Loop
	long long nthFibonacci, fib, fibM1, fibM2;

	cout << "Enter the Fibonacci position you are interested in: ";
	cin >> nthFibonacci;

	for (long long i = 0; i <= nthFibonacci; i++)
	{
		if (i == 0)
			fib = fibM1 = fibM2 = 0;
		else if (i == 1)
			fib = fibM1 = 1;
		else
		{
			fib = fibM1 + fibM2;	// fib(n) = fib(n-1) + fin(n-2)

			// Prep fib's for next loop iterations
			fibM2 = fibM1;
			fibM1 = fib;
		}
	}

	cout << "Your Fibonacci number is " << fib << endl;

	// do-while loop deomstration
	cout << "do-while loop demo" << endl;
	int day = 0;
	do 
	{
		cout << "Enter a number between 1 and 7 inclusive: ";
		cin >> day;

		// fix cin if the user broke it
		if (!cin)
		{
			cin.clear();
			cin.ignore(256, '\n');
		}
	} while (day < 1 || day > 7);

	// switch in conjuction with previous while loop
	switch (day)
	{
	case 1: cout << "Monday"; break;
	case 2: cout << "Tuesday"; break;
	case 3: cout << "Wednesday"; break;
	case 4: cout << "Thursday"; break;
	case 5: cout << "Friday"; break;
	case 6: cout << "Saturday"; break;
	case 7: cout << "Sunday"; break;
	}
	cout << endl << endl;
	*/
	
	// break and continue
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			continue;
		else if (i > 20)
			break;
		cout << i << ' ';
	}

	// nested for-loops
	cout << "nested for-loop demo" << endl;
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= i; j++)
			cout << '*';
		cout << endl;
	}
	
	return 0;
}