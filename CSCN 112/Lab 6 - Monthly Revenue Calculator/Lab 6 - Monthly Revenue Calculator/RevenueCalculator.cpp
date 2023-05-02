// CSCN 112-001 Spring 2023
// Lab 6: Monthly Revenue Calculator
// Carson Kramer

// Include statements (pre-processing directives)
#include <iostream> // cin & cout
#include "CompletedJob.h" // CompletedJob object
#include <iomanip> // setw
#include <string> // string
#include <fstream> // file input
#include <random> // random_device

// Namespace
using namespace std;

// Function Prototypes

// Prompt options for invoice
void optionsForInvoice(int&);

// Number of invoices prompt
void numOfInvoices(string&, int&);

// Option 1: rompt the user for each of the variables listed for the class
void jobManually(CompletedJob*);

// Option 2: Prompt the user for a file name and read the data from a file
void jobFromFile(CompletedJob*, bool&);

// Generate & print report
void generateReport(ostream&, CompletedJob**, int, string, float&);

// Print to file
void printToFile(CompletedJob**, int, string, float&);

// Print centered text (aesthetic function)
void centerAndPrint(ostream&, string, bool);

// Error check integers
void errorCheckInt(int&, int, int, bool);

// Error check floats
void errorCheckFloat(float&, int, int, bool);

// Error check strings
void errorCheckString(string&);

// Main function
int main()
{
	// Local variables
	int menuChoice, numOfJobs, jobCounter = 0;
	float finalRevenue;
	string month;

	// Reprint name for screenshots
	std::cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 6" << std::endl << std::endl;
	
	
	numOfInvoices(month, numOfJobs);
	CompletedJob** jobs = new CompletedJob *[numOfJobs];

	
	// Do while loop until exit prompt entered
	do
	{
		// Variable for checking if job was successfully added
		bool jobComplete = false;

		// Create dynamically stored CompletedJob object
		CompletedJob* j = new CompletedJob();

		// Prompt for manual or file input
		optionsForInvoice(menuChoice);
		
		// Act on manual or file input prompt
		switch (menuChoice)
		{
		case 1: // Manual input
			jobManually(j);

			// jobComplete does not need passed in function because 
			//  jobManually() function error checks to completion
			jobComplete = true;
			break;
		case 2: // File input
			jobFromFile(j, jobComplete);
			break;
		default:
			break;
		}
		
		jobs[jobCounter] = j;

		// Increment job counter
		if (jobComplete) // If the job was added, move to next job
		{
			jobCounter++;
		}
	} while (jobCounter < numOfJobs);
	
	// Generate report
	generateReport(cout, jobs, numOfJobs, month, finalRevenue);

	// Pause until user is done viewing report
	system("pause");

	// Prompt file name and print report to file
	printToFile(jobs, numOfJobs, month, finalRevenue);

	//  Deallocate memory of every element in array, then array itself
	for (int i = 0; i < numOfJobs; i++)
	{
		delete jobs[i];
	}
	delete[] jobs;

	system("pause");
	
	return 0;
}

// Prompt options for invoice
void optionsForInvoice(int& select)
{
	// Textbook chapter 13-6 C++11 Random Number Generator
	random_device rdevice{};
	default_random_engine num{ rdevice() };
	uniform_int_distribution<unsigned int> randomNum{ 1, 1000 };

	// Prompt manual or file
	cout << endl << "Please select from the following options for invoice # " << randomNum(num);
	cout << endl << endl << "1 - Enter a completed job manually" << endl << "2 - Enter a completed job from a file" << endl;

	// Error check job input
	errorCheckInt(select, 1, 2, true);
}

// Number of invoices prompt & menu selection
void numOfInvoices(string& month, int& jobs)
{
	// Prompt month
	cout << "Month: ";
	// Prompt
	getline(cin, month);

	// Prompt jobs
	cout << endl << "How many jobs were completed in " << month << "?" << endl;

	// Error check jobs
	errorCheckInt(jobs, 0, -1, false);
}

