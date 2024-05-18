#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubArray(vector<int>& nums, int target) {
    int n = nums.size();
    int minLen = INT_MAX;
    int currentsum = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        currentsum += nums[end];

        while (currentsum >= target) {
            minLen = min(minLen, end - start + 1);
            currentsum -= nums[start];
            ++start;
        }
    }

    return (minLen != INT_MAX) ? minLen : 0;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter " << size << " integers for the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int result = minSubArray(nums, target);
    cout << "Minimum length of subarray with sum at least " << target << " is: " << result << endl;

    return 0;
}
