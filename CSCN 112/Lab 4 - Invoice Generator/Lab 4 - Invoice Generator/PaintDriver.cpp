// CSCN 112-001 Spring 2023
// Lab 4: Invoice Generator
// Carson Kramer

// Include statements (pre-processing directives)
#include <iostream> // cin & cout
#include "House.h" // house object
#include <iomanip> // setw

// Namespace
using namespace std;

// Function Prototypes
// Initial prompt for name, rooms, and distance to clean up main
void basicInfoPrompt(string&, float&, float&);

// Menu options to reprint
void menuOptions(char&);

// Add new room with error check
void addNewRoom(House&);

// Main function
int main()
{
	// Local variables
	string name;
	float rooms, distance;
	
	basicInfoPrompt(name, rooms, distance);

	// Reprint name for screenshots
	std::cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 4" << std::endl << std::endl;

	// Creates an instance of a Room (using the zero-argument constructor)
	House house1(name, (int)rooms, distance);
	char temp;
	
	do
	{
		menuOptions(temp);
		switch (temp)
		{
		case 'A':
			// Add new rooms
			addNewRoom(house1);
			break;
		case 'L':
			// List rooms
			house1.listRooms();
			break;
		case 'Q':
			// Make sure rooms have been added
			if (house1.numOfRooms() > 0)
			{
				// Quit and prepare invoice
				house1.generateInvoice();
				house1.printToFile();
			}
			else
			{
				cout << "No rooms exist. Invoice cannot be generated." << endl << endl;
				// Set temp to random character to re-prompt window and not exit
				temp = 'A';
			}
			break;
		default:
			break;
		}

	} while (temp != 'Q');
	
	system("pause");
	return 0;
}

// Initial prompt for name, rooms, and distance to clean up main
void basicInfoPrompt(string& name, float& rooms, float& distance)
{
	cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 4" << endl << endl;

	// Enter name
	cout << "Please enter the name of the client you wish to generate the invoice for: ";
	getline(cin, name);

	// Enter max number of rooms
	cout << "Please enter the maximum number of rooms in the house that can be painted: ";
	cin >> rooms;

	// Error check - positive integer
	//  Design decision to input value as float to prevent crash, and convert to int that just cuts off decimal
	while (cin.fail() || rooms < 0)
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be a non-negative integer. Please try again: ";
		cin >> rooms;
	}

	// Enter distance
	cout << "Please enter how far(in miles) the client is from the store: ";
	cin >> distance;

	// Error check - positive float
	while (cin.fail() || distance < 0)
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be a non-negative number. Please try again: ";
		cin >> distance;
	}

	// Reset console and reprint values spaced out
	system("CLS");
}

// Menu options to reprint
void menuOptions(char& temp)
{
	cout << "Please select from the following options: " << endl;
	cout << "A - Add a room to the house" << endl;
	cout << "L - List all rooms currently in the house" << endl;
	cout << "Q - Quit and prepare invoice:" << endl;
	cin >> temp;

	// Capitalize option
	temp = toupper(temp);

	// Error check
	while (cin.fail() || (temp != 'A' && temp != 'L' && temp != 'Q'))
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be 'A', 'L', or 'Q'. Please try again: ";
		cin >> temp;
		temp = toupper(temp);
	}
	cout << endl;
}

// Add new room with error check
void addNewRoom(House& h)
{
	if (h.numOfRooms() < h.getMaxRooms())
	{
		// Local temp variables
		float length, width, height, numOfCoats;

		// Exit print instructions
		cout << "(Enter -1 for length, width, height, or number of coats to exit)" << endl;

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

		// Enter number of coats
		cout << "Number of coats: ";
		cin >> numOfCoats;

		// Direct exit if -1 entered
		if (numOfCoats == -1)
		{
			return; // Break out of function
		}
		// Error check - positive integer
		//  Design decision to input value as float to prevent crash, and convert to int that just cuts off decimal
		while (cin.fail() || (numOfCoats < 0 && numOfCoats != -1))
		{
			cin.clear(); // clears the error from the input stream
			cin.ignore(10000000, '\n'); // remove anything remaining in the stream
			cout << "Invalid input. Value needs to be a non-negative integer. Please try again: ";
			cin >> numOfCoats;
		}

		cout << endl;

		// Add new room to house passed by reference
		h.addRoom(length, width, height, (int)numOfCoats);
	}
	else
	{
		cout << "Maximum number of rooms have already been reached. No further rooms available" << endl;
	}
}