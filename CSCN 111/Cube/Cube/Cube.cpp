#include<iostream>

using namespace std;

int cube(int n);

int main()
{

	int initialValue;
	char myChar = 97;

	cin >> initialValue;
	cout << "The cube of " << initialValue << " is " << cube(initialValue) << endl;
	cout << "The memory location of initialValue is " << &initialValue << endl;
	cout << "The size of initialValue is " << sizeof(initialValue) << endl;
	cout << "myChar = " << int(myChar) << endl;

	return 0;
}


int cube(int n)
{
	return n * n * n;
}