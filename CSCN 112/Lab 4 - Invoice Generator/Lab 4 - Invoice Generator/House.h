// House Class Declaration File
#pragma once

#include <string> // Client Name
#include <vector> // Rooms vector
#include "Room.h" // Rooms vector

class House
{
public:
	// Default Constructor
	House();

	// Multi-argument constructor
	House(std::string, int, float);

	// Deconstructor
	~House();

	// Get & Set Functions
	void setName(std::string);
	std::string getName() const;

	void setMaxRooms(int);
	int getMaxRooms() const;

	void setDistance(float);
	float getDistance() const;

	// Vector access

	// Add room to vector
	//  first check to make sure that the maximum 
	//  number of rooms has not already been exceeded
	void addRoom(float, float, float, int);

	// Print function
	void listRooms() const;

	// Vector size return
	int numOfRooms() const;

	// Print to file function
	void printToFile() const;

	// Total amount of paint for the full house
	float totalPaint() const;

	// Number of coats of paint in a single job
	int numOfCoats() const;

	// Number of paint cans needed for a single room in the vector at a given position
	int numOfCans(int) const;

	// Generate invoice for house
	void generateInvoice() const;
private:
	// Private variables
	std::string name;
	int maxRooms;
	float distance;
	std::vector<Room> rooms;
};