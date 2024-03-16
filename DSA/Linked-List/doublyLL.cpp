#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    // Constructor for the Node
    Node(int data) : data(data), prev(nullptr), next(nullptr) {}
};

// Insert at the beginning of the list
void InsertAtHead(Node** head, int new_data) {
    // Allocate the node
    Node* new_node = new Node(new_data);

    // Make next of new node as head and previous as null
    new_node->next = *head;
    new_node->prev = nullptr;

    // Change the previous of head to new node
    if (*head != nullptr) {
        (*head)->prev = new_node;
    }

    // Move the head to point to the new node
    *head = new_node;
}

// Add node at the end of the linked list 
void append(Node **head, int new_data) {
    // Allocate node
    Node *new_node = new Node(new_data);
    
    // If the list is empty, make the new node as head
    if (*head == nullptr) {
        *head = new_node;
        return;
    }
    
    // Traverse till last node
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }
    
    // Change next of last node and make the last node as previous of new node
    last->next = new_node;
    new_node->prev = last;
}

// Insert before a given node
void insertBefore(Node **next_node, int new_data) {
    // Check if next_node is nullptr
    if (*next_node == nullptr) {
        cout << "Cannot insert before a nullptr." << endl;
        return;
    }

    // Allocate new node
    Node* new_node = new Node(new_data);

    // Make prev of new node as prev of next_node
    new_node->prev = (*next_node)->prev;
    // Make prev of next_node as new_node
    (*next_node)->prev = new_node;

    // Make next of new node as next_node
    new_node->next = *next_node;

    // Change the next of new node's previous node
    if (new_node->prev != nullptr) {
        new_node->prev->next = new_node;
    } else {
        // If new node's previous node is nullptr, update head
        *next_node = new_node;
    }
}


// Insert after a given node
void insertAfter(Node **prev_node, int new_data) {
    // Check if given prev_node pointer is null
    if (*prev_node == nullptr) {
        cout << "Previous node cannot be null." << endl;
        return;
    }

    Node *new_node = new Node(new_data);

    new_node->next = (*prev_node)->next;
    (*prev_node)->next = new_node;
    new_node->prev = *prev_node;

    // Change the previous of new node's next node
    if (new_node->next != nullptr) {
        new_node->next->prev = new_node;
    }
}
