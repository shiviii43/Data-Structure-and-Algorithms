/*	
	Insertion of a Node in Linked List.
		This can be done at there locations : 
		a.The starting of the Linked List.
		b.At a certain index.
		c.At the Ending/Last of the Linked List.
		d.Insert after a node(node address is given).
		e.Insert after a value.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;	
};

void traverseList(struct Node* head);
struct Node* insertAtFirst(struct Node* head, int value);
void insertAtIndex(struct Node* head, int value, int index);
void insertAtLast(struct Node*, int value);
void insertAfterNode(struct Node* prevNode, int value);
void insertAfterValue(struct Node* head, int preValue, int value);

int main(){
	
	struct Node* head;
	struct Node* second;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = NULL;
	
	traverseList(head);
	printf("\nAfter insertion at First\n");
	head = insertAtFirst(head,5);
	traverseList(head);
	printf("\nAfter insertion at Index(2)\n");
	insertAtIndex(head,6,2);
	traverseList(head);
	printf("\nAfter insertion at End\n");
	insertAtLast(head,3);
	traverseList(head);
	printf("\nAfter insertion after a Node(second)\n");
	insertAfterNode(second,8);
	traverseList(head);
	printf("\nAfter insertion After a Value(6)\n");
	insertAfterValue(head,6,7);
	traverseList(head);
	return 0;
}

struct Node* insertAtFirst(struct Node* head, int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->next=head;
	ptr->data=value;
	return ptr;
}

void insertAtIndex(struct Node* head, int value, int index){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	struct Node* p = head;
	int i = 0;
	while(i!=index-1){
		i++;
		p = p->next;
	}
	ptr->next = p->next;
	p->next = ptr;
}

void insertAtLast(struct Node* head, int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	ptr->next = NULL;
	
	struct Node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = ptr;
}

void insertAfterNode(struct Node* prevNode,int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	
	ptr->next = prevNode->next;
	prevNode->next = ptr;
}

void insertAfterValue(struct Node* head,int preValue,int value){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = value;
	
	struct Node* temp = head;
	while(temp->data!=preValue){
		temp = temp->next;
	}
	ptr->next = temp->next;
	temp->next = ptr;
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
