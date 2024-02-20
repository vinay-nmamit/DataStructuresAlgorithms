#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;

        int startIndex = 0;
        for (int i = 0; i <= n; i++) {
            // Check if the current character is a space or if we reached the end of the string
            if (s[i] == ' ' || i == n) {
                // Extract the word from the input string
                string subString = s.substr(startIndex, i - startIndex);
                
                // If the substring is not empty, push it onto the stack
                if (!subString.empty()) {
                    st.push(subString);
                }
                // Update startIndex for the next word
                startIndex = i + 1;
            }
        }

        string ans = "";

        // Pop each word from the stack and append it to the ans string
        while (!st.empty()) {
            ans += st.top();
            ans += " ";
            st.pop();
        }

        // Remove the trailing space, if any
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};

int main() {
    Solution sol; // Create an instance of the Solution class

    // Take user input
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    // Call the reverseWords function and output the result
    string result = sol.reverseWords(input);
    cout << "String with reversed words: " << result << endl;

    return 0;
}