// Option 1: Prompt the user for each of the variables listed for the class
void jobManually(CompletedJob* j)
{
	cout << "Now entering a new invoice: " << endl;

	// Client name
	cout << endl << "Client name: ";
	string name;
	errorCheckString(name);
	j->setClientName(name);

	// Rooms painted
	cout << endl << "Number of Rooms Painted: ";
	int rooms;
	errorCheckInt(rooms, 0, -1, false); // Non-negative input & error check
	j->setRoomsPainted(rooms);

	// Labor charges
	cout << "Labor Charges: ";
	float labor;
	errorCheckFloat(labor, 0, -1, false); // Non-negative input & error check
	j->setLaborCharges(labor);

	// Number of paint cans
	cout << "Number of Paint Cans Needed: ";
	int paint;
	errorCheckInt(paint, 0, -1, false); // Non-negative input & error check
	j->setNumOfPaintCans(paint);

	// Product charges
	cout << "Product Charges: ";
	float product;
	errorCheckFloat(product, 0, -1, false); // Non-negative input & error check
	j->setProductCharges(product);

	// Number of miles
	cout << "Number of Miles: ";
	float miles;
	errorCheckFloat(miles, 0, -1, false); // Non-negative input & error check
	j->setMileage(miles);

	// Travel charges
	cout << "Travel Charges: ";
	float travel;
	errorCheckFloat(travel, 0, -1, false); // Non-negative input & error check
	j->setTravelCharges(travel);
}

// Option 2: Prompt the user for a file name and read the data from a file
void jobFromFile(CompletedJob* j, bool& jobComplete)
{
	// Variables
	ifstream infile; // Instantiate a file object 
	string file, strTemp;

	cin.clear(); // clears the error from the input stream
	cin.ignore(10000000, '\n'); // remove anything remaining in the stream

	// Input file name
	cout << "Please enter the name of the file (including extension): ";
	getline(cin, file);

	infile.open(file); // Try to open the file 

	// An error check should go here to ensure that the file opened successfully. 
	if (!infile.fail())
	{
		// Go through first 7 lines
		for (int i = 0; i < 7; i++)
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
			case 0: // Client Name
				j->setClientName(strTemp);
				break;
			case 1: // Rooms
				// Typecast string to integer https://cplusplus.com/reference/string/stoi/
				j->setRoomsPainted(stoi(strTemp));
				break;
			case 2: // Labor Charges
				// Typecast string to integer https://cplusplus.com/reference/string/stof/
				j->setLaborCharges(stof(strTemp));
				break;
			case 3: // Paint Cans
				j->setNumOfPaintCans(stoi(strTemp));
				break;
			case 4: // Product Charges
				j->setProductCharges(stof(strTemp));
				break;
			case 5: // Mileage
				j->setMileage(stof(strTemp));
				break;
			case 6: // Travel Charges
				j->setTravelCharges(stof(strTemp));
				break;
			default:
				break;
			}
		}
		// Mark job as complete
		jobComplete = true;
		cout << "File loaded successfully. " << endl;
	}
	else
	{
		cout << "File could not be located. Please try again." << endl;
	}
}

// Generate & print report
void generateReport(ostream& out, CompletedJob** jobs, int numOfJobs, string month, float& finalRevenue)
{
	out << "*********************************************" << endl;
	centerAndPrint(out, "WePaintHouses LLC", true);
	centerAndPrint(out, "Revenue for " + month, true);
	out << "*********************************************" << endl << endl;
	out << "WePaintHouses LLC" << endl;
	out << "1971 University Blvd" << endl;
	out << "Lynchburg, VA 24502" << endl;
	out << "4344554545" << endl;
	out << "wepainthousesllc.com" << endl << endl;
	out << "---------------------------------------------" << endl;

	// Initialize finalRevenue
	finalRevenue = 0;

	// Go through every CompletedJob in array and print contents
	for (int i = 0; i < numOfJobs; i++)
	{
		out << setprecision(2) << fixed;
		out << "Client Name: " << jobs[i]->getClientName() << endl;
		out << "\tRooms Painted: " << jobs[i]->getRoomsPainted() << endl;
		out << "\tLabor Charges: " << jobs[i]->getLaborCharges() << endl;
		out << "\tPaint Cans: " << jobs[i]->getNumOfPaintCans() << endl;
		out << "\tProduct Charges: " << jobs[i]->getProductCharges() << endl;
		out << "\tMileage: " << jobs[i]->getMileage() << endl;
		out << "\tTravel Charges: " << jobs[i]->getTravelCharges() << endl;
		out << setw(38) << left << "Total Cost: " << jobs[i]->totalRevenue() << endl << endl;

		// Add totalRevenue of individual job in list to temp total
		finalRevenue += jobs[i]->totalRevenue();
	}
	out << "---------------------------------------------" << endl;
	string tempStr = "Final Revenue for " + month;
	out << setw(36) << left << tempStr << "$" << finalRevenue << endl;
	out << "---------------------------------------------" << endl;
	
		/*

‘*********************************************
WePaintHouses LLC
1971 University Blvd
Lynchburg, VA 24502
4344554545
wepainthousesllc.com
---------------------------------------------
Client Name: Test
	Rooms Painted: 
	Labor Charges: 
	Paint Cans: 
	Product Charges: 
	Mileage: 
	Travel Charges: 100.00
Total Cost:					240.00

Client Name: Test2
	Rooms Painted: 
	Labor Charges: 
	Paint Cans: 
	Product Charges: 
	Mileage: 
	Travel Charges: 100.00
Total Cost:					240.00
---------------------------------------------
Final Revenue for January			$8789.18
---------------------------------------------

	*/
}

