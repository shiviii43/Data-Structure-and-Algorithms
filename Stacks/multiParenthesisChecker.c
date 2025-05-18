//Multiple Parenthesis Matching Using Stack.

#include<stdio.h>
#include<stdlib.h>

struct Node{
	char data;
	struct Node* next;
};

struct Node* createNode(char val);
struct Node* push(struct Node* top, char value);
struct Node* pop(struct Node* top);
int isEmpty(struct Node* top);
char peek(struct Node* top);
int matching(char a, char b);

int main(){
	char arr[] = "{[52+9(3*2)-3(2+2)/2]-3}";
	struct Node* top = NULL;
	int i=0,flag=1;
	while(arr[i]){
		if(arr[i]=='{'||arr[i]=='['||arr[i]=='('){
			top = push(top,arr[i]);
		}
		else if(arr[i]=='}'||arr[i]==']'||arr[i]==')'){
			if(isEmpty(top)){
				flag--;
				break;
			}
			else{
				char temp = peek(top);
				if(matching(temp,arr[i])){
					top = pop(top);
				}
				else{
					flag--;
					break;
				}
			}
		}
		i++;
	}
	if(top==NULL && flag==1){
		printf("\nThe Expression is Balanced.");
	}
	else{
		printf("\nThe Expression is Unbalanced.");
	}
}
char peek(struct Node* top){
	char top_val;
	top_val = top->data;
	return top_val;
}
int matching(char a, char b){
	if(a=='{'&&b=='}')
		return 1;
	else if(a=='['&&b==']')
		return 1;
	else if(a=='('&&b==')')
		return 1;
	else
		return 0;
}
struct Node* createNode(char val){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = val;
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