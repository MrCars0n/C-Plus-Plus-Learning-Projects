// Room Class Declaration File
#pragma once

#include <fstream> // printToFile function

// Define a struct object for a single game
class Room
{
public:
	// Constructors
	// Default Constructor
	Room();

	// Multi-argument constructor
	Room(float, float, float, int);

	// Destructor
	~Room();

	// Get and Set functions
	void setLength(float);
	float getLength() const;

	void setWidth(float);
	float getWidth() const;

	void setHeight(float);
	float getHeight() const;

	void setNumOfCoats(int);
	int getNumOfCoats() const;

	// Print function
	void showData() const;

	// Use calculated the paintable area with constant in main to calculate 
	//  and print out the number of gallons of paint needed for that room
	//  No rounding to show exact amount of gallons used, transparency allowing user to decide to round or not
	float calculateGallonsNeeded() const;
private:
	// Private variables
	float length;
	float width;
	float height;
	int numOfCoats;

	// Private member functions
	float calcVolume() const;

	// Member functions
	//  Decided to make calcPaintedArea function public to allow calculations with global constant in main
	//  I think it makes more sense for this to be apart of this object for reusability,
	//   but it does not make sense for it to pass in arguments if it would need to be public either way.
	//  (kept as const, however, to protect variables as a public function)
	float calcPaintedArea() const;
};