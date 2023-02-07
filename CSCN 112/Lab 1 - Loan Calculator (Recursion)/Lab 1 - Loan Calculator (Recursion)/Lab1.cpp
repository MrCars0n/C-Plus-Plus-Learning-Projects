// CSCN 112-001 Spring 2023
// Lab 1: Loan Calculator (Recursion)
// Carson Kramer

// Include statements (pre-processing directives)
#include<iostream> // cin & cout
#include<iomanip> // setprecision

// Namespace
using namespace std;

// Global Variables - constants only

// Function Prototypes
void promptUser(double &pAmount, double &intRate, int &t);
double PaymentCalculator(double p, double r, int n);
void Amortize(int currentPeriod, int totPeriods, double payAmount, double monthIntRate, double curBalance);

// Main function
int main()
{
	cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 1" << endl << endl;

	// Local Variables
	double principleAmount = -1;
	double interestRate = -1;
	int term = -1;
	double payAmount = -1;

	// Program Logic
	// Prompt user
	promptUser(principleAmount, interestRate, term);

	// Calculate payment and print amortization table
	payAmount = PaymentCalculator(principleAmount, interestRate, term);
	Amortize(0, term, payAmount, interestRate, principleAmount);

	system("pause");
	return 0;
}

// Function definitions

// Prompts user input for function values
void promptUser(double& pAmount, double& intRate, int& t)
{
	// Round to two decimals
	cout << fixed << showpoint << setprecision(2);

	// Precision prompt
	cout << "Precision: ";
	cin >> pAmount;
	// Error check - positive double
	while (cin.fail() || pAmount <= 0)
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be a number greater than zero. Please try again: ";
		cin >> pAmount;
	}

	// Period prompt
	cout << "Life of Loan (10, 15 or 30 years): ";
	cin >> t;
	// Error check - 10, 15, or 30
	while (cin.fail() || (t != 10 && t != 15 && t != 30))
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be 10, 15 or 30 years. Please try again: ";
		cin >> t;
	}

	// Interest prompt - positive double
	cout << "Annual interest rate: ";
	cin >> intRate;
	// Error check
	while (cin.fail() || intRate <= 0)
	{
		cin.clear(); // clears the error from the input stream
		cin.ignore(10000000, '\n'); // remove anything remaining in the stream
		cout << "Invalid input. Value needs to be a number greater than zero. Please try again: ";
		cin >> intRate;
	}

	// Reset console and reprint values spaced out
	system("CLS");

	cout << "Carson Kramer - CSCN 112 - Spring 2023 - Lab 1" << endl << endl;
	cout << "Loan Application - Amortization Schedule" << endl;
	cout << setw(40) << left << "Precision: " << right << "$" << pAmount << endl;
	cout << setw(40) << left << "Life of Loan (10, 15 or 30 years): " << right << t << " years" << endl;
	cout << setw(40) << left << "Annual interest rate: " << right << intRate << "%" << endl;
	cout << setw(40) << left << "Monthly payment: " << right << "$" << PaymentCalculator(pAmount, intRate, t) << endl;

}

// Calculates payment
double PaymentCalculator(double p, double r, int n)
{
	// n years * 12 months
	n *= 12;

	// (r% per year / 12 months) * (1/100) (convert to percentage)
	r *= (1.0 / 12.0) * 0.01;

	// Return equation
	return p * ((r * pow(1 + r, n)) / (pow(1 + r, n) - 1));
}

void Amortize(int currentPeriod, int totPeriods, double payAmount, double monthIntRate, double curBalance)
{
	// Round to two decimals
	cout << fixed << showpoint << setprecision(2);

	// Calculate current iteration interest and principal amounts
	double curInterest = monthIntRate * curBalance * (1.0 / 12.0) * 0.01;
	double principal = payAmount - curInterest;

	// Base case - if the loan is paid off
	if (curBalance - principal <= 0)
	{
		cout << setw(10) << right << currentPeriod << setw(10) << right << payAmount << setw(10)
			<< right << curInterest << setw(10) << right << principal << setw(10) << right << abs(curBalance - principal) << endl;
		return;
	}

	// First case
	else if (currentPeriod == 0)
	{
		// Payment Amount Interest Principal Balance
		cout << endl << setw(10) << right << "Payment";
		cout << setw(10) << right << "Amount";
		cout << setw(10) << right << "Interest";
		cout << setw(10) << right << "Principal";
		cout << setw(10) << right << "Balance" << endl;
		cout << setw(50) << right << curBalance << endl;

		// First recursive call
		Amortize(currentPeriod + 1, totPeriods, payAmount, monthIntRate, curBalance);
	}
	else // All other cases
	{
		cout << setw(10) << right << currentPeriod << setw(10) << right << payAmount << setw(10)
			<< right << curInterest << setw(10) << right << principal << setw(10) << right << abs(curBalance - principal) << endl;

		// Recursive call
		Amortize(currentPeriod + 1, totPeriods, payAmount, monthIntRate, curBalance - principal);
	}
}