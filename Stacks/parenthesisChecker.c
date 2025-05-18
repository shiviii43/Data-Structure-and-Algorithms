//Parenthesis Checker using Stack Data Structure.

#include<stdio.h>
#include<stdlib.h>

struct Node{
	char data;
	struct Node* next;
};

int isEmpty(struct Node* top);
struct Node* createNode(char value);
struct Node* push(struct Node* top, char value);
struct Node* pop(struct Node* top);

int main(){
	char arr[] = "((3*1)+(2-1))";
	struct Node* top = NULL;
	int i=0,flag=1;
	while(arr[i]){
		if(arr[i]=='('){
			top = push(top,arr[i]);
		}
		else if(arr[i]==')'){
			if(isEmpty(top)){
				flag--;
				break;
			}
			top = pop(top);
		}
		i++;
	}
	if(top==NULL && flag==1){
		printf("The Expression is Balanced.\n");
	}
	else{
		printf("The Expression is Unbalanced.\n");
	}
	return 0;
}


struct Node* createNode(char value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	ptr->next = NULL;
	return ptr;
}
struct Node* push(struct Node* top, char value){
	struct Node* ptr = createNode(value);
	if(top==NULL){
		top = ptr;
		return top;
	}
	struct Node* temp = top;
	top = ptr;
	ptr->next = temp;
	return top;
}
struct Node* pop(struct Node* top){
	struct Node* temp;
	temp = top;
	top = top->next;
	free(temp);
	return top;
}
int isEmpty(struct Node* top){
	if(top==NULL){
		return 1;
	}
	return 0;
}
