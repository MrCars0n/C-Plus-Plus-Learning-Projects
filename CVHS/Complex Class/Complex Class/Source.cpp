// Complex Number
// 1-27-20

#include"Complex.h"
#include<iostream>
using namespace std;

int main()
{
	Complex c1(4, 5);	// 4 + 5i
	Complex c2(2, 3);	// 2 + 3i

	c1.print();
	c2.print();

	Complex sum;
	sum = sum.add(c1, c2);
	sum.print();

	return 0;
}