#include<iostream>
using namespace std;

int main()
{
	char char1;

	cout << "Enter a letter: ";
	cin >> char1;

	cout << static_cast<int>(char1) << endl;
	return 0;
}