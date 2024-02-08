#include <iostream>
#include <stack>
#include <cctype>
#include <cstring>
using namespace std;

bool isOperator(char symbol) {
    return(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '+' || symbol == '-' || symbol == '&' );
}

int precedence(char symbol) {
    if (symbol == '^' || symbol == '&') {
        return 3;
    } else if (symbol == '*' || symbol == '/' || symbol == '%'){
        return 2;
    } else if (symbol == '+' || symbol == '-'){
        return 1;
    } else {
        return 0;
    }
}

void infixTopostfix(const char infix[], char postfix[]){
    stack<char> st;
    st.push('(');

    size_t i = 0;
    size_t j = 0;

    while(infix[i] != '\0') {
        char item = infix[i];

        if(item == '(') {
            st.push(item);
        } else if (isdigit(item) || isalpha(item)) {
            postfix[j++] = item;
        } else if (isOperator(item)) {
            while(!st.empty() && precedence(st.top()) >= precedence(item)){
                postfix[j++] = st.top();
                st.pop();
            }
            st.push(item);
        } else if(item == ')') {
            while(!st.empty() && st.top() != '('){
                postfix[j++] = st.top();
                st.pop();
            }
            st.pop();
        }
        i++;
    }

    while(!st.empty()){
        postfix[j++] = st.top();  //if stack not empty pop everything 
        st.pop();
    }

    postfix[j] = '\0';  //null charcter to determine the end of the string
}

int main(){
    char infix[100], postfix[100];
    cout << "enter the infix expression: \n";
    cin >> infix;
    infixTopostfix(infix, postfix);
    cout << "postfix expression is: "  << postfix << endl;
    return 0;
}