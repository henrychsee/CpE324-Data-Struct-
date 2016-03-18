/*
	Name: Matidios, Henry
	Description: Stack
	
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node *next;
	struct node *prev;
};

struct node *head;
char dval;
int size;

void displayArray();
void insertFront(char choices);
void deleteFront();
void askUser();

void displayArray()
{
	struct node *temp=head;
	
	while(temp!=NULL)
	{
		printf("%c ",temp->data);
		temp=temp->next;
	}
	printf("\n");
	
}

void insertFront(char choices)
{
	struct node *temp;
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=choices;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(head!=NULL)
	{
		temp->next=head;
		head->prev=temp;
	}
	head=temp;
	size++;
}
void deleteFront()
{
	struct node *current;
	
	current=head;
	if(head->next!=NULL)
	{
		head=head->next;
	}
	dval=current->data;
	printf("Deleted value of the node: %c\n",dval);
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
	size=0;
	head=NULL;
	askUser();
}

