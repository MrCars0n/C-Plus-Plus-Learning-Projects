// Vigenere Class Declaration File
#pragma once

#include <string> // string

// Define Vigenere class
class Vigenere
{
public:
	// Constructors
	// Default Constructor - default key is set to "KEY"
	Vigenere();

	// One-argument constructor
	Vigenere(std::string);

	// Destructor
	~Vigenere();

	// Get and Set functions
	void setKey(std::string);
	std::string getKey() const;

	// Encrypt and decrypt a single word functions
	std::string encrypt(std::string);
	std::string decrypt(std::string);

private:
	// Private key string variable
	std::string key;

	// Function to convert a string entirely to uppercase
	//   Loop with toupper function for each character
	std::string keyToUpper(std::string);
};