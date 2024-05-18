#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1, size;

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
    return stack[top--];
  }
}

int isEmpty() {
  return top == -1;
}

int is_operator(char symbol) {
  return (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '+' || symbol == '-' || symbol == '&');
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

  while (infix[i] != '\0') {
    char item = infix[i];
    if (item == '(') {
      push(item);
    } else if (isdigit(item) || isalpha(item)) {
      postfix[j++] = item;
    } else if (is_operator(item) == 1) {
      while (!isEmpty() && precedence(stack[top]) >= precedence(item)) {
        postfix[j++] = pop();
      }
      push(item);
    } else if (item == ')') {
      while (!isEmpty() && stack[top] != '(') {
        postfix[j++] = pop();
      }
      pop(); 
    }
    i++;
  }

  while (!isEmpty()) {
    postfix[j++] = pop();
  }

  postfix[j] = '\0';
}

int main() {
  char infix[MAX_SIZE], postfix[MAX_SIZE];
  printf("Enter the size of array: ");
  scanf("%d", &size);
  printf("Enter the infix expression: \n");
  scanf("%s", infix);
  infixTopostfix(infix, postfix);
  printf("Postfix expression is: %s\n", postfix);
  return 0;
}
