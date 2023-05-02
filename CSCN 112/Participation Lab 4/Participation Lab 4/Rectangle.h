// Carson Kramer
// Participation Lab4 
// Rectangle class header file

#pragma once
#include <iostream>
#include "NegativeNumberException.h"

// Change this to a class template definition!  (so that we can use ints, doubles, or floats) 
template <class dType> class Rectangle
{
	// Overload the << operator to print out each rectangle's dimensions 

public:
	Rectangle();
	~Rectangle();
	void setLength(dType);
	dType getLength() const;
	void setWidth(dType);
	dType getWidth() const;
	void showData() const;
private:
	dType calcPerimeter() const;
	dType calcArea() const;
	dType length;
	dType width;
};

// You will also need to change all of these function definitions to function templates! 

template <class dType> Rectangle<dType>::Rectangle()
{
	length = 0;
	width = 0;
}

template <class dType> Rectangle<dType>::~Rectangle() {}

template <class dType> dType Rectangle<dType>::calcPerimeter() const
{
	return ((2 * length) + (2 * width));
}

template <class dType> dType Rectangle<dType>::calcArea() const
{
	return (length * width);
}

template <class dType> void Rectangle<dType>::setLength(dType input)
{
	if (input > 0)
		length = input;
	else
		length = 0;
}

template <class dType> dType Rectangle<dType>::getLength() const
{
	return length;
}

template <class dType> void Rectangle<dType>::setWidth(dType input)
{
	if (input > 0)
		width = input;
	else
		width = 0;
}

template <class dType> dType Rectangle<dType>::getWidth() const
{
	return width;
}

template <class dType> void Rectangle<dType>::showData() const
{
	std::cout << "Side Length: " << length << std::endl;
	std::cout << "Side Width: " << width << std::endl;
	std::cout << "Perimeter: " << Rectangle<dType>::calcPerimeter() << std::endl;
	std::cout << "Area: " << Rectangle<dType>::calcArea() << std::endl;
	std::cout << "***************" << std::endl;
}
