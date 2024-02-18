#include <stdio.h>
#include <limits.h>

long int getMinimumCost(int arr[], int n){
    long int min_cost = INT_MAX;
    for(int i = 0; i < n - 1; i++){
        int new_element = (arr[i] + arr[i+1]) / 2;
        long int new_cost = (arr[i] - new_element) * (arr[i] - new_element) +
                            (new_element - arr[i+1]) * (new_element = arr[i+1]);
    
        if(new_cost < min_cost){
            min_cost = new_cost;
        }
    }
    return min_cost;
}