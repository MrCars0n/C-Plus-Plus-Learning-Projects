#pragma once
#include<iostream>
using namespace std;

struct Rectangle
{
	int length, width;
};

int perimeter(Rectangle r)
{
	return 2 * r.length + 2 * r.width;
}

void print(Rectangle r)
{
	for (int v = 1; v <= r.length; v++)
	{
		for (int h = 1; h <= r.width; h++)
		{
			cout << (char)219;
		}
		cout << endl;
	}
}

bool isSquare(Rectangle r)
{
	return r.length == r.width;
}

int area(Rectangle r)
{
	return r.length * r.width;
}