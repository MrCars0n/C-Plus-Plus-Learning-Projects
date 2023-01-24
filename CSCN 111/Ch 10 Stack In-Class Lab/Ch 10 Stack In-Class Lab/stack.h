#pragma once
#include<string>

const int MAX_SIZE = 100;

// A stack of strings
class Stack {
public:
	// Stack operations
	void Push(std::string s); // Adds 's' to the top of the stack

	std::string Pop(); // Returns the item at the top of the stack and removes it from the stack

	std::string Peek() const; // Returns the item at the top of the stack without removing it

	int Size() const; // Returns the size of the stack

	bool isEmpty() const; // Returns true if the stack is empty, false otherwise

	bool isFull() const; // Returns true if the stack is full, false otherwise

	int Capacity() const; // Returns the capacity of the stack

	//Stack();  // Default constructor

	//Stack(int cap = MAX_SIZE // User defines the stack capacity

	//static const int MAX_SIZE = 1000;
private:
	int capacity = MAX_SIZE; // capacity of the stack
	std::string stack[MAX_SIZE]; // stack data member
	int size = 0; // current size of the stack
};