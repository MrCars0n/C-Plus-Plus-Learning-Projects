// Satin Class Declaration File
#pragma once

#include "Paint.h" // inheritence
#include <iostream> // cout

class Satin : public Paint
{
public:
	// Default constructor
	//		outputs the message “Invoking the <name> Paint constructor.”
	Satin()
	{
		std::cout << "Invoking the Satin Paint constructor." << std::endl;
	}

	// 2-Argument constructor
	//		color and gloss_level to be set by the client
	//		output the message “Invoking the 2 - argument <name> Paint constructor.”
	Satin(std::string color, float gloss) : Paint(color, gloss)
	{
		setColor(color);
		setGlossLevel(gloss);
		std::cout << "Invoking the 2-argument Satin Paint constructor." << std::endl;
	}

	// Destructor
	//		output the message “Invoking the <name> Paint destructor.”
	~Satin() { std::cout << "Invoking the Satin Paint destructor." << std::endl; }

	// Virtual help() override function
	//		custom help messages printed
	void help() override
	{
		std::cout << "Satin paint is the most common interior paint. It is easier to clean than flat or eggshell, but it can be very tricky to touch-up if errors are made during application. This type of paint is great for high-traffic areas." << std::endl;
	}
};