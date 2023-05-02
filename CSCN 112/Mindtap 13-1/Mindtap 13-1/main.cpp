#include<iostream>
#include"rectangleType.h"
using namespace std;
int main()
{
	rectangleType ob1(20, 30), ob2(12, 15);
	ob1++;
	++ob2;
	ob1.show();
	ob2.show();
	rectangleType ob3 = ob1 - ob2;
	ob3.show();
	cout << "ob1 is less than ob2:" << std::boolalpha << (ob1 < ob2) << endl;
	cout << "ob1 is greater than ob2:" << std::boolalpha << (ob1 > ob2) << endl;
	cout << "ob1 is less than or equal to ob2:" << std::boolalpha << (ob1 <= ob2) << endl;
	cout << "ob1 is greater than or equal to ob2:" << std::boolalpha << (ob1 >= ob2) << endl;
	cout << "ob1 is equal to ob2:" << std::boolalpha << (ob1 == ob2) << endl;
	cout << "ob1 is not equal to ob2:" << std::boolalpha << (ob1 != ob2) << endl;
}
