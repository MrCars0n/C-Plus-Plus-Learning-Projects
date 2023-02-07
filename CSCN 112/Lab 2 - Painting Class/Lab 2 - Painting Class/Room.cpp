// Room Class Implementation File
#include "Room.h"
#include <iostream> // cin & cout in print
#include <iomanip> // setprecision

// Default Constructor
Room::Room()
{
	length = 0;
	width = 0;
	height = 0;
}

// Get and Set functions

// Length
void Room::setLength(float l)
{
	if (l >= 0)
		length = l;
}

float Room::getLength() const
{
	return length;
}

// Width
void Room::setWidth(float w)
{
	if (w >= 0)
		width = w;
}

float Room::getWidth() const
{
	return width;
}

// Height
void Room::setHeight(float h)
{
	if (h >= 0)
		height = h;
}

float Room::getHeight() const
{
	return height;
}

// Print function
void Room::showData() const
{
	// Round to two decimals
	std::cout << std::fixed << std::showpoint << std::setprecision(2);

	// Should then print out the room information (confirm the dimensions, volume, and paintable area)
	
	// Reset console and reprint values spaced out
	system("CLS");

	// Reprint name for screenshots
	std::cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 2" << std::endl << std::endl;

	std::cout << std::setw(20) << std::left << "Length: " << std::right << getLength() << " ft" << std::endl;
	std::cout << std::setw(20) << std::left << "Width: " << std::right << getWidth() << " ft" << std::endl;
	std::cout << std::setw(20) << std::left << "Height: " << std::right << getHeight() << " ft" << std::endl;
	std::cout << std::setw(20) << std::left << "Volume: " << std::right << calcVolume() << " cu ft" << std::endl;
	std::cout << std::setw(20) << std::left << "Paintable Area: " << std::right << calcPaintedArea() << " sq ft" << std::endl;
	// Calculation of how many gallons of paint will be necessary
}

// Member functions
// Volume
float Room::calcVolume() const
{
	return length * width * height;
}

// Printed areas (Surface Area without floor / ceiling)
float Room::calcPaintedArea() const
{
	return (2 * width * height) + (2 * length * height);
}
