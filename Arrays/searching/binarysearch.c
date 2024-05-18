#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int n;
    printf("Enter the size of the elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements into the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key element to be found: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1) {
        printf("Element found at the position: %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
