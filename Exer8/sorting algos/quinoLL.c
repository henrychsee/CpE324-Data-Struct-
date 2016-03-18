#include <stdio.h>
#include <string.h>

struct node
{
	char data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
char array[50]={0};

void insertRear(char array[], char input, int *count);
void display();
void menu();
void selectionLL();
void radixLL(char array[], int elements, int digits);

void radixLL(char array[], int elements, int digits)
{
	struct node *ptr,*start,*prev;
	struct node *front[10], *rear[10];
	int k=1,i,j,y,p;;
	/*creating initial linked list*/
	start=NULL;
	for(i=0; i<elements; ++i)
	{
		ptr=(struct node *)malloc(sizeof(struct node));
		ptr->data=array[i];
		ptr->next=NULL;
		if(start==NULL)
		start=ptr;
		else
		prev->next=ptr;
		prev=ptr;
	}

	/*radix sort*/

	for(i=1;i<=digits;++i)
	{
		for(j=0;j< 10;++j)
		front[j]=NULL;
		/*placing elements into queues*/
		ptr=start;
		while(ptr!=NULL)
		{
			y=ptr->data/k %10;/*y is the digit*/
			if(front[y]==NULL)
			{
				front[y]=ptr;
				rear[y]=ptr;
			}
			else
			{
				rear[y]->next=ptr;
				rear[y]=ptr;
			}
			ptr=ptr->next;
		}

		start=NULL;
		for(j=0;j< 10;++j)
			if(front[j]!=NULL)
			{
				if(start==NULL)
				start=front[j];
				else rear[p]->next=front[j];
				p=j;
			}
		rear[p]->next=NULL;
		k=k*10;
	}
	/*copying back to array*/
	ptr=start;
	for(i=0; i<elements; ++i,ptr=ptr->next)
	array[i]=ptr->data;
}

void selectionLL()
{
	 struct node *ptr1 = NULL;
	 struct node *ptr2 = NULL;
	 struct node *ptr3 = NULL;
	 struct node *ptr4 = NULL;
	 struct node *tmp = NULL;

	ptr1 = ptr3 = head;
	while(ptr1->next != NULL) 
	{
		ptr4 = ptr2 = ptr1->next;
		while(ptr2 != NULL) 
		{
			if(ptr1->data > ptr2->data) 
			{
			/* neighboring linked list node */
				if(ptr1->next == ptr2) 
				{ 
					if(ptr1 == head) 
					{
						ptr1->next = ptr2->next;
						ptr2->next = ptr1;
						tmp = ptr1;
						ptr1 = ptr2;
						ptr2 = tmp;
						head = ptr1;
						ptr3 = ptr1;
						ptr4 = ptr2;
						ptr2 = ptr2->next;
					} 
					else 
					{
						ptr1->next = ptr2->next;
						ptr2->next = ptr1;
						ptr3->next = ptr2;
						tmp = ptr1;
						ptr1 = ptr2;
						ptr2 = tmp;
						ptr4 = ptr2;
						ptr2 = ptr2->next;
					}
				}	
				else 
				{
					if(ptr1 == head) 
					{
						tmp = ptr2->next;
						ptr2->next = ptr1->next;
						ptr1->next = tmp;
						ptr4->next = ptr1;
						tmp = ptr1;
						ptr1 = ptr2;
						ptr2 = tmp;
						ptr4 = ptr2;
						ptr2 = ptr2->next;
						head = ptr1;
					}
					else
					{
						tmp = ptr2->next;
						ptr2->next = ptr1->next;
						ptr1->next = tmp;
						ptr3->next = ptr2;
						ptr4->next = ptr1;
						tmp = ptr1;
						ptr1 = ptr2;
						ptr2 = tmp;
						ptr4 = ptr2;
						ptr2 = ptr2->next;
					}
				}
			}
			else
			{
				ptr4 = ptr2;
				ptr2 = ptr2->next;
			}
		}
		ptr3 = ptr1;
		ptr1 = ptr1->next;
	}
}


void insertRear(char array[], char input, int *count)
{
	struct node *ptr, *newNode;
	newNode=malloc(sizeof(struct node));
	newNode->data=input;
	
	if(head==NULL)
	{
		head=newNode;
		newNode->next=NULL;
		newNode->prev=NULL;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newNode;
		newNode->prev=ptr;
		newNode->next=NULL;
	}
	
//	insert rear for array
	array[*count] = input;
	*count = *count+1;
}

void display()
{
	struct node *tmp=head;
	if(head==NULL)
	{
		system("cls");
		printf("LIST IS EMPTY");
	}
	else
	{
		while(tmp!=NULL)
		{
			printf("%c", tmp->data);
			tmp=tmp->next;
		}
		printf("\n");
	}
}


void menu()
{
	int choice, count, elements, digits, x=0;
	char input;
	
	printf("What do you want to do?\n");
	printf("[1] Enter data\n");
	printf("[2] Sort Data\n");
	printf("[3] Exit\n");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1: 
			system("cls");
			printf("ENTERING DATA\n");
			printf("Enter number of elements: ");
			scanf("%d", &elements);
			printf("Enter number of digits: ");
			scanf("%d", &digits);
			for(x; x<elements; x++)
			{
				printf("Data[%d]: ", x);
				scanf("%s", &input);
				insertRear(array, input, &count);
			}
			system("cls");
			display();
			menu();
			break;
		case 2:	
			system("cls");
			printf("SORTING DATA\n");
			printf("[1] Selection Sort - Linked List Implementation\n");
			printf("[2] Radix Sort - Linked List Implementation\n");
			printf("[3] Back to Menu\n");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1: selectionLL(); system("cls"); display(); menu(); break;
				case 2: radixLL(array, elements, digits);
//						system("cls");
						for(x=0; x<elements; ++x)
						printf("%c",array[x]);
						menu();
						break;
				case 3: menu(); break;
			}
		case 3: exit(0); break;
		default: printf("Invalid Input."); menu(); break;
	}
}

void main()
{
	while(1)
	{
		menu();
	}
}