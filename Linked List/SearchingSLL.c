/*
	Searching in a Linked List.
	=>As Linked List is Sequential when comes to data access meaning that we can only apply linear search to it.
	=>Time complexity - 0(n)
*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int value);
void linearSearch(struct Node* head, int key);
void traverseList(struct Node* head);

int main()
{		
		//15 20 22 84 51 3 9 7 97 1
	struct Node* head = createNode(15);
	struct Node* p1 = createNode(20);
	struct Node* p2 = createNode(22);
	struct Node* p3 = createNode(84);
	struct Node* p4 = createNode(51);
	struct Node* p5 = createNode(3);
	struct Node* p6 = createNode(9);
	struct Node* p7 = createNode(7);
	struct Node* p8 = createNode(97);
	struct Node* p9 = createNode(1);
	
	head->next = p1;
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	p6->next = p7;
	p7->next = p8;
	p8->next = p9;
	p9->next = NULL;
	
	int ele;
	printf("Enter the element you want to search in the Linked List : ");
	scanf("%d",&ele);
	linearSearch(head,ele);
	traverseList(head);
	return 0;
}

struct Node* createNode(int value){
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = value;
	return head;
}
void linearSearch(struct Node* head, int key){
	int flag = 1,i=0;
	struct Node* temp;
	temp = head;
	while(temp!=NULL){
		if(temp->data == key){
			flag--;
			printf("\n%d was found at %d position in the Linked List.\n",key,i+1);
			return;
		}
		temp = temp->next;
		i++;
	}
	if(flag){
		printf("\n%d was not present in the Linked List\n");
	}
}
void traverseList(struct Node* head){
	struct Node* temp = head;
	printf("\nLinked List : [ ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("]");
}