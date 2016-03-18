#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"

void insertRear(int str)
{
	struct node *temp;
	struct node *current;
	struct node *before;
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=str;
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
	size++;
}
void displayArray()
{
	struct node *temp;
	
	temp=head;
	printf("\n");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void askStr()
{
	int str;
	
	printf("Integer:\n");
	scanf("%d",&str);
	
	insertRear(str);
	displayArray();	
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
			
			printf("INTEGER: %d\n",curr->next->data);
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
			printf("INTEGER: %d\n",curr->prev->data);
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
void sortMenu()
{
	char choice;
	
	system('cls');
	printf("[1]-INSERTION SORT\n[2]-SELECTION SORT\n[3]-BUBBLE SORT\n[4]-BUCKET SORT\n[5]-HEAP SORT\n[6]-QUICK SORT\n[7]-RADIX SORT\n[8]-COMB SORT\n[9]-MERGE SORT\n[0]-SHELL SORT\n");
	printf("Press any key in order to return to MAIN MENU...");
	choice=getche();
	
	switch(choice)
	{
		case '1':		//insertion
			sortInsert();
			getch();
			sortMenu();
			break;
		case '2':		//selection
			getch();
			sortMenu();
			break;
		case '3':		//bubble
			//bubbleSort(parameter1);
			getch();
			sortMenu();	
			break;
		case '4':		//bucket
			getch();
			sortMenu();
			break;
		case '5':		//heap
			getch();
			sortMenu();
			break;
		case '6':		//quick
			//QuickSortList(parameter1,parameter2);
			getch();
			sortMenu();
			break;
		case '7':		//radix
			getch();
			sortMenu();
			break;
		case '8':		//comb
			getch();
			sortMenu();
			break;
		case '9':		//merge
			//mergesort(parameter1)
			getch();
			sortMenu();
			break;
		case '0':		//shell
			getch();
			sortMenu();
			break;
		default:
			getch();
			askUser();
			break;
	}
}
void askUser()
{
	char choice;
	int x;
	int loop;
	
	system("cls");
	printf("---MAIN MENU---\n");
	printf("\n[1]-ENTER STRING\n[2]-DISPLAY\n[3]-SORT\n\n");
	choice=getch();

	switch(choice)
	{
		case '1':
			printf("How many number(s)?");
			scanf("%d",&loop);
			
			for(x=0;x<loop;x++)
				askStr();
				
			getch();
			askUser();
			break;
		case '2':
			displayMenu();
			getch();
			askUser();
			break;
		case '3':
			sortMenu();
			getch();
			askUser();
			break;
		default:
			getch();
			break;	
	}	
}
