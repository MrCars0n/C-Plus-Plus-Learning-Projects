/*
	Carson Kramer
	9-17-2019
	Period 5
	While Loops (Total, Average, Largest, Smallest)
*/

#include<iostream>
using namespace std;

int main()
{
	int num;			// only need 1 variable for all 10
	int count = 1;		// control the loop, also used for average
	int total = 0;
	double average;

	int largest = INT_MIN;
	int smallest = INT_MAX;

	while(count <= 10)
	{
		cout << "Enter value " << count << ":";
		cin >> num;
		count++;
		total += num;

		if (num > largest)
			largest = num;
		if (num < smallest)
			smallest = num;
	}

	average = (double)total / (count - 1);

	cout << "The total is " << total << endl;
	cout << "The average is " << average << endl;
	cout << "The largest is " << largest << endl;
	cout << "The smallest is " << smallest << endl;

	return 0;
}