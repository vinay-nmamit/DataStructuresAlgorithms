#include <iostream>
using namespace std;

// Function to perform left rotation of an array
void leftRotate(int arr[], int d, int n) {
    for (int p = 0; p < d; p++) {
        // Store the first element of the array
        int first = arr[0];
        
        // Shift each element to the left
        for (int i = 0; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        // Place the first element at the end of the array
        arr[n - 1] = first;
    }
}

// Function to print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int d, n;

    // Input the rotation value 'd' and array size 'n'
    cin >> d >> n;

    // Input the elements of the original array
    int originalArr[n];
    for (int i = 0; i < n; i++) {
        cin >> originalArr[i];
    }

    // Perform left rotation
    leftRotate(originalArr, d, n);

    // Print the rotated array
    printArray(originalArr, n);

    return 0;
}
