#include <iostream>
using namespace std;

// Define the structure of a node for a singly linked list
struct Node {
    int data;
    Node* next;
};

// Insert a node at the beginning of the linked list
void push(Node** head_ref, int new_data) {
    // Allocate a new node
    Node* new_node = new Node();

    // Assign data to the new node
    new_node->data = new_data;

    // Make next of new node as head
    new_node->next = *head_ref;

    // Move the head to point to the new node
    *head_ref = new_node;
}

// Insert a node after a given node
void insert_after(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
    // Allocate a new node
    Node* new_node = new Node();

    // Assign data to the new node
    new_node->data = new_data;

    // Make next of new node as next of prev_node
    new_node->next = prev_node->next;

    // Make prev_node point to new node
    prev_node->next = new_node;
}

// Insert a node at the end of the linked list
void append(Node** head_ref, int new_data) {
    // Allocate a new node
    Node* new_node = new Node();
    Node* last = *head_ref; // To traverse the list

    // Assign data to the new node
    new_node->data = new_data;
    new_node->next = nullptr; // As it will be the last node

    // If the list is empty, make the new node as head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    // Traverse to the last node
    while (last->next != nullptr)
        last = last->next;

    // Change the next of the last node
    last->next = new_node;
}

//function to delete the entire LinkedList
//The function correctly deallocates memory for each node and sets the head pointer to NULL after deleting all nodes.
void deleteLinkedlist(Node** head_ref)
{
    Node* current = *head_ref; // Initialize the current node to the start of the list
    Node* next; // Initialize the next node to be processed

    while (current != NULL) // Loop through the linked list until the end is reached
    {
        next = current->next; // Set the next node to the next node in the list
        delete current; // Delete the current node
        current = next; // Move the current node to the next node in the list
    }

    *head_ref = NULL; // Set the head pointer to NULL to prevent any further access to the deleted list
}

//function to delete node in the beginning 
void deletebeginning(Node **head_ref){
    //check if list is empty
    if(*head_ref == nullptr){
        return ;
    }
    //store the node to be deleted
    Node * beginning = *head_ref;
    //update head to point to second node
    *head_ref = (*head_ref)->next;
    //delete first node
    delete beginning;
}

//function to delete nodes from the end
void deleteEnd(Node **head_ref){
    //check if list is empty
    if(*head_ref == nullptr){
        return ;
    }
    //check if there is only one node in the list
    if((*head_ref)->next == nullptr){
        delete *head_ref;
        *head_ref = nullptr; //update head to nullptr after deletion
        return;
    }
   //traverse till second-to-last node
   Node* end = *head_ref;
   while(end->next->next != nullptr){
    end = end->next;
   }
    //delete last node
   delete end;
   end->next = nullptr; //update next of seconf-to-last node to nullptr
}

//function to delete a node from the middle
void deleteMiddle(Node **head_ref, int position) {
    // Check if the list is empty or if the position is invalid
    if (*head_ref == nullptr || position <= 0)
        return;

    Node *temp = *head_ref;

    // If the position is 1, delete the head node
    if (position == 1) {
        *head_ref = temp->next;
        delete temp;
        return;
    }

    // Traverse to the node before the one to delete
    for (int i = 1; temp != nullptr && i < position - 1; i++)
        temp = temp->next;

    // If position is more than the number of nodes
    if (temp == nullptr || temp->next == nullptr)
        return;

    // Store pointer to the next of node to be deleted
    Node *next = temp->next->next;

    // Unlink the node from linked list
    delete temp->next;

    // Unlink the deleted node from list
    temp->next = next;
}

//to find the given number(x) if present in the linked list
bool search(Node **head_ref, int x){
    Node *current = *head_ref;
    while(current != nullptr){
        if(current->data == x)
            return true;
        current = current->next;
    }
    return false;
}

//to find the length of the linked list by just counting the number of nodes present
int printLength(Node **head_ref)
{
    int count = 0;        // Initialize a counter variable to keep track of the number of nodes.
    Node *current = *head_ref;   // Initialize a pointer to the current node in the linked list.
    while (current != nullptr)  // Iterate over the linked list until the end of the list is reached.
    {
        count++;          // Increment the counter variable by 1 every time we encounter a new node.
        current = current->next;  // Move to the next node in the linked list.
    }
    return count;        // Once the end of the list is reached, return the final count of nodes.
}

//To reverse a linked list
void reverselinkedlist(Node **head_ref){
    Node *prev = nullptr;
    Node *current = *head_ref;
    Node *next = nullptr;

    while(current!= nullptr){
        //store next node
        next = current->next;

        //reverse currrent nodes pointer
        current->next = prev;

        //move pointers one poisition ahead;
        prev = current;
        current = next;
    }
    //set new head
    *head_ref = prev;
}

void displayLinkedList(Node** head_ref) {
    cout << "Linked List: ";
    Node* current = *head_ref;

    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}


int main() {
    Node* head = nullptr;

    while (true) {
        cout << "\nLinked List Operations:";
        cout << "\n1. Insert at the beginning";
        cout << "\n2. Insert after a given node";
        cout << "\n3. Insert at the end";
        cout << "\n4. Delete the entire list";
        cout << "\n5. Delete from the beginning";
        cout << "\n6. Delete from the end";
        cout << "\n7. Delete from the middle";
        cout << "\n8. Search for a number";
        cout << "\n9. Print the length of the list";
        cout << "\n10. Reverse the list";
        cout << "\n11. Display the list";
        cout << "\n12. Exit";

        int choice;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the data to insert at the beginning: ";
                cin >> data;
                push(&head, data);
                break;
            }
            case 2: {
                int data, position;
                cout << "Enter the data to insert: ";
                cin >> data;
                cout << "Enter the position to insert after: ";
                cin >> position;
                insert_after(head, data);
                break;
            }
            case 3: {
                int data;
                cout << "Enter the data to insert at the end: ";
                cin >> data;
                append(&head, data);
                break;
            }
            case 4: {
                deleteLinkedlist(&head);
                cout << "Linked list deleted successfully.\n";
                break;
            }
            case 5: {
                deletebeginning(&head);
                cout << "First node deleted successfully.\n";
                break;
            }
            case 6: {
                deleteEnd(&head);
                cout << "Last node deleted successfully.\n";
                break;
            }
            case 7: {
                int position;
                cout << "Enter the position of the node to delete from the middle: ";
                cin >> position;
                deleteMiddle(&head, position);
                break;
            }
            case 8: {
                int num;
                cout << "Enter the number to search: ";
                cin >> num;
                bool found = search(&head, num);
                if (found)
                    cout << "Number found in the list.\n";
                else
                    cout << "Number not found in the list.\n";
                break;
            }
            case 9: {
                int length = printLength(&head);
                cout << "Length of the list: " << length << endl;
                break;
            }
            case 10: {
                reverselinkedlist(&head);
                cout << "Linked list reversed successfully.\n";
                break;
            }
            case 11: {
                displayLinkedList(&head);
                break;
            }
            case 12: {
                cout << "Exiting program...\n";
                exit(0);
            }
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
