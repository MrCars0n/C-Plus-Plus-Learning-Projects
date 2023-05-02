// Department Class Declaration File
#pragma once

#include "Manager.h" // Manager object
#include "Employee.h" // Employee vector
#include <string> // String
#include <vector> // Employees vector

class Department
{
	// Overload the insertion operator to be able to print out a room object using <<
	friend std::ostream& operator<<(std::ostream&, const Department&);

public:
	// Default constructor
	Department();

	// Multiargument constructor
	Department(std::string, int, float, Manager);

	// Destructor
	~Department();

	// Get and set
	void setName(std::string);
	std::string getName() const;

	void setCapacity(int);
	int getCapacity() const;

	void setProductCost(float);
	float getProductCost() const;

	void setManager(Manager);
	Manager getManager() const;

	// Vector manipulation
	void addEmployee(Employee);
	void removeEmployee(int);
	int numOfEmployees() const;

	// Total Revenue for department
	float totalRevenue() const;

	// Cost of labor for department
	//  number of employees in the department multiplied by the base pay rate 
	//  (all painters are currently paid at the same rate) then adding the salary 
	//  of the manager for that department
	float costOfLabor() const;

	// Cost of travel
	//  adding up all employees’ miles and multiplying by the standard rate of ($0.87/mile)
	float costOfTravel() const;

	// Checks if inputted ID is already taken
	bool idTaken(int) const;

	// Average Employee Rating
	float avgEmployeeRating() const;

private:
	std::string name;
	int capacity;
	float productCost;
	Manager manager;
	std::vector<Employee> employees;
};