#include"Date.h"
#include<iostream>
using namespace std;

int main()
{
	Date today(2, 12, 2020);
	cout << today << endl;
	today++;
	cout << today << endl;
	today += 100;
	cout << today << endl;

	Date test(2, 29, 2020);
	test++;
	cout << test << endl;

	Date ny(12, 31, 2020);
	ny++;
	cout << ny << endl;

	Date test2(3, 1, 2020);
	test2--;
	cout << test2 << endl;
	return 0;
}