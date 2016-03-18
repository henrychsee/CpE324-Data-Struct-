#include<stdio.h>
#include<stdlib.h>
#include "functions.h"

void sortInsert()
{
	struct node *unsorted_list;
	struct node *insert;
	struct node *temp;
	struct node *trail;
	//int cmp,cmp2;
	
	key=head;
	head=key->next;
	unsorted_list=head;
	
	//isolate the key from the list
	key->prev=NULL;
	key->next=NULL;
	
	while(unsorted_list!=NULL)
	{
		temp=unsorted_list;
		if(unsorted_list!=NULL)		//if not empty
			unsorted_list=unsorted_list->next;
			
		temp->next=NULL;
		temp->prev=NULL;
		
		if(key->data>temp->data)		//left
		{
			/*insert=key;
			
			//search for the place to insert			
			while(temp->data<insert->data)
			{
				if(insert!=NULL)
				{
					trail=insert;		//follow your dreams(insert)
					insert=insert->prev;	
				}
				else
					break;
			}
			//connect
			temp->next=trail;
			if(insert!=NULL)
				temp->next=insert;
			else*/
				//head=temp;
		}	
		else if(key->data<temp->data)	//right
		{
			insert=key;
			
			//search for the place to insert			
			while(temp->data>insert->data)
			{
				if(insert!=NULL)
				{
					trail=insert;		//follow your dreams(insert)
					insert=insert->next;	
				}
				else
					break;
			}
			//connect
			temp->prev=trail;
			if(insert!=NULL)
				temp->next=insert;		
		}
		else		//equal
		{
			/*temp->next=key->next;
			temp->prev=key;	*/
		}
	}	
}
