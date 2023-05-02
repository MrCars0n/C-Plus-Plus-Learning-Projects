// Message Class Declaration File
#pragma once

#include <string> // string
#include <vector> // words vector
#include "Vigenere.h" // Vigenere object

// Define Message class
class Message
{
public:
	// Constructors
	// Default Constructor - default key is set to "KEY"
	Message();

	// One-argument constructor
	Message(std::string);

	// Destructor
	~Message();

	// Print vector of encrypted or decrypted words
	void showWords();

	// Print to File
	void makeFile(std::string);

	// Function should receive the token as a char* data type and cast it into a string variable
	//   push that newly encrypted word onto the vector of words.
	void encryptWord(char*);

	// Opposite of encryptWord
	void decryptWord(char*);

private:
	// Vector of all of your tokenized words
	std::vector<std::string> tokenized;

	// Private data member of the Vigenère class (demonstrating composition)
	Vigenere v;

	// Encrypt and decrypt a single word functions
	std::string encrypt(std::string);
	std::string decrypt(std::string);
};