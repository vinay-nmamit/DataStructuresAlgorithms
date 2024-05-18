#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void reverse(stack<int> & stk){
    queue<int> qu;

    //enqueue all elements from stack to queue
    while(!stk.empty()){
        qu.push(stk.top());
        stk.pop();
    }

    //dequeue elements from queue to stack
    while(!qu.empty()){
        stk.push(qu.front());
        qu.pop();
    }
}