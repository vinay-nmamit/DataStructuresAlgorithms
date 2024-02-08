#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int arr[], int size){
    int k;
    for(int i =0; i < size -1; i++ ){
        k = i;
        for(int j = i+1; j < size; j++)
            if(arr[j] < arr[k])
                k = j;
        if(k != i)
            swap(&arr[k], &arr[i]);
    }
}

void printarray(int arr[], int size){
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    printf("enter the size of the array: ");
    int size;
    scanf("%d", &size);
    if(size < 0)
        printf("invalid size");
    int arr[size];
    printf("enter the elements: ");
    for(int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    selectionsort(arr,size);
    printf("sorted array: ");
    printarray(arr,size);
    return 0;
}