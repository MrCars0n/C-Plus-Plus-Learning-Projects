// Participation Lab 3
// Room class

#include <iostream>
#include "Room.h"
#include <fstream>

using namespace std;

int main()
{
	cout << "CSCN 112-001  Spring 2023   Participation Lab 3" << endl << endl;

	Room room1(10, 10, 10, 5);
	//room1.printRoomInfo();
	cout << room1;

	Room room2(1, 1, 1, 1);
	//room2.printRoomInfo();
	cout << room2;

	system("pause");
	system("CLS");

	Room room3;
	room3 = room1 + room2;
	//room3.printRoomInfo();
	cout << room3;

	Room room4(5, 5, 5, 5);
	room4 = room4 + 2.2;
	//room4.printRoomInfo();
	cout << room4;

	// Prove to print to file
	ofstream outFile;
	outFile.open("TestPrint.txt");
	outFile << room4;
	outFile.close();

	// Practice bringing a room in from the user
	Room room5;
	cout << "Please enter the length, width, height, and number of coats: " << endl;
	cin >> room5;
	cout << room5;
	++room5;
	system("pause");
	system("CLS");

	cout << "The values of room5 are now: " << endl << room5 << endl << endl;

	room5++;
	cout << "The values of room5 are now: " << endl << room5 << endl << endl;

	// Create a room object using cin >> room

	// Print out that object using cout << room

	// Set one object equal to another object using the copy constructor

	// Set one object equal to another object using the equivalence operator

	// Increment your room using room++

	// Increment your room using ++ room

	// Add one room to another room

	// Subtract one room from another room

	// Check whether one room is equal to another room


	system("pause");
	return 0;
}