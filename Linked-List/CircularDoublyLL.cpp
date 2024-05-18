// all operations of a circular doubly linked list
#include <iostream>
using namespace std;

//defining the structure for circular doubly linked list 
struct Node {
    int data;
    Node *prev;
    Node *next;
};

//function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

//function to add node at the beginning of the circular linked list 
void InsertBeginning(Node **head, int data){
    Node * newNode = createNode(data);

    //if list is empty 
    if(*head == nullptr){
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    }
} 

//fucntion to add node at the end of the circular linked list 
void InsertEnd(Node **head, int data){
    Node *newNode = createNode(data);

    //if list is empty 
    if(*head == nullptr){
        *head = newNode;
        newNode->next = newNode;
        newNode->prev=newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

//function to delete a node from the beginning
void DeleteBeginning(Node **head){
    //if list is empty
    if (*head == nullptr) {
        cout << "list is empty nothing to delete." << endl;
    }

    //if theres only one node 
    if((*head)->next = *head){
        delete *head;
        *head = nullptr;
    }
    //find the last node
    else {
        Node *last = (*head)->prev;
        //update pointers to remove first node
        (*head)->next->prev = last;
        last->next = (*head)->next;

        Node *temp = *head;
        (*head) = (*head)->next;
        delete temp;
    }
}

//function to delete node at the end 
void deleteEnd(Node **head){
    //if list is empty
    if(*head == nullptr){
        cout << "List empty." <<endl;

    }

    //if only one node present 
    if((*head)->next = *head){
        delete *head;
        *head = nullptr;
    } else {
        //find second-to-last node and last node
        Node *last = (*head)->prev;
        Node *Secondlast = last->prev;

        //update pointers to remove the last node
        Secondlast->next = *head;
        (*head)->prev = Secondlast;

        //delete last node
        delete last; 
    }
}

// Function to display the circular doubly linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "Circular Doubly Linked List is empty." << endl;
        return;
    }

    Node* current = head;
    cout << "Circular Doubly Linked List: ";
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int choice;

    do {
        cout << "\nCircular Doubly Linked List Operations:";
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete from Beginning";
        cout << "\n4. Delete from End";
        cout << "\n5. Display List";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                InsertBeginning(&head, data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter data to insert at the end: ";
                cin >> data;
                InsertEnd(&head, data);
                break;
            }
            case 3: {
                DeleteBeginning(&head);
                break;
            }
            case 4: {
                deleteEnd(&head);
                break;
            }
            case 5: {
                displayList(head);
                break;
            }
            case 6: {
                cout << "Exiting the program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please enter a valid option." << endl;
                break;
            }
        }
    } while (choice != 6);

    return 0;
}
