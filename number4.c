/*
	Name: Matidios, Henry
	Description: Implement a queue using two stacks.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char data;
	struct node *next;
	struct node *prev;
};

struct node *stack_head;
struct node *stack2_head;
int size;
int size2;

void displayArray();
void insertFront(char choices);
void insertRear(char choices);
void deleteFront();
void askUser();


void displayArray()		
{
	struct node *temp=stack2_head;
	
	while(temp!=NULL)
	{
		printf("%c ",temp->data);
		temp=temp->next;
	}
	printf("\n");
	
}
void insertFront(char choices)			//stack 1
{
	struct node *temp;
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=choices;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(stack_head!=NULL)
	{
		temp->next=stack_head;
		stack_head->prev=temp;
	}
	stack_head=temp;
	size++;
	insertRear(temp->data);
}
void insertRear(char choices)
{
	struct node *temp;
	struct node *current;
	struct node *before;
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=choices;
	temp->next=NULL;
	temp->prev=NULL;
	
	current=stack2_head;
	before=stack2_head;
	
	if(stack2_head==NULL)
	{
		stack2_head=temp;
	}
	else
	{
		while(current->next!=NULL)		//traverse the linked list
		{
			before=current;
			current=current->next;
		}
			current->next=temp;			//include the newly made node to the list
			temp->prev=current;
	}
}
void deleteFront()
{
	struct node *current;
	
	current=stack2_head;
	if(stack2_head->next!=NULL)
	{
		stack2_head=stack2_head->next;
	}
	/*dval=current->data;
	printf("Deleted value of the node: %c\n",dval);*/
	current->next=NULL;
	current->prev=NULL;
	size--;
}

void askUser()
{
	char choices='9';
	
	while(choices=='0'||choices=='1'||choices=='2'||choices=='3'||choices=='4'||choices=='5'||choices=='6'||choices=='7'||choices=='8'||choices=='9'||choices=='-'||choices=='='||choices=='_'||choices=='+'||choices=='?')
	{
		system("cls");
		printf("\n[*]-PUSH\n[ANY LETTER]-POP\n");
		choices=getch();
	}
	switch(choices)
	{
		case '*':
			deleteFront();
			displayArray();
			getch();
			askUser();
			break;
		default:
			insertFront(choices);
			displayArray();
			getch();
			askUser();
			break;
	}
}
void main()
{
	stack_head=NULL;
	stack2_head=NULL;
	
	askUser();
}
