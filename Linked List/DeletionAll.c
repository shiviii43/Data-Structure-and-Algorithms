/*
	Deletion in a Linked List
		a.Delete the First Element.
		b.Delete the Last Element.
		c.Delete value at a certain index.
		d.Delete After a certain node.
		e.Delete a certain value.
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
		int data;
		struct Node* next;
};

void traverseList(struct Node* head);
struct Node* deleteAtFirst(struct Node* head);
void deleteAtLast(struct Node* head);
void deleteAtIndex(struct Node* head, int index);
void deleteAfterNode(struct Node* preNode);
void deleteWithValue(struct Node* head, int value);

int main(){
	struct Node *head;
	struct Node *first;
	struct Node *second;
	struct Node *third;
	struct Node *fourth;
	
	head = (struct Node*)malloc(sizeof(struct Node));
	first = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 1;
	head->next = first;
	first->data = 2;
	first->next = second;
	second->data = 3;
	second->next = third;
	third->data = 4;
	third->next = fourth;
	fourth->data = 5;
	fourth->next = NULL;
	traverseList(head);
	//printf("\nAfter deleting the First element\n");
	//head = deleteAtFirst(head);
	//traverseList(head);
	//printf("\nAfter Deleting the element at index (2)\n");
	//deleteAtIndex(head,2);
	//traverseList(head);
	//printf("\nAfter Deleting the last element\n");
	//deleteAtLast(head);
	//traverseList(head);
	//printf("\nAfter Deleting the node after the second node\n");
	//deleteAfterNode(second);
	//traverseList(head);
	printf("\nAfter deleteing the node with 2 value\n");
	deleteWithValue(head,2);
	traverseList(head);	
	return 0;
}

struct Node* deleteAtFirst(struct Node* head){
	struct Node* temp;
	temp=head->next;
	free(head);
	return temp;
}

void deleteAtLast(struct Node* head){
	struct Node* p = head;
	struct Node* q = head->next;
	while(q->next!=NULL){
		p = p->next;
		q = q->next;
	}
	p->next = NULL;
	free(q);
}

void deleteAfterNode(struct Node* preNode){
	struct Node* nextNode;
	nextNode = preNode->next;
	preNode->next = nextNode->next;
	free(nextNode);
}

void deleteAtIndex(struct Node* head,int index){
	struct Node* p = head;
	struct Node* q = head->next;
	int i = 0;
	while(i!=index-1){
		i++;
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	free(q);
}

void deleteWithValue(struct Node* head, int value){
	struct Node* p = head;
	struct Node* q = head->next;
	while(q->data!=value){
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	free(q);
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