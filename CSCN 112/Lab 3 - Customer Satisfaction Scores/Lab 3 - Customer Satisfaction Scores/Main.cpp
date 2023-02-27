// CSCN 112-001 Spring 2023
// Lab 3: Customer Satisfaction Scores
// Carson Kramer

// Include statements (pre-processing directives)
#include <iostream> // cin & cout
#include <iomanip> // setw
#include <fstream> // file input
#include <string> // getline
#include "Employee.h" // Employee object

// Namespace
using namespace std;

// Global Variables - constants only

// Function Prototypes
// Print main menu
void printMenu();

// Switch/Open Employee File (pass by reference to alter temp employee)
void openFile(Employee&);

// Create new employee (pass by reference to alter temp employee)
void newEmployee(Employee&);

// Add Score to Current Employee (pass by reference to alter temp employee)
void addScoreAndErrorCheck(Employee&);

// Save Current Employee Info to File
void saveInfoToFile(Employee);

// Prompt user if they want to save
void continueWithoutSaving(Employee&);

// Main function
int main()
{
	cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 3" << endl;

	// Local variables
	Employee e;
	int case1 = 0;
	while (case1 != 6)
	{
		switch (case1)
		{
		case 1: // Open Employee File
			continueWithoutSaving(e);
			openFile(e);
			printMenu();
			break;
		case 2: // Create New Employee
			continueWithoutSaving(e);
			newEmployee(e);
			printMenu();
			break;
		case 3: // Add Score to Current Employee
			addScoreAndErrorCheck(e);
			printMenu();
			break;
		case 4: // Save Current Employee Info to File
			saveInfoToFile(e);
			printMenu();
			break;
		case 5: // Print Employee Info
			e.printEmployeeinfo();
			printMenu();
			break;
		default:
			printMenu();
		}
		cin >> case1;

		// Error check main menu input
		while (cin.fail() || case1 > 6 || case1 < 1)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Value must be between 1 and 6. Try again: ";
			cin >> case1;
		}
	}

	// Exit without saving (option 6: Quit)
	continueWithoutSaving(e);

	system("pause");
	return 0;
}

// Print main menu
void printMenu()
{
	cout << endl << "*****************************************************************" << endl;
	cout << setw(30) << right << "MENU" << endl;
	cout << "Current Employee:" << endl << endl;

	cout << "1 -\tSwitch/Open Employee File" << endl;
	cout << "2 -\tCreate New Employee" << endl;
	cout << "3 -\tAdd Score to Current Employee" << endl;
	cout << "4 -\tSave Current Employee Info to File" << endl;
	cout << "5 -\tPrint Employee Info" << endl;
	cout << "6 -\tQuit" << endl;
	cout << "*****************************************************************" << endl;
}

// Switch/Open Employee File
void openFile(Employee& e)
{
	ifstream infile; //instantiate a file object 
	string file, strTemp;
	float intTemp = 0;

	cin.clear(); // clears the error from the input stream
	cin.ignore(10000000, '\n'); // remove anything remaining in the stream

	// Input file name
	cout << "Please enter the name of the employee file (including extension): ";
	getline(cin, file, '\n');

	infile.open(file); //try to open the file 

	//An error check should go here to ensure that the file opened successfully. 
	if (!infile.fail())
	{
		// Reset temp employee to default state
		e.resetEmployee();

		// Go through first three lines of file to get name, city, and id
		for (int i = 0; i < 3; i++)
		{
			getline(infile, strTemp, '\n');

			// If file is empty check
			if (strTemp == "")
			{
				cout << "Empty file... Exiting program" << endl;
				exit(0);
			}
			switch (i)
			{
			case 0:
				e.setName(strTemp);
				break;
			case 1:
				e.setCity(strTemp);
				break;
			case 2:
				e.setID(strTemp);
				break;
			}
		}
	}
	else
	{
		cout << "File could not be located. Please try again." << endl;
	}

	/*The following is a loop to read in all of the values in the file. This loop
	executes for as long as the file object has not gone into the fail state
	(caused by reading past the end of the file or reading in a non-numeric
	value) and as long as the last number read in is positive.  Otherwise, the
	loopends, and the program ends.*/

	while (!infile.fail() && intTemp >= 0)
	{

		infile >> intTemp; //read in a value from the file 
		/*If the file object goes into the fail state, BUT the eof has not been
		reached, then the problem is due to reading a non-numeric value into
		a variable designed to hold a numeric value. */

		// If non-numeric value
		if (infile.fail() && !infile.eof())
		{
			cout << "A non-numeric value was found in the scores...Exiting program. " << endl;
			exit(0);
		}

		/*If the file object goes into the fail state, and the eof has been
		reached, the file object is in the fail state because the program has
		read past the end of the file.  This can occur if the file is empty.
		If the file is empty and you try to read in anything, the file object
		immediately goes into the fail state, and the eof function returns
		TRUE. */

		//If the number is negative... 
		else if (intTemp < 0)
		{
			cout << "A negative value was found in the scores...Exiting program. " << endl;
			exit(0);
		}


		//Otherwise, do something with the value read in, such as print it out. 

		else
		{
			e.addScore(intTemp);
		}

	}  //end of while loop  

	// Input function above accidentally inputs last value in file twice. Removed duplicate value
	if (!infile.fail())
	{
		e.removeScore(e.numScores() - 1);
	}
}

