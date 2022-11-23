/*
The cost to become a member of a fitness center is as follows:
	(a) the senior citizens monthly membership discount is 30%;
	(b) the discount for chosing to prepay the annual membership cost is 15%; and
	(c) if more than five personal training sessions are bought and paid for, the discount on each session is 20% (the discounts in a and b above do not apply to personal
	training).

Write a menu-driven program that determines the annual cost of a new membership. Your program must contain
	a function that displays the general information about the fitness center and its charges,
	a function to get all of the necessary information to determine the membership cost, and (use pass-by-reference parameters)
	a function to determine the membership cost.

Use appropriate parameters to pass information in and out of a function. (Do not use any global variables.)

Malik, Ch 6, Programming Exercise 25 (page 463)

*/
//CSCN 111-03
//Public Domain

//Include statements
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const float MONTHLY_MEMBERSHIP_RATE = 25.00;
const float PERSONAL_SESSION_RATE = 50.00;

//Function prototypes
void wait();
void info();
void getDiscounts(bool&, bool&, int&);
float cost(float, float);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Carson Kramer -- Lab 6" << endl << endl;

	//Variable declarations


	//Program logic
	info();

	cout << fixed << showpoint << setprecision(2);
	cout << "Your annual member ship cost is $" << cost(MONTHLY_MEMBERSHIP_RATE, PERSONAL_SESSION_RATE) << endl;

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

//Function Definitions

void info()
{
	cout << "***************************** SUPER FITNESS ****************************" << endl;
	cout << "Super Fitness is an old school fitness center dedicated to getting you \nin the best possible shape in a way that is healthy and fun. There \nare no gimicks here. Just solid training." << endl << endl;
	cout << "Our monthly rates are $25.00, but we do offer the following discounts: " << endl;
	cout << "\ta) Senior Citizents (65 and older):"<< right << setw(25) << "30%" << endl;
	cout << "\tb) Prepaid Annual Membership:" << right << setw(31) << "15%" << endl;
	cout << "\tc) Prepaid personal training sessions (5 or more):" << right << setw(10) << "20%" << endl << endl;
}

void getDiscounts(bool& senior, bool& annual, int& training)
{
	training = 0;
	int option = 0;
	bool finished = false;

	while(!finished)
	{
		cout << "Membership Options Menu:" << endl;
		if (!senior)
		{
			cout << "\tEnter '1' if you are a Senior Citizen (30% discount)" << endl;
		}
		if (!annual)
		{
			cout << "\tEnter '2' if you are interested prepaying for your annual membership (15% discount)" << endl;
		}
		if (training == 0)
		{
			cout << "\tEnter '3' if you are interested in Personal Training Sessions" << endl;
			cout << "\t\t($50.00 per session -- more than 5 sessions earns you a 20% reduction in Personal Training Rates)" << endl;
		}
		cout << "\tEnter '4' if you are done." << endl;
		cout << "Please enter the number of your option above: ";
		cin >> option;

		switch (option)
		{
		case 1:
			senior = true;
			break;
		case 2:
			annual = true;
			break;
		case 3:
			cout << "Enter the number of personal training sessions desired: ";
			cin >> training;
			break;
		case 4:
			finished = true;
			break;
		}

		if (senior && annual && training != 0)
		{
			finished = true;
		}
		cout << endl;
	}

}

float cost(float monthlyRate, float personalRate)
{
	bool senior = false, annual = false;
	int training = 0;
	float monthlyDiscount = 1, trainingDiscount = 1;

	getDiscounts(senior, annual, training);
	if (senior)
	{
		monthlyDiscount -= .3;
	}
	if (annual)
	{
		monthlyDiscount -= .15;
	}
	if (training > 5)
	{
		trainingDiscount -= .2;
	}
	
	return (monthlyRate * 12 * monthlyDiscount) + (personalRate * training * trainingDiscount);
}
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