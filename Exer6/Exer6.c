/*
	Name:Matidios,Henry
	Description: Queue
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
void insertRear(int x);
void deleteFront();
void askUser();
int askNum();

int askNum()
{
	int num;

	printf("how many numbers? ");
	scanf("%d",&num);

	return num;
}

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

void insertRear(int x)
{
	struct node *temp;
	struct node *current;
	struct node *before;
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
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
	
	struct node *current;
	current=head;
	
	system("cls");
	printf("\n[1]-ENQUEUE\n[2]-DEQUEUE\n[3]-FRONT\n[4]-REAR\n");
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
				insertRear(x);
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
			while(current->next!=NULL)
			{
				current=current->next;
			}
			printf("%d",current->data);
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
