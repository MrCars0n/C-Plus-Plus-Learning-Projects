#pragma once
#include <string>
#include <iostream>
class Shape {

public:
	Shape() = default;
	Shape(std::string name) { setName(name); }

	virtual ~Shape() {}

	virtual void draw() { std::cout << "I'm a shape." << std::endl; }
	void setName(std::string name) { shapeName = name; }
	std::string getName() { return shapeName; }
private:
	std::string shapeName;
};
