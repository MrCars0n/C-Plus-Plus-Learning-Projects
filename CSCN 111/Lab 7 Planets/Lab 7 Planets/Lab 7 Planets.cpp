//Lab 7 Planets -- Write a C++ program that asks the user to enter his or her weight and the name of a planet using functions, a switch statement, and enum types for planets.
//CSCN 111-03
//Public Domain


//Include statements
#include <iostream>
#include <string>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
enum Planets { MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};

//Function prototypes
void wait();
float calculateWeight(float, string);
bool validPlanet(string, Planets&);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Carson Kramer -- Lab 7" << endl << endl;

	//Variable declarations
	float weight = 0;
	string planet = "";

	//Program 

	do
	{
	cout << "Enter your weight (in lbs): ";
	cin >> weight;
	cout << endl << "Enter the planet (ex. Earth): ";
	cin >> planet;
	cout << endl;
	} while (calculateWeight(weight, planet) == -1);
	// Checked for valid planet in calculateWeight() function to also check for valid weight

	cout << "Your weight on " << planet << " would be " << calculateWeight(weight, planet) << "lbs." << endl;

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

//Function Definitions
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer 
	}
	cout << "Press the Enter key to continue ... ";
	cin.get();
}

float calculateWeight(float weight, string planet)
{
	Planets plan;
	if (validPlanet(planet, plan) && weight > 0)
	{
		switch (plan)
		{
		case 0: // Mercury
			return weight * 0.4155;
		case 1: //Venus
			return weight * 0.8975;
		case 2: //Earth
			return weight * 1.0;
		case 3: //Moon
			return weight * 0.166;
		case 4: //Mars
			return weight * 0.3507;
		case 5: //Jupiter
			return weight * 2.5374;
		case 6: //Saturn
			return weight * 1.0677;
		case 7: //Uranus
			return weight * 0.8947;
		case 8: //Neptune
			return weight * 1.1794;
		case 9: //Pluto
			return weight * 0.0899;
		}
	}
	return -1;
}

bool validPlanet(string str, Planets& plan)
{
	string planetNames[10] = { "Mercury", "Venus", "Earth", "Moon", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto" };
	for (int i = 0; i < 10; i++)
	{
		if (str == planetNames[i])
		{
			plan = static_cast<Planets>(i);
			return true;
		}
	}
	return false;
}
