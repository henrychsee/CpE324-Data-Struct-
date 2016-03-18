#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
void QuickSortList(struct node *pLeft, struct node *pRight)
{
    struct node *pStart;
    struct node *pCurrent; 
    int nCopyInteger;
    if (pLeft == pRight) return;
    pStart = pLeft;
    pCurrent = pStart->next;
    while (1)
    {
        if (pStart->data < pCurrent->data)
        {
            nCopyInteger = pCurrent->data;
            pCurrent->data = pStart->data;
            pStart->data = nCopyInteger;
        }
        if (pCurrent == pRight) break;
        pCurrent = pCurrent->next;
    }
    nCopyInteger = pLeft->data;
    pLeft->data = pCurrent->data;
    pCurrent->data = nCopyInteger;
    struct node *pOldCurrent = pCurrent;
    pCurrent = pCurrent->prev;
    if (pCurrent != NULL)
    {
        if ((pLeft->prev != pCurrent) && (pCurrent->next != pLeft))
            QuickSortList(pLeft, pCurrent);
    }
    pCurrent = pOldCurrent;
    pCurrent = pCurrent->next;
    if (pCurrent != NULL)
    {
        if ((pCurrent->prev != pRight) && (pRight->next != pCurrent))
            QuickSortList(pCurrent, pRight);
    }
}
