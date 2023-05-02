// CSCN 112-001 Spring 2023
// Lab 5: Messaging System
// Carson Kramer

// Include statements (pre-processing directives)
#include <iostream> // cin & cout
#include "Message.h" // message object
#include <iomanip> // setw
#include <string> // string
#include <fstream> // file input

// Namespace
using namespace std;

// Function Prototypes
// Menu options to reprint
void menuOptions(int&);

// Key Prompt
void keyPrompt(string&);

// Prompt file names and read contents
void fileManipulation(Message&, bool);

// Print centered text (aesthetic function)
void centerAndPrint(string, bool newLine);

// Function to convert a string entirely to uppercase
//   Loop with toupper function for each character (re-added to main for printing purposes)
std::string keyToUpper(std::string);

// Main function
int main()
{
	// Local variables
	int menuChoice;
	string key;

	// Reprint name for screenshots
	std::cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 5" << std::endl << std::endl;

	// Do while loop until exit prompt entered
	do
	{
		// Prompt menu
		menuOptions(menuChoice);
		if (menuChoice != 3)
		{
			// Prompt for key and capitalization
			keyPrompt(key);

			// Creates an instance of a Message (using the zero-argument constructor)
			Message m(key);

			// Menu choices for options 1 & 2
			switch (menuChoice)
			{
			case 1: // Encrypt
				fileManipulation(m, true);
				break;
			case 2: // Decrypt
				fileManipulation(m, false);
				break;
			default:
				break;
			}
		}

	} while (menuChoice != 3);

	return 0;
}

// Menu options to reprint
void menuOptions(int& temp)
{
	// Center and print menu
	centerAndPrint("Vigenere Cypher", true);
	centerAndPrint("Main Menu", true);
	centerAndPrint("1 - Encrypt File", true);
	centerAndPrint("2 - Decrypt File", true);
	centerAndPrint("3 - Quit", true);
	cout << endl;
	centerAndPrint("Selection : ", false);

	cin >> temp;

	cout << endl;

	// Error check menu options
	while (cin.fail() || temp < 1 || temp > 3)
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be between 1 and 3. Please try again: ";
		cin >> temp;
	}
}

// Key Prompt
void keyPrompt(string& key)
{
	// Prompt for key
	cout << "Enter an encryption/decryption key: ";

	cin >> key;

	while (cin.fail())
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Enter a valid key. Please try again: ";
		cin >> key;
	}
	cout << endl;

	cout << "Key is now: " << keyToUpper(key) << endl << endl;
}

// Prompt file names and read contents
void fileManipulation(Message& m, bool encrypt)
{
	ifstream file; //instantiate a file object 
	string oldFileName, newFileName;
	cin.clear(); // clears the error from the input stream
	cin.ignore(10000000, '\n'); // remove anything remaining in the stream

	// Input file name (prompt changes based on bool)
	if (encrypt)
	{
		cout << "Please enter the name of the file that needs encrypted (include file extension): ";
	}
	else
	{
		cout << "Please enter the name of the file that needs decrypted (include file extension): ";
	}
	getline(cin, oldFileName, '\n');

	file.open(oldFileName); // Try to open the file 

	// An error check should go here to ensure that the file opened successfully. 
	if (!file.fail())
	{
		// Allocate memory for 1000 sized character array
		char* c = new char[1000];
		string fileDump;

		// Put file content into string variable
		getline(file, fileDump);

		// Run through for loop of string and put it in character array
		for (int i = 0; i < fileDump.size(); i++) 
		{
			c[i] = fileDump[i];
		}

		// Add null terminator at the end of the array
		c[fileDump.size()] = '\0';

		// Close the file
		file.close();

		// Print the contents of the array
		printf("%s\n", c);

		// Encrypt or decrypt the inputed words based on bool
		if (encrypt)
		{
			m.encryptWord(c);
		}
		else
		{
			m.decryptWord(c);
		}

		// Free the memory allocated for the character array
		delete[] c;
	}
	else
	{
		cout << "File could not be located. Please try again." << endl << endl;
		return;
	}

	cout << endl << endl;

	// Prompt for file to save to
	cout << "Please enter the name of the file you would like to store the message in (include file extension): ";
	getline(cin, newFileName, '\n');

	// Print out encrypted / decrypted words
	m.showWords();

	// Make new file with inputted name
	m.makeFile(newFileName);
}

// Print centered text (aesthetic function)
void centerAndPrint(string str, bool newLine)
{
	// Calculate the number of spaces needed to center the string
	int numSpaces = (80 - str.length()) / 2;

	// Output the string centered in the console
	cout << setw(numSpaces + str.length()) << str;
	
	// Print endl if newLine bool is true
	if (newLine)
	{
		cout << endl;
	}
}

// Function to convert a string entirely to uppercase
//   Loop with toupper function for each character (re-added to main for printing purposes)
std::string keyToUpper(std::string k)
{
	std::string temp = "";

	for (char c : k) {
		temp += std::toupper(c); // append the uppercase version of c to temp
	}

	return temp;
}