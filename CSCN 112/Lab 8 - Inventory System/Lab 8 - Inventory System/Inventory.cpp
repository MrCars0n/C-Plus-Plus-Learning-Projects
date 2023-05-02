// CSCN 112-001 Spring 2023
// Lab 8: Inventory System
// Carson Kramer

// Include statements (pre-processing directives)
#include <iostream> // cout
#include <random> // Gloss level percentage
#include <fstream> // infile
#include <iomanip> // setw
#include "Paint.h" // Default paint objects
#include "Flat.h" // Flat paint objects
#include "Eggshell.h" // Eggshell paint objects
#include "Satin.h" // Satin paint objects
#include "SemiGloss.h" // Semi-Gloss paint objects
#include "HighGloss.h" // High-Gloss paint objects

// Namespace
using namespace std;

// Function Prototypes

// Paint selection menu
void paintSelectionMenu(int&, bool, int);

// Add color
void addColor(int, Paint*[]);

// Load inventory from file
void loadFromFile(Paint*[]);

// Second menu
void secondMenu(int&);

// (1) Adjust Inventory
void adjustInventory(Paint*[]);

// (2) View Help for Selection
void viewHelp(Paint*[]);

// (3) View Current Inventory
void viewCurrentInv(Paint*[]);

// (4) Print Inventory to a File
void printInvToFile(Paint*[]);

// (5) Quit
void quit(Paint*[]);

// Error check integers
void errorCheckInt(int&, int, int, bool, int);

// Error check floats
void errorCheckFloat(float&, int, int, bool, int);

// Error check strings
void errorCheckString(string&, bool);

// Main function
int main()
{
	// Local variables
	int menuOption;

	// Reprint name for screenshots
	cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 8" << endl << endl;

	// Create paints array
	Paint * paints[7];

	// Prompt paint selection and menu printing
	paintSelectionMenu(menuOption, true, 1);


	if (menuOption == 6)
	{
		// Load colors from file
		loadFromFile(paints);
	}
	else
	{
		// Add colors manually
		addColor(menuOption, paints);
	}

	do
	{
		// Prompt second menu and option selection
		secondMenu(menuOption);

		switch (menuOption)
		{
		case 1: // Adjust Inventory
			adjustInventory(paints);
			break;
		case 2: // View Help for Selection
			viewHelp(paints);
			break;
		case 3: // View Current Inventory
			viewCurrentInv(paints);
			break;
		case 4: // Print Inventory to a File
			printInvToFile(paints);
			break;
		case 5: // Quit
			quit(paints);
			break;
		default:
			break;
		}
	} while (menuOption != 5); // While quit option is not selected

	// Deallocate Paint objects
	for (int i = 0; i < 7; i++) 
	{
		delete paints[i];
		paints[i] = NULL;
	}

	system("pause");

	return 0;
}

// Paint selection menu
void paintSelectionMenu(int& menuOption, bool printToFile, int num)
{
	cout << "Please choose from the following options for object #" << num << ": " << endl << endl;
	cout << "\t(1) Flat Paint" << endl;
	cout << "\t(2) Eggshell Paint" << endl;
	cout << "\t(3) Satin Paint" << endl;
	cout << "\t(4) Semi - Gloss Paint" << endl;
	cout << "\t(5) High - Gloss Paint" << endl;

	if (printToFile)
	{
		// If printToFile is true
		//		DESIGN DECISION - Only allow the loading of colors from a file on the initial prompt
		//		If a manual color has already been added, you cannot cut off the manual input process
		cout << "\t(6) Load Inventory from a File" << endl;

		// Input menu option + error check
		errorCheckInt(menuOption, 1, 6, true, -1);
	}
	else
	{
		// Input menu option + error check
		errorCheckInt(menuOption, 1, 5, true, -1);
	}
}

