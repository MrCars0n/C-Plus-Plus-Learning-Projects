/*
	Write a program to help a local restaurant automate its breakfast billing system. The 	program should do the following:

	1. Show the customer the different breakfast items offered by the restaurant.

	2. Allow the customer to select more than one item from the menu.

	3. Calculate and print the bill.

	Use an array menuList of type MenuItemType. MenuItemType consists of three components:
		menuItem of type string,
		menuPrice of type double, and
		isOrdered of type bool.

	Your program must contain at least the following functions:

	1. Function getData: This function loads the data into the array menuList from the file menu.txt.

	2. Function showMenu: This function shows the different items offered by the restaurant and tells the user how to select the items.

	3. Function printCheck: This function calculates and prints the check. (Note that the billing amount should include a 5% tax.)

	Format your output with two decimal places. The name of each item in the output must be left justified. You may assume that the user
	selects only one item of a particular type.

	Algorithm:

		main
		{
			GetData
			do {
				showMenu
			} while not done
			printCheck
		}
*/
//CSCN 111-03
//Public Domain

//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
struct MenuItemType {
	string menuItem;
	double menuPrice;
	bool isOrdered = false;
};

//Function prototypes
void wait();
void getData(MenuItemType[]);
void showMenu(MenuItemType[]);
void printCheck(MenuItemType[]);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Carson Kramer -- Lab 9" << endl << endl;

	//Variable declarations
	MenuItemType menu[8];

	//Program logic
	getData(menu);
	showMenu(menu);
	printCheck(menu);

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

void getData(MenuItemType menu[])
{
	ifstream in;

	in.open("menu.txt");
	string tempDouble;

	// Input data from file
	for (int x = 1; x <= 8; x++)
	{
		getline(in, menu[x-1].menuItem, '\n');
		getline(in, tempDouble, '\n');
		
		// Use temp string to get data from getLine and covert it into double for menuPrice
		menu[x-1].menuPrice = stof(tempDouble);
	}
}

void showMenu(MenuItemType menu[])
{
	// Print Menu with numbers
	cout << fixed << showpoint << setprecision(2);
	for (int x = 1; x <= 8; x++)
	{
		cout << x << ") " << menu[x - 1].menuItem << right << setw(25 - menu[x - 1].menuItem.length()) << "$" << menu[x - 1].menuPrice << endl;
	}

	cout << endl;

	// Prompt menu selection
	int selection;
	do
	{
		cout << "Enter your selection number (-1 to finish): ";
		cin >> selection;
		if (selection > 0 && selection < 9)
			menu[selection - 1].isOrdered = true;
	} while (selection != -1);
	
	cout << endl;
}

void printCheck(MenuItemType menu[])
{
	cout << "Welcome to Johnny's Restaurant" << endl;

	double total = 0;
	double tax = 0;

	// Print selection menu items
	for (int x = 1; x <= 8; x++)
	{
		if (menu[x - 1].isOrdered)
		{
			cout << menu[x - 1].menuItem << right << setw(25 - menu[x - 1].menuItem.length()) << "$" << menu[x - 1].menuPrice << endl;
			total += menu[x - 1].menuPrice;
		}
	}

	// Calculate tax
	tax = total * 0.05;
	cout << "Tax" << right << setw(22) << "$" << tax << endl;

	// Calculate final amount
	total += tax;
	cout << "Amount Due" << right << setw(15) << "$" << total << endl;
}