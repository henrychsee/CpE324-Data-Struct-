#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
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

