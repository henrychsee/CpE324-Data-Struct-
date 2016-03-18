/*
	Name:Matidios,Henry
	Description: Queue
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node *next;
	struct node *prev;
};

struct node *head;
int size;
char dval;

void displayArray();
void insertRear(char choices);
void deleteFront();
void askUser();
int askNum();

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

void insertRear(char choices)
{
	struct node *temp;
	struct node *current;
	struct node *before;
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=choices;
	temp->next=NULL;
	temp->prev=NULL;
	
	current=head;
	before=head;
	
	if(head==NULL)
	{
		head=temp;
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
	printf("Deleted value: %c\n",dval);
	current->next=NULL;
	current->prev=NULL;
	size--;
}

void askUser()
{
	char choices='9';
	
	struct node *current;
	current=head;
	while(choices=='0'||choices=='1'||choices=='2'||choices=='3'||choices=='4'||choices=='5'||choices=='6'||choices=='7'||choices=='8'||choices=='9'||choices=='-'||choices=='='||choices=='_'||choices=='+'||choices=='?')
	{
		system("cls");
		printf("\n[*]-GET\n[ANY LETTER]-PUT\n");
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
			insertRear(choices);
			displayArray();
			getch();
			askUser();
			break;
	}
}

void main()
{
	head=NULL;
	askUser();
}