// Add color
void addColor(int type, Paint * p[])
{
	/*
	Gloss Percentage Ranges:
		1. Flat: 0.1 – 5.0 percent
		2. Eggshell: 10.5 – 25 percent
		3. Satin: 25.5 – 35 percent
		4. Semi-Gloss: 35.5 – 70 percent
		5. High-Gloss: 85 – 95 percent
	*/
	float bottom[] = { 0.1, 10.5, 25.5, 35.5, 85 }; // Bottom part of ranges percentages
	float top[] = { 5, 25, 35, 70, 95 }; // Top part of ranges percentages

	//cout << endl << "Please select from the following options for invoice # " << randomNum(num);
	for (int i = 0; i < 7; i++)
	{
		string color;
		float numOfCans;

		// Prompt color
		cout << "Please enter the color: ";
		errorCheckString(color, true);

		// Capitalize color
		string capitalizedStr = "";
		for (int i = 0; i < color.length(); i++) {
			capitalizedStr += toupper(color[i]);
		}
		color = capitalizedStr;

		// Prompt number of cans
		cout << endl << "Please enter the number of cans to add to inventory: ";
		errorCheckFloat(numOfCans, 0, -1, false, -1);

		// Textbook chapter 13-6 C++11 Random Number Generator
		random_device rdevice{};
		default_random_engine num{ rdevice() };
		uniform_real_distribution<float> randomNum(bottom[type - 1], top[type - 1]);

		switch (type)
		{
		case 1: // (1) Flat Paint
			p[i] = new Flat(color, randomNum(num));
			p[i]->setNumOfCans(numOfCans);
			break;
		case 2: // (2) Eggshell Paint
			p[i] = new Eggshell(color, randomNum(num));
			p[i]->setNumOfCans(numOfCans);
			break;
		case 3: // (3) Satin Paint
			p[i] = new Satin(color, randomNum(num));
			p[i]->setNumOfCans(numOfCans);
			break;
		case 4: // (4) Semi-Gloss Paint
			p[i] = new SemiGloss(color, randomNum(num));
			p[i]->setNumOfCans(numOfCans);
			break;
		case 5: // (5) High-Gloss Paint
			p[i] = new HighGloss(color, randomNum(num));
			p[i]->setNumOfCans(numOfCans);
			break;
		case 6: // (6) Load Inventory from a File

			break;
		default:
			break;
		}

		// If not on last iteration, reprompt paint seleciton
		if (i != 6)
		{
			system("pause");
			system("CLS");
			paintSelectionMenu(type, false, i + 2);
		}
	}
}

// Load inventory from file
void loadFromFile(Paint * p[])
{
	ifstream infile; //instantiate a file object 
	string file, color;
	float numOfCans, gloss;

	cin.clear(); // clears the error from the input stream
	cin.ignore(10000000, '\n'); // remove anything remaining in the stream

	// Input file name
	cout << "Please enter the name of the file (including extension): ";
	getline(cin, file, '\n');

	infile.open(file); //try to open the file 

	// An error check should go here to ensure that the file opened successfully
	if (!infile.fail())
	{
		for (int i = 0; i < 7; i++) 
		{
			infile >> color;
			infile >> numOfCans;
			infile >> gloss;

			// Determine the class object based on the inputted gloss percentage
			if (gloss >= 85) // High-Gloss: 85 – 95 percent
			{
				p[i] = new HighGloss(color, gloss);
				p[i]->setNumOfCans(numOfCans);
			}
			else if (gloss >= 35.5) // Semi-Gloss: 35.5 – 70 percent
			{
				p[i] = new SemiGloss(color, gloss);
				p[i]->setNumOfCans(numOfCans);
			}
			else if (gloss >= 25.5) // Satin: 25.5 – 35 percent
			{
				p[i] = new Satin(color, gloss);
				p[i]->setNumOfCans(numOfCans);
			}
			else if (gloss >= 10.5) // Eggshell: 10.5 – 25 percent
			{
				p[i] = new Eggshell(color, gloss);
				p[i]->setNumOfCans(numOfCans);
			}
			else // Flat: 0.1 – 5.0 percent
			{
				p[i] = new Flat(color, gloss);
				p[i]->setNumOfCans(numOfCans);
			}

			// Skip the empty line
			string line;
			getline(infile, line);
		}
	}
	else
	{
		cout << "File could not be located. Please try again." << endl << endl;
		loadFromFile(p);
	}
}

