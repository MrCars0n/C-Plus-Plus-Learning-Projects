#include <iostream>
#include <fstream>
#include <string>
#define NDEBUG // disables code in cassert and MUST be first
#include<cassert>

using namespace std;

int main()
{
	/*
	cout << "if statement demo" << endl;
	int x, y;
	cout << "Enter two integers: ";
	cin >> x >> y;
	if (x > y)
		cout << "Your first number is greater than your second number";
	else
		cout << "Your second number is greater than or equal to your first number.";
	cout << endl << endl;
	

	cout << "compound statement demo" << endl;
	int age;
	cout << "Enter your age: ";
	cin >> age;

	if (age >= 21)
	{
		cout << "You have every adult privlege." << endl << "You are no longer a minor." << endl;
	}
	else
	{
		cout << "You do not have all your adult privileges yet." << endl << "You are still a minor" << endl;
	}
	

	ifstream input;
	input.open("myfile.txt");
	if (!input)
	{
		cout << "Could not open myfile.txt" << endl;
		exit(1);
	}
	cout << "myfire.txt open successfully" << endl;
	

	cout << "conditional operator demo" << endl;
	int a, b;
	cout << "Enter two numbers: ";
	cin >> a >> b;
	cout << "The greater number is " << ((a >= b) ? a : b) << endl;
	cout << endl;
	

	cout << "swtich statement demo" << endl;
	int age2;
	cout << "Enter you age: ";
	cin >> age2;
	cout << "Chances are you are a ";
	switch (age2)
	{
	case 18:
		cout << "Freshman";
		break;
	case 19:
		cout << "Softmore";
		break;
	case 20:
		cout << "Junior";
		break;
	case 21:
		cout << "Senior";
		break;
	default:
		cout << "Non-college person";
		break;
	}
	*/

	//assert demo
	ifstream input2;
	input2.open("yourfile.txt");
	assert(input2); // any if statement can go in assert
	cout << "yourfile.txt opened successfully" << endl;

	return 0;
}