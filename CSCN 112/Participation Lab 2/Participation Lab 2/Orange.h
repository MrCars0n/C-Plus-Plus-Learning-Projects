#pragma once

// Orange Header file - cclass declaration
//  This class will inherit from the Fruit class

// Derived classes - Orange
//		Orange - seeds bool

#include "Fruit.h"

class Orange : public Fruit
{
public:
	// Default Constructor
	Orange();
	// Four argument Constructor
	Orange(int, int, std::string, bool);

	// Get and set functions
	void setSeeds(bool);
	bool getSeeds() const;

	// Print function
	void printOrange() const;

private: 
	bool seeds;
};