#include <stdio.h>
#include <string.h>

void naivePatternMatching(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == m) {
            printf("Pattern found at position: %d\n", i);
        }
    }
}

int main() {
    const char *text = "AABAACAADAABAABA";
    const char *pattern = "AABA";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    printf("Pattern matching results:\n");
    naivePatternMatching(text, pattern);

    return 0;
}
