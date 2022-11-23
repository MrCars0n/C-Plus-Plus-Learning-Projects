#include<iostream>
using namespace std;

int main()
{
	int num, total = 0;
	cin >> num;

	for (int x = 0; x <= num; x++)
	{
		total += x;
	}

	cout << total << endl;

	return 0;
}