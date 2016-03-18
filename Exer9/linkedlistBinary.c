/*
	Name: Matidios, Henry
	Date: 16/02/16 18:24
	Description: Linked list Binary Search(Doubly)
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head;
int size;

int askKey()
{
	int key;
	
	printf("\nWhat do you want to find? ");
	scanf("%d",&key);
	
	return key;
}
int binarySearch(int key)
{
	int low;
	int high;
	float test;
	int x;
	struct node *current;
	struct node *start;
	struct node *temp;
	
	/*low=0;
	high=size;*/
	
	x=0;
	test=size/2;
	
	current=head;
	start=head;
	while(x<test)
	{
		current=current->next;
	}
	
	/*while(low+1<high)
	{
		test=test/2;
		test=round(test);
		
		if(current->data>key)
			//high=test;
			current=start;
		else
			start=current;
			//low=test;
			
		x=0;
		while(x<test)
		{
			if(current->next!=NULL)
			{
				current=current->next;
			}
		}
	}*/

	if(current->data==key)
	{
		printf("\n%d is found in index %d\n",key,low);
		return low;
	}
	else
		return -1;
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
	size++;
}
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
void askUser()
{
	int num;
	int x=10;
	int i;
	int key;
	int index;
	char choices;
	
	struct node *current;
	
	current=head;
	
	system("cls");
	printf("\n[1]-ENTER ARRAY\n[2]-SEARCH\n");
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
			key=askKey();
			index=binarySearch(key);
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
	size=0;
	askUser();
}
