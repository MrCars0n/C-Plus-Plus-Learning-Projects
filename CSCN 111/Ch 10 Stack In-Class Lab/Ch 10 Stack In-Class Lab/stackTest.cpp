#include"stack.h"
#include<string>
#include<iostream>
using namespace std;

int main()
{
	// Instantiate a Stack object
	Stack myStack;

	// Test Stack methods
	// Test isFull() method
	if (myStack.isFull())
		cout << "The stack is full";
	else
		cout << "The stack is not full";
	cout << endl;
}