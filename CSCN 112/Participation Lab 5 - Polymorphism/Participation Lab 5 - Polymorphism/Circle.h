#pragma once
#include "Shape.h"

class Circle : public Shape
{
public:
	Circle() = default;
	void draw() { std::cout << "I am a circle" << std::endl; }

private:
	int radius;

};
