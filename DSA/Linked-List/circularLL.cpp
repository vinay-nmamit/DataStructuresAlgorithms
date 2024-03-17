// all operations of a circular linked list
#include <iostream>
using namespace std;

//defining structure for a node of circular linked list
struct Node{
    int data;
    Node *next;
};

//function to add new element at the beginning of the circular linked list
void InsertFront(Node **head, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;

    //if list is empty make new node as head and make its next point to itself 
    if(*head == nullptr){
        *head = new_node;
        new_node->next = *head;
    } else {
        //find the last node and link its next to the new node
        Node *last = *head;
        while(last->next != *head){
            last = last->next;
        }
        new_node->next = *head;
        last->next = new_node;

        //update head to point to the new node
        *head = new_node;
    }
    
}

//function to add elements into the circular linked list
void InsertEnd(Node **head, int new_data){
    Node *new_node = new Node();
    new_node->data = new_data;

    //if the list is empty, make the new node as head and point its next to itself 
    if(*head == nullptr){
        *head = new_node;
        new_node->next = *head;
    } else {
        // otherwise find the last node and link the new node with head
        Node *last = *head;
        while(last->next != *head){
            last = last->next;
        }
        last->next = new_node;
        new_node->next = *head;

        //update head to point to the new node
        *head = new_node;
    }
}

//function to display the circular linked list
void display(Node* head) {
    // If list is empty
    if (head == nullptr) {
        cout << "Circular linked list is empty." << endl;
        return;
    }

    cout << "Circular linked list: ";
    Node* current = head;
    // Traverse all the nodes and print their data members
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);

    cout << endl;
}


//delete from beginning 
void deleteFront(Node **head){
    //if linked list is empty
    if(*head == nullptr){
        cout << "list is empty"<<endl;
        return ;
    }
    //if there is only one node, delete it and set head to nullptr
    if((*head)->next == *head){
        delete *head;
        *head = nullptr;
        return ;
    }
    //find the last node and update its next pointer
    Node *last = *head;
    while(last->next != *head){
        last = last->next;
    }
    Node *start = *head;
    *head = (*head)->next;
    last->next = *head;
    delete start;
}

//function to delete last node from circular linked list
void deleteEnd(Node **head){
    //if list is empty
    if(*head == nullptr){
        cout << "List is empty." << endl;
        return;
    }

    //if there is only one node, delete it and set head to null ptr
    if((*head)->next == *head){
        delete *head;
        *head = nullptr;
        return ;
    }

    //find second-to-last node
    Node *second_last = *head;
    while(second_last->next->next != *head){
        second_last = second_last->next;
    }
    //delete last node
    Node *last = second_last->next;
    second_last->next = *head;
    delete last;
}

//Delete node at any given position
void deleteAtPosition(Node **head, int pos){
    //if the list is empty
    if(*head == nullptr){
        cout << "list is emoty." << endl;
        return; 
    }
    //if position is first node
    if(pos == 0){
        deleteFront(head);
        return;
    }
    //traverse to node just before the one to be deleted
    Node *temp = *head;
    for(int i = 0; i < pos - 1; ++i){
        temp = temp->next;
        //if position is out of range print an error message
        if(temp->next == *head){
            cout << "position is out of range." << endl;
            return; 
        }
    }
    //store the node to be deleted and adjuts the next pointer of the prev node
    Node *to_delete = temp->next;
    temp->next = temp->next->next;
    //delete the node
    delete to_delete;
}

//to count the number of elemets or nodes in the circular linked list
int getCount(Node **head){
    //if list is empty
    if(*head == nullptr){
        cout << "list is empty." << endl;
    }

    int count = 0;
    Node *temp = *head;
    //traverse circular linked list and increment count untill you reach the head again
    do{
        count++;
        temp = temp->next;
    }while(temp!= (*head));

    return count;
}

//main function
int main() {
    Node* head = nullptr;
    int choice;

    do {
        cout << "\nCircular Linked List Operations:";
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Display List";
        cout << "\n4. Delete from Beginning";
        cout << "\n5. Delete from End";
        cout << "\n6. Delete at Position";
        cout << "\n7. Count Nodes";
        cout << "\n8. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                InsertFront(&head, data);
                display(head);
                break;
            }
            case 2: {
                int data;
                cout << "Enter data to insert at the end: ";
                cin >> data;
                InsertEnd(&head, data);
                display(head);
                break;
            }
            case 3: {
                display(head);
                break;
            }
            case 4: {
                deleteFront(&head);
                display(head);
                break;
            }
            case 5: {
                deleteEnd(&head);
                display(head);
                break;
            }
            case 6: {
                int pos;
                cout << "Enter the position to delete: ";
                cin >> pos;
                deleteAtPosition(&head, pos);
                display(head);
                break;
            }
            case 7: {
                cout << "Number of nodes in the circular linked list: " << getCount(&head) << endl;
                break;
            }
            case 8: {
                cout << "Exiting the program." << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please enter a valid option." << endl;
                break;
            }
        }
    } while (choice != 8);

    return 0;
}
