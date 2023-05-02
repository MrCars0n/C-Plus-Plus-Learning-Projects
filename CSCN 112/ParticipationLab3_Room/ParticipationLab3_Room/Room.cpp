#include "Room.h"

Room::Room(float l, float w, float h, int coats)
{
	// Since using pointers, need to dynamically allocate space for each value
	length = new float;
	width = new float;
	height = new float;
	numCoats = new int;

	*length = l;
	*width = w;
	*height = h;
	*numCoats = coats;
}

// Add a definition for a copy constructor here!
Room::Room(const Room& templateRoom)
{
	length = new float;
	width = new float;
	height = new float;
	numCoats = new int;

	*length = templateRoom.getLength();
	*width = templateRoom.getWidth();
	*height = templateRoom.getHeight();
	*numCoats = templateRoom.getCoats();
}

Room::~Room()
{
	// No dynamically allocated memory has been created in this class, so there is nothing to deallocate here!
	delete length;
	delete width;
	delete height;
	delete numCoats;
}

void Room::setLength(float l)
{
	*length = l;
}

float Room::getLength() const
{
	return *length;
}

void Room::setWidth(float w)
{
	*width = w;
}

float Room::getWidth() const
{
	return *width;
}

void Room::setHeight(float h)
{
	*height = h;
}

float Room::getHeight() const
{
	return *height;
}

void Room::setCoats(int coats)
{
	*numCoats = coats;
}

int Room::getCoats() const
{
	return *numCoats;
}

void Room::printRoomInfo() const
{
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "*************************************" << std::endl;
	std::cout << std::right << std::setw(25) << "Room Details:" << std::endl;
	std::cout << std::left << std::setw(20) << "  Length:" << std::right << std::setw(15) << getLength() << std::endl;
	std::cout << std::left << std::setw(20) << "  Width:" << std::right << std::setw(15) << getWidth() << std::endl;
	std::cout << std::left << std::setw(20) << "  Height:" << std::right << std::setw(15) << getHeight() << std::endl;
	std::cout << std::left << std::setw(20) << "  Number of Coats:" << std::right << std::setw(15) << getCoats() << std::endl;
	std::cout << std::left << std::setw(20) << "  Volume:" << std::right << std::setw(15) << calcVolume() << std::endl;
	std::cout << std::left << std::setw(20) << "  Paintable Area:" << std::right << std::setw(15) << calcPaintableArea() << std::endl;
	std::cout << std::left << std::setw(20) << "  Number of Cans:" << std::right << std::setw(15) << calcNumCans() << std::endl;
	std::cout << "*************************************" << std::endl;

}

float Room::calcNumCans() const
{
	return (calcPaintableArea() / PAINT_FACTOR) * getCoats();
}

float Room::calcVolume() const
{
	return getLength() * getHeight() * getWidth();
}

float Room::calcPaintableArea() const
{
	return (2 * getHeight() * getLength()) + (2 * getHeight() * getWidth());
}

// Overloaded operators
// Addition - take one room and add value of another room to it
Room Room::operator+(const Room& rightSideRoom) const
{
	float tempL, tempW, tempH, tempNC;
	tempL = getLength() + rightSideRoom.getLength();
	tempW = getWidth() + rightSideRoom.getWidth();
	tempH = getHeight() + rightSideRoom.getHeight();
	tempNC = getCoats() + rightSideRoom.getCoats();

	return Room(tempL, tempW, tempH, tempNC);

}

// Overload addition for a room object and a float value
//  Not a member of the class, so don't need scope resolution operator
Room operator+(const Room& leftSideRoom, float addedValue)
{
	float tempL, tempW, tempH, tempNC;
	tempL = leftSideRoom.getLength() + addedValue;
	tempW = leftSideRoom.getWidth() + addedValue;
	tempH = leftSideRoom.getHeight() + addedValue;
	tempNC = leftSideRoom.getCoats() + addedValue;

	return Room(tempL, tempW, tempH, tempNC);
}

// Overload the insertion operator to be able to print out a room object using <<
//  Do not need scope resolution here bc function is not a member of the class, it's a friend
//  Remove friend keyword bc function cannot decalare friendship, class gives friendship
std::ostream& operator<<(std::ostream& out, const Room& inputRoom)
{
	out << std::fixed << std::setprecision(2);
	out << "*************************************" << std::endl;
	out << std::right << std::setw(25) << "Room Details:" << std::endl;
	out << std::left << std::setw(20) << "  Length:" << std::right << std::setw(15) << inputRoom.getLength() << std::endl;
	out << std::left << std::setw(20) << "  Width:" << std::right << std::setw(15) << inputRoom.getWidth() << std::endl;
	out << std::left << std::setw(20) << "  Height:" << std::right << std::setw(15) << inputRoom.getHeight() << std::endl;
	out << std::left << std::setw(20) << "  Number of Coats:" << std::right << std::setw(15) << inputRoom.getCoats() << std::endl;
	out << std::left << std::setw(20) << "  Volume:" << std::right << std::setw(15) << inputRoom.calcVolume() << std::endl;
	out << std::left << std::setw(20) << "  Paintable Area:" << std::right << std::setw(15) << inputRoom.calcPaintableArea() << std::endl;
	out << std::left << std::setw(20) << "  Number of Cans:" << std::right << std::setw(15) << inputRoom.calcNumCans() << std::endl;
	out << "*************************************" << std::endl;

	return out;
}

// Overload the extraction operator to be able to bring in a room using >>
std::istream& operator>>(std::istream& in, Room& outPutObject)
{
	float tempL, tempW, tempH;
	int tempCoats;

	in >> tempL >> tempW >> tempH >> tempCoats;
	outPutObject.setLength(tempL);
	outPutObject.setWidth(tempW);
	outPutObject.setHeight(tempH);
	outPutObject.setCoats(tempCoats);


	return in;
}

// Pre-increment operator
Room Room::operator++()
{
	// I need to increment each private member variable of the object
	*length = ++(*length);
	*width = ++(*width);
	*height = ++(*height);
	*numCoats = ++(*numCoats);

	// At the end of this function, I need to return the object itself
	// *this uses the this pointer, which points to the current object and dereferences it
	return *this;
}

// Post-increment operator
Room Room::operator++(int)
{
	// I need to increment each private member variable of the object
	*length = (*length)++;
	*width = (*width)++;
	*height = (*height)++;
	*numCoats = (*numCoats)++;

	// At the end of this function, I need to return the object itself
	// *this uses the this pointer, which points to the current object and dereferences it
	return *this;
}

// Assignment operator
const Room& Room::operator=(const Room& rightSideRoom)
{
	if (this != &rightSideRoom) // avoid self-assignment
	{
		// Set value stored in address that length points to equal to value
		//  stored in the address that rightSideRoom's length points to]
		//  By default, = operator takes length = rightSideRoom.length; resulting in shallow copy
		*length = rightSideRoom.getLength();
		*width = rightSideRoom.getWidth();
		*height = rightSideRoom.getHeight();
		*numCoats = rightSideRoom.getCoats();
	}

	return *this;
}