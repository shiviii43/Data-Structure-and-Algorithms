/*
	Operations on Stacks
	a.Push operation 
	b.POP operation
	c.isEmpty operation 
	d.isFull operation
	e.Peek operation
	f.Display operation
*/

#include<stdlib.h>
#include<stdio.h>

struct stack {
	int size;
	int top;
	int *arr;
};

int isEmpty(struct stack* ptr);
int isFull(struct stack* ptr);
void push(struct stack* ptr, int value);
void pop(struct stack *ptr);
int peek(struct stack* ptr);
void display(struct stack* ptr);

int main(){
	int ele;
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	s->size = 10;
	s->top = -1;
	s->arr = (int*)malloc(s->size * sizeof(int));
	
	printf("Enter the element you want to insert : ");
	scanf("%d",&ele);
	push(s,ele);
	printf("Enter the element you want to insert : ");
	scanf("%d",&ele);
	push(s,ele);
	int p = peek(s);
	printf("%d", p);
	pop(s);
	display(s);
	free(s);
	return 0;
}

int isEmpty(struct stack* ptr){
	if(ptr->top == -1){
		return 1;
	}
	return 0;
}

int isFull(struct stack* ptr){
	if(ptr->top == ptr->size-1){
		return 1;
	}
	return 0;
}

void push(struct stack* ptr, int value){
	if(isFull(ptr)){
		printf("\nStack Overflow !! Cannot insert anymore !!\n");
		return;
	}
	ptr->top++;
	ptr->arr[ptr->top] = value;
	printf("\nSuccessfully Inserted %d into stack.\n",value);
}

void pop(struct stack* ptr){
	if(isEmpty(ptr)){
		printf("\nStack Underflow!! Cannot fetch elements !!\n");
		return;
	}
	printf("\nSuccessfully Deleted %d from the stack.\n",ptr->arr[ptr->top]);
	ptr->top--;
}

int peek(struct stack* ptr){
	if(isEmpty(ptr)){
		printf("\nStack Underflow!!\n");
		return 0;
	}
	return ptr->arr[ptr->top];
}

void display(struct stack* ptr){
	if(isEmpty(ptr)){
		printf("Stack Underflow!!");
		return;
	}
	printf("\nThe STACK is : ( ");
	while(ptr->top!=-1){
		printf("%d ",ptr->arr[ptr->top]);
		ptr->top--;
	}
	printf(")");
}
