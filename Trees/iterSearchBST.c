/*
	Iterative Search in a Binary Search Tree.
	Approach : Without using recurrsion search for a key in the BST.
			make a temp pointer pointing to the root of the tree.
			a.check if the pointer is not NULL.
			b.check for the value of pointer.
			c.if value of key is greater traverse the right of the current pointer location.
			d.else traverse the left to the current pointer location.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;	
};

struct Node* createNode(int value);
void inOrder(struct Node* root);
struct Node* iterSearchBST(struct Node* root, int key);
int main(){
	int key;
	struct Node* root = createNode(50);
	struct Node* p1 = createNode(40);
	struct Node* p2 = createNode(60);
	struct Node* p3 = createNode(30);
	struct Node* p4 = createNode(55);
	struct Node* p5 = createNode(70);
	struct Node* p6 = createNode(20);
	struct Node* p7 = createNode(45);
	struct Node* p8 = createNode(65);
	struct Node* p9 = createNode(80);
	
	root->left = p1;
	root->right = p2;
	p1->left = p3;
	p1->right = p7;
	p3->left = p6;
	p2->left = p4;
	p2->right = p5;
	p5->left = p8;
	p5->right = p9;

	printf("Enter the element you want to search in the BST : ");
	scanf("%d",&key);
	struct Node* res = iterSearchBST(root,key);
	if(!res)
		printf("The Element was not found in the Tree.");
	else
		printf("Found : %d",res->data);
	return 0;
}
struct Node* iterSearchBST(struct Node* root, int key){
	struct Node* ptr = root;
	while(ptr!=NULL){
		if(ptr->data==key)
			return ptr;
		else if(ptr->data>key)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}
	return NULL;
}
struct Node* createNode(int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}
void inOrder(struct Node* root){
	if(root!=NULL){
		inOrder(root->left);
		printf("%d ",root->data);
		inOrder(root->right);
	}
}