#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Function to add a new node
void pushNode(Node** head_ref, int data_val) {
    // Allocate node
    Node *new_node = new Node();

    // Put in the data
    new_node->data = data_val;

    // Link the old list of the new node
    new_node->next = *head_ref;

    // move the head to point to the new node
    *head_ref = new_node;
}

// Function to display the middle element of the linked list
void displayMiddle(Node* head) {
    vector<int> v;
    Node* temp = head;
    while (temp != nullptr) {
        v.push_back(temp->data);
        temp = temp->next;
    }
    if (v.empty()) {
        cout << "Linked list is empty." << endl;
        return;
    }
    cout << "Middle Value Of Linked List is: ";
    cout << v[v.size() / 2] << endl;
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        int data_val;
        cin >> data_val;
        pushNode(&head, data_val);
    }
    displayMiddle(head);
    return 0;
}
