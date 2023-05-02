// House Class Implementation File
#include "House.h"
#include <iostream> // cout
#include <iomanip> // setw
#include <fstream> // print to file

// Global Variables - constants only
const float hourlyRate = 18.50;
const float milageCost = 0.67;
const float paintCost = 70.35;

// Default Constructor
House::House()
{
	setName("");
	setMaxRooms(0);
	setDistance(0);
}

// Multi-argument constructor
House::House(std::string n, int r, float d)
{
	setName(n);
	setMaxRooms(r);
	setDistance(d);
}

// Deconstructor
House::~House()
{
	// Nothing yet
}

// Get & Set Functions
void House::setName(std::string n)
{
	name = n;
}
std::string House::getName() const
{
	return name;
}

void House::setMaxRooms(int r)
{
	maxRooms = r;
}
int House::getMaxRooms() const
{
	return maxRooms;
}

void House::setDistance(float d)
{
	distance = d;
}
float House::getDistance() const
{
	return distance;
}

// Vector access

// Add room to vector
//  first check to make sure that the maximum 
//  number of rooms has not already been exceeded
void House::addRoom(float l, float w, float h, int n)
{
	// Create temp room
	Room r(l, w, h, n);

	// Add temp room to rooms vector
	rooms.push_back(r);
}

// Print function
void House::listRooms() const
{
	std::cout << "************************************************" << std::endl;
	std::cout << std::setw(20) << std::left << "Client Name: " << std::right << getName() << std::endl;
	std::cout << std::setw(20) << std::left << "Max Rooms: " << std::right << getMaxRooms() << std::endl;
	std::cout << std::setw(20) << std::left << "Distance: " << std::right << getDistance() << std::endl;
	std::cout << std::setw(20) << std::left << "Current Rooms: " << std::right << numOfRooms() << std::endl;

	// Error check to make sure rooms exist
	if (numOfRooms() > 0)
	{
		// Show data for each room in vector
		std::cout << std::endl << "------------- Room Details -------------" << std::endl;
		for (const auto& i : rooms)
		{
			i.showData();
		}
	}

	std::cout << "************************************************" << std::endl << std::endl;

}

// Vector size return
int House::numOfRooms() const
{
	return rooms.size();
}

// Print to file function
void House::printToFile() const
{
	std::ofstream outfile(getName() + ".txt");

	outfile << std::setprecision(2) << std::fixed;
	outfile << "************************************************" << std::endl;
	outfile << std::setw(30) << std::right << getName() << std::endl;
	outfile << std::setw(30) << std::right << "Final Invoice" << std::endl;
	outfile << "************************************************" << std::endl << std::endl;
	outfile << "WePaintHouses LLC" << std::endl;
	outfile << "1971 University Blvd" << std::endl;
	outfile << "Lynchburg, VA 24502" << std::endl;
	outfile << "4344554545" << std::endl;
	outfile << "wepainthousesllc.com" << std::endl << std::endl;

	outfile << "Billed to: " << getName() << std::endl << std::endl;

	outfile << "-----------------------------------------------------" << std::endl;
	outfile << std::setw(30) << std::right << "Labor Charges" << std::endl;
	outfile << std::setw(32) << std::right << "-----------------" << std::endl;

	// Calculate labor charges
	float laborCharges = numOfCoats() * hourlyRate;
	outfile << std::setw(10) << std::left << "Rooms" << std::right << "Number of coats" << std::setw(15) << "Hourly Rate" << std::setw(10) << "Total" << std::endl;
	outfile << std::setw(10) << std::left << numOfRooms() << std::right << numOfCoats() << std::setw(23) << hourlyRate << std::setw(17) << laborCharges << std::endl;
	outfile << std::endl << std::setw(30) << std::right << "Product Charges" << std::endl;
	outfile << std::setw(32) << std::right << "-----------------" << std::endl;
	outfile << std::setw(10) << std::left << "Room #" << std::right << "Paint Cans" << std::setw(18) << "Unit Cost" << std::setw(10) << "Amount" << std::endl;

	// Initialize product charges variable
	float productCharges = 0;
	for (int i = 0; i < numOfRooms(); i++)
	{
		// Calculate current loop iteration vector charge
		float tempCharge = (rooms.at(i).calculateGallonsNeeded() * paintCost);

		outfile << std::setw(10) << std::left << i + 1 << std::right << rooms.at(i).calculateGallonsNeeded() << std::setw(20) << paintCost << std::setw(14) << tempCharge << std::endl;

		// Add current vector iterations charge to total
		productCharges += tempCharge;
	}

	outfile << "Total Product Charges: " << std::setw(19) << "$" << productCharges << std::endl << std::endl;
	outfile << std::setw(30) << std::right << "Travel Charges" << std::endl;
	outfile << std::setw(32) << std::right << "-----------------" << std::endl;
	float travelCharges = distance * milageCost;
	outfile << std::setw(10) << std::left << "Mileage" << std::right << "Rate Per Mile" << std::setw(11) << "Total" << std::endl;
	outfile << std::setw(10) << std::left << getDistance() << std::right << milageCost << std::setw(16) << "$" << travelCharges << std::endl << std::endl;

	outfile << std::setw(29) << std::left << "Final Total: " << std::right << "$" << (laborCharges + productCharges + travelCharges) << std::endl;
	outfile << "-----------------------------------------------------" << std::endl << std::endl;
}

