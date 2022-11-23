// Ddecision structures

#include<iostream>
using namespace std;

int main()
{
	int grade;
	cout << "Please enter your grade percentage: ";
	cin >> grade;

	// Single selection
	if (grade >= 70)
		cout << "Passed!" << endl;

	// Double selection
	if (grade >= 70)
		cout << "Passed!" << endl;
	else
		cout << "Failed!" << endl;

	// Multiple selection
	if (grade >= 93)
		cout << "A" << endl;
	else if (grade >= 86)
		cout << "B" << endl;
	else if (grade >= 78)
		cout << "C" << endl;
	else if (grade >= 70)
		cout << "D" << endl;
	else
		cout << "F" << endl;

	// Shortcut for if/else -- the ?: operator
	cout << (grade >= 96 ? "NHS" : "Not worthy") << endl;

	// Nested structures - a structure inside of another structure
	int x = 5;
	int y = -6;

	if (x == 5)
	{
		if (y > 0)
		{

		}
		else
		{
			// This will run using 5 and -6
		}
	}

	return 0;
}