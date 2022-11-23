#include<iostream>

using namespace std;

// Starts at 0 unless specified
enum Sports { BASKETBALL = 1, FOOTBALL, HOCKEY, BASEBALL, SOCCER, VOLLEYBALL };

Sports mySport(int s = 0);

int main()
{
	// Function Example
	int sport;
	do {
		cout << "Enter a number between 1 and 6 inclusive: ";
		cin >> sport;
	} while (sport < 1 || sport > 6);

	cout << "Your sport is ";
	switch (mySport(sport))
	{
	case BASKETBALL:
		cout << "Basketball";
		break;
	case FOOTBALL:
		cout << "Football";
		break;
	case HOCKEY:
		cout << "Hockey";
		break;
	case BASEBALL:
		cout << "Baseball";
		break;
	case SOCCER:
		cout << "Soccer";
		break;
	case VOLLEYBALL:
		cout << "Volleyball";
		break;
	}
	cout << endl << endl;


	// For-Loop Example
	for (Sports s = BASKETBALL; s <= VOLLEYBALL; s = static_cast<Sports>(s + 1))
	{
		switch (s)
		{
		case BASKETBALL:
			cout << "Basketball";
			break;
		case FOOTBALL:
			cout << "Football";
			break;
		case HOCKEY:
			cout << "Hockey";
			break;
		case BASEBALL:
			cout << "Baseball";
			break;
		case SOCCER:
			cout << "Soccer";
			break;
		case VOLLEYBALL:
			cout << "Volleyball";
			break;
		}
		cout << endl;
	}
}

Sports mySport(int s)
{
	return static_cast<Sports>(s);
}