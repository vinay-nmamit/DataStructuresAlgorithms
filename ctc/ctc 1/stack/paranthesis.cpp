#include <iostream>
#include <bits/stdc++.h>
#include <stack>
using namespace std;

bool bracketsBalanced(string expr){
    stack<char> x;

    for(int i = 0; i < expr.length(); ++i){
        // if stack is empty push bracket into the stack
        if(x.empty()){
            x.push(expr[i]);
        } else if (x.top() == '(' && expr[i] == ')'
                    || x.top() == '{' && expr[i] == '}'
                    || x.top() == '[' && expr[i] == ']'){
                    // pop if found any complete pair of brackets
                    x.pop();
        } else{
            x.push(expr[i]);
        }
    }
    if(x.empty()){
        return true;
    }
    return false;
}

int main(){
    string expr;
    cin >> expr;

    if(bracketsBalanced(expr)){
        cout << "balanced" << endl;
    } else {
        cout << "imbalanced" << endl;
    }

    return 0;
}