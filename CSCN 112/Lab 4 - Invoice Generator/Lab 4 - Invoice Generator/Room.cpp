// Room Class Implementation File
#include "Room.h"
#include <iostream> // cin & cout in print
#include <iomanip> // setprecision

// Global Variables - constants only
const float paintPerGallon = 350; // 350 - 400 sq ft per gallon. Choose 350 to show worst case scenario

// Default Constructor
Room::Room()
{
	length = 0;
	width = 0;
	height = 0;
}

// Multi-argument constructor
Room::Room(float l, float w, float h, int n)
{
	setLength(l);
	setWidth(w);
	setHeight(h);
	setNumOfCoats(n);
}

// Destructor
Room::~Room()
{
	// Nothing yet
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

void Room::setNumOfCoats(int n)
{
	numOfCoats = n;
}
int Room::getNumOfCoats() const
{
	return numOfCoats;
}

// Print function
void Room::showData() const
{
	// Round to two decimals
	std::cout << std::fixed << std::showpoint << std::setprecision(2);

	// Should then print out the room information (confirm the dimensions, volume, and paintable area)

	std::cout << std::setw(20) << std::left << "Length: " << std::right << getLength() << " ft" << std::endl;
	std::cout << std::setw(20) << std::left << "Width: " << std::right << getWidth() << " ft" << std::endl;
	std::cout << std::setw(20) << std::left << "Height: " << std::right << getHeight() << " ft" << std::endl;
	std::cout << std::setw(20) << std::left << "Coats :" << std::right << getNumOfCoats() << std::endl;
	std::cout << std::setw(20) << std::left << "Volume: " << std::right << calcVolume() << " cu ft" << std::endl;
	std::cout << std::setw(20) << std::left << "Area: " << std::right << calcPaintedArea() << " sq ft" << std::endl;
	std::cout << "-- Paint Required -- " << calculateGallonsNeeded() << " gallons" << std::endl;
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
	return getNumOfCoats() * ((2 * width * height) + (2 * length * height));
}

// Use calculated the paintable area with constant in main to calculate 
//  and print out the number of gallons of paint needed for that room
//  No rounding to show exact amount of gallons used, transparency allowing user to decide to round or not
float Room::calculateGallonsNeeded() const
{
	return calcPaintedArea() / paintPerGallon;
}