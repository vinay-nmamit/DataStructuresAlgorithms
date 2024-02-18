#include <stdio.h>
#include <math.h>

long long int getMinimumCost(const int arr[], int size) {
    long long int cost = 0;
    for (int i = 1; i < size; i++) {
        int diff = arr[i] - arr[i - 1];
        cost += pow(diff, 2);
    }
    return cost;
}

int main() {
    int size;

    scanf("%d", &size);

    int myArray[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &myArray[i]);
    }

    long long int minimumCost = getMinimumCost(myArray, size);

    printf("Minimum Cost: %lld\n", minimumCost);

    return 0;
}
