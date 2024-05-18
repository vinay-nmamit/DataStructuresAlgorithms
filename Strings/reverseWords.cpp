#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

void printWords(string str) {
    string word;

    stringstream ss(str);

    while (ss >> word) {
        reverse(word.begin(), word.end());
        cout << word << " ";
    }
}

int main() {
    string str;
    cout << "Enter a sentence: ";
    getline(cin, str);

    printWords(str);
    return 0;
}