// Second menu
void secondMenu(int& menuOption)
{
	system("CLS");
	cout << endl << "Please choose from the following options: " << endl << endl;
	cout << "\t(1) Adjust Inventory" << endl;
	cout << "\t(2) View Help for Selection" << endl;
	cout << "\t(3) View Current Inventory" << endl;
	cout << "\t(4) Print Inventory to a File" << endl;
	cout << "\t(5) Quit" << endl;

	// Input menu option + error check
	errorCheckInt(menuOption, 1, 5, true, -1);
}

// (1) Adjust Inventory
void adjustInventory(Paint * p[])
{
	cout << "Which object (1-7) do you wish to adjust the inventory of?" << endl;
	cout << setw(10) << left << "#:" << setw(20) << "Paint Color" << setw(20) << "Number of Cans" << "Gloss Level(%)" << endl;

	// Print every paint object in array
	for (int i = 0; i < 7; i++)
	{
		cout << setw(10) << left << (i + 1) << setw(20) << p[i]->getColor() << setw(20) << p[i]->getNumOfCans() << p[i]->getGlossLevel() << endl;
	}

	cout << endl;

	// Prompt option to change
	int option;
	cout << "I want to adjust object #";
	errorCheckInt(option, 1, 7, true, -1);

	// Prompt number of cans
	float cans;
	cout << endl << "How many cans should be in inventory for this paint: ";
	errorCheckFloat(cans, 0, -1, false, -1);

	// Change number of cans in selected option
	p[option - 1]->setNumOfCans(cans);
}

// (2) View Help for Selection
void viewHelp(Paint * p[])
{
	cout << "Which object (1-7) do you wish to view help for?" << endl;
	cout << setw(10) << left << "#:" << setw(20) << "Paint Color" << setw(20) << "Number of Cans" << "Gloss Level(%)" << endl;

	// Print every paint object in array
	for (int i = 0; i < 7; i++)
	{
		cout << setw(10) << left << (i + 1) << setw(20) << p[i]->getColor() << setw(20) << p[i]->getNumOfCans() << p[i]->getGlossLevel() << endl;
	}

	cout << endl;

	// Prompt option to change
	int option;
	cout << "I want help for object #";
	errorCheckInt(option, 1, 7, true, -1);

	system("CLS");

	// View help for selected object
	p[option - 1]->help();
	system("pause");

	cout << endl;
}

// (3) View Current Inventory
void viewCurrentInv(Paint * p[])
{
	cout << "Now printing current inventory..." << endl << endl;
	cout << setw(10) << left << "#:" << setw(20) << "Paint Color" << setw(20) << "Number of Cans" << "Gloss Level(%)" << endl;
	
	// Print every paint object in array
	for (int i = 0; i < 7; i++)
	{
		cout << setw(10) << left << (i + 1) << setw(20) << p[i]->getColor() << setw(20) << p[i]->getNumOfCans() << p[i]->getGlossLevel() << endl;
	}

	cout << endl;
	system("pause");
}

// (4) Print Inventory to a File
void printInvToFile(Paint * p[])
{
	string fileName;
	cout << "Please enter the name of the file you would like to print inventory to (with extension): ";
	errorCheckString(fileName, true);

	// Create output file object
	ofstream outfile(fileName);

	// Loop through paint array to print to file
	for (int i = 0; i < 7; i++)
	{
		outfile << p[i]->getColor() << endl;
		outfile << p[i]->getNumOfCans() << endl;
		outfile << p[i]->getGlossLevel();

		// If not on last line, add line break
		if (i != 6)
		{
			outfile << endl << endl;
		}
	}
}

