#include <iostream>
#include <stack>
using namespace std;

class solution{
public:
    string reversewords(string s) {
        int n = s.size();
        stack<string> st;

        int startIndex = 0;
        for(int i = 0; i <= n; i++){
            if(s[i] == ' ' || i ==  n){
                string Substring = s.substr(startIndex, i - startIndex);

                if(!Substring.empty()){
                    st.push(Substring);
                }
                startIndex = i + 1;
            }
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            ans += " ";
            st.pop();
        }

        if(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }
        return ans;
    }
};

int main() {
    solution sol; // Create an instance of the Solution class

    // Take user input
    cout << "Enter a string: ";
    string input;
    getline(cin, input);

    // Call the reverseWords function and output the result
    string result = sol.reversewords(input);
    cout << "String with reversed words: " << result << endl;

    return 0;
}
