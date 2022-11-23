#pragma once
#include<iostream>
using namespace std;

struct Sphere
{
	double radius;
};

// A=4(Pi)r^2
double area(Sphere s)
{
	return 4 * 3.14 * s.radius * s.radius;
}

// V=(4/3)(Pi)(r^3)
double volume(Sphere s)
{
	return (4 * 3.14 * s.radius * s.radius * s.radius) / 3;
}