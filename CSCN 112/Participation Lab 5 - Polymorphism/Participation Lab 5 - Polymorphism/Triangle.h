#pragma once

// This is the Triangle class that should be inheriting from the Shape class

#include "Shape.h"
#include <iostream>

class Triangle : public Shape
{
public:
	Triangle() = default;
	Triangle(std::string name, int side1, int side2) : Shape(name)
	{
		setSideOne(side1);
		setSideTwo(side2);
	}

	~Triangle() {}
	void setSideOne(int s) { side1 = s; }
	void setSideTwo(int s) { side2 = s; }
	int getSideOne() const { return side1; }
	int getWidth() const { return side2; }
	void draw() { std::cout << "I'm a Triangle." << std::endl; }
private:
	int side1;
	int side2;
};