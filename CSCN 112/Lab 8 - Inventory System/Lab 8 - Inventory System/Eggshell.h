// Eggshell Class Declaration File
#pragma once

#include "Paint.h" // inheritence
#include <iostream> // cout

class Eggshell : public Paint
{
public:
	// Default constructor
	//		outputs the message “Invoking the <name> Paint constructor.”
	Eggshell()
	{
		std::cout << "Invoking the Eggshell Paint constructor." << std::endl;
	}

	// 2-Argument constructor
	//		color and gloss_level to be set by the client
	//		output the message “Invoking the 2 - argument <name> Paint constructor.”
	Eggshell(std::string color, float gloss) : Paint(color, gloss)
	{
		setColor(color);
		setGlossLevel(gloss);
		std::cout << "Invoking the 2-argument Eggshell Paint constructor." << std::endl;
	}

	// Destructor
	//		output the message “Invoking the <name> Paint destructor.”
	~Eggshell() { std::cout << "Invoking the Eggshell Paint destructor." << std::endl; }

	// Virtual help() override function
	//		custom help messages printed
	void help() override
	{
		std::cout << "Eggshell paint is more durable that flat paint and has slightly more luster. This type of paint is great for places that experience low or medium traffic." << std::endl;
	}
};