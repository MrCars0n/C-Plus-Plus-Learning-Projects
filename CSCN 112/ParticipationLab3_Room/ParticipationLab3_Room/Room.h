#pragma once

// Header file for the Room class
// Room object will store the room's length, width, height, and number of cans of paint required to paint it

/*
	GOALS FOR THIS ASSIGNMENT:

	Define a copy constructor, then overload the following operators: 

	1.  Overload <<
	2.  Overload >>
	3.  Overload +
	4.  Overload -
	5.  Overload ==
	6.  Overload >=
	7.  Overload <=
	8.  Overload =
	9/10.  Overload ++ (pre and post)

*/

#include <iostream>
#include <iomanip>

const int PAINT_FACTOR = 400;

class Room
{
	// Overload addition as a friend function
	friend Room operator+(const Room&, float);

	// Overload the insertion operator to be able to print out a room object using <<
	friend std::ostream& operator<<(std::ostream&, const Room&);

	// Overload the extraction operator to be able to bring in a room using >>
	friend std::istream& operator>>(std::istream&, Room&);

public:
	// Constructor - default arguments so we don't need to include a default constructor
	Room(float l = 0, float w = 0, float h = 0, int coats = 0); 

	// Add a definition for a copy constructor here!
	Room(const Room& templateRoom);
	// Destructor
	~Room();

	// Get and set functions
	void setLength(float l);
	float getLength() const;

	void setWidth(float w);
	float getWidth() const;

	void setHeight(float h);
	float getHeight() const;

	void setCoats(int coats);
	int getCoats() const;

	// Functions
	void printRoomInfo() const;
	float calcNumCans() const;

	// Overloaded operators
	// Addition - take one room and add value of another room to it
	Room operator+(const Room&) const;

	// Pre-increment operator
	Room operator++();

	// Post-increment operator
	Room operator++(int);

	// Assignment operator
	const Room& operator=(const Room&);

private:
	// Private member variables
	float * length;
	float * width;
	float * height;
	int * numCoats;

	// Helper/Utility Functions
	float calcVolume() const;
	float calcPaintableArea() const;

};