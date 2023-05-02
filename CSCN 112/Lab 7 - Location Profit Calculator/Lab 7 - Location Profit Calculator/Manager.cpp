// Manager Class Implementation File

#include "Manager.h"

// Overload the insertion operator to be able to print out a room object using <<
std::ostream& operator<<(std::ostream& out, const Manager& inputManager)
{
	out << "Name: " << inputManager.getFirstName() << " " << inputManager.getLastName() << std::endl;
	out << "Title: " << inputManager.getTitle() << std::endl;
	out << "Employee ID: " << inputManager.getID() << std::endl;
	out << "Birth Date: " << inputManager.getBirthDate() << std::endl;
	out << "Date Hired: " << inputManager.getDateHired() << std::endl;
	out << "Promotion Date: " << inputManager.getPromotionDate() << std::endl;
	out << "Salary: $" << inputManager.getSalary() << std::endl;

	return out;
}

// Default constructor
Manager::Manager()
{
	Date d(0, 0, 0);

	setTitle("");
	setID(0);
	setDateHired(d);
	setPromotionDate(d);
	setSalary(0);
}

// Multiargument constructor
Manager::Manager(std::string t, int i, Date h, Date p, float s)
{
	setTitle(t);
	setID(i);
	setDateHired(h);
	setPromotionDate(p);
	setSalary(s);
}

// Destructor
Manager::~Manager()
{
}

// Get and set
void Manager::setTitle(std::string t)
{
	title = t;
}
std::string Manager::getTitle() const
{
	return title;
}

void Manager::setID(int i)
{
	ID = i;
}
int Manager::getID() const
{
	return ID;
}

void Manager::setDateHired(Date d)
{
	dateHired = d;
}
Date Manager::getDateHired() const
{
	return dateHired;
}

void Manager::setPromotionDate(Date d)
{
	promotionDate = d;
}
Date Manager::getPromotionDate() const
{
	return promotionDate;
}

void Manager::setSalary(float s)
{
	salary = s;
}
float Manager::getSalary() const
{
	return salary;
}

// Assignment operator
const Manager& Manager::operator=(const Manager &rightSideManager)
{
	if (this != &rightSideManager) // avoid self-assignment
	{
		// Set value stored in address that length points to equal to value
		//  stored in the address that rightSideRoom's length points to]
		//  By default, = operator takes length = rightSideRoom.length; resulting in shallow copy
		setFirstName(rightSideManager.getFirstName());
		setLastName(rightSideManager.getLastName());
		setTitle(rightSideManager.getTitle());
		setID(rightSideManager.getID());
		setBirthDate(rightSideManager.getBirthDate());
		setDateHired(rightSideManager.getDateHired());
		setPromotionDate(rightSideManager.getPromotionDate());
		setSalary(rightSideManager.getSalary());
	}

	return *this;
}