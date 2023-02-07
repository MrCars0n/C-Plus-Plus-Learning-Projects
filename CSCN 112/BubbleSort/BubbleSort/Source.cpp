#include <iostream>

using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int find(int arr[], int n, int& key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[10];
    int n = 10;
    int key;

    cout << "Enter 10 integers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> key;

    bubbleSort(arr, n);

    int temp = find(arr, n, key);
    if (temp != -1)
        cout << key << " is found at position " << temp << endl;
    else
        cout << key << " is not in the list" << endl;

    return 0;
}
