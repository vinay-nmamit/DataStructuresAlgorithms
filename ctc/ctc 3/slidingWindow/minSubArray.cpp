#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minSubarrayLength(vector<int>& nums, int target) {
    int n = nums.size();
    int minLength = INT_MAX;
    int currentSum = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        currentSum += nums[end];

        // Shrink the window from the left if the sum is >= target
        while (currentSum >= target) {
            minLength = min(minLength, end - start + 1);
            currentSum -= nums[start];
            ++start;
        }
    }

    // If minLength is still INT_MAX, it means no valid subarray found
    return (minLength != INT_MAX) ? minLength : 0;
}

int main() {
    // Input size of the array
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Input array of integers
    vector<int> nums(size);
    cout << "Enter " << size << " integers for the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    // Input target sum
    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    // Calculate the minimum length of subarray with sum at least target
    int result = minSubarrayLength(nums, target);
    cout << "Minimum length of subarray with sum at least " << target << " is: " << result << endl;
    
    return 0;
}
