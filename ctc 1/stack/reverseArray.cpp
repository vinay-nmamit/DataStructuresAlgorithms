#include <iostream>
#include <stack>
using namespace std;

void reverseArray(int arr[], int n) {
    stack<int> st;

    // Push all elements into the stack
    for (int i = 0; i < n; ++i) {
        st.push(arr[i]);
    }

    // Pop elements from the stack and put them back into the array
    for (int i = 0; i < n; ++i) {
        arr[i] = st.top();
        st.pop();
    }
}

int main() {
    int size;
    cout << "Enter the size: ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    reverseArray(arr, size);

    cout << "Reversed array: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
