#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

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

