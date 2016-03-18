#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


void displayArray(int array[], int count);
void insertRear(int array[],int item,int *count);
void insertFront(int array[],int item, int *count);
void deleteAllItem(int array[],int item,int *count);

void main()
{
	int array[50];
	int count;
	char choice;
	
	printf("Enter an integer: ");
	fgets(array,sizeof(array),stdin);
	
	system("cls");
	printf("[1]-DISPLAY ARRAY\n[2]-INSERT REAR\n[3]-INSERT FRONT\n[4]-INSERT INTO\n[5]-DELETE FRONT\n[6]-DELETE REAR\n[7]-DELETE ITEM\n[8]-DELETE ALL ITEM\n");
	choice=getch();
	
	count=strlen(array);
	
	switch(choice)
	{
		case '1':
			displayArray(array,count);
			break;
		case '2':
			insertRear(array,0,&count);
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			break;
		case '7':
			break;
		case '8':
			break;
	}
	
}

void displayArray(int array[],int count)
{
	printf("\n%s",array);
}
void insertRear(int array[],int item, int *count)
{
	int arr[50];
	printf("%s",array);
	printf("Enter the number you want to insert in the rear: ");
	scanf("%d",&item);
	//array[*count]=item;
	printf("%x",array[0]);
}
void deleteAllItem(int array[],int item,int *count)
{
	
}
