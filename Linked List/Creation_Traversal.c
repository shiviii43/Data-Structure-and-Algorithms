//Linked List creation and traversal.

#include<stdio.h>
#include<stdlib.h>			//This is used for the malloc function

struct Node{
	//A node of linked List will consist of 2 major things - Data and the address of next node
	int data;
	struct Node* next;		//This will be a pointer that is of Node type as it points to next Node.
};

void traverseList(struct Node* head);
int main(){
	
	//Create a HEAD pointer that points to the Memory location of first Node and then multiple nodes.
	struct Node* head;
	struct Node* second;
	struct Node* third;
	struct Node* fourth;
	//Use the malloc function to allocate memory to each node created.
	//Syntax - (type_conversion)malloc(sizeof(variable_you_want_to_create));
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	//Inserting Values in these created Nodes and Linking them to each other.
	//example : 12  45	69	75
	//Head node data then the head node pointing to the next node.
	head->data = 12;
	head->next = second;
	//Same procedure for the remaining nodes.
	second->data = 45;
	second->next = third;
	//Same for the third node.
	third->data = 69;
	third->next = fourth;
	//The same for the fourth node, and the last node of the LinkedList will contain NULL as the next Node Address.
	fourth->data = 75;
	fourth->next = NULL;
	
	//Calling the traversal function and passing on the head location to access all the elements.
	traverseList(head);
	traverseList(head);
	return 0;
}

void traverseList(struct Node* head){
	//We traverse by printing the data present in the node.
	//And the base condition is that the Node must not be null.
	struct Node* temp = head;
	printf("Linked List : [ ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("]");
}