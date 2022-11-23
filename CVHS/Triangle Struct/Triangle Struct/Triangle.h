#pragma once
#include<iostream>
#include<string>
using namespace std;

struct Triangle
{
	double side1, side2, side3;
};

double perimeter(Triangle t)
{
	return t.side1 + t.side2 + t.side3;
}

double area(Triangle t)
{
	double s = perimeter(t) * .5;

	return sqrt(s * (s - t.side1) * (s - t.side2) * (s - t.side3));
}

string triType(Triangle t)
{
	if (t.side1 == t.side2 && t.side2 == t.side3)
		return "Equilateral";
	else if (t.side1 == t.side2 || t.side1 == t.side3 || t.side2 == t.side3)
		return "Isosceles";
	else
		return"Scalene";
}