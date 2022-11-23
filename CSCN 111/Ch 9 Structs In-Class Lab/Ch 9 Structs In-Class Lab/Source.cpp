#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

// Lab 1 - Struct declaration
struct StudentType {
	string firstName;
	string lastName;
	char courseGrade = 'U';
	double GPA = 0.0;
};

struct ListType {
	const static int ARRAY_SIZE = 1000;
	int listLength = 0;
	int listElem[ARRAY_SIZE];
};

void printStudent(StudentType student);
void printList(ListType list);

int main()
{
	StudentType newStudent;

	// Lab 2
	cout << endl << "Lab 2 Code" << endl;
	newStudent.firstName = "John";
	newStudent.lastName = "Brown";
	newStudent.GPA = 3.5;
	newStudent.courseGrade = 'A';
	cout << left << setw(15) << "First Name: " << newStudent.firstName << endl
		<< setw(15) << "Last Name: " << newStudent.lastName << endl
		<< setw(15) << "GPA: " << newStudent.GPA << endl
		<< setw(15) << "Grade: " << newStudent.courseGrade << endl;

	// Lab 3
	cout << endl << "Lab 3 Code" << endl;
	StudentType student = newStudent;
	cout << left << setw(15) << "First Name: " << student.firstName << endl
		<< setw(15) << "Last Name: " << student.lastName << endl
		<< setw(15) << "GPA: " << student.GPA << endl
		<< setw(15) << "Grade: " << student.courseGrade << endl;

	// Lab 4 - passing a struct
	cout << endl << "Lab 4 Code" << endl;
	cout << "Printing newStudent:\t";
	printStudent(newStudent);
	cout << "Printing student:\t";
	printStudent(student);

	// Lab 5 Array in a struct
	cout << endl << "Lab 5 Code" << endl;
	ListType intList;
	intList.listElem[intList.listLength++] = 12;
	intList.listElem[intList.listLength++] = 37;
	printList(intList);
}


void printStudent(StudentType student)
{
	cout << student.firstName << ' ' << student.lastName
		<< ' ' << student.courseGrade << ' ' << student.GPA << endl;
}

void printList(ListType list)
{
	cout << "Printing the list" << endl;
	for (int i = 0; i < list.listLength; i++)
	{
		cout << "Item " << i << " = " << list.listElem[i] << endl;
	}
}