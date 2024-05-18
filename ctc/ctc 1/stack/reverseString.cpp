#include <iostream>
#include <bits/stdc++.h>
#include <stack>
#include <string>
using namespace std;

void reversestring(string &str){
    stack<char> s;

    for(auto it : str)s.push(it);
    str.clear();

    while(!s.empty()){
        str.push_back(s.top());
        s.pop();
    }
}

int main(){
    string str;
    getline(cin, str);

    reversestring(str);
    cout << "reversed string is: " << str;

    return 0;
}