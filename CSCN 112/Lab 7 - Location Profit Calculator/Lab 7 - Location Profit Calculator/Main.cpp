// CSCN 112-001 Spring 2023
// Lab 7: Location Profit Calculator
// Carson Kramer

// Include statements (pre-processing directives)
#include <iostream>
#include <iomanip> // setw
#include "Department.h"

// Namespace
using namespace std;

// Function Prototypes
// Error check characters
void errorCheckChar(char&, char[]);

// Initalize department at start of program
void departmentInit(Department&);

// Menu
void menu(char&);

// M -- Add Manager
void addManager(Department&);

// E -- Add Employee
void addEmployee(Department&);

// R -- Remove Employee
void removeEmployee(Department&);

// P -- Print Final Profit
//  Ends the loop execution and prints off the final profit summary
void printFinalProfit(Department&);

// Error check integers
void errorCheckInt(int&, int, int, bool, int);

// Error check floats
void errorCheckFloat(float&, int, int, bool, int);

// Error check strings
void errorCheckString(string&, bool);

// Tokenize date
void tokenizeDate(char*, int&, int&, int&);

// Print centered text (aesthetic function)
void centerAndPrint(ostream&, string, bool);

// Main function
int main()
{
	// Local variables
	char menuOption;

	// Reprint name for screenshots
	cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 7" << endl << endl;

	// Create the department object
	Department d;

	//  Prompt user for department name, capacity, and current total cost of product purchases
	departmentInit(d);

	// Display menu of options to user(error check options + automatic capitalization)
	do
	{
		menu(menuOption);

		switch (menuOption)
		{
		case 'M': // M -- Add Manager
			// Check manager does not exist
			if (d.getManager().getID() == 0)
			{
				// Prompt user for info to create new managerand add to data member
				addManager(d);
			}
			else // Manager does exist
			{
				cout << "Manager already exists: " << d.getManager().getFirstName() << " " << d.getManager().getLastName() << endl;
			}
			break;
		case 'E': // E -- Add Employee
			// Check capacity has not been reached
			if (d.getCapacity() < 50)
			{
				// Prompt user for info to create new employee and add to vector
				addEmployee(d);
			}
			else // Department is at capacity
			{
				cout << "Department is at capacity! No further employees can be added at this time" << endl;
			}
			break;
		case 'R': // R -- Remove Employee
			// Check if at least 1 employee exists
			if (d.numOfEmployees() > 0)
			{
				// Prompt Employee ID(index of employee in vector) and remove from vector
				removeEmployee(d);
			}
			else // No employees exist
			{
				cout << "No employees exist to remove" << endl;
			}
			break;
		case 'L': // L -- List Dept.Info(print the following info)
			// Department Name, Capacity, and Cost of Products
			// Manager Information(if no manager has been assigned, the appropriate warning message should be included)
			// All information for each employee in the department sorted by last name(if no employees have been assigned, the appropriate warning message should be included)
			cout << d << endl;
			system("pause");
			system("CLS");
			break;
		case 'P': // P -- Print Final Profit
			// Ends the loop execution and prints off the final profit summary
			printFinalProfit(d);
			break;
		default:
			break;
		}

		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
	} while (menuOption != 'P');

	system("pause");

	return 0;
}

// Initalize department at start of program
void departmentInit(Department& d)
{
	std::string name;
	int capacity;
	float productCost;

	// Department name, error check & assign
	cout << "Please enter the department name: ";
	errorCheckString(name, false);
	d.setName(name);

	// Product costs, error check & assign
	cout << endl << "Please enter the dollar amount of products this department has used: $";
	errorCheckFloat(productCost, 0, -1, true, -1);
	d.setProductCost(productCost);

	// Capacity, error check & assign
	cout << "Please enter the total capacity (max number of employees) for the given department. Department cannot be > 50 employees" << endl;
	errorCheckInt(capacity, 1, 50, true, -1);
	d.setCapacity(capacity);

	cin.clear(); // clears the error from the input stream
	cin.ignore(10000000, '\n'); // remove anything remaining in the stream

	system("CLS");
}

// Menu
void menu(char& c)
{
	// Character array of possible values
	char parameters[] = { 'M', 'E', 'R', 'L', 'P', '\0' };

	// Print menu
	cout << "\tMain Menu" << endl;
	cout << "M -- Add Manager" << endl;
	cout << "E -- Add Employee" << endl;
	cout << "R -- Remove Employee" << endl;
	cout << "L -- List Dept. Info" << endl;
	cout << "P -- Print Final Profit" << endl;

	// Error check inputted character
	errorCheckChar(c, parameters);

	system("CLS");
}

