// reversing the stack elements by using queue
#include <iostream>
#include<stack>
#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int>& stk){
    queue<int> qu;

    //enqueue all elements from stack to queue
    while(!stk.empty()){
        qu.push(stk.top());
        stk.pop();
    }

    //push all elements from stack to queue
    while(!qu.empty()){
        stk.push(qu.front());
        qu.pop();
    }
}

int main(){
    stack<int> stk;
    int size;
    cout << "enter size of stack: ";
    cin >> size;

    cout << "enter the elements: ";
    for(int i = 0; i < size; ++i){
        int elements;
        cin >> elements;
        stk.push(elements);
    }

    reverse(stk);

    //print reversed stack (top to bottom)
    while(!stk.empty()){
        cout << stk.top() << " ";
        stk.pop();
    }

    cout << endl;

    return 0;

}