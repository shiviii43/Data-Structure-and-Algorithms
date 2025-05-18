//Tree Data Structure using Linked List representaion

#include<stdio.h>
#include<stdlib.h>

//Structural design of a Tree.
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
/*
	The tree initially looks like : 
	 
		 4
		/ \
	   1   6
	  / \
	 5   2
*/

struct Node* createNode(int value);
void preOrder(struct Node* root);
void inOrder(struct Node* root);
void postOrder(struct Node* root);

int main(){
	//creating Nodes of the tree
	struct Node* root = createNode(4);
	struct Node* r1 = createNode(1);
	struct Node* r2 = createNode(6);
	struct Node* r3 = createNode(5);
	struct Node* r4 = createNode(2);
	//Linking the Nodes to form a tree structure
	root->left = r1;
	root->right = r2;
	r1->left = r3;
	r1->right = r4;
	//Traversing the tree in different orders.
	printf("\nThe PreOrder Traversal of the Tree is : ");
	preOrder(root);
	printf("\nThe InOrder Traversal of the Tree is : ");
	inOrder(root);
	printf("\nThe PostOrder Traversal of the Tree is : ");
	postOrder(root);
	return 0;
	
}

struct Node* createNode(int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}
void preOrder(struct Node* root){
	if(root!=NULL){
		printf("%d ",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void inOrder(struct Node* root){
	if(root!=NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}
void postOrder(struct Node* root){
	if(root!=NULL){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ",root->data);
	}
}