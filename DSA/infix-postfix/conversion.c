#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1, item, size;

void push(char item) {
    if (top >= size - 1) {
        printf("Stack is full!!!\n");
    } else {
        top++;
        stack[top] = item;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack is underflow!!\n");
        exit(1);
    } else {
        item = stack[top];
        top--;
        return item;
    }
}

int is_operator(char symbol) {
    if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '+' || symbol == '-' || symbol == '&') {
        return 1;
    } else {
        return 0;
    }
}

int precedence(char symbol) {
    if (symbol == '^' || symbol == '&') {
        return 3;
    } else if (symbol == '*' || symbol == '/' || symbol == '%') {
        return 2;
    } else if (symbol == '+' || symbol == '-') {
        return 1;
    } else {
        return 0;
    }
}

void infixTopostfix(char infix[], char postfix[]) {
    push('(');
    strcat(infix, ")");
    int i = 0;
    int j = 0;
    item = infix[i];

    while (item != '\0') {
        if (item == '(') {
            push(item);
        } else if (isdigit(item) || isalpha(item)) {
            postfix[j] = item;
            j++;
        } else if (is_operator(item) == 1) {
            int x = pop();
            while (is_operator(x) == 1 && precedence(x) >= precedence(item)) {
                postfix[j] = x;
                j++;
                x = pop();
            }
            push(item);
        }
        item = infix[++i];
    }
}

int main() {
    char infix[100], postfix[100];
    printf("Enter the size of array: ");
    scanf("%d", &size);
    printf("Enter the infix expression: \n");
    scanf("%s", infix);
    infixTopostfix(infix, postfix);
    printf("Postfix expression is: %s\n", postfix);
    return 0;
}
