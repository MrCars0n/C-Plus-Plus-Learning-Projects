// Message Class Implementation File
#include "Message.h"
#include <iostream> // cout
#include <fstream> // file input

// Constructors
// Default Constructor - default key is set to "KEY"
Message::Message()
{
	v.setKey("KEY");
}

// One-argument constructor
Message::Message(std::string k)
{
	v.setKey(k);
}

// Destructor
Message::~Message()
{
	// Nothing here yet
}

// Print vector of encrypted or decrypted words
void Message::showWords()
{
	// Go through every element in tokenized vector
	for (int i = 0; i < tokenized.size(); i++)
	{
		// If if is not the last word, print a space. Else, don't print space
		if (i != tokenized.size())
		{
			std::cout << tokenized.at(i) << " ";
		}
		else
		{
			std::cout << tokenized.at(i);
		}
	}
	std::cout << std::endl << std::endl;
}

// Print to File
void Message::makeFile(std::string name)
{
	// Create an ofstream object and open the file
	std::ofstream outfile(name);

	if (outfile.is_open()) {
		// Write info to file
		// Go through every element in tokenized vector
		for (int i = 0; i < tokenized.size(); i++)
		{
			// If if is not the last word, print a space. Else, don't print space
			if (i != tokenized.size())
			{
				outfile << tokenized.at(i) << " ";
			}
			else
			{
				outfile << tokenized.at(i);
			}
		}

		// Close the file
		outfile.close();

		std::cout << "The file name is now set to " << name << std::endl << std::endl;
	}
	else {
		std::cout << "Error: could not create file." << std::endl << std::endl;
	}
}

// Function should receive the token as a char* data type and cast it into a string variable
//   push that newly encrypted word onto the vector of words.
//   https://msdn.microsoft.com/en-us/library/ftsafwz3.aspx
void Message::encryptWord(char* c)
{
	char seps[] = " ,\t\n";
	char* token1 = NULL;
	char* next_token1 = NULL;

	// Establish string and get the first token:
	token1 = strtok_s(c, seps, &next_token1);

	// While there are tokens in "c"
	while (token1 != NULL)
	{
		// Typecast char* array to strings
		std::string str(token1);

		// Add encrypted word to vector
		tokenized.push_back(encrypt(str));

		token1 = strtok_s(NULL, seps, &next_token1);
	}
}

// Opposite of encryptWord
void Message::decryptWord(char* c)
{
	char seps[] = " ,\t\n";
	char* token1 = NULL;
	char* next_token1 = NULL;

	// Establish string and get the first token:
	token1 = strtok_s(c, seps, &next_token1);

	// While there are tokens in "c"
	while (token1 != NULL)
	{
		// Typecast char* array to strings
		std::string str(token1);

		// Add decrypted word to vector
		tokenized.push_back(decrypt(str));

		token1 = strtok_s(NULL, seps, &next_token1);
	}
}

// Encrypt and decrypt a single word functions
std::string Message::encrypt(std::string s)
{
	// Prompt private vigenere member functions
	return v.encrypt(s);
}

std::string Message::decrypt(std::string s)
{
	// Prompt private vigenere member functions
	return v.decrypt(s);
}