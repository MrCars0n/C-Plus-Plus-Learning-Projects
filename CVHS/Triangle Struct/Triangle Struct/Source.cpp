// Triangle Header Test File

#include<iostream>
#include<string>
#include"Triangle.h"

using namespace std;

int main()
{
	Triangle t1;
	cin >> t1.side1 >> t1.side2 >> t1.side3;

	cout << "Area = " << area(t1) << endl;
	cout << "Perimeter = " << perimeter(t1) << endl;
	cout << "Type = " << triType(t1) << endl;

	return 0;
}