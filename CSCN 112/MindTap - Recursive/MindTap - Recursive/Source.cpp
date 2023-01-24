#include <iostream>

using namespace std;

void recursive(int);

int main()
{
    // Write your main here
    int num;
    cin >> num;
    recursive(num);
    return 0;
}

void recursive(int n)
{
    if (n <= 0)
    {
        return;
    }
    for (int x = 0; x < n; x++)
    {
        cout << "*";
    }
    cout << endl;
    recursive(n - 1);
    for (int x = 0; x < n; x++)
    {
        cout << "*";
    }
    cout << endl;
}

/*
#include <iostream>

using namespace std;

void recursive(int, int, bool);

int main()
{
    // Write your main here
    int num;
    cin >> num;
    recursive(num, num, true);
    return 0;
}

void recursive(int n, int original, bool dec)
{
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    if (n == 0)
    {
        recursive(1, original, false);
    }
    else if (dec)
    {
        cout << endl;
        recursive(n - 1, original, true);
    }
    else if(n != original)
    {
        cout << endl;
        recursive(n + 1, original, false);
    }
}
*/