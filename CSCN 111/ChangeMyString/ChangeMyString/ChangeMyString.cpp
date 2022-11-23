#include<iostream>
#include<string>

using namespace std;

// Prototypes
void changeMyString1(string);
void changeMyString2(string&);

int main()
{
	string s = "This is my original string.";

	cout << s << endl;
	changeMyString1(s);
	cout << s << endl;
	changeMyString2(s);
	cout << s << endl;

	// Close Program
	return 0;
}

void changeMyString1(string a)
{
	a = "This is my changed string";
}

void changeMyString2(string& a)
{
	a = "This is my changed string";
}