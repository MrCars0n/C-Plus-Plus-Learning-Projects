// Implementation file for Fruit Class

#include "Fruit.h"
#include <iostream> // cout
#include <iomanip> // setw

 // default constructor
Fruit::Fruit()
{
	calories = 0;
	servingSize = 0;
	type = "";
}

// three-argument constructor
Fruit::Fruit(int c, int s, std::string t)
{
	calories = c;
	servingSize = s;
	type = t;
}

// Set and get functions
void Fruit::setCalories(int c)
{
	calories = c;
}
int Fruit::getCalories() const
{
	return calories;
}

void Fruit::setServingSize(int s)
{
	servingSize = s;
}
int Fruit::getServingSize() const
{
	return servingSize;
}

void Fruit::setType(std::string t)
{
	type = t;
}
std::string Fruit::getType() const
{
	return type;
}

// Print function
void Fruit::printFruit() const
{
	std::cout << std::left << std::setw(20) << "Calories: " << getCalories() << std::endl;
	std::cout << std::left << std::setw(20) << "Serving Size: " << getServingSize() << std::endl;
	std::cout << std::left << std::setw(20) << "Type: " << getType() << std::endl;
}