#include <iostream>
#include <stack>
using namespace std;

// deletes middle of the stack of size n, curr is the current item number
void deleteMid(stack<char>& st) {
    int n = st.size();
    stack<char> temp;
    int count = 0;

    while (count < n / 2) {
        char c = st.top();
        st.pop();
        temp.push(c);
        count++;
    }

    // delete middle element
    st.pop();

    // put all the n/2 elements of temp back to stack
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

int main() {
    stack<char> st;
    int size;
    cout << "Enter size: ";
    cin >> size;

    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        char element;
        cin >> element; // Read the input element
        st.push(element);
    }

    deleteMid(st);

    cout << "After deletion: ";
    while (!st.empty()) {
        char p = st.top();
        st.pop();
        cout << p << " ";
    }
    return 0;
}
