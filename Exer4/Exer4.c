/*
	Name: Matidios, Henry
	Date: 13/12/15 20:32
	Description: Doubly Linked List implementation of exercise 1
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head;
struct node *curr;



void insertFront(int x);
void insertRear(int x);
void insertInto();
void deleteItem();
void deleteAllItem();
void makeUnique();
void deleteRear();
void deleteFront();
void displayArray();
int askNum();
void nextItem();
void prevItem();
void askUser();

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
	curr=head;
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
}
void insertInto()
{
	int x=10;
	int countlist=0;
	int index;
	int countbefore=1;
	int countafter=0;
	struct node *temp;
	struct node *current;
	struct node *before;
	
	while(x<0||x>9)		//accepts only the values between 0-9
	{
		printf("Enter the number to be inserted: ");
		scanf("%d",&x);
	}
	current=head;
	while(current->next!=NULL)		//count the number of list
	{
		current=current->next;
		countlist++;
	}
	index=countlist+1;
	while(index>countlist)		//asks again if the inputted index is out of bounds
	{
		printf("Index: ");
		scanf("%d",&index);
	}
	
	temp=(struct node*)malloc(sizeof(struct node));
	
	if(temp)
	{
		temp->data=x;
		temp->next=NULL;
		temp->prev=NULL;
	}
	else
	{
		printf("Failed to allocate a memory.");
		insertInto();
	}
	
	before=head;
	while(countbefore<index)	//ibutang ang before nga pointer sa node before kung asa i.insert ang new node.
	{
		before=before->next;
		countbefore++;
	}
	current=head;
	while(countafter<index)		
	{
		current=current->next;
		countafter++;
	}
	
	before->next=temp;
	temp->prev=before;
	temp->next=current;
	current->prev=temp;
	
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
void deleteRear()
{
	int count=0;
	int i;
	struct node *current;
	struct node *temp;
	
	current=head;
	temp=head;
	
	if(current->next!=NULL)
	{
		while(current->next!=NULL)
		{
			current=current->next;
		}
		temp=current->prev;
		free(current);
		temp->next=NULL;
	}
}
void deleteItem()
{
	struct node *before;
	struct node *search;
	struct node *current;
	
	int countbefore=1;
	int countafter=0;
	int countlist=0;
	int countitem=0;
	int item=10;
	
	
	while(item<0||item>9)
	{
		printf("Enter number to be deleted: ");
		scanf("%d",&item);
	}
	
	current=head;
	while(current->next!=NULL)
	{
		current=current->next;
		countlist++;
	}
	//printf("%d\n",countlist);
	search=head;
	while(item!=search->data)			//search for the node to be deleted
	{
		search=search->next;
		countitem++;
	}
	
	if(countitem==0)		//if ang e delete kay naa sa pinaka una
	{
		deleteFront();
	}
	else if(countitem==countlist)		// if ang e delete kay naa sa pinaka tomoy
	{
		deleteRear();
	}
	else
	{
		before=head;
		while(countbefore<countitem)	//point the before pointer to the node before the node to be deleted
		{
			before=before->next;
			countbefore++;
		}
		current=before->next->next;		
		before->next=current;		//delete the node to be deleted  from the list
	}
}
void deleteAllItem()
{
	struct node *current;
	struct node *before;

	int item=10;
	
	while(item<0||item>9)			//the numbers that can be inputted are only from 0-9
	{
		printf("Enter number to be deleted: ");
		scanf("%d",&item);
	}
	
	current=head;
	before=head;

	if(head==NULL)
	{
		//system("cls");
		printf("LIST IS EMPTY!");
	}
	else
	{
		while(current!=NULL)
		{
			if(current->data==item)
			{
				if(current==head)
				{
					head=current->next;
					free(current);
					before=head;
					current=head;
				}
				else
				{
					before->next=current->next;
					current=before->next;
				}
			}
			else
			{
				before=current;
				current=current->next;
			}
		}
	}
}
void makeUnique()
{
	struct node *current;
	struct node *traverse;
	struct node *before;
	struct node *search;
	
	
	current=head;
	while(current->next!=NULL)
	{
		traverse=current;
		while(traverse->next!=NULL)
		{
			if(current->data==traverse->next->data)
			{
				before=traverse->next;
				traverse->next=traverse->next->next;
				free(before);
			}
			else
			{
				traverse=traverse->next;
			}
		}
		current=current->next;
	}
}
int askNum()
{
	int num;

	printf("how many numbers? ");
	scanf("%d",&num);

	return num;
}
void nextItem()
{
	if(curr->next!=NULL)
	{
		printf("%d",curr->next->data);
		curr=curr->next;
	}
	else
	{
		printf("NO MORE NEXT NODE.");
	}
}
void prevItem()
{
	if(curr->prev!=NULL)
	{
		printf("%d",curr->prev->data);
		curr=curr->prev;
	}
	else
	{
		printf("NO MORE PREVIOUS NODE.");
	}
}
void askUser()
{
	int num;
	int x=10;
	int i;
	char choices;
	
	system("cls");
	printf("\n[1]-DISPLAY ARRAY\n[2]-INSERT REAR\n[3]-INSERT FRONT\n[4]-INSERT INTO\n[5]-DELETE FRONT\n[6]-DELETE REAR\n[7]-DELETE ITEM\n[8]-DELETE ALL ITEM\n[9]-MAKE UNIQUE\n[a]-NEXT\n[d]-PREVIOUS\n");
	choices=getch();

	switch(choices)
	{
		case '1':
			displayArray();
			getch();	
			askUser();
			break;
		case '2':
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
		case '3':
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
		case '4':
			displayArray();
			insertInto();
			displayArray();
			getch();
			askUser();
			break;
		case '5':
			deleteFront();
			displayArray();
			getch();
			askUser();
			break;
		case '6':
			deleteRear();
			displayArray();
			getch();
			askUser();
			break;
		case '7':
			displayArray();
			deleteItem();
			displayArray();
			getch();
			askUser();
			break;
		case '8':
			displayArray();
			deleteAllItem();
			displayArray();
			getch();
			askUser();
			break;
		case '9':
			displayArray();
			makeUnique();
			displayArray();
			getch();
			askUser();
			break;
		case 'a':
			//printf("Hello nigga");
			//printf("%d",curr->data);
			nextItem();
			getch();
			askUser();
			break;
		case 'd':
			//printf("Hi nigga");
			prevItem();
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
	curr=NULL;

	askUser();
}
