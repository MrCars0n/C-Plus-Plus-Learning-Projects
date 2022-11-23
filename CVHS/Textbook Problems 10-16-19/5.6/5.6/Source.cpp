#include<iostream>
using namespace std;

int main()
{
	double sum = 0, num1, count = 0;
	double average = 0;
	while (true)
	{
		cin >> num1;
		if (num1 == 9999)
			break;
		sum += num1;
		count++;
	}
	average = sum / count;

	cout << "Average = " << average << endl;
	return 0;
}