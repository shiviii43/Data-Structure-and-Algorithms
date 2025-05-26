/*
	Insertion Sort: 
	The array is divided into 2 parts i.e. Sorted and Unsorted part.
	A value is taken from the unsorted part and is inserted into the sorted part of the array at its correct position.
	time complexity : 
		Best case :
			When the array is already sorted.
			time complexity : O(n)
		Average case :
			time complexity : O(n*n)
		Worst case : 
			When the array is reversed.
			time complexity : O(n*n)
*/

#include<stdio.h>

void printArray(int *arr, int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void insertionSort(int * arr, int n){
	for(int i=1;i<n;i++){
		int temp = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>temp){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

int main(){
	int arr[] = {5,4,10,1,6,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("The Array before Sorting : ");
	printArray(arr,size);
	insertionSort(arr,size);
	printf("The Array after Sorting : ");
	printArray(arr,size);
	return 0;
}
