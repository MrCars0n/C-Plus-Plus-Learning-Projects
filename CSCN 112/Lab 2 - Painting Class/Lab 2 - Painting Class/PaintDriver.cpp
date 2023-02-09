// CSCN 112-001 Spring 2023
// Lab 2: Painting Class
// Carson Kramer

// Include statements (pre-processing directives)
#include <iostream> // cin & cout
#include "Room.h" // room object
#include <iomanip> // setw

// Namespace
using namespace std;

// Global Variables - constants only
const int paintPerGallon = 350; // 350 - 400 sq ft per gallon. Choose 350 to show worst case scenario

// Function Prototypes
// Prompts user input for function values
void promptUser(float& length, float& width, float& height);

// Calculated the paintable area (explained below)
float calculateGallonsNeeded(Room room);

// Main function
int main()
{
	cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 2" << endl << endl;

	// Local variables
	float l, w, h;

	// Creates an instance of a Room (using the zero-argument constructor)
	Room room1;

	// Do-while for repeat prompt (until -1 entered)
	do
	{
		// Prompts the user for the length, width, and height
		//  Chose to prompt user right after printing previous iteration to show user that it is a looping function, no need to relauch program
		promptUser(l, w, h);

		// Error check in-case of while loop exit command (-1)
		if (l != -1 && w != -1 && h != -1)
		{
			// Calls set functions to set those values
			room1.setLength(l);
			room1.setWidth(w);
			room1.setHeight(h);

			// Calls showData() to display the final results
			room1.showData();

			// Use calculated the paintable area with constant in main to calculate 
			//  and print out the number of gallons of paint needed for that room
			//  No rounding to show exact amount of gallons used, transparency allowing user to decide to round or not
			cout << setw(20) << left << "Gallons Required: " << right << calculateGallonsNeeded(room1) << " gal" << endl << endl;
		}
	} while (l != -1 && w != -1 && h != -1);
	
	return 0;
}

// Prompts user input for function values
void promptUser(float& length, float& width, float& height)
{
	// Exit print instructions
	cout << "(Enter -1 for length, width, or height to exit)" << endl;

	// Precision prompt
	cout << "Length: ";
	cin >> length;
	
	// Direct exit if -1 entered
	if (length == -1)
	{
		return; // Break out of function
	}
	// Error check - positive float / -1 entered
	while (cin.fail() || (length < 0 && length != -1))
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be a non-negative number. Please try again: ";
		cin >> length;
	}

	// Width prompt
	cout << "Width: ";
	cin >> width;

	// Direct exit if -1 entered
	if (width == -1)
	{
		return; // Break out of function
	}
	// Error check - positive float
	while (cin.fail() || (width < 0 && width != -1))
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be a non-negative number. Please try again: ";
		cin >> width;
	}

	// Height prompt
	cout << "Height: ";
	cin >> height;

	// Direct exit if -1 entered
	if (height == -1)
	{
		return; // Break out of function
	}
	// Error check - positive float
	while (cin.fail() || (height < 0 && height != -1))
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be a non-negative number. Please try again: ";
		cin >> height;
	}
}

// Use calculated the paintable area with constant in main to calculate 
//  and print out the number of gallons of paint needed for that room
//  No rounding to show exact amount of gallons used, transparency allowing user to decide to round or not
float calculateGallonsNeeded(Room room)
{
	return room.calcPaintedArea() / paintPerGallon;
}
