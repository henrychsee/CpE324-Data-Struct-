/*
	Name: Matidios, Henry
	Description: Stack
	
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head;

void displayArray();
void insertFront(int x);
void deleteFront();
void askUser();
int askNum();

void displayArray()
{
	struct node *temp=head;
	
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
	
}

void insertFront(int x)
{
	struct node *temp;
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;
	
	if(head!=NULL)
	{
		temp->next=head;
		head->prev=temp;
	}
	head=temp;
}
void deleteFront()
{
	struct node *current;
	
	current=head;
	if(head->next!=NULL)
	{
		head=head->next;
	}
	current->next=NULL;
	current->prev=NULL;
}
void askUser()
{
	int num;
	int x=10;
	int i;
	char choices;
	
	system("cls");
	printf("\n[1]-PUSH\n[2]-POP\n[3]-TOP\n[4]-DISPLAY\n");
	choices=getch();

	switch(choices)
	{
		case '1':
			num=askNum();
			for(i=0;i<num;i++)
			{
				while(x<0||x>9)
				{
					printf("Enter number: ");
					scanf("%d",&x);
				}
				insertFront(x);
				x=10;
				displayArray();
			}
			getch();
			askUser();
			break;
		case '2':
			deleteFront();
			displayArray();
			getch();
			askUser();
			break;
		case '3':
			if(head!=NULL)
			{
				printf("%d",head->data);
			}
			else
			{
				printf("List is empty");
			}
			getch();
			askUser();
			break;
		case '4':
			displayArray();
			getch();
			askUser();
			break;
		default:
			getch();
			break;
	}
}
int askNum()
{
	int num;

	printf("how many numbers? ");
	scanf("%d",&num);

	return num;
}
void main()
{
	head=NULL;
	askUser();
}

