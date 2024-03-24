#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome(string word){
    int length = word.length();
    for(int i = 0; i < length/2; ++i){
        if(word[i] != word[length- i - 1]){
            return false;
        }
    }
    return true;
}

int main(){
    string word;
    cin >> word;

    if(isPalindrome(word)){
        cout << "palindrome" << endl;
    } else {
        cout << "not a palindrome" << endl;
    }
}