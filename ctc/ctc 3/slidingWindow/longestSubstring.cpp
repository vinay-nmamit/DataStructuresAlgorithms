#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// Function to find the longest substring of a given string containing
// `k` distinct characters using a sliding window
string findLongestSubstring(const string& str, int k) {
    int n = str.length();
    int begin = 0, end = 0; // Initialize pointers for the longest valid substring
    int maxLen = 0; // Length of the longest valid substring found
    unordered_map<char, int> charCount; // Map to count occurrences of characters
    int distinctCount = 0; // Count of distinct characters in the current window

    for (int low = 0, high = 0; high < n; ++high) {
        char currentChar = str[high];

        // Add the current character to the map and update its count
        charCount[currentChar]++;

        // If this is the first occurrence of the character, increment distinct count
        if (charCount[currentChar] == 1) {
            distinctCount++;
        }

        // If we have more than `k` distinct characters, shrink the window from the left
        while (distinctCount > k) {
            char leftChar = str[low];
            charCount[leftChar]--;

            // If count becomes 0, decrement distinct count
            if (charCount[leftChar] == 0) {
                distinctCount--;
            }

            // Move the left pointer to the right to shrink the window
            low++;
        }

        // Update the longest valid substring if the current window size is larger
        if (high - low + 1 > maxLen) {
            maxLen = high - low + 1;
            begin = low;
            end = high;
        }
    }

    // Return the longest substring found at `str[begin...end]`
    return str.substr(begin, maxLen);
}

int main() {
    string str = "abcbdbdbbdcdabd";
    int k = 2;

    string longestSubstring = findLongestSubstring(str, k);

    cout << "Longest substring with " << k << " distinct characters: " << longestSubstring << endl;

    return 0;
}
