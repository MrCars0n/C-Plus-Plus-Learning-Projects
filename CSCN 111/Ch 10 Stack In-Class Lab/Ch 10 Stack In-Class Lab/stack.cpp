#include"stack.h"
#include<string>
#include<iostream>
using namespace std;

bool Stack::isFull() const {
	if (size < capacity)
		return false;
	else
		return true;
	//return (size >= capacity);
}