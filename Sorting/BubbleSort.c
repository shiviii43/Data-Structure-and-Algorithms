/*
	BUBBLE SORT:
	Two Adjacent elements are compared and swapped.
	One loop will iterate from first to last and the second loop will compare the value of adjacent elements till the range.
	Time Complexities : 
		Best Case : 
			When the array is already sorted.
			Time complexity : O(n)
		Worst Case : 
			When the Array is reversed.
			Time Complexity : O(n*n)
		Average Case : 
			Time Complexity : O(n*n)
*/

#include<stdio.h>

void printArray(int* arr, int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void bubbleSort(int* arr, int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
void optiBubbleSort(int* arr, int n){
	int swapFlag;		//A flag varible that will track if a swap took place in an iteration or not
	for(int i=0;i<n-1;i++){
		swapFlag=0;		//For every iteration the flag will be initailly 0
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				swapFlag++;
			}
		}
		if(swapFlag==0)		//Meaning that there were no swap that occurred.
			break;
	}
}
int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	printf("The array before sorting : ");
	printArray(arr,size);
	//bubbleSort(arr,size);
	optiBubbleSort(arr,size);
	printf("The array after sorting : ");
	printArray(arr,size);
	return 0;
}