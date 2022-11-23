// Big Integer test File
#include"Bigint.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	BigInt num1("123456789123456789");
	cout << num1 << endl;

	BigInt num2("123456789");
	cout << num2 << endl;

	BigInt sum = num1 + num2;
	cout << sum << endl;

	BigInt diff = num1 - num2;
	cout << diff << endl;
	return 0;
}