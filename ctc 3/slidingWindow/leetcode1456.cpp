// 1456. Maximum Number of Vowels in a Substring of Given Length

/* Given a string s and an integer k, 
return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters. */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int maxVowels(const string& s, int k) {
    int n = s.length();
    int maxVowelCount = 0;
    int currentVowelCount = 0;

    // Calculate vowel count for the first window of size k
    for (int i = 0; i < k; ++i) {
        if (isVowel(s[i])) {
            currentVowelCount++;
        }
    }
    maxVowelCount = currentVowelCount; // Initialize maxVowelCount with the count of vowels in the first window

    // Slide the window across the string to find the maximum number of vowels in any k-length subarray
    for (int i = k; i < n; ++i) {
        if (isVowel(s[i])) {
            currentVowelCount++;
        }
        if (isVowel(s[i - k])) {
            currentVowelCount--;
        }
        // Update maxVowelCount with the maximum vowel count encountered
        maxVowelCount = max(maxVowelCount, currentVowelCount);
    }

    return maxVowelCount;
}

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    int k;
    cout << "Enter the length of the subarray (k): ";
    cin >> k;

    int result = maxVowels(s, k);
    cout << "Maximum number of vowels in any contiguous subarray of length " << k << " is: " << result << endl;

    return 0;
}
