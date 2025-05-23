//Reverse a Linked List 

/*
	Input: head: 1 -> 2 -> 3 -> 4 -> NULL
	Output: head: 4 -> 3 -> 2 -> 1 -> NULL
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	ptr->next=NULL;
	return ptr;
}

void display(struct Node* head){
	if(head==NULL){
		printf("Cannot print as the Linked List is Empty !!");
		return;
	}
	while(head!=NULL){
		printf("%d ",head->data);
		head = head->next;
	}
}

struct Node* reverse(struct Node* head){
	//create 3 pointers : prev, cur, and nextP 
	struct Node* prev = NULL;
	struct Node* cur = head;
	struct Node* nextP;
	
	while(cur!=NULL){
		nextP = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nextP;
		
	}
	return prev;
}

int main(){
	
	struct Node* head = createNode(1);
	struct Node* p1 = createNode(2);
	struct Node* p2 = createNode(3);
	struct Node* p3 = createNode(4);
	
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	
	display(head);	
	head = reverse(head);
	printf("\nLinked List after reverse : ");
	display(head);
	return 0;
}