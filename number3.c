/*
	Name: Matidios, Henry
	Description:A program that reads in a sequence of characters and prints them in reverse order.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	char data[50];
	char rev[50];
	struct node *next;
	struct node *prev;
};

struct node *head;
struct node *curr;

void insertRear(char str[]);
void displayArray();
void askStr();
void nextItem();
void prevItem();
void displayMenu();
void askUser();

void insertRear(char str[])
{
	struct node *temp;
	struct node *current;
	struct node *before;
	
	temp=(struct node*)malloc(sizeof(struct node));
	strcpy(temp->data,str);
	strcpy(temp->rev,strrev(str));
	temp->next=NULL;
	temp->prev=NULL;
	
	current=head;
	before=head;
	
	if(head==NULL)
	{
		head=temp;
		curr=head;
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
	//printf("\n\nSTRING: %s\n",temp->data);
	printf("\nREVERSE: %s\n",temp->rev);
}
void displayArray()
{
	struct node *temp;
	
	temp=head;
	while(temp!=NULL)
	{
		printf("\nSTRING:\n%s\n",temp->data);
		printf("REVERSE:%s\n\n",temp->rev);
		temp=temp->next;
	}
	printf("\n");
}
void askStr()
{
	char str[50];
	
	printf("STRING:\n");
	fflush(stdin);
	fgets(str,sizeof(str),stdin);
	
	insertRear(str);	
}
void nextItem()
{
	if(head==NULL)
	{
		printf("LIST IS EMPTY.");
	}
	else
	{
		if(curr->next!=NULL)
		{
			
			printf("STRING: %s\n",curr->next->data);
			printf("REVERSE: %s\n",curr->next->rev);
			curr=curr->next;
		}
		else
		{
			printf("NO MORE NEXT NODE.");
		}
	}
}
void prevItem()
{
	if(head==NULL)
	{
		printf("LIST IS EMPTY.");
	}
	else
	{
		if(curr->prev!=NULL)
		{
			printf("STRING: %s\n",curr->prev->data);
			printf("REVERSE: %s\n",curr->prev->rev);
			curr=curr->prev;
		}
		else
		{
			printf("NO MORE PREVIOUS NODE.");
		}
	}
}
void displayMenu()
{
	char choice;

	system("cls");
	printf("[1]-DISPLAY ALL\n[a]-NEXT\n[d]-PREVIOUS\n");
	printf("PRESS ESC TO RETURN TO MAIN MENU...\n");
	choice=getch();

	switch(choice)
	{
		case '1':
			displayArray();
			getch();
			displayMenu();
			break;
		case 'a':
			nextItem();
			getch();
			displayMenu();
			break;
		case 'd':
			prevItem();
			getch();
			displayMenu();
			break;
		default:
			askUser();	
			break;
	}
}
void askUser()
{
	char choice;
	
	system("cls");
	printf("---MAIN MENU---\n");
	printf("\n[1]-ENTER STRING\n[2]-DISPLAY\n");
	choice=getch();

	switch(choice)
	{
		case '1':
			askStr();
			getch();
			askUser();
			break;
		case '2':
			displayMenu();
			getch();
			askUser();
			break;
		default:
			getch();
			break;	
	}	
}
void main()
{
	head=NULL;
	askUser();
}
