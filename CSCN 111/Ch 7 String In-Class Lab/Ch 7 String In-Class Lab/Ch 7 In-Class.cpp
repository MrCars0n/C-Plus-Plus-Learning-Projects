#include<iostream>
#include<string>

// New namespace call utilz
namespace utilz
{
	const int MAX = 100;
}

// Only endl does not need std:: before it
using std::endl;

int main()
{
	std::cout << "Max = " << utilz::MAX << endl;

	// local namespace example
	using std::cout;

	/*/ String Example
	using namespace std;
	string myString;
	string::size_type pos; // largest possible size of the datatype

	pos = myString.find('A');

	if (pos == string::npos) // npos is a value outsize the range of the largest string array we can have
		cout << "No 'A' was found" << endl;
	else
		cout << "An 'A' was found in position " << pos << endl;*/

	std::string myString = "This is my string";

	cout << "The s econd character of my string is " << myString[1] << endl;
	cout << "The length of my string is " << myString.length() << endl;
	cout << "The last character is " << myString[myString.length() - 1] << endl;

	std::string::size_type pos;
	pos = myString.find('i');
	if (pos == std::string::npos)
		cout << "Could not find 'i'.";
	else
		cout << "An 'i' was found at position " << pos;
	cout << endl << endl;

	// str1.swap(str2);		swaps strings

}