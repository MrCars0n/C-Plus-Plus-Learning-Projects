// High-Gloss Class Declaration File
#pragma once

#include "Paint.h" // inheritence
#include <iostream> // cout

class HighGloss : public Paint
{
public:
	// Default constructor
	//		outputs the message “Invoking the <name> Paint constructor.”
	HighGloss()
	{
		std::cout << "Invoking the High-Gloss Paint constructor." << std::endl;
	}

	// 2-Argument constructor
	//		color and gloss_level to be set by the client
	//		output the message “Invoking the 2 - argument <name> Paint constructor.”
	HighGloss(std::string color, float gloss) : Paint(color, gloss)
	{
		setColor(color);
		setGlossLevel(gloss);
		std::cout << "Invoking the 2-argument High-Gloss Paint constructor." << std::endl;
	}

	// Destructor
	//		output the message “Invoking the <name> Paint destructor.”
	~HighGloss() { std::cout << "Invoking the High-Gloss Paint destructor." << std::endl; }

	// Virtual help() override function
	//		custom help messages printed
	void help() override
	{
		std::cout << "High-glass is the shiniest type of paint we offer, and also the most durable and washable. It can also be used as an outdoor paint! It is best for doors, trim, and cabinetry as it can show many imperfections if applied incorrectly." << std::endl;
	}
};