// longest increasing subsequence
#include <iostream>
#include <vector>
using namespace std;

int longest_increasing_subsequence(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int max_length = 0;
    for (int i = 0; i < n; i++) {
        max_length = max(max_length, dp[i]);
    }

    return max_length;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Length of LIS is " << longest_increasing_subsequence(arr) << endl;

    return 0;
}