// CompletedJob Class Implementation File
#include "CompletedJob.h"
#include <iostream> // cout

//Default Constructor
CompletedJob::CompletedJob()
{
	setClientName("Client");
	setInvoiceNumber(0);
	setRoomsPainted(0);
	setNumOfPaintCans(0);
	setLaborCharges(0);
	setProductCharges(0);
	setMileage(0);
	setTravelCharges(0);
}

// Destructor
CompletedJob::~CompletedJob()
{
	// Nothing here yet
}

// Get and set for each variable
void CompletedJob::setClientName(std::string name)
{
	clientName = name;
}
std::string CompletedJob::getClientName() const
{
	return clientName;
}

void CompletedJob::setInvoiceNumber(int num)
{
	if (num >= 0)
	{
		invoiceNumber = num;
	}
	else // Error check negative
	{
		std::cout << "Invoice Number entered is not positive. Setting to default value of \"0\"" << std::endl;
		invoiceNumber = 0;
	}
}
int CompletedJob::getInvoiceNumber() const
{
	return invoiceNumber;
}

void CompletedJob::setRoomsPainted(int rooms)
{
	if (rooms >= 0)
	{
		roomsPainted = rooms;
	}
	else // Error check negative
	{
		std::cout << "Rooms painted entered is not positive. Setting to default value of \"0\"" << std::endl;
		roomsPainted = 0;
	}
}
int CompletedJob::getRoomsPainted() const
{
	return roomsPainted;
}

void CompletedJob::setNumOfPaintCans(int num)
{
	if (num >= 0)
	{
		numOfPaintCans = num;
	}
	else // Error check negative
	{
		std::cout << "Number of paint cans entered is not positive. Setting to default value of \"0\"" << std::endl;
		numOfPaintCans = 0;
	}
}
int CompletedJob::getNumOfPaintCans() const
{
	return numOfPaintCans;
}

void CompletedJob::setLaborCharges(float labor)
{
	if (labor >= 0)
	{
		laborCharges = labor;
	}
	else // Error check negative
	{
		std::cout << "Labor charges entered is not positive. Setting to default value of \"0\"" << std::endl;
		laborCharges = 0;
	}
}
float CompletedJob::getLaborCharges() const
{
	return laborCharges;
}

void CompletedJob::setProductCharges(float prod)
{
	if (prod >= 0)
	{
		productCharges = prod;
	}
	else // Error check negative
	{
		std::cout << "Product charges entered is not positive. Setting to default value of \"0\"" << std::endl;
		productCharges = 0;
	}
}
float CompletedJob::getProductCharges() const
{
	return productCharges;
}

void CompletedJob::setMileage(float mil)
{
	if (mil >= 0)
	{
		mileage = mil;
	}
	else // Error check negative
	{
		std::cout << "Mileage entered is not positive. Setting to default value of \"0\"" << std::endl;
		mileage = 0;
	}
}
float CompletedJob::getMileage() const
{
	return mileage;
}

void CompletedJob::setTravelCharges(float trav)
{
	if (trav >= 0)
	{
		travelCharges = trav;
	}
	else // Error check negative
	{
		std::cout << "Travel Charges entered is not positive. Setting to default value of \"0\"" << std::endl;
		travelCharges = 0;
	}
}
float CompletedJob::getTravelCharges() const
{
	return travelCharges;
}

// Total revenue - sum of labor, product, and travel charges
float CompletedJob::totalRevenue() const
{
	return getLaborCharges() + getProductCharges() + getTravelCharges();
}