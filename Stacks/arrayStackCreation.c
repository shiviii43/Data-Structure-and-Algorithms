//Stack implementaion using Arrays.

#include<stdio.h>
#include<stdlib.h>


//ADT of an Array based Stack Data Structure.
struct stack {
	int size;
	int top;
	int *arr;
};

void display(struct stack* ptr);

int main(){
	
	//The memory has been allocated for the stack data structure 
	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	
	s->size = 5;
	s->top = -1;
	s->arr = (int *)malloc(s->size * sizeof(int));
	
	//manually inserting data into the Stack.
	s->arr[0] = 7;
	s->top++;
	s->arr[1] = 9;
	s->top++;
	s->arr[2] = 13;
	s->top++;
	s->arr[3] = 19;
	s->top++;
	display(s);
	return 0;
}

void display(struct stack* ptr){
	if(ptr->top == -1){
		printf("The stack is empty.\n");
		return;
	}
	while(ptr->top!=-1){
		printf("%d ",ptr->arr[ptr->top]);
		ptr->top--;
	}
}
