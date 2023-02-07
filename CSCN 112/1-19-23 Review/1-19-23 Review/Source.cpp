// CSCN 112-001 Spring 2023
// Review In-Class Exercise

/*
	ALGORITHM

	Step 1: Create Variables
			- Labs: Array of 8 - floats
			- MindTap: Array of 15 - floats
			- Exam 1 - int
			- Exam 2 - int
			- Final Exam - int
			- Name of the course - string

	Step 2: Create menu with options
			0 - Load data from a file
			1 - Add a lab grade
			2 - Add a MinTap Grade
			3 - Add an exam grade
				a - Add Exam 1
				b - Add Exam 2
				c - Add Exam 3
			4 - Print to the console
			5 - Print to a file

			- Menu should continue looping until a print option is selected

	Step 3: Create a function to update data
			Option A: Pass in all variables by reference to change the given option
			void updateDataByReferences(string &cName, float labGrade[], float mindTapGrades[], int &e1, int &e2, int &final);

			Option B: Create multiple value-returning functions for each type of data
				I'm going to need functions for each type of data:	string, float, int

				string updateClassName();
				float updateFloatData();
				int updateIntData();

	Step 4: Create a function to print data
			VOID printClassDataToConsole(string cName, float labGades[], float mindTapGrades[], int e1, int e2, int final);
			This function should neatly print the name of the class, each grade, total grade, and letter grade to the console

	Step 5: Create a function to print data to a file
			VOID printClassDataToFile(string cName, float labGades[], float mindTapGrades[], int e1, int e2, int final);
			This function should neatly print the name of the class, each grade, total grade, and letter grade to a given input file
*/

// Include statements (pre-processing directives)
#include<iostream> // cin & cout

// Namespace
using namespace std;

// Global Variables - constants only

// Function Prototypes
// Int function that prints the menu, brings in an option from the user, error checks it, and returns it to main
int mainMenu();

// Option A : Pass in all variables by reference to change the given option
void updateDataByReferences(int option, string& cName, float labGrade[], float mindTapGrades[], int& e1, int& e2, int& final);


int main()
{
	cout << "CSCN 112 - Spring 2023 - In-Class Review" << endl << endl;

	// Local Variables
	float labs[8] = { 0 };
	float MindTap[15] = { 0 };
	int exam1Grade = 0;
	int exam2Grade = 0;
	int finalExamGrade = 0;
	string cName = "";
	int menuOptionChosen = 0;

	// Program Logic
	do
	{
		menuOptionChosen = mainMenu(); // Calls the function to make menu choice
		system("CLS");

		// Using switch statement to handle each valid option
		switch (menuOptionChosen)
		{
		case 0:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			cout << "ERROR ... NOT SURE HOW YOU GOT HERE" << endl;
		}
	} while (menuOptionChosen != 6); // Continues looping until the option of six is chosen

	system("pause");
	return 0;
}

// Function definitions
// Int function that prints the menu, brings in an option from the user, error checks it, and returns it to main
int mainMenu()
{
	cout << "\t0 - Load data from a file" << endl;
	cout << "\t1 - Add a lab grade" << endl;
	cout << "\t2 - Add a MinTap Grade" << endl;
	cout << "\t3 - Add an exam grade" << endl;
	//cout << "   a - Add Exam 1" << endl;
	//cout << "   b - Add Exam 2" << endl;
	//cout << "   c - Add Exam 3" << endl;
	cout << "\t4 - Print to the console" << endl;
	cout << "\t5 - Print to a file" << endl;
	cout << "\t6 - Quit" << endl;

	// Bring in an option from the user
	int optionChosen = 9;

	cout << "\n\tPlease enter your choice: ";
	cin >> optionChosen;

	// Error check
	while (cin.fail() || optionChosen < 0 || optionChosen > 6)
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be an option from the menu. Please try again: ";
		cin >> optionChosen;
	}

	return optionChosen;
}

// Option A : Pass in all variables by reference to change the given option
void updateDataByReferences(int option, string& cName, float labGrade[], float mindTapGrades[], int& e1, int& e2, int& final)
{
	// Have a way to determine which value should be changed - passed in the option chosen by the user

	// Prompt the user for the new value of that item
	switch (option)
	{
	case 1:
	case 2:
		float value = 0;
		cout << "Please enter the value you would like to add: ";
		cin >> value;
		break;
	case 3:
		int value2 = 0;
		cout << "Please enter the scoure you would like to add: ";
		cin >> value2;
		break;
	default:
	}

	// Error check that value to make sure it is valid

	// Change the value of the variables passed in to that newly entered value
}