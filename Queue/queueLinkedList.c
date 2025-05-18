//Queue Data Structure using Linked List representaion.

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

void displayQueue(struct Node* front, struct Node* rear);	//done
int isEmpty(struct Node* front, struct Node* rear);	//done
int isFull();		//done
struct Node* createNode(int value);		//done
void enQueue(struct Node** front, struct Node** rear, int value);	
void deQueue(struct Node** front, struct Node** rear);
int getFront(struct Node* front);	//done
int getRear(struct Node* rear);		//done

int main(){
	struct Node* front=NULL;
	struct Node* rear=NULL;
	enQueue(&front,&rear,7);
	enQueue(&front,&rear,14);
	enQueue(&front,&rear,21);
	enQueue(&front,&rear,28);
	enQueue(&front,&rear,35);
	displayQueue(front, rear);
	deQueue(&front,&rear);
	deQueue(&front,&rear);
	displayQueue(front,rear);
	printf("\nFRONT : %d",getFront(front));
	printf("\nREAR : %d",getRear(rear));
	printf("\nIsFULL : %d",isFull());
	printf("\nisEmpty : %d",isEmpty(front,rear));
	return 0;
}
void deQueue(struct Node** front,struct Node** rear){
	struct Node* temp = *front;
	//If the Queue is initially empty.
	if(isEmpty(*front,*rear)){
		printf("Queue UnderFlow, cannot print!!\n");
		return;
	}
	//If the Queue consist of only a single element.
	else if(*front==*rear){
		*front = *rear = NULL;
		free(temp);
		return;
	}
	//If the Queue consist of more than 1 element.
	*front = (*front)->next;
	free(temp);
}
int getRear(struct Node* rear){
	if(rear==NULL){
		printf("\nQueue Empty.\n");
		return -1;
	}
	return rear->data;
}
int getFront(struct Node* front){
	if(front==NULL){
		printf("\nQueue Empty.\n");
		return -1;
	}
	return front->data;
}
int isFull(){
	struct Node* ptr =(struct Node*)malloc(sizeof(struct Node));
	if(ptr==NULL)
		return 1;
	free(ptr);
	return 0;
}
void displayQueue(struct Node* front, struct Node* rear){
	//For Empty Queue
	if(isEmpty(front, rear)){
		printf("\nQueue Underflow, cannot print!!\n");
		return;
	}
	struct Node* tFront=front;
	struct Node* tRear=rear;
	printf("\nThe Queue is : [ ");
	//For Queue consisting of a single element
	if(tFront==tRear){
		printf("%d ]",tFront->data);
		return;
	}
	while(tFront!=NULL){
		printf("%d ",tFront->data);
		tFront = tFront->next;
	}
	printf("]");
}
int isEmpty(struct Node* front, struct Node* rear){
	if(front==NULL && rear==NULL)
		return 1;
	return 0;
}
void enQueue(struct Node** front, struct Node** rear, int value){
	struct Node* ptr = createNode(value);
	if(isEmpty(*front,*rear)){
		*front = ptr;
		*rear = ptr;
	}
	else if(isFull()){
		printf("\nQueue Full cannot insert.\n");
		return;
	}
	(*rear)->next = ptr;
	*rear = (*rear)->next;
}
struct Node* createNode(int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	ptr->next = NULL;
	return ptr;
}