struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head;
struct node *curr; 
struct node *key;
int size;

//input.c functions
void insertRear(int str);
void displayArray();
void askStr();
void nextItem();
void prevItem();
void displayMenu();
void askUser();
//insertion.c functions
void sortInsert();
//bubble.c functions
void bubbleSort(struct node *start);
//merge.c functions
void mergesort(struct node** headRef);
struct node* sortedmerge(struct node* a, struct node* b);
void frontbacksplit(struct node* source, struct node** frontRef, struct node** backRef);
//quick.c functions
void QuickSortList(struct node *pLeft, struct node *pRight);
//selection.c functions
void selectionLL();
//radix.c functions
void radixLL(char array[], int elements, int digits);
