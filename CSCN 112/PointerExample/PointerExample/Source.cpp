#include<iostream>

using namespace std;

int main()
{
	int* ptr1;
	int side;
	side = 99;
	ptr1 = &side;
	*ptr1 = 56;
	cout << side << ", " << *ptr1 << endl;
	return 0;
}