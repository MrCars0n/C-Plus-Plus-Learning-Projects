#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
    //varaible declarations
    string* names;
    double* votes;
    int n;

    //prompt and read the number of candidates
    cout << "Enter number of candidates: ";
    cin >> n;

    //create two dynamic arrays
    names = new string[n];
    votes = new double[n];

    double sum = 0;
    double winner = -1;
    string winnerName = "";
    int total = 0;

    //run a loop to read the candidate details
    for (int i = 0; i < n; i++) {
        //prompt and read candidates name
        cout << "Enter candidate's name: ";
        cin >> names[i];

        //prompt and read number of votes received
        cout << "Enter votes received: ";
        cin >> votes[i];
        //compute the running total of number of votes
        sum += votes[i];

        //compare and get the winner
        if (winner < votes[i]) {
            winner = votes[i];
            winnerName = names[i];
        }
    }

    cout << endl;
    cout << setprecision(2) << fixed;

    //display the output headers
    cout << "Candidate Votes Received % of Total Votes" << endl;
    //cout << setw(20) << left << "Name" << setw(20) << left << "Votes" << setw(20) << left << "% of Total     Votes" << endl;
    //iterate and display the candidate details
    for (int i = 0; i < n; i++) {
        cout << setw(20) << left << names[i] << setw(20) << left << setprecision(0) << votes[i] << setprecision(2) << votes[i] / sum * 100 << endl;
        total += votes[i];
    }

    //displat the total number of votes
    cout << setw(20) << left << "Total" << setw(20) << left << total << endl;
    //display the winner
    cout << endl << "The winner of the Election is " << winnerName;

    return 0;
}
