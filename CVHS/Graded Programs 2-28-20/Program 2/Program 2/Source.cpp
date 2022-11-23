#include<iostream>
using namespace std;

int main()
{
	int num, arr[4];

	cin >> num;

	for(int x = 3; x >= 0; x--)
	{
		arr[x] = num % 10;
		num /= 10;
	}

	int numCopy = arr[0];

	arr[0] = arr[3];
	arr[3] = numCopy;


	for (int x = 0; x < 4; x++)
	{
		cout << arr[x];
	}
	cout << endl;

	return 0;

}