/*
	Sorting in Singly Linked List.
		Types of Sortings allowed are : 
		a.Insertion Sort(Second Most Efficient)
		b.Bubble Sort 
		c.Merge Sort (Most Efficient)
		d.Quick Sort
		e.Heap Sort

	These are all the type of Sorting algorithms that can be applied on Linked List.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;	
};

void traverseList(struct Node** head);
void insertionSort();
void bubbleSort();
void mergeSort();
void quickSort();
void heapSort();

int main(){
	
	//create a Linked List of 5 Nodes.
	// [51,48,2,9,79]
	struct Node** head = NULL ;
	struct Node* p1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p5 = (struct Node*)malloc(sizeof(struct Node));
	
	head = &p1;
	p1->data = 51;
	p1->next = p2;
	p2->data = 48;
	p2->next = p3;
	p3->data = 2;
	p3->next = p4;
	p4->data = 9;
	p4->next = p5;
	p5->data = 79;
	p5->next = NULL;
	
	
	traverseList(head);
	
 /*a.Insertion Sort
	insertionSort(head);
	printf("\nAfter Sorting :\n");
	traverseList(head);
	
	//b.Bubble Sort
	bubbleSort(head);
	printf("\nAfter Sorting :\n");
	traverseList(head);
	
	//c.Merge Sort
	mergeSort(head);
	printf("\nAfter Sorting :\n");
	traverseList(head);
	
	//d.Quick Sort
	quickSort(head);
	printf("\nAfter Sorting :\n");
	traverseList(head);
	
	//e.Heap Sort
	heapSort(head);
	printf("\nAfter Sorting :\n");
	traverseList(head);
	
	return 0;
	*/
}

void traverseList(struct Node** head){
	if(head==NULL){
		printf("\nThe Linked List is Empty.\n");
		return;
	}
	struct Node* temp;
	temp = *head;
	printf("The Linked List is : \n[ ");
	while(temp!= NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("]");
}

