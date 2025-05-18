//Queue Data Structure using ARRAY implementaion.

#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int size;
	int front;
	int rear;
	int* arr;
};

void enqueue(struct Queue* q,int val);
void dequeue(struct Queue* q);
void display(struct Queue* q);
int getFront(struct Queue* q);
int getRear(struct Queue* q);
int isFull(struct Queue* q);
int isEmpty(struct Queue* q);

int main(){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->size = 5;
	q->front = -1;
	q->rear = -1;
	q->arr = (int*)malloc(q->size*sizeof(int));
	
	//Insertion in Queue 
	enqueue(q,3);
	enqueue(q,9);
	enqueue(q,12);
	enqueue(q,15);
	enqueue(q,18);
	display(q);
	dequeue(q);
	display(q);
	printf("Front : %d\n",getFront(q));
	printf("Rear : %d\n",getRear(q));
	printf("Empty : %d\n",isEmpty(q));
	printf("Full : %d\n",isFull(q));
	enqueue(q,6);
	return 0;
	
}
int getRear(struct Queue* q){
	if(q->rear==-1){
		printf("\nThe Queue is Empty, no rear element found.\n");
		return -1;
	}
	return q->arr[q->rear];
}
int getFront(struct Queue* q){
	if(q->front==-1){
		printf("\nThe Queue is Empty, no front element found.\n");
		return -1;
	}
	return q->arr[q->front];
}
void dequeue(struct Queue* q){
	if(isEmpty(q)){
		printf("\nThe Queue is already empty.\n");
		return;
	}
	else if(q->front==q->rear){
		q->front = q->rear = -1;
		return;
	}
	q->front++;
}
void enqueue(struct Queue* q,int value){
	if(isEmpty(q)){
		q->front = 0;
		q->rear = 0;
		q->arr[q->rear] = value;
	}
	else if(isFull(q)){
		printf("\nQueue Overflow, cannot insert !!\n");
		return ;
	}
	else{
		q->rear++;
		q->arr[q->rear] = value;
	}
}
int isEmpty(struct Queue* q){
	if(q->front==-1 && q->rear==-1)
		return 1;
	return 0;
}
int isFull(struct Queue* q){
	if(q->rear==q->size-1)
		return 1;
	return 0;
}
void display(struct Queue* q){
	if(isEmpty(q)){
		printf("\nQueue UnderFlow, cannot display.\n");
		return;
	}
	int tf = q->front ;
	int tr = q->rear;
	printf("The Queue : ");
	while(tf<=tr){
		printf("%d ",q->arr[tf]);
		tf++;
	}
	printf("\n");
}