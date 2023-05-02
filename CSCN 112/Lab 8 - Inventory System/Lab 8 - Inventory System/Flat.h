// Flat Class Declaration File
#pragma once

#include "Paint.h" // inheritence
#include <iostream> // cout

class Flat : public Paint
{
public:
	// Default constructor
	//		outputs the message “Invoking the <name> Paint constructor.”
	Flat()
	{
		std::cout << "Invoking the Flat Paint constructor." << std::endl;
	}
	
	// 2-Argument constructor
	//		color and gloss_level to be set by the client
	//		output the message “Invoking the 2 - argument <name> Paint constructor.”
	Flat(std::string color, float gloss) : Paint(color, gloss)
	{
		setColor(color);
		setGlossLevel(gloss);
		std::cout << "Invoking the 2-argument Flat Paint constructor." << std::endl;
	}
	
	// Destructor
	//		output the message “Invoking the <name> Paint destructor.”
	~Flat() { std::cout << "Invoking the Flat Paint destructor." << std::endl; }
	
	// Virtual help() override function
	//		custom help messages printed
	void help() override
	{
		std::cout << "Flat paint is less durable with less shine but will provide the most coverage. This type of paint is best for low traffic areas." << std::endl;
	}
};