// Paint Class Declaration File
#pragma once

#include <string> // string
#include <iostream> // cout

class Paint
{
public:
	// Default constructor
	//		initializes the gloss_level to zero
	//		outputs the message “Invoking the default Paint constructor.”
	Paint()
	{
		setGlossLevel(0);
		std::cout << "Invoking the default Paint constructor." << std::endl;
	}

	// 2-Argument constructor
	//		color and gloss_level to be set by the client
	//		output the message “Invoking the 2-argument Paint constructor.”
	Paint(std::string color, float gloss) 
	{ 
		setColor(color); 
		setGlossLevel(gloss);
		std::cout << "Invoking the 2-argument Paint constructor." << std::endl;
	}

	// Destructor
	//		output the message “Invoking the default Paint destructor.”
	virtual ~Paint() { std::cout << "Invoking the default Paint destructor." << std::endl; }

	// Get and set functions
	void setColor(std::string c) { color = c; }
	std::string getColor() const { return color; }
	void setGlossLevel(float g) { gloss_level = g; }
	float getGlossLevel() const { return gloss_level; }
	void setNumOfCans(float c) { numOfCans = c; }
	float getNumOfCans() const { return numOfCans; }
		
	// Virtual help() function
	//		unable to call help from a general paint object
	virtual void help() = 0;

private:
	std::string color;
	float gloss_level;
	float numOfCans;
};