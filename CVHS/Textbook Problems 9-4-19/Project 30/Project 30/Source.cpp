#include<iostream>
using namespace std;

int main()
{
	int weight, height, BMI;

	cout << "Enter your weight (in pounds), then your height (in inches): ";
	cin >> weight >> height;

	BMI = (weight * 703) / pow(height, 2);

	if (BMI < 18.5)
	{
		cout << "You're underweight" << endl;
	}
	else if (BMI < 25)
	{
		cout << "You're normal" << endl;
	}
	else if (BMI < 30) 
	{
		cout << "You're overweight" << endl;
	}
	else if (BMI > 30)
	{
		cout << "You're obese" << endl;
	}
	return 0;
}