// M -- Add Manager
void addManager(Department& dep)
{
	Manager man;
	string fName, lName, title;
	int ID, m, d, y;
	Date bDate, dateHired, promotionDate;
	float salary;
	char charDate[20];

	// Creating a New Manager
	cout << "Creating a New Manager" << endl;

	// First name
	cout << endl << "First Name: ";
	errorCheckString(fName, false);
	man.setFirstName(fName);

	// Last name
	cout << endl << "Last Name: ";
	errorCheckString(lName, false);
	man.setLastName(lName);

	// Birthday (mm/dd/yyyy)
	cout << endl << "Birthday (mm/dd/yyyy): ";
	cin >> charDate; // Input date
	tokenizeDate(charDate, m, d, y); // Tokenize date into integer variables
	bDate.setDate(m, d, y); // Assign date values to temp birthday variable
	man.setBirthDate(bDate); // Set birthday in manager object to bDate temp object

	// Employee ID
	cout << endl << "ID: ";
	errorCheckInt(ID, 1, -1, true, -1);
	while (dep.idTaken(ID)) // Error check if ID already taken
	{
		cout << "ID #" << ID << " is already taken. Try again: ";
		errorCheckInt(ID, 1, -1, true, -1);
	}
	man.setID(ID);

	// Date Hired (mm/dd/yyyy)
	cout << "Date Hired (mm/dd/yyyy): ";
	cin >> charDate; // Input date
	tokenizeDate(charDate, m, d, y); // Tokenize date into integer variables
	dateHired.setDate(m, d, y); // Assign date values to temp birthday variable
	man.setDateHired(dateHired); // Set birthday in manager object to bDate temp object

	// Current Salary
	cout << endl << "Current Salary: $";
	errorCheckFloat(salary, 0, -1, true, -1);
	man.setSalary(salary);

	// Job Title
	cout << "Title: ";
	errorCheckString(title, true);
	man.setTitle(title);

	// Promotion Date
	cout << endl << "Promotion Date (mm/dd/yyyy): ";
	cin >> charDate; // Input date
	tokenizeDate(charDate, m, d, y); // Tokenize date into integer variables
	promotionDate.setDate(m, d, y); // Assign date values to temp birthday variable
	man.setPromotionDate(promotionDate); // Set birthday in manager object to bDate temp object

	// Add temp manager to department object
	dep.setManager(man);

	system("CLS");
}

// E -- Add Employee
void addEmployee(Department& dep)
{
	Employee e;
	string fName, lName;
	int ID, m, d, y, milesTraveled, newRevenue;
	Date bDate, dateHired;
	float salary, employeeRating, completedJobRevenue;
	char charDate[20];

	// Creating a New Employee
	cout << "Creating a New Employee" << endl << endl;

	// First name
	cout << endl << "First Name: ";
	errorCheckString(fName, false);
	e.setFirstName(fName);

	// Last name
	cout << endl << "Last Name: ";
	errorCheckString(lName, false);
	e.setLastName(lName);

	// Birthday (mm/dd/yyyy)
	cout << endl << "Birthday (mm/dd/yyyy): ";
	cin >> charDate; // Input date
	tokenizeDate(charDate, m, d, y); // Tokenize date into integer variables
	bDate.setDate(m, d, y); // Assign date values to temp birthday variable
	e.setBirthDate(bDate); // Set birthday in manager object to bDate temp object

	// Employee ID
	cout << endl << "ID: ";
	errorCheckInt(ID, 1, -1, true, -1);
	while (dep.idTaken(ID)) // Error check if ID already taken
	{
		cout << "ID #" << ID << " is already taken. Try again: ";
		errorCheckInt(ID, 1, -1, true, -1);
	}
	e.setID(ID);

	// Date Hired (mm/dd/yyyy)
	cout << "Date Hired (mm/dd/yyyy): ";
	cin >> charDate; // Input date
	tokenizeDate(charDate, m, d, y); // Tokenize date into integer variables
	dateHired.setDate(m, d, y); // Assign date values to temp birthday variable
	e.setDateHired(dateHired); // Set birthday in manager object to bDate temp object

	// Miles Traveled
	cout << endl << "Miles Traveled: ";
	errorCheckInt(milesTraveled, 0, -1, true, -1);
	e.setMilesTraveled(milesTraveled);

	// Employee Rating from Last Review
	cout << "Employee Rating from Last Review: ";
	errorCheckFloat(employeeRating, 0, 10, true, -1);
	e.setEmployeeRating(employeeRating);

	// New revenue
	cout << "Please enter 0 to add a new revenue amount for a job completed by the employee. Enter -1 to quit: ";
	errorCheckInt(newRevenue, -1, 0, true, -2);

	// While -1 to quit has not been entered
	while (newRevenue == 0)
	{
		cout << "What was the total revenue amount for this job? $";
		errorCheckFloat(completedJobRevenue, 0, -1, true, -1);

		e.addJob(completedJobRevenue); // Add new job to employee's job vector

		cout << endl;
		errorCheckInt(newRevenue, -1, 0, true, -2);
	}

	dep.addEmployee(e);

	system("CLS");
}

