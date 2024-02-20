#include <iostream>
using namespace std;

class solution {
public:
    string reverseVowel(string s){
        string word = s;
        int start = 0;
        int end = s.length() - 1;
        string vowels = "aeiouAEIOU";

        while(start < end){
            while(start < end && vowels.find(word[start]) == string::npos){
                start++;
            }
            while(start < end && vowels.find(word[end]) == string::npos){
                end--;
            }
            swap(word[start], word[end]);
            start++;
            end--;
        }
        return word;
    }
};

int main() {
    solution sol; 

    // Take user input
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    // Call the reverseVowel function and output the result
    string result = sol.reverseVowel(input);
    cout << "String with reversed vowels: " << result << endl;

    return 0;
}