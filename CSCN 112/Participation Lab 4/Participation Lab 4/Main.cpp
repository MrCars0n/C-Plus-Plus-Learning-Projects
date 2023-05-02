// Carson Kramer
// Participation Lab4 
// Rectangle class Driver file 

#include <iostream>
#include "Rectangle.h"
#include "NegativeNumberException.h"

using namespace std;

int main()
{
	// Create three Rectangle objects using the default constructor, r1, r2, and r3
	Rectangle<float> r1;
	Rectangle<int> r2;
	Rectangle<long long> r3;

	// Call the setLength and setWidth functions for each 
		// Set r1 to a length = 2.2 and width = 3.3
	r1.setLength(2.2);	r1.setWidth(3.3);
		// Set r2 to a length = 4 and width = 5
	r2.setLength(4);	r2.setWidth(5);
		// Set r3 to a length = -5 and width = -7
	r3.setLength(-5);	r3.setWidth(-7);

	// Print out the length and width of each using cout <<  
	r1.showData();
	r2.showData();
	r3.showData();

	// If an exception is thrown, print out the message returned by the exception object 

	system("pause");
	return 0;
}