// Create new employee (pass by reference to alter temp employee)
void newEmployee(Employee& e)
{
	e.resetEmployee();
	string name, city, id;

	cin.clear(); // clears the error from the input stream
	cin.ignore(10000000, '\n'); // remove anything remaining in the stream

	// Name enter
	cout << "Please enter the employee's name: ";
	getline(cin, name, '\n');

	e.setName(name);

	// City enter
	cout << "Please enter the city that the employee will be working: ";
	getline(cin, city, '\n');

	e.setCity(city);

	// ID enter
	cout << "Please enter the employee's ID: ";
	getline(cin, id, '\n');

	e.setID(id);
}

// Add Score to Current Employee
void addScoreAndErrorCheck(Employee& e)
{
	// Check if an employee exists first
	if (e.getName() != "NULL")
	{
		// Local variable of type T that will temporarily store the user's input
		float inputValue;

		// Start by prompting the user for their input and bringing in the value
		cout << "Please enter the customer satisfaction score for this employee (1-5): " << endl;
		cin >> inputValue;

		while (cin.fail() || inputValue > 5 || inputValue < 0)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Invalid input. Value must be between 0 and 5" << endl;
			cin >> inputValue;
		}

		e.addScore(inputValue); // add error checked value entered to vector
	}
	else
	{
		cout << "Employee has not beed created or loaded in. Please create or load an employee first" << endl;
	}
}

// Save Current Employee Info to File
void saveInfoToFile(Employee e)
{
	// Create an ofstream object and open the file
	ofstream outfile(e.getName() + ".txt");

	if (outfile.is_open()) {
		// Write info to file
		outfile << e.getName() << std::endl;
		outfile << e.getCity() << std::endl;
		outfile << e.getID() << std::endl;
		outfile << e.printScores();

		// Close the file
		outfile.close();

		std::cout << "The file name is now set to " << e.getName() << ".txt" << std::endl;
	}
	else {
		std::cout << "Error: could not create file." << std::endl;
	}
}

// Prompt user if they want to save
void continueWithoutSaving(Employee& e)
{
	// Switch employee without saving
	if (e.getName() != "NULL")
	{
		// Get input
		char charTemp;
		cout << "You have an employee already loaded. Would you like to save? (Y / N)\t";
		cin >> charTemp;

		// Capitlize answer
		charTemp = toupper(charTemp);

		// Error check for 'Y' or 'N' selected
		while (cin.fail() || (charTemp != 'Y' && charTemp != 'N'))
		{
			cin.clear(); // clears the error from the input stream
			cin.ignore(10000000, '\n'); // remove anything remaining in the stream
			cout << "Invalid input. Needs to be either 'Y' for Yes or 'N' for No Please try again: ";
			cin >> charTemp;
		}

		// If answer is yes, save. Else, unsaved.
		if (charTemp == 'Y')
		{
			saveInfoToFile(e);
		}
		else
		{
			cout << "Previous employee is unsaved." << endl;
		}
	}
}