// Print to file
void printToFile(CompletedJob** jobs, int numOfJobs, string month, float& finalRevenue)
{
	// Clear screen
	system("CLS");

	// Prompt file name
	cout << "Now that all invoices have been loaded, what file would you like to print the final report to (with extension): ";
	string file;

	// File name
	getline(cin, file);

	// Create new file
	ofstream outfile(file);

	// Regenerate report with file as output stream instead of cout
	generateReport(outfile, jobs, numOfJobs, month, finalRevenue);

	// Clear screen
	system("CLS");

	// Print final screen
	cout << "WePaintHouses LLC" << endl << endl << "Final Revenue: $" << finalRevenue << endl;
}

// Print centered text (aesthetic function)
void centerAndPrint(ostream& out, string str, bool newLine)
{
	// Calculate the number of spaces needed to center the string
	int numSpaces = (45 - str.length()) / 2;

	// Output the string centered in the console
	out << setw(numSpaces + str.length()) << str;

	// Print endl if newLine bool is true
	if (newLine)
	{
		out << endl;
	}
}

// Error check integers
void errorCheckInt(int& num, int lower, int upper, bool inclusive)
{
	// Prompt
	cin >> num;
	if (inclusive) // Inclusive error check
	{
		if (lower != -1 && upper != -1) // If lower and upper limit exist
		{
			while (cin.fail() || num < lower || num > upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be between " << lower << " and " << upper << " (inclusive). Please try again: ";
				cin >> num;
			}
		}
		else if (lower == -1)  // If no lower limit
		{
			while (cin.fail() || num > upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be less than or equal to " << upper << ". Please try again: ";
				cin >> num;
			}
		}
		else if (upper == -1) // If no upper limit
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
		if (lower != -1 && upper != -1) // If lower and upper limit exist
		{
			while (cin.fail() || num <= lower || num >= upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be between " << lower << " and " << upper << " (exclusive). Please try again: ";
				cin >> num;
			}
		}
		else if (lower == -1)  // If no lower limit
		{
			while (cin.fail() || num >= upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be less than " << upper << ". Please try again: ";
				cin >> num;
			}
		}
		else if (upper == -1) // If no upper limit
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
void errorCheckFloat(float& num, int lower, int upper, bool inclusive)
{
	// Prompt
	cin >> num;
	if (inclusive) // Inclusive error check
	{
		if (lower != -1 && upper != -1) // If lower and upper limit exist
		{
			while (cin.fail() || num < lower || num > upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be between " << lower << " and " << upper << " (inclusive). Please try again: ";
				cin >> num;
			}
		}
		else if (lower == -1)  // If no lower limit
		{
			while (cin.fail() || num > upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be less than or equal to " << upper << ". Please try again: ";
				cin >> num;
			}
		}
		else if (upper == -1) // If no upper limit
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
		if (lower != -1 && upper != -1) // If lower and upper limit exist
		{
			while (cin.fail() || num <= lower || num >= upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be between " << lower << " and " << upper << " (exclusive). Please try again: ";
				cin >> num;
			}
		}
		else if (lower == -1)  // If no lower limit
		{
			while (cin.fail() || num >= upper)
			{
				cin.clear(); // clears the error from the input stream
				cin.ignore(10000000, '\n'); // remove anything remaining in the stream
				cout << "Invalid input. Value needs to be less than " << upper << ". Please try again: ";
				cin >> num;
			}
		}
		else if (upper == -1) // If no upper limit
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
void errorCheckString(string& str)
{
	cin.clear(); // clears the error from the input stream
	cin.ignore(10000000, '\n'); // remove anything remaining in the stream
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