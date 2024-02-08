// C program for implementation of selection sort 
#include <stdio.h> 

void swap(int *a, int *b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, k; 
	for (i = 0; i < n-1; i++) 
	{ 
		k = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[k]) 
			k = j; 

		if(k != i) 
			swap(&arr[k], &arr[i]); 
	} 
} 

void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

int main() 
{ 
	int arr[] = {64, 25, 12, 22, 11}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	selectionSort(arr, n); 
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
} 
