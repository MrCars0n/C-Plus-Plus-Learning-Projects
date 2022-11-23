// Structures (Structs in C++)
// 1-9-20

#include<iostream>
#include"Rectangle.h"
using namespace std;

int main()
{
	Rectangle r1;
	r1.length = 3;
	r1.width = 5;

	cout << area(r1) << endl;
	cout << perimeter(r1) << endl;
	print(r1);

	return 0;
}