// (5) Quit
void quit(Paint * p[])
{
	cout << setw(10) << left << "#:" << setw(20) << "Paint Color" << setw(20) << "Number of Cans" << "Gloss Level(%)" << endl;

	// Print every paint object in array
	for (int i = 0; i < 7; i++)
	{
		cout << setw(10) << left << (i + 1) << setw(20) << p[i]->getColor() << setw(20) << p[i]->getNumOfCans() << p[i]->getGlossLevel() << endl;
		p[i]->help();
		cout << endl << endl;
	}
}

// Error check integers
void errorCheckInt(int& num, int lower, int upper, bool inclusive, int limitOperator)
{
	// Prompt
	cin >> num;
	if (inclusive) // Inclusive error check
	{
		if (lower != limitOperator && upper != limitOperator) // If lower and upper limit exist
		{
			while (cin.fail() || num < lower || num > upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be between " << lower << " and " << upper << " (inclusive). Please try again: ";
				cin >> num;
			}
		}
		else if (lower == limitOperator)  // If no lower limit
		{
			while (cin.fail() || num > upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be less than or equal to " << upper << ". Please try again: ";
				cin >> num;
			}
		}
		else if (upper == limitOperator) // If no upper limit
		{
			while (cin.fail() || num < lower)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be greater than or equal to " << lower << ". Please try again: ";
				cin >> num;
			}
		}
	}
	else // Exclusive error check
	{
		if (lower != limitOperator && upper != limitOperator) // If lower and upper limit exist
		{
			while (cin.fail() || num <= lower || num >= upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be between " << lower << " and " << upper << " (exclusive). Please try again: ";
				cin >> num;
			}
		}
		else if (lower == limitOperator)  // If no lower limit
		{
			while (cin.fail() || num >= upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be less than " << upper << ". Please try again: ";
				cin >> num;
			}
		}
		else if (upper == limitOperator) // If no upper limit
		{
			while (cin.fail() || num <= lower)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be greater than " << lower << ". Please try again: ";
				cin >> num;
			}
		}
	}
	cout << endl;
}

// Error check floats (copy of errorCheckInt but with float input)
void errorCheckFloat(float& num, int lower, int upper, bool inclusive, int limitOperator)
{
	// Prompt
	cin >> num;
	if (inclusive) // Inclusive error check
	{
		if (lower != limitOperator && upper != limitOperator) // If lower and upper limit exist
		{
			while (cin.fail() || num < lower || num > upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be between " << lower << " and " << upper << " (inclusive). Please try again: ";
				cin >> num;
			}
		}
		else if (lower == limitOperator)  // If no lower limit
		{
			while (cin.fail() || num > upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be less than or equal to " << upper << ". Please try again: ";
				cin >> num;
			}
		}
		else if (upper == limitOperator) // If no upper limit
		{
			while (cin.fail() || num < lower)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be greater than or equal to " << lower << ". Please try again: ";
				cin >> num;
			}
		}
	}
	else // Exclusive error check
	{
		if (lower != limitOperator && upper != limitOperator) // If lower and upper limit exist
		{
			while (cin.fail() || num <= lower || num >= upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be between " << lower << " and " << upper << " (exclusive). Please try again: ";
				cin >> num;
			}
		}
		else if (lower == limitOperator)  // If no lower limit
		{
			while (cin.fail() || num >= upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be less than " << upper << ". Please try again: ";
				cin >> num;
			}
		}
		else if (upper == limitOperator) // If no upper limit
		{
			while (cin.fail() || num <= lower)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be greater than " << lower << ". Please try again: ";
				cin >> num;
			}
		}
	}
	cout << endl;
}

// Error check strings
void errorCheckString(string& str, bool clear)
{
	// Initial clear
	if (clear)
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
	}

	// Prompt
	getline(cin, str);

	// Error check
	while (cin.fail())
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Enter a valid string. Please try again: ";
		getline(cin, str);
	}
}