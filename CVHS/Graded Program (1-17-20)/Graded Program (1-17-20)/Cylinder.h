#pragma once
#include<iostream>
using namespace std;

struct Cylinder
{
	double height, radius;
};

// A=2(Pi)rh+2(Pi)r^2
double area(Cylinder c)
{
	return (2 * 3.14 * c.radius * c.height) + (2 * 3.14 * c.radius * c.radius);
}

//V=(Pi)(r^2)h
double volume(Cylinder c)
{
	return 3.14 * c.radius * c.radius * c.height;
}