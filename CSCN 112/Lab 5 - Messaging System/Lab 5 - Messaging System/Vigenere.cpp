// Vigenere Class Implementation File
#include "Vigenere.h"

// Constructors
// Default Constructor - default key is set to "KEY"
Vigenere::Vigenere()
{
	setKey("KEY");
}

// One-argument constructor
Vigenere::Vigenere(std::string k)
{
	setKey(k);
}

// Destructor
Vigenere::~Vigenere()
{
	// Nothing here yet
}

// Get and Set functions
void Vigenere::setKey(std::string k)
{
	key = keyToUpper(k);
}

std::string Vigenere::getKey() const
{
	return key;
}

// Encrypt and decrypt a single word functions
std::string Vigenere::encrypt(std::string word)
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		j = (j + 1) % key.length();
	}
	return output;
}
std::string Vigenere::decrypt(std::string word)
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c - key[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		j = (j + 1) % key.length();
	}
	return output;
}

// Function to convert a string entirely to uppercase
//   Loop with toupper function for each character
std::string Vigenere::keyToUpper(std::string k)
{
	std::string temp = "";

	for (char c : k) {
		temp += std::toupper(c); // append the uppercase version of c to temp
	}

	return temp;
}