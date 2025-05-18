//Creation of STACK DATA STRUCTURE using Singly Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

int isEmpty(struct Node** top);
int isFull();
void display(struct Node* top);
struct Node** push(struct Node** top, int value);
struct Node** pop(struct Node** top);
int peek(struct Node** top);

int main(){
	//Linked List - > 12 78 98 9 56
	struct Node** top;
	struct Node* p1 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p2 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p3 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p4 = (struct Node*)malloc(sizeof(struct Node));
	struct Node* p5 = (struct Node*)malloc(sizeof(struct Node));
	//Initializing all of them
	top = &p1;
	p1->data = 12;
	p1->next = p2;
	p2->data =  78;
	p2->next = p3;
	p3->data = 98;
	p3->next = p4;
	p4->data = 9;
	p4->next = p5;
	p5->data = 56;
	p5->next = NULL;
	//display(*top);
	//top = push(top,1);
	//display(*top);
	//top = pop(top);
	display(*top);	
	
	printf("\n%d",isEmpty(top));
	printf("\n%d",isFull());
	int x = peek(top);
	printf("\n%d",x);
	return 0;
}

int peek(struct Node** top){
	if(*top==NULL){
		printf("\nThe Stack is Empty\n");
		return 0;
	}
	return (*top)->data;
}

int isEmpty(struct Node** top){
	if(top==NULL)
		return 1;
	return 0;
}

int isFull(){
	//The malloc function returns 0 if the memory requested is not allocated.
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	if(ptr==NULL){
		return 1;
	}
	free(ptr);
	return 0;
}

struct Node** push(struct Node** top, int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	struct Node* temp = *top;
	ptr->next = temp;
	top = &ptr;
	return top;
}

struct Node** pop(struct Node** top){
	struct Node* temp;
	temp = *top;
	temp = temp->next;
	top = &temp;
	return top;
}

void display(struct Node* top){
	printf("\nThe Stack is : [ ");
	struct Node* p = top;
	while(p!=NULL){
		printf("%d ",p->data);
		p = p->next;
	}
	printf("]");
}
