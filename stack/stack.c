#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

void push(int);
int pop();
int isFull();
int isEmpty();
void peek();
void Traverse();

int stack[CAPACITY];
int top = -1, element, item, choice;

int main() {
    while (1) {
        printf("1.Push\n2.Pop\n3.Peek\n4.Traverse\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                item = pop();
                if (item == 0) {
                    printf("Stack Underflow!!\n");
                } else {
                    printf("Popped element: %d\n", item);
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                Traverse();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    printf("\n\n");
    return 0;
}

void push(int element) {
    if (isFull()) {
        printf("Stack is full!!\n");
    } else {
        top++;
        stack[top] = element;
    }
}

int isFull() {
    if (top == CAPACITY - 1) {
        return 1;
    } else {
        return 0;
    }
}

int pop() {
    if (isEmpty()) {
        return 0;
    } else {
        return stack[top--];
    }
}

int isEmpty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Stack is Empty!!\n");
    } else {
        printf("Peek element: %d\n", stack[top]);
    }
}

void Traverse() {
    if (isEmpty()) {
        printf("Stack is Empty!!\n");
    } else {
        printf("Stack elements are: \n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
