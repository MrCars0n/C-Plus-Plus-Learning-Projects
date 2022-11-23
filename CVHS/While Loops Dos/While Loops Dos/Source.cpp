/*
	Carson Kramer
	9-19-19
	Period 5
	While Loops Example 2
*/

#include<iostream>
using namespace std;

int main()
{
	int num, count = 0, total = 0, largest = INT_MIN, smallest = INT_MAX;
	double average;

	// We ask the sentinel queestion first before the lop conditions
	cout << "Please enter a number (-1 to quit): ";
	cin >> num;

	while (num != -1) 
	{
		count++;
		total += num;

		if (num > largest)
			largest = num;
		if (num < smallest)
			smallest = num;

		// At bottom of loop repeat question
		cout << "Please enter a number (-1 to quit): ";
		cin >> num;
	}

	if (count != 0)
	{
		average = (double)total / count;
		cout << "The total is = " << total << endl;
		cout << "The average is = " << average << endl;
		cout << "The largest is = " << largest << endl;
		cout << "The smallest is = " << smallest << endl;
	}
	else
	{
		cout << "There are no numbers" << endl;
	}

	return 0;
}