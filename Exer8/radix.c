#include<stdio.h>
#include<stdlib.h>
#include"functions.h"

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

