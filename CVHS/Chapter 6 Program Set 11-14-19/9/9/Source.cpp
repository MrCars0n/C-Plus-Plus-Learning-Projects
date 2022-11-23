// Program 9

#include<iostream>
using namespace std;

double areaPolygon(int, int);
double cotan(double);

int main()
{
	double sidesNum, sidesLen;
	cin >> sidesNum >> sidesLen;

	cout << "Area of Polygon = " << areaPolygon(sidesNum, sidesLen) << endl;

	return 0;
}

// a = side length
// n = side number
double areaPolygon(int sidesLen, int sidesNum)
{
	//return (1 / 4) * n * pow(a, 2) * cotan(3.1415 / n);
	double apothem = (sidesLen / 2) / tan(((360 / sidesNum) / 2) * (3.1415 / 180));
	double perimeter = sidesNum * sidesLen;
	return (apothem * perimeter) / 2;
}

double cotan(double i)
{
	return(1 / tan(i));
}