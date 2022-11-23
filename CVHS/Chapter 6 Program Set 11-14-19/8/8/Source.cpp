// Program 8

#include<iostream>
using namespace std;

bool isLetter(char);

int main()
{
	char num;

	cin >> num;

	if (isLetter(num))
		cout << "Letter" << endl;
	else
		cout << "Not Letter" << endl;

	return 0;
}

bool isLetter(char character)
{
	int num = (int)character;
	return ((num >= 65) && (num <= 90)) || ((num >= 97) && (num <= 122)); 
	//return isalnum(character);
}