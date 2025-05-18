//Circular linked List

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
	
};
void traverseCLL(struct Node* head);
struct Node* insertAtBeginning(struct Node* head, int value);


int main(){
	int val;
	struct Node* head = NULL;
	struct Node* p1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p5 = (struct Node*)malloc(sizeof(struct Node));
	
	// 1 3 5 7 9
	head = p1;
	p1->data = 1;
	p1->next = p2;
	p2->data = 3;
	p2->next = p3;
	p3->data = 5;
	p3->next = p4;
	p4->data = 7;
	p4->next = p5;
	p5->data = 9;
	p5->next = head;
	
	
	printf("Enter the element you want to insert at the beginning : ");
	scanf("%d",&val);
	printf("before\n");
	traverseCLL(head);
	head = insertAtBeginning(head,val);
	printf("\nafter\n");
	traverseCLL(head);
}
struct Node* insertAtBeginning(struct Node* head, int value){
	
	struct Node* temp = head;
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	ptr->next = temp;
	
}
void traverseCLL(struct Node* head){
	struct Node* temp;
	temp = head;
	printf("The Linked List is : \n[ ");
	do{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("]");
}