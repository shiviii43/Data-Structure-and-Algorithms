//Menu Driven Program for Singly Linked List.

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

struct Node* createNode(int value);

struct Node* insertAtStart(struct Node* head,int value);
void insertAtLast(struct Node* head, int value);
void insertAfterValue(struct Node* head,int preValue,int value);
void insertAtIndex(struct Node* head, int value, int index);

struct Node* deleteAtFirst(struct Node* head);
void deleteAtLast(struct Node* head);
void deleteWithValue(struct Node* head, int value);
void deleteAtIndex(struct Node* head,int index);

void updateAtValue(struct Node* head, int preVal, int newVal);

void linearSearch(struct Node* head, int key);

void traverseList(struct Node* head);

int main(){
	
	int ch, val=0,index,key,pVal,nVal;
	
	while(1)
	{
		printf("\n\t---***MENU***---\t\n");
		printf("1.Create a Node.\n");
		printf("2.Insert at Start.\n");
		printf("3.Insert at End.\n");
		printf("4.Insert after a value.\n");
		printf("5.Insert at an index.\n");
		printf("6.Delete the First element.\n");
		printf("7.Delete the Last element.\n");
		printf("8.Delete at an index.\n");
		printf("9.Delete element with a certain value.\n");
		printf("10.Update value at an index.\n");
		printf("11.Search an element in the Linked List.\n");
		printf("12.Display the Current Linked List.\n");
		printf("13.EXIT\n\n");
		printf("Please chose an option from the above menu :");
		scanf("%d",&ch);
		
		switch(ch){
			case 1: 
				printf("\nEnter the value you want to insert in the node :");
				scanf("%d",&val);
				struct Node* head = createNode(val);
				printf("Node created successfully.\n");
				break;
			case 2 :
				printf("Enter the value you want to insert :");
				scanf("%d",&val);
				struct Node* ptr = insertAtStart(head, val);
				printf("Inserted Successfully!\n");
				break;
			case 3 :
				printf("Enter the value you want to insert :");
				scanf("%d",&val);
				insertAtLast(head,val);
				printf("Inserted Successfully!\n");
				break;
			
			case 4 :
				printf("\nEnter the value you want to insert node after :");
				scanf("%d",&pVal);
				printf("\nEnter the value you want to insert : ");
				scanf("%d",&nVal);
				insertAfterValue(head,pVal,nVal);
				printf("Inserted Successfully!\n");
				break;
				
			case 5:
				printf("\nEnter the index at which you want to insert a Node : ");
				scanf("%d",&index);
				printf("\nEnter the Value you want to insert at %d index : ",index);
				scanf("%d",&val);
				insertAtIndex(head,val,index);
				printf("Inserted Successfully!\n");
				break;
			case 6 : 
				deleteAtFirst(head);
				printf("Deleted Successfully !!\n");
				break;
				
			case 7 :
				deleteAtLast(head);
				printf("Deleted Successfully !!\n");
				break;
				
			case 8 :
				traverseList(head);
				printf("\nEnter the index of element you want to delete: ");
				scanf("%d",&index);
				deleteAtIndex(head,index);
				printf(" Deleted Successfully!!\n");
				break;
				
			case 9 :
				traverseList(head);
				printf("\nFrom the Above List, Enter the value you want to delete :");
				scanf("%d",&val);
				deleteWithValue(head,val);
				printf("Successfully Deleted !!\n");
				break;
				
			case 10:
				traverseList(head);
				printf("\nEnter the value you want to update from the above list : ");
				scanf("%d",&pVal);
				printf("\nEnter the new vale that you want to insert instead : ");
				scanf("%d",&nVal);
				updateAtValue(head,pVal,nVal);
				printf("Successfully Updated !!\n");
				break;
				
			case 11 : 
				printf("\nEnter the element you want to search in the Linked List :");
				scanf("%d",&key);
				linearSearch(head,key);
				break;
				
			case 12:
				traverseList(head);
				break;
				
			case 13:
				printf("\nTHANK YOU!");
				exit(1);
				break;	
						
			default :
				printf("\nInvalid choice ! Please enter again !!\n");
				break;
		}
	}
	return 0;
}

struct Node* createNode(int value){
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));
	head->data = value;
	head->next = NULL;
	return head;
}

struct Node* insertAtStart(struct Node* head,int value){
	struct Node* ptr = createNode(value);
	ptr->next=head;
	return ptr;
}

void insertAtLast(struct Node* head, int value){
	struct Node* ptr = createNode(value);
	struct Node* temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = ptr;
}

void insertAfterValue(struct Node* head,int preValue,int value){
	struct Node* ptr = createNode(value);
	struct Node* temp = head;
	while(temp->data!=preValue){
		temp = temp->next;
	}
	ptr->next = temp->next;
	temp->next = ptr;
}

void insertAtIndex(struct Node* head, int value, int index){
	struct Node* ptr = createNode(value);
	struct Node* p = head;
	int i = 0;
	while(i!=index-1){
		i++;
		p = p->next;
	}
	ptr->next = p->next;
	p->next = ptr;
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

struct Node* deleteAtFirst(struct Node* head){
	struct Node* temp;
	temp=head->next;
	free(head);
	return temp;
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

void updateAtValue(struct Node* head, int preVal, int newVal){
	struct Node* ptr = head;
	while(ptr->data!=preVal){
		ptr = ptr->next;
	}
	ptr->data = newVal;
}
