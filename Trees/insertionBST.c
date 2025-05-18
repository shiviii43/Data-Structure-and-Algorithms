/*
	Insertion in a Binary Search Tree.
	The insertion in a Binary Search Tree always takes place at the Leaf Node.
	So we don't have to take care of cases to manage the tree's structure unlike the deletion concept.
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
struct Node* insert(struct Node* root, int key);
int main(){
	struct Node* root = createNode(50);
	root = insert(root,40);
	root = insert(root,60);
	root = insert(root,30);
	root = insert(root,45);
	root = insert(root,55);
	root = insert(root,70);
	//insert(root,50);
	
	printf("\nInOrder : ");
	inOrder(root);
	return 0;
}

struct Node* insert(struct Node* root, int key){
	struct Node* prev = NULL;
	struct Node* temp = root;
	//Handling if the tree is empty or does not contain any elements.
	if(temp==NULL)
		return createNode(key);
	while(temp!=NULL){
		prev = temp;
		if(temp->data==key){
			printf("The key already exists in the Tree and cannot be inserted again.\n");
			return root;
		}
		else if(temp->data>key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	struct Node* newNode = createNode(key);
	if(prev->data>key)
		prev->left = newNode;
	else
		prev->right = newNode;

	return root;
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