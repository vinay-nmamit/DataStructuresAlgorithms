#include <iostream>
#include <deque>
#include <queue>
using namespace std;

// Function to reverse the first k elements of the queue
void reversekelements(queue<int>& qu, int k){

    deque<int> d;

    // Dequeue the first k elements of the queue
    // and push them into the deque
    for(int i = 0; i < k; ++i){
        d.push_front(qu.front());
        qu.pop();
    }

    // Pop the elements from the deque and 
    // enqueue them back into the queue
    while(!d.empty()){
        qu.push(d.front());
        d.pop_front();
    }

    // Store the size of the queue beforehand
    int remaining = qu.size();

    // Dequeue the remaining elements and
    // enqueue them back into the queue
    for(int i = 0; i < remaining - k; ++i){
        qu.push(qu.front());
        qu.pop();
    }
}

int main() {
    queue<int> qu;
    int n, k, temp;

    cout << "Enter the number of elements in the queue: ";
    cin >> n;

    cout << "Enter the elements of the queue: ";
    for(int i = 0; i < n; ++i) {
        cin >> temp;
        qu.push(temp);
    }

    cout << "Enter the value of k: ";
    cin >> k;

    reversekelements(qu, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!qu.empty()) {
        cout << qu.front() << " ";
        qu.pop();
    }
    cout << endl;

    return 0;
}
