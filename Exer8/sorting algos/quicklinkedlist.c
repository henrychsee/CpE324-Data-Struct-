#include <stdio.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} struct node;

struct node *g_pFirstItem = NULL;
struct node *g_pLastItem = NULL;

void AddListItem(int data)                  //insertRear
{
    struct node *pItem = (struct node *)malloc(sizeof(struct node));
    pItem->data = data;
    if (g_pFirstItem == NULL)
    {
        g_pFirstItem = g_pLastItem = pItem;
        pItem->next = pItem->prev = NULL;
    }
    else
    {
        g_pLastItem->next = pItem;
        pItem->prev = g_pLastItem;
        g_pLastItem = pItem;
        pItem->next = NULL;
    }
}

void PrintList()
{
    struct node *pItem = g_pFirstItem;
    while (pItem != NULL)
    {
        printf("%d\n", pItem->data);
        pItem = pItem->next;
    }
}

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

void menu()
{
    int choice, x;
    
    printf("[1] Enter data\n");
    printf("[2] Sort Data\n");
    printf("[3] Exit\n");
    scanf("%d", &choice);
    
    switch(choice)
    {
        case 1: 
            system("cls");
            printf("Enter data: ");
            scanf("%d",&x);
            system("cls");
            AddListItem(x);
            menu();
            break;
        case 2:    
            system("cls");
            printf("Sorting data\n");
            QuickSortList(g_pFirstItem, g_pLastItem);
            PrintList();
        case 3: exit(0); break;
        default: printf("Invalid Input."); menu(); break;
    }
}

void main ()
{
    menu();
}
