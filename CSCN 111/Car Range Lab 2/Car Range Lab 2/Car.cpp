//car_range.cpp -- Write a program that prompts the capacity, in gallons, of an automobile fuel tank 
//	and the miles per gallon the automobile can be driven. The program outputs the number of miles 
//	the automobile can be driven without refueling.
//CSIS 111-03
//Public Domain


//Include statements
#include <iostream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "<Carson Kramer -- Lab 2>" << endl << endl;

	//Variable declarations
	int tankCapacity;
	int milesPerGallon;
	int range;

	//Program logic
	//	Prompt user for tank capacity and miles per gallon
	cout << "Tank capacity (in gallons): ";
	cin >> tankCapacity;
	cout << "Miles per gallon: ";
	cin >> milesPerGallon;

	//	Calculate the car's range and assign it to the variable range
	range = tankCapacity * milesPerGallon;

	//	Output the cars range as well as what the user entered.
	cout << "\nRange: " << range << " miles" << endl;

	//Closing program statements
	wait();
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
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}
