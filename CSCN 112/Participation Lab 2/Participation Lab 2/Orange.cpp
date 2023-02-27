// Implementation file for Orange Class

#include "Orange.h"
#include <iostream> // cout
#include <iomanip> // setw

// Default Constructor
Orange::Orange() : Fruit()
{
	seeds = true;
}

// Four argument Constructor
Orange::Orange(int c, int s, std::string t, bool ss) : Fruit(c, s, t)
{
	seeds = ss;
}

// Get and set functions
void Orange::setSeeds(bool s)
{
	seeds = s;
}

bool Orange::getSeeds() const
{
	return seeds;
}

// Print function
void Orange::printOrange() const
{
	printFruit();
	std::cout << std::left << std::setw(20) << "Seeds: " << getSeeds() << std::endl;
}
