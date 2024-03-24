#include <iostream>
#include <unordered_set>
#include <string>
#include <stack>
using namespace std;

string removeDirtyChars(string str1, string str2) {
    unordered_set<char> dirtyChars(str2.begin(), str2.end());
    stack<char> cleanChars;

    // Push characters to stack from str1 if it's not in str2
    for (char c : str1) {
        if (dirtyChars.find(c) == dirtyChars.end()) {
            cleanChars.push(c);
        }
    }

    // Pop characters from stack and print result string
    string result;
    while (!cleanChars.empty()) {
        result = cleanChars.top() + result;
        cleanChars.pop();
    }

    return result;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    cout << removeDirtyChars(str1, str2) << endl;
    return 0;
}
