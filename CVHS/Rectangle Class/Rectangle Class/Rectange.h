#pragma once
#include<iostream>
using namespace std;

class Rectangle
{
private:
	double width;
	double length;
public:
	Rectangle();
	Rectangle(double, double);
	void setWidth(double);
	void setLength(double);
	double getWidth();
	double getLength();
	void print();
	double area();
	double perimeter();
};

Rectangle::Rectangle()
{
	setWidth(1);
	setLength(1);
}

Rectangle::Rectangle(double l, double w)
{
	setWidth(w);
	setLength(l);
}

double Rectangle::getWidth()
{
	return width;
}

double Rectangle::getLength()
{
	return length;
}

void Rectangle::setWidth(double w)
{
	if (w > 0)
	{
		width = w;
	}
	else
	{
		cout << "Invalid width - setting width to 1" << endl;
		width = 1;
	}
}

void Rectangle::setLength(double l)
{
	if (l > 0)
	{
		length = l;
	}
	else
	{
		cout << "Invalid length - setting length to 1" << endl;
		length = 1;
	}
}

void Rectangle::print()
{
	for (int r = 0; r < width; r++)
	{
		for (int c = 0; c < length; c++)
		{
			cout << char(254) << " ";
		}
		cout << endl;
	}

	/*
	for (int i = 0; i < length; i++)
	{
		cout << "=";
	}
	cout << endl;

	for (int r = 1; r < width-1; r++)
	{
		cout << "|";
		for (int c = 1; c < length - 1; c++)
		{
			cout << " ";
			//cout << char(254) << " ";
		}
		cout << "|" << endl;
	}

	for (int i = 0; i < length; i++)
	{
		cout << "=";
	}
	cout << endl;
	*/
}

double Rectangle::area()
{
	return length * width;
}

double Rectangle::perimeter()
{
	return 2 * (length + width);
}