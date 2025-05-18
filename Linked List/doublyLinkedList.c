//Doubly Linked List in Data Structure

#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};

//creation
struct Node* createNode(int val);
//insertion
struct Node* insertAtFirst(struct Node* head, int val);
void insertAtLast(struct Node* head, int val);
void insertAtIndex(struct Node* head,int val,int index);
void insertBeforeValue(struct Node* head,int newVal,int val);
//deletion
struct Node* deleteAtFirst(struct Node* head);
void deleteAtLast(struct Node* head);
void deleteAtValue(struct Node* head,int val);
void deleteAtIndex(struct Node* head, int index);
//traversal
void traverseList(struct Node* head);
void traverseReverseList(struct Node* head);

int main(){
	struct Node* head;
	head = NULL;
	//insertion
	head = insertAtFirst(head,9);
	traverseList(head);
	head = insertAtFirst(head,15);
	traverseList(head);
	head = insertAtFirst(head,18);
	traverseList(head);
	insertAtLast(head,6);
	traverseList(head);
	insertAtLast(head,3);
	traverseList(head);
	insertAtIndex(head,12,2);
	traverseList(head);
	insertBeforeValue(head,10,9);
	traverseList(head);
	traverseReverseList(head);
	//deletion
	head = deleteAtFirst(head);
	traverseList(head);
	deleteAtLast(head);
	traverseList(head);
	deleteAtValue(head,10);
	traverseList(head);
	deleteAtIndex(head,2);
	traverseList(head);
	
	return 0;
}

void deleteAtIndex(struct Node* head, int index){
	struct Node* preNode = head;
	struct Node* nextNode = preNode->next;
	int i=1;
	while(i!=index){
		preNode = nextNode;
		nextNode = nextNode->next;
		i++;
	}
	preNode->next = nextNode->next;
	struct Node* t = nextNode;
	nextNode = nextNode->next;
	nextNode->prev = preNode;
	free(t);
}

void deleteAtValue(struct Node* head, int val){
	struct Node* preNode = head;
	struct Node* nextNode = head->next;
	while(nextNode->data!=val){
		preNode = nextNode;
		nextNode = nextNode->next;
	}
	preNode->next = nextNode->next;
	struct Node* temp = nextNode;
	nextNode = nextNode->next;
	nextNode->prev = preNode;
	free(temp);
}

void deleteAtLast(struct Node* head){
	struct Node* preNode = head;
	struct Node* nextNode = head->next;
	while(nextNode->next!=NULL){
		preNode = nextNode;
		nextNode = nextNode->next;
	}
	preNode->next = NULL;
	free(nextNode);
}

struct Node* deleteAtFirst(struct Node* head){
	head = head->next;
	head->prev = NULL;
	return head;
}

void traverseReverseList(struct Node* head){
	struct Node* t = head;
	while(t->next!=NULL){
		t = t->next;
	}
	printf("\nThe Reverse Linked List is : [ ");
	while(t!=NULL){
		printf("%d ",t->data);
		t = t->prev;
	}
	printf("]");
}

void insertBeforeValue(struct Node* head, int newVal, int val){
	struct Node* ptr = createNode(newVal);
	struct Node* preNode = head;
	struct Node* nextNode = preNode->next;
	while(nextNode->data!=val){
		preNode = nextNode;
		nextNode = nextNode->next;
	}
	preNode->next = ptr;
	ptr->prev = preNode;
	ptr->next = nextNode;
	nextNode->prev = ptr;
}

void insertAtIndex(struct Node* head,int val,int index){
	struct Node* ptr = createNode(val);
	struct Node* preNode = head;
	struct Node* nextNode = preNode->next;
	int i = 1;
	while(i!=index){
		preNode = nextNode;
		nextNode = nextNode->next;
		i++;
	}
	preNode->next = ptr;
	ptr->prev = preNode;
	ptr->next = nextNode;
	nextNode->prev = ptr;
}

void insertAtLast(struct Node* head,int val){
	struct Node* ptr = createNode(val);
	struct Node* tNext;
	struct Node* tPrev;
	tPrev = head;
	tNext = tPrev->next;
	while(tNext!=NULL){
		tPrev = tNext;
		tNext = tNext->next;
	}
	tPrev->next = ptr;
	ptr->prev = tPrev;
}

struct Node* insertAtFirst(struct Node* head,int val){
	//Case 1 : when the Linked List is Empty
	struct Node* p1 = createNode(val);
	p1->data = val;
	if(head==NULL){
		head = p1;
		p1->prev = NULL;
		p1->next = NULL;
		return head;
	}
	//Case 2 : when the Linked List is not empty.
	struct Node* temp;
	temp = head;
	head = p1;
	p1->prev = NULL;
	p1->next = temp;
	temp->prev = p1;
	return head;
}

void traverseList(struct Node* head){
	struct Node* temp = head;
	printf("\nThe Doubly Linked List is :[ ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("]");
}

struct Node* createNode(int val){
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = val;
	ptr->prev = NULL;
	ptr->next = NULL;
	return ptr;
}
