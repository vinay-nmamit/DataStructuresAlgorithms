#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size;
    printf("Enter the size of the elements: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements into the array: "); 
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the element to be found: ");
    scanf("%d", &key);

    int result = linearSearch(arr, size, key);

    if (result != -1) {
        printf("Position: %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
