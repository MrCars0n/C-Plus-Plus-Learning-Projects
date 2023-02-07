// Room Class Declaration File
#pragma once

#include <string>

// Define a struct object for a single game
class Room
{
public:
	// Constructors
	// Default Constructor
	Room();

	// Get and Set functions
	void setLength(float l);
	float getLength() const;

	void setWidth(float w);
	float getWidth() const;

	void setHeight(float h);
	float getHeight() const;

	// Print function
	void showData() const;

	// Member functions
	//  Decided to make calcPaintedArea function public to allow calculations with global constant in main
	//  I think it makes more sense for this to be apart of this object for reusability,
	//   but it does not make sense for it to pass in arguments if it would need to be public either way.
	//  (kept as const, however, to protect variables as a public function)
	float calcPaintedArea() const;

private:
	// Private variables
	float length;
	float width;
	float height;

	// Private member functions
	float calcVolume() const;
};