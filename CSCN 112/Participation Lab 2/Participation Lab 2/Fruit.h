#pragma once

// Fruit header file
// BASE CLASS

#include <string> // private string type

// Base class - Fruit
//		Calories - int
//		Serving Size - int
//		Type - string

class Fruit
{
public:
	Fruit(); // default constructor
	Fruit(int, int, std::string); // three-argument constructor

	// Set and get functions
	void setCalories(int);
	int getCalories() const;

	void setServingSize(int);
	int getServingSize() const;

	void setType(std::string);
	std::string getType() const;

	// Print function
	void printFruit() const;

private:
	int calories;
	int servingSize;
	std::string type;
};