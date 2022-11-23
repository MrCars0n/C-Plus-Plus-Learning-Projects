/*
	Carson Kramer
	8/29/2019
	Period 5
	Math and If Statements
*/

#include<iostream>
using namespace std;

int main()
{
	
	// Declaring variables (giving name & type); Must give variables values
	int num1, num2, sum, diff, prod, quot;
	
	// Input
	cout << "Please enter two numbers: ";
	cin >> num1 >> num2;

	// Use values
	sum = num1 + num2;
	diff = num1 - num2;
	prod = num1 * num2;
	quot = num1 / num2;

	// Display output
	cout << "The sum is: " << sum << endl;
	cout << "The difference is: " << diff << endl;
	cout << "The product is: " << prod << endl;
	cout << "The quotient is: " << quot << endl;

	// No power operator, "pow" used
	cout << "The power is: " << pow(num1, num2) << endl;

	// Modulus (remainder), symbol = %
	if (num1 % 2 == 0) {
		cout << num1 << " is even" << endl;
	}
	else {
		cout << num1 << " is odd" << endl;
	}
	
	/* If statements - evaluate booleans; 
			6 comparison symbols are < > <= >=
			== (comparison equals - double equal sign)		!= (not equal to)
			"and" = &&		"or" = ||
			if/else - true or false
			if/else if/else - conditions with multiple possibilities
			nest if statements (if inside an if)
	*/		

	int testNum;
	cout << "Please enter a number to test: ";
	cin >> testNum;

	if (testNum > 0 && testNum % 2 == 0) {
		cout << "Your number is positive and even" << endl;
	}
	else if(testNum == 0){
		cout << "Your number is zero!" << endl;
	}

	return 0;
}				