#include <bits/stdc++.h>
using namespace std;

void insertElement(int arr[], int n, int x, int pos) {
    for (int i = n - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = x;
}

int main() {
    int size;
    cout << "enter the size of array: ";
    cin >> size;

    int n;
    cout << "enter size of elements: ";
    cin >> n;

    int arr[size];
    cout << "enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "before insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    int x, pos;
    cout << "Enter the element to be inserted: ";
    cin >> x;

    cout << "enter the position: ";
    cin >> pos;

    insertElement(arr, n, x, pos);
    n++;

    cout << "after insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
