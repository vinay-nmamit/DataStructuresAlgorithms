//all operations of a Queue data structure
#include <iostream>
using namespace std;

//structrue for a node in queue
struct Node{
    int data;
    Node* next;
};

//function to create a new node 
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

//fucntion to check if queue is empty
bool isEmpty(Node *head){
    return head == nullptr;
}

//function to enqueue the element to the rear of the queue
void enqueue(Node*& front, Node*& rear, int value){
    Node *newNode = createNode(value);
    if(isEmpty(front)){
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " enqueued to queue." << endl;
}

//function to dequeue the element from the front of the queue
int dequeue(Node*& front, Node*& rear){
    if(isEmpty(front)){
        cerr << "queue is empty cannot dequeue. " << endl;
        return -1;
    }
    int dequeuedvalue = front->data;
    Node *temp = front;
    front = front->next;
    if(front == nullptr){
        rear = nullptr;
    }
    delete temp;
    cout << dequeuedvalue << " dequeued from the queue. "<< endl;
    return dequeuedvalue;
}

//function to peek the front element of the queue
int peek(Node* head){
    if(isEmpty(head)){
        cerr << "queue is empty, cannot peek" << endl;
        return -1;
    }
    return head->data;
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;
    int choice;
    int value;

    do {
        cout << "\nQueue Operations:" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                enqueue(front, rear, value);
                break;
            case 2:
                dequeue(front, rear);
                break;
            case 3:
                value = peek(front);
                if (value != -1) {
                    cout << "Front element: " << value << endl;
                }
                break;
            case 4:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != 4);

    // Clean up memory
    Node* temp;
    while (front != nullptr) {
        temp = front;
        front = front->next;
        delete temp;
    }

    return 0;
}
