#include<iostream>
#include"Rectange.h"
using namespace std;

int main()
{
	Rectangle r(5, 5);
	r.print();
	cout << "Area = " << r.area() << endl;
	cout << "Perimeter = " << r.perimeter() << endl;
	return 0;
}