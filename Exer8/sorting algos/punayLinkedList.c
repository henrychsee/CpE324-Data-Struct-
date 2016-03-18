#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

char array[50]={0};
struct node *head=NULL;

struct node* sortedmerge(struct node* a, struct node* b);
void frontbacksplit(struct node* source, struct node** frontRef, struct node** backRef);


void mergesort(struct node** headRef);
void push(struct node** head_ref, int new_data);
void printlist(struct node *node);
void main();
void display();



 
 
void menu()
{
	struct node* a = NULL;
	int choice, count, elements, x=0;
	int input;
	
	printf("[1] Merge Sort - Linked List\n");
	printf("[2] Shell Sort - Linked List\n");
	printf("[3] Exit\n");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1: 
			system("cls");
			printf("ENTERING DATA\n");
			
			 printf("Enter number of elements: ");
			scanf("%d", &elements);
			for(x; x<elements; x++)
			{
				printf("Data[%d]: ", x);
				scanf("%d", &input);
				push(&a,input);
			}
			mergesort(&a);
			system("cls");
			printf("Sorted Linked List - Merge Algo\n\n");
			printlist(a);
		
			menu();
			break;
		case 2:	
			break;
		case 3: exit(0);break;
		default: printf("Invalid Input."); menu(); break;
	}
}

void printlist(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node -> data);
        node = node -> next;
    }
}
 

void mergesort(struct node** headRef)
{
    struct node* head = *headRef;
    struct node* a;
    struct node* b;
    if ((head == NULL) || (head -> next == NULL))
    {
        return;
    }
    frontbacksplit(head, &a, &b);
    mergesort(&a);
    mergesort(&b);
    *headRef = sortedmerge(a, b);
}
 
struct node* sortedmerge(struct node* a, struct node* b)
{
    struct node* result = NULL;
 
    if (a == NULL)
        return(b);
    else if (b == NULL)
        return(a);
 
    if ( a-> data <= b -> data)
    {
        result = a;
        result -> next = sortedmerge(a -> next, b);
    }
    else
    {
        result = b;
        result -> next = sortedmerge(a, b -> next);
    }
    return(result);
}
 
void frontbacksplit(struct node* source, struct node** frontRef, struct node** backRef)
{
    struct node* fast;
    struct node* slow;
    if (source==NULL || source->next==NULL)
    {
        *frontRef = source;
        *backRef = NULL;
    }
    else
    {
        slow = source;
        fast = source -> next;
        while (fast != NULL)
        {
            fast = fast -> next;
            if (fast != NULL)
            {
                slow = slow -> next;
                fast = fast -> next;
            }
    }
 
    *frontRef = source;
    *backRef = slow -> next;
    slow -> next = NULL;
    }
}
  
void push(struct node** head_ref, int new_data)         //insertFront
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node -> data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
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

void main()
{
	while(1)
	{
		menu();
	}
}
