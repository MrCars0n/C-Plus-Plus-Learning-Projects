#pragma once
#include "Shape.h"
#include <iostream>
class Rectangle : public Shape {

public:
	Rectangle() = default;
	Rectangle(std::string name, int l, int w) :Shape(name)
	{
		setLength(l);
		setWidth(w);
	}
	void setLength(int l) { length = l; }
	void setWidth(int w) { width = w; }
	int getLength() { return length; }
	int getWidth() { return width; }
	void draw() override { std::cout << "I'm a rectangle." << std::endl; }
private:
	int length;
	int width;

};
