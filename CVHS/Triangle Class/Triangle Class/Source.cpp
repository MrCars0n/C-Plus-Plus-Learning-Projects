// Triangle Class Test
// Period 5
// Carson Kramer
// 1-28-20
#include<iostream>
#include"Triangle.h"
using namespace std;

int main()
{
	Triangle t(2, 1, 2);

	t.printType();
	cout << "Area = " << t.area() << endl;
	cout << "Perimeter = " << t.perimeter() << endl;

	return 0;
}