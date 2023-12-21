#include <stdio.h>
#include <string.h>

// Function to perform naive pattern matching
void naivePatternMatching(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    // Iterate through the text
    for (int i = 0; i <= n - m; i++) {
        int j;

        // Check for pattern match
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        // If the inner loop completed without a break, pattern is found
        if (j == m) {
            printf("Pattern found at position: %d\n", i);
        }
    }
}

int main() {
    char text[100];  // Assuming a maximum length for the text
    char pattern[50];  // Assuming a maximum length for the pattern

    // Input text and pattern from the user
    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    // Print the input text and pattern
    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    // Perform pattern matching and print results
    printf("Pattern matching results:\n");
    naivePatternMatching(text, pattern);

    return 0;
}
