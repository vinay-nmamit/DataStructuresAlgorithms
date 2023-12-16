#include <stdio.h>

void fibonacciRecursive(int n, int prev, int current, int terms) {
    if (n == terms) {
        return;
    }

    printf("%d, ", prev);

    fibonacciRecursive(n + 1, current, prev + current, terms);
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    scanf("%d", &terms);
    
    if (terms < 0) {
        printf("Please enter a non-negative number of terms.\n");
        return 1; 
    }

    if (terms == 0) {
        printf("Fibonacci Series: (None)\n");
        return 0;
    }

    
    printf("Fibonacci Series up to %d terms: ", terms);
    fibonacciRecursive(0, 0, 1, terms);
    printf("\n");

    return 0;
}
