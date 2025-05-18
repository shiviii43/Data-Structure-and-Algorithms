/*
	Deleting a node from a BST includes three major cases that we have to handle, they are as:
	
	a. Deleting a node with no children (Leaf Node Deletion).
	=> Simply delete that node and free its memory.
	
	b. Deleting a node with a single child (Not a Leaf Node)
	=> Replace the node with its successor node in the Tree and then free the memory of the removed node.
	
	c. Deleting a node with two childen (Root Node Deletion)
	=> Replace the node with its in-order successor(smallest value in the right subtree), then delete the successor.

	*SIMPLEST ALTERNATE LOGIC*
	a.Simply Perform Binary Search and reach the Node that needs to be deleted.
	b.Create a function that takes the deleteable Node as a parameter and then checks for its Left subtree's :
		if the Left Subtree is not null simply exchange the Deletable Node with the Max/Largest element of the Left Subtree.
		else if it is NULL check for its Right Subtree : 
		 exchange the deletable Node with the Min/Smallest value in the Right SubTree, if the right subtree is NULL as well simply exchange the deletable with NULL.
	This approach simply handles all the 3 cases of deletion in a single function.
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
struct Node* insertNode(struct Node* root, int value);
struct Node* deleteNode(struct Node* root, int key);
struct Node* smallest(struct Node* root);

int main(){
	struct Node* root = NULL;
	root = insertNode(root,8);
	root = insertNode(root,10);
	root = insertNode(root,3);
	root = insertNode(root,1);
	root = insertNode(root,6);
	root = insertNode(root,7);
	root = insertNode(root,4);
	root = insertNode(root,14);
	root = insertNode(root,13);
	//struct Node* min = smallest(root);
	//printf("The Smallest Element in the Tree is : %d",min->data);
	printf("\nInOrder Before : ");
	inOrder(root);
	//root = deleteNode(root,16);			//Deleting a Node that does not exists.
	root = deleteNode(root,4);			//Deleting a Leaf Node from the tree.	[CASE 1]
	//root = deleteNode(root,14);				//Deleting a Node with single child from the tree.	[CASE 2]
	root = deleteNode(root,3);				//Deleting a Root Node or a Node with two children. [CASE 3]
	printf("\nInOrder After : ");
	inOrder(root);
	return 0;
}

struct Node* smallest(struct Node* root){
	//Traversing till the leftmost element in the tree as it is the samllest one in the tree.
	struct Node* prev = NULL;
	while(root->left!=NULL){
		prev = root;
		root = root->left;
	}
	prev->left = NULL;
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
struct Node* insertNode(struct Node* root, int value){
	
	struct Node* prev = NULL;
	struct Node* temp = root;
	//When the tree is empty.
	if(temp==NULL)
		return createNode(value);
	while(temp!=NULL){
		prev = temp;
		if(temp->data==value){
			printf("\nThe value already exists in the tree and hence cannot be inserted.\n");
			return root;
		}
		else if(temp->data>value)
			temp = temp->left;
		else 
			temp = temp->right;
	}
	struct Node* newNode = createNode(value);
	if(prev->data>value)
		prev->left = newNode;
	else
		prev->right = newNode;
	return root;
}
struct Node* deleteNode(struct Node* root, int key){
	struct Node* temp = root;
	struct Node* prev = NULL;
	int flag = 0;
	//When the tree is empty.
	if(temp==NULL){
		printf("\nCannot delete as the Tree is empty.");
		return root;
	}
	//Search for the Node you want to delete
	while(temp!=NULL){
		if(temp->data==key){
			flag++;
			break;
		}
		prev = temp;
		if(temp->data>key){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	if(flag){
		/*				CURRENT STATE
			This Block of code will be entered only when the element was found.
			The temp pointer currently points the desired deletable node.
			The prev pointer holds the ancester or the parent node of the temp pointer node.
		*/

		//CASE 1 : Deleting a Leaf Node or the Node with no children.
		if(temp->left==NULL && temp->right==NULL){
			if(prev->left==temp)
				prev->left = NULL;
			else
				prev->right = NULL;
			printf("\nThe Leaf Node %d was deleted Successfully.",temp->data);
			free(temp);		//Freeing up the deleted node.
			return root;
		}
		//CASE 2 : Deleting a Node with only a single child.
		else if(temp->left==NULL||temp->right==NULL){
			//When the left of the desired deletable is Not Null.
			if(temp->left!=NULL){
				if(prev->left==temp)
					prev->left = temp->left;
				else
					prev->right = temp->left;
			}
			//When the right of the desired deletable is Not Null.
			else{
				if(prev->left==temp)
					prev->left = temp->right;
				else
					prev->right = temp->right;
			}
			printf("\nThe Internal Node %d deleted Successfully.",key);
			free(temp);		//Freeing up the deleted Node.
			return root;
		}
		//CASE 3 : Deleting a Node with 2 children nodes.
		else{
			struct Node* min = smallest(temp->right);		//The Minimum element is stored here
			/*	LOGIC 1 :
			min->left = temp->left;
			min->right = temp->right;
			if(prev->left==temp)
				prev->left = min;
			else
				prev->right = min;
			*/
			temp->data = min->data;		//Logic 2 : Simply override the value of temp with the min value.
			printf("\nThe Root Node %d was deleted SuccessFully.",key);
			free(min);
			return root;
		}
	}
	else{
		//Entering this block means that the element was not found in the tree.
		printf("\nThe Element : %d was not found in the Tree.",key);
		return root;
	}
}