// R -- Remove Employee
void removeEmployee(Department& d)
{
	int id;
	cout << "Please enter the ID of the employee that you would like to remove: ";
	errorCheckInt(id, 0, -1, true, -1);

	d.removeEmployee(id);

	system("CLS");
}

// P -- Print Final Profit
//  Ends the loop execution and prints off the final profit summary
void printFinalProfit(Department& d)
{
	cout << "----------------------------------------------------------------" << std::endl;
	centerAndPrint(cout, "WePaintHouses LLC", true);
	string temp = "Department Profit Calculation for the " + d.getName() + " Department";
	centerAndPrint(cout, temp, true);
	cout << setw(32) << right << "Manager: " << setw(4) << " " << d.getManager().getFirstName() << " " << d.getManager().getLastName() << endl;
	cout << setw(32) << right << "Total Income: " << setw(5) << "$" << d.totalRevenue() << endl;
	cout << setw(32) << right << "Cost of Products: " << setw(5) << "$" << d.getProductCost() << endl;
	cout << setw(32) << right << "Cost of Labor: " << setw(5) << "$" << d.costOfLabor() << endl;
	cout << setw(32) << right << "Cost of Travel: " << setw(5) << "$" << d.costOfTravel() << endl;
	cout << setw(32) << right << "Average Employee Rating: " << setw(4) << " " << d.avgEmployeeRating() << endl;

	// Calculate final profit
	float finalProfit = d.totalRevenue() - (d.getProductCost() + d.costOfLabor() + d.costOfTravel());

	cout << setw(32) << right << "Final Profit: " << setw(5) << "$" << finalProfit << endl;
	cout << "----------------------------------------------------------------" << std::endl;
}

// Error check characters
void errorCheckChar(char& input, char bounds[])
{
	// Prompt
	string str;
	getline(cin, str); // Get whole line
	input = toupper(str[0]); // Take first character of inputted string & capitalize

	// Run through and check if inputted character is in bounds array provided
	bool found = false;

	for (int i = 0; bounds[i] != '\0'; i++)
	{
		if (bounds[i] == input) 
		{
			found = true;
			break;
		}
	}

	// Error check
	while (cin.fail() || !found)
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream

		// Print error message
		cout << "Invalid input. Enter a valid character (";

		// Run through array of valid characters given
		for (int i = 0; bounds[i] != '\0'; i++)
		{
			if (bounds[i + 1] != '\0') // Every iteration except last
			{
				cout << bounds[i] << ", ";
			}
			else // Last character in array
			{
				cout << bounds[i] << "). Please try again: ";
			}
		}

		// Reprompt input
		getline(cin, str); // Get whole line
		input = toupper(str[0]); // Take first character of inputted string & capitalize

		// Recheck
		for (int i = 0; bounds[i] != '\0'; i++)
		{
			if (bounds[i] == input)
			{
				found = true;
				break;
			}
		}
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

// Tokenize date
void tokenizeDate(char* c, int& mon, int& day, int& year) 
{
	char seps[] = "/";
	char* token = NULL;
	char* next_token = NULL;
	token = NULL;
	next_token = NULL;
	// Establish string and get the tokens:
	token = strtok_s(c, seps, &next_token);
	mon = atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	day = atoi(token);
	token = strtok_s(NULL, seps, &next_token);
	year = atoi(token);
}

// Print centered text (aesthetic function)
void centerAndPrint(ostream& out, string str, bool newLine)
{
	// Calculate the number of spaces needed to center the string
	int numSpaces = (64 - str.length()) / 2;

	// Output the string centered in the console
	out << setw(numSpaces + str.length()) << str;

	// Print endl if newLine bool is true
	if (newLine)
	{
		out << endl;
	}
}