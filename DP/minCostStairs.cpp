// 746. Minimum Cost Climbing Stairs

/* You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor.

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15. */

#include <iostream>
#include <vector>
using namespace std;

int minCostStairs(vector<int>& cost){
    int n = cost.size();

    for(int i = 2; i < n; i++){
        cost[i] += min(cost[i-1], cost[i-2]);
    }

    return min(cost[n-1], cost[n-2]);
}

int main() {
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;

    vector<int> cost(n);
    cout << "Enter the cost for each step:\n";
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int minCost = minCostStairs(cost);

    cout << minCost << endl;

    return 0;
}