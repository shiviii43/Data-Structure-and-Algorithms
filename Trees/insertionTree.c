//Insertion in Tree Data Structure

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int value);
void insertNode(struct Node** root,int val);
void preOrder(struct Node* root);
int main(){
	struct Node* root = NULL;
	insertNode(&root,4);
	insertNode(&root,5);
	insertNode(&root,6);
	insertNode(&root,7);
	printf("\nThe PreOrder Traversal of the tree is : ");
	preOrder(root);
	return 0;
}

void insertNode(struct Node** root,int val){
	//First condition when the root is NULL.
	struct Node* r = createNode(val);
	if(*root==NULL){
		*root = r;
		return;
	}
	else if((*root)->left==NULL){
		(*root)->left = r;
		return;
	}
	else{
		(*root)->right = r;
	}
}
void preOrder(struct Node* root){
	if(root!=NULL){
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
struct Node* createNode(int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	ptr->right = NULL;
	ptr->left = NULL;
	return ptr;
}
