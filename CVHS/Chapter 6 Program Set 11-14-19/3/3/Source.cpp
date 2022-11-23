#include<iostream>
using namespace std;

bool multiples(int, int);

int main()
{
	int multiple1, multiple2;

	cin >> multiple1 >> multiple2;
	
	if (multiples(multiple1, multiple2))
		cout << "Multiples" << endl;
	else
		cout << "Not Multiples" << endl;

	return 0;
}

bool multiples(int multiple1, int multiple2)
{
	return multiple1 % multiple2 == 0 || multiple2 % multiple1 == 0;
}