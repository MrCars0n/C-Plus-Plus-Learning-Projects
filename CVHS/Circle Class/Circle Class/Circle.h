// Circle Class
// Period 5
// Carson Kramer
// 1-29-20

#include<iostream>
using namespace std;

#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
class Circle
{
private:
	int x;
	int y;
	int radius;
public:
	Circle();
	Circle(int, int, int);
	void setX(int);
	void setY(int);
	void setRadius(int);
	int getX();
	int getY();
	int getRadius();
	double circumference();
	double area();
	void printEquation();
};

Circle::Circle()
{
	setX(0);
	setY(0);
	setRadius(1);
}

Circle::Circle(int x1, int y1, int radius1)
{
	setX(x1);
	setY(y1);
	setRadius(radius1);
}

void Circle::setX(int x1)
{
	x = x1;
}

void Circle::setY(int y1)
{
	y = y1;
}

void Circle::setRadius(int radius1)
{
	if (radius1 > 0)
	{
		radius = radius1;
	}
	else
	{
		radius = 1;
		cout << "Invalid radius = set value to 1" << endl;
	}
}

int Circle::getX()
{
	return x;
}

int Circle::getY()
{
	return y;
}

int Circle::getRadius()
{
	return radius;
}

double Circle::circumference()
{
	return 2 * 3.14 * getRadius();
}

double Circle::area()
{
	return 3.14 * getRadius() * getRadius();
}

void Circle::printEquation()
{
	cout << "(x" << ((getX() * -1) >= 0 ? "+" : "") << (getX() * -1)
		<< ")^2 + (y" << ((getY() * -1) >= 0 ? "+" : "")
		<< (getY() * -1) << ")^2 = " << getRadius() * getRadius() << endl;
}

#endif