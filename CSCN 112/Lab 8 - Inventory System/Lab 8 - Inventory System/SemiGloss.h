// Semi-Gloss Class Declaration File
#pragma once

#include "Paint.h" // inheritence
#include <iostream> // cout

class SemiGloss : public Paint
{
public:
	// Default constructor
	//		outputs the message “Invoking the <name> Paint constructor.”
	SemiGloss()
	{
		std::cout << "Invoking the Semi-Gloss Paint constructor." << std::endl;
	}

	// 2-Argument constructor
	//		color and gloss_level to be set by the client
	//		output the message “Invoking the 2 - argument <name> Paint constructor.”
	SemiGloss(std::string color, float gloss) : Paint(color, gloss)
	{
		setColor(color);
		setGlossLevel(gloss);
		std::cout << "Invoking the 2-argument Semi-Gloss Paint constructor." << std::endl;
	}

	// Destructor
	//		output the message “Invoking the <name> Paint destructor.”
	~SemiGloss() { std::cout << "Invoking the Semi-Gloss Paint destructor." << std::endl; }

	// Virtual help() override function
	//		custom help messages printed
	void help() override
	{
		std::cout << "Semi-gloss is a very shiny and reflective paint. It is durable and resistant to mildew, but will show more imperfections than flat, eggshell, or satin paint. This type of paint is great for rooms that have high moisture or high levels of wear and tear." << std::endl;
	}
};