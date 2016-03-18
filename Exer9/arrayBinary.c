/*
	Name: Matidios, Henry
	Date: 16/02/16 02:33
	Description: Binary Search(Array Implementation), binary search assumes that the data is already sorted
*/

#include<stdio.h>
#include<stdlib.h>


int binarySearch(int *array,int size,int key)
{
	int low;
	int high;
	int test;
	
	low=0;
	high=size;
	
	while(low+1<high)
	{
		test=(low+high)/2;
		
		if(*(array+test)>key)
			high=test;
		else
			low=test;
	}
	
	if(*(array+low)==key)
	{		
		printf("\n%d is found in index %d\n",key,low);
		return low;
	}
	else
		return -1;
}
int askKey()
{
	int key;
	
	printf("\nWhat do you want to find? ");
	scanf("%d",&key);
	
	return key;
}
int *askUser(int size)
{
	static int array[50];
	int i;
	
	printf("\nEnter %d number(s)\n",size);
	
	for(i=0;i<size;i++)
		scanf("%d",&array[i]);
	return array;
}
int askNum()
{
	int size;

	printf("\nhow many numbers? ");
	scanf("%d",&size);

	return size;
}
void askMenu(int *array, int size, int key)
{
	char choice;
	int match;
	
	system("cls");
	printf("--MENU--\n[1]-ENTER ARRAY\n[2]-SEARCH\n");
	choice=getche();
	
	switch(choice)
	{
		case '1':
			size=askNum();
			array=askUser(size);
			getch();
			askMenu(array,size,key);
			break;
		case '2':
			key=askKey();
			match=binarySearch(array,size,key);
			getch();
			askMenu(array,size,key);
			break;
		default:
			break;
	}
}
void main()
{
	askMenu(0,0,0);
}
