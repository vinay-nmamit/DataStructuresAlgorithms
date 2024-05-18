#include <iostream>
using namespace std;

struct Node {
    Node * next;
    int data;
};

Node * removeDuplicates(Node * head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node * current = head;
    while (current->next != nullptr) {
        if (current->data == current->next->data) {
            Node * temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
    return head;
}

// Function to insert a new node at the end of the linked list
Node* insert(Node* head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int size, data;

    // Taking size of the linked list
    cout << "Enter the size of the linked list: ";
    cin >> size;

    // Taking user input to create linked list
    cout << "Enter " << size << " elements for the linked list: ";
    for (int i = 0; i < size; ++i) {
        cin >> data;
        head = insert(head, data);
    }

    // Removing consecutive duplicates
    head = removeDuplicates(head);

    cout << "Linked List after removing consecutive duplicates: ";
    display(head);

    return 0;
}
