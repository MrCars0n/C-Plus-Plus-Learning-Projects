// CSCN 112 Spring 2023 - In-Class Participation Lab 2

#include <iostream> // cin & cout
#include "Fruit.h" // Fruit object link
#include "Orange.h" // Orange object link

// Food example

// Base class - Fruit
//		Calories - int
//		Serving Size - int
//		Type - string


// Derived classes - Banana, Apple, Orange
//		Orange - seeds bool
//		Apple - stem bool
//		Banana - color string

using namespace std;

int main()
{
	cout << "Participation Lab 2 - Carson Kramer" << endl << endl;

	// Create an object of the fruit class
	Fruit object1;

	// Set properties of new fruit object
	object1.setCalories(227);
	object1.setServingSize(4);
	object1.setType("Banana");

	// Print characteristics of object1 fruit
	object1.printFruit();

	// Create an object of the Orange Class
	Orange object2(329, 2, "Orange", true);
	object2.printOrange();

	system("pause");
	return 0;
}