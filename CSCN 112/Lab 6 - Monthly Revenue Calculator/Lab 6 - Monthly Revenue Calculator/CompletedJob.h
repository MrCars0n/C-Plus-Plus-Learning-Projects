// CompletedJob Class Declaration File
#pragma once

#include <string> // string

// Define CompletedJob class
class CompletedJob
{
public:
	// Default Constructor
	CompletedJob();

	// Destructor
	~CompletedJob();

	// Get and set for each variable
	void setClientName(std::string);
	std::string getClientName() const;

	void setInvoiceNumber(int);
	int getInvoiceNumber() const;

	void setRoomsPainted(int);
	int getRoomsPainted() const;

	void setNumOfPaintCans(int);
	int getNumOfPaintCans() const;

	void setLaborCharges(float);
	float getLaborCharges() const;

	void setProductCharges(float);
	float getProductCharges() const;

	void setMileage(float);
	float getMileage() const;

	void setTravelCharges(float);
	float getTravelCharges() const;

	// Total revenue - sum of labor, product, and travel charges
	float totalRevenue() const;
private:
	std::string clientName;
	int invoiceNumber, roomsPainted, numOfPaintCans;
	float laborCharges, productCharges, mileage, travelCharges;
};