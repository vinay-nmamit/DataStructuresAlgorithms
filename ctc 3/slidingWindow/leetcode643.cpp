// 643. Maximum Average Subarray I
/*You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75 */

#include <iostream>
#include <vector>
#include <algorithm> // Nee ded for std::max
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Edge case: If k is greater than the size of nums, return 0
    if (k > n) return 0.0;

    // Initialize currentSum with the sum of the first k elements
    double currentSum = 0;
    for (int i = 0; i < k; ++i) {
        currentSum += nums[i];
    }
    
    // Initialize maxAverage with the average of the first k elements
    double maxAverage = currentSum / k;

    // Slide the window across the array to find the maximum average of any k-length subarray
    for (int i = k; i < n; ++i) {
        currentSum += nums[i] - nums[i - k]; // Slide the window by adding the current element and removing the (i-k)th element
        maxAverage = max(maxAverage, currentSum / k); // Update maxAverage if the current average is greater
    }

    return maxAverage;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " integers for the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k;
    cout << "Enter the length of the subarray (k): ";
    cin >> k;

    double maxAvg = findMaxAverage(nums, k);
    cout << "Maximum average of any subarray of length " << k << " is: " << maxAvg << endl;

    return 0;
}
