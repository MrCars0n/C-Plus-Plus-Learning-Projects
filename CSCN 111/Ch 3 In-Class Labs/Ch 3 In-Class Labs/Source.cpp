#include <iostream>
#include <string>
//#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
	
	string firstName, lastName, fullName;

	/*
	cout << "What is your full name? ";
	cin >> firstName >> lastName;
	cout << "You entered " << firstName << ' ' << lastName << '.' << endl;

	cout << "What is your full name? ";
	cin >> fullName;
	cout << "You entered " << fullName << endl;
	
	// Demonstrate manipulators
	double varDouble;
	cout << "Enter a floating point number with a bunch of digits after the decimal point: ";
	cin >> varDouble;
	cout << "You entered " << varDouble << endl;
	cout << fixed << showpoint << setprecision(2);
	//cout << setprecision(5);
	cout << "Your formatted number is: " << varDouble << endl;
	cout << scientific;
	cout << "Your number in scientific notation: " << varDouble << endl;
	

	// Demonstrate setw()
	const int ITEM = 15, PRICE = 10;
	cout << setw(ITEM) << "Hamburger" << right << setw(PRICE) << "$5.52" << endl;
	cout << setw(ITEM) << "Cheeseburger" << right << setw(PRICE) << "$6.85" << endl;
	cout << setw(ITEM) << "Streak Sandwich" << right << setw(PRICE) << "$19.95" << endl;
	cout << endl << endl;
	*/

	// Demonstrate setfull()
	cout << left;
	//cout.unsetf(ios::left);
	cout << setw(20) << setfill('#');
	cout << 87000000 << endl << endl;
	
	// Demonstrate getline
	cout << "Enter your full name: ";
	getline(cin, fullName);
	cout << "Your full name is: " << fullName << endl;
	
	// Demonstrate writing to and reading from a file
	ofstream output;
	ifstream input;
	string myData;

	output.open("data.txt");	// open the file
	output << "This is my data!!!";
	output.close();
	input.open("data.txt");
	getline(input, myData);
	input.close();
	cout << "This is what your data.txt file contained: " << myData << endl << endl;
	return 0;
}