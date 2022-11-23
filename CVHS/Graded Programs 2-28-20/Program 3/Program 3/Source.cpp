#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main()
{
	srand(time(0));
	// Use % to scale a random number down to the range you want
	int num1 = 0, num2 = 0, count = 1, total = 0;

	while (count < 6)
	{
		num1 = rand() % 6 + 1;
		num2 = rand() % 6 + 1;

		total = num1 + num2;
		cout << num1 << " + " << num2 << " = " << total;
		
		if (total == 7)
		{
			cout << "\tSEVEN!\tCount = " << count;
			count++;
		}
		cout << endl;
	}

	//cout << rand() % 6 + 1 << endl;

	// rand() % range + lowest number -- range = (high - low) + 1
	return 0;
}