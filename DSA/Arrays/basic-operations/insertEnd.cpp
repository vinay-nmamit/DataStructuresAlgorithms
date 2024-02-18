#include <iostream>
using namespace std;

// Inserts a key in arr[] of given capacity.
// n is the current size of arr[]. This
// function returns n + 1 if insertion
// is successful, else n.
int insertSorted(int arr[], int n, int key, int capacity)
{
    // Cannot insert more elements if n is
    // already more than or equal to capacity
    if (n >= capacity)
        return n;

    arr[n] = key;
    return (n + 1);
}

int main()
{
    int capacity;
    cout << "Enter the capacity of the array: ";
    cin >> capacity;

    int *arr = new int[capacity];
    int n;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter the key to be inserted: ";
    cin >> key;

    cout << "Before Insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Inserting key
    n = insertSorted(arr, n, key, capacity);

    cout << "\nAfter Insertion: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr; // Don't forget to free the dynamically allocated memory

    return 0;
}
