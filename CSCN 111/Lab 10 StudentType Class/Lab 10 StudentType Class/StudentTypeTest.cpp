//StudentTypeTest.cpp -- driver used to test StudentType implementation.
//CSCN 111-03
//Public Domain


//Include statements
#include <iostream>
#include <string>
#include "StudentType.h"

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Carson Kramer -- Lab 10" << endl << endl;

	//Variable declarations
	StudentType st;	//declare your StudentType variable
	StudentType carson("Carson", "Kramer", 95, 'A');

	st.setFirstName("John");
	st.setLastName("Doe");
	st.setTestScore(85);
	st.setGrade('B');

	//Program logic -- set your StudentType instance variables using your set functions
	// then display your student data using you StudentType get functions.

	std::cout << "Student Name: " << st.getFirstName() << " " << st.getLastName() << std::endl
		<< "Test Score: " << st.getTestScore() << "%" << std::endl
		<< "Grade: " << st.getGrade() << std::endl << std::endl;

	std::cout << "Student Name: " << carson.getFirstName() << " " << carson.getLastName() << std::endl
		<< "Test Score: " << carson.getTestScore() << "%" << std::endl
		<< "Grade: " << carson.getGrade() << std::endl << std::endl;

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