// Total amount of paint for the full house
float House::totalPaint() const
{
	float temp = 0;

	// For every room, add number of cans to temp total
	for (const auto& i : rooms)
	{
		temp += i.calculateGallonsNeeded();
	}
	return temp;
}

// Number of coats of paint in a single job
int House::numOfCoats() const
{
	int temp = 0;

	// For every room, add number of coats to temp total
	for (const auto& i : rooms)
	{
		temp += i.getNumOfCoats();
	}

	return temp;
}

// Number of paint cans needed for a single room in the vector at a given position
int House::numOfCans(int i) const
{
	// At index i in vector rooms, call number of gallons needed
	return rooms.at(i).calculateGallonsNeeded();
}

// Generate invoice for house
void House::generateInvoice() const
{
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "************************************************" << std::endl;
	std::cout << std::setw(30) << std::right << getName() << std::endl;
	std::cout << std::setw(30) << std::right << "Final Invoice" << std::endl;
	std::cout << "************************************************" << std::endl << std::endl;
	std::cout << "WePaintHouses LLC" << std::endl;
	std::cout << "1971 University Blvd" << std::endl;
	std::cout << "Lynchburg, VA 24502" << std::endl;
	std::cout << "4344554545" << std::endl;
	std::cout << "wepainthousesllc.com" << std::endl << std::endl;

	std::cout << "Billed to: " << getName() << std::endl << std::endl;

	std::cout << "-----------------------------------------------------" << std::endl;
	std::cout << std::setw(30) << std::right << "Labor Charges" << std::endl;
	std::cout << std::setw(32) << std::right << "-----------------" << std::endl;

	// Calculate labor charges
	float laborCharges = numOfCoats() * hourlyRate;
	std::cout << std::setw(10) << std::left << "Rooms" << std::right << "Number of coats" << std::setw(15) << "Hourly Rate" << std::setw(10) << "Total" << std::endl;
	std::cout << std::setw(10) << std::left << numOfRooms() << std::right << numOfCoats() << std::setw(23) << hourlyRate << std::setw(17) << laborCharges << std::endl;
	std::cout << std::endl << std::setw(30) << std::right << "Product Charges" << std::endl;
	std::cout << std::setw(32) << std::right << "-----------------" << std::endl;
	std::cout << std::setw(10) << std::left << "Room #" << std::right << "Paint Cans" << std::setw(18) << "Unit Cost" << std::setw(10) << "Amount" << std::endl;
	
	// Initialize product charges variable
	float productCharges = 0;
	for (int i = 0; i < numOfRooms(); i++)
	{
		// Calculate current loop iteration vector charge
		float tempCharge = (rooms.at(i).calculateGallonsNeeded() * paintCost);

		std::cout << std::setw(10) << std::left << i + 1 << std::right << rooms.at(i).calculateGallonsNeeded() << std::setw(20) << paintCost << std::setw(14) << tempCharge << std::endl;

		// Add current vector iterations charge to total
		productCharges += tempCharge;
	}

	std::cout << "Total Product Charges: " << std::setw(19) << "$" << productCharges << std::endl << std::endl;
	std::cout << std::setw(30) << std::right << "Travel Charges" << std::endl;
	std::cout << std::setw(32) << std::right << "-----------------" << std::endl;
	float travelCharges = distance * milageCost;
	std::cout << std::setw(10) << std::left << "Mileage" << std::right << "Rate Per Mile" << std::setw(11) << "Total" << std::endl;
	std::cout << std::setw(10) << std::left << getDistance() << std::right << milageCost << std::setw(16) << "$" << travelCharges << std::endl << std::endl;

	std::cout << std::setw(29) << std::left << "Final Total: " << std::right << "$" << (laborCharges + productCharges + travelCharges) << std::endl;
	std::cout << "-----------------------------------------------------" << std::endl << std::endl;
	std::cout << "Saved to file " << getName() << ".txt" << std::endl;
}