/*
	Carson Kramer
	10-30-19
	Period 5
	Common Math Functions
*/

#include<iostream>
using namespace std;

double slope(int, int, int, int);
bool isRightTriangle(int, int, int);

// Void functions do not have returns, they just do a task
void midpoint(int, int, int, int);

void starBox(int);

int main()
{
	int x1 = 5, y1 = -2, x2 = 7, y2 = -4;

	// Keep math functions returning a value. Don't just "cout" in functions
	cout << "The slope is " << slope(x1, y1, x2, y2) << endl;

	if (slope(x1, y2, x2, y2) < 0)
	{
		cout << "The slope is negative" << endl;
	}

	// isRightTriangle
	int a = 7, b = 24, c = 25;
	if (isRightTriangle(a, b, c) == true)
	{
		cout << "Yes, it's a right triangle" << endl;
	}

	// Void functions are just called by name
	midpoint(x1, y1, x2, y2);

	for(int x = 1; x <= 10; x++)
		starBox(x);

	return 0;
}

void starBox(int size)
{
	for (int v = 1; v <= size; v++)
	{
		for (int h = 1; h <= size; h++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

double slope(int x1, int y1, int x2, int y2)
{
	return (y2 - y1) / (x2 - x1);
}

bool isRightTriangle(int a, int b, int c)
{
	return a * a + b * b == c * c;
/*	if (a * a + b * b == c * c)
		return true;
	else
		return false;	*/
}

void midpoint(int x1, int y1, int x2, int y2)
{
	double mpX = (x1 + x2) / 2.0;
	double mpY = (y1 + y2) / 2.0;

	cout << "Midpoint = (" << mpX << ", " << mpY << ")" << endl;
}