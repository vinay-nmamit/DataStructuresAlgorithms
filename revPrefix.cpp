#include <iostream>
#include <string>
#include <stack>
using namespace std;

// function to reverse a prefix string
string RevPrefix(string word, char ch){
    string ans;
    int index = 0;
    
    // Find the index of the first occurrence of character ch
    for(int i = 0; i < word.length(); i++){
        if(word[i] == ch) {
            index = i;
            break;
        }
    }
    
    // Reverse the characters from the beginning of the string to the index
    for(int i = index; i >= 0; i--){
        ans += word[i];
    }

    // Append the remaining characters after the index
    for(int i = index + 1; i < word.length(); i++){
        ans += word[i];
    }

    return ans;
}

int main(){
    string word;
    cout << "Enter a string: ";
    getline(cin, word);
    
    char ch;
    cout << "Enter a character to reverse the prefix up to: ";
    cin >> ch;

    string res = RevPrefix(word, ch);

    cout << "Result after reversing prefix: " << res << endl;

    return 0;
}
