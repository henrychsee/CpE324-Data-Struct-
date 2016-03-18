/*
	Name: Matidios,Henry
	Date: 29/11/15 01:05
	Description: ComE324L Exercise 1
*/

#include<stdio.h>
#include<stdlib.h>

void askUser(int array[], int count);
void displayArray(int array[], int count);
void insertRear(int array[], int item, int *count);
void insertFront(int arrray[], int item, int *count);
void insertInto(int array[], int item, int index, int *count);
void deleteFront(int array[], int *count);
void deleteRear(int array[], int *count);
void deleteItem(int array[], int item, int *count);
void deleteAllItem(int array[], int item, int *count);
void makeUnique(int array[], int *count);

void main()
{
	int count;
	int i;
	int array[50]={10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10};
	
	printf("N = ");
	scanf("%d",&count);
	
	for(i=0;i<count;i++)
	{
		while(array[i]<0||array[i]>9)
		{
			printf("Enter the number[0-9]: ");
			scanf("%d",&array[i]);
	
		}
	}
	
	askUser(array,count);
}

void askUser(int array[],int count)
{
	int i;
	char choice;
	
	system("cls");
	printf("\n[1]-DISPLAY ARRAY\n[2]-INSERT REAR\n[3]-INSERT FRONT\n[4]-INSERT INTO\n[5]-DELETE FRONT\n[6]-DELETE REAR\n[7]-DELETE ITEM\n[8]-DELETE ALL ITEM\n[9]-MAKE UNIQUE\n");
	choice=getch();
	
	switch(choice)
	{
		case '1':
			displayArray(array,count);	
			break;
		case '2':
			insertRear(array,10,&count);
			break;
		case '3':
			insertFront(array,10,&count);
			break;
		case '4':
			insertInto(array,10,10,&count);
			break;
		case '5':
			deleteFront(array,&count);
			break;
		case '6':
			deleteRear(array,&count);
			break;
		case '7':
			deleteItem(array,10,&count);
			break;
		case '8':
			deleteAllItem(array,10,&count);
			break;
		case '9':
			makeUnique(array,&count);
			break;
		default:
			getch();
			break;
	}
}
void displayArray(int array[], int count)
{
	int i;
		
	system("cls");
	
	for(i=0;i<count;i++)
	{
		printf("%d",array[i]);
	}
	
	getch();
	askUser(array,count);
}
void insertRear(int array[], int item, int *count)
{
	int n;
	int i;
	
	system("cls");
	
	while(item>9||item<0)
	{
		printf("Number to be inserted: ");
		scanf("%d",&item);
	}
	
	
	array[*count]=item;
	
	*count=*count+1;
	
	for(i=0;i<*count;i++)
	{
		printf("%d",array[i]);
	}
	getch();
	askUser(array,*count);
}
void insertFront(int array[], int item, int *count)
{
	int i;
	int dummy[50];
	int dummy2[50];

	system("cls");
	
	while(item>9||item<0)
	{
		printf("Number to be inserted: ");
		scanf("%d",&item);
	}
	//shift the values to the right
	for(i=0;i<*count;i++)
	{
		dummy[i]=array[i];
		dummy2[i+1]=dummy[i];
	}

	dummy2[0]=item;
	*count=*count+1;
	
	for(i=0;i<*count;i++)
	{
		array[i]=dummy2[i];
	}

	for(i=0;i<*count;i++)
	{
		printf("%d",array[i]);
	}

	getch();
	askUser(array,*count);
} 
void insertInto(int array[], int item, int index, int *count)
{
	int i;
	int d;
	int temp[50];
	int temp2[50];

	system("cls");
	
	printf("Starting index: " );
	scanf("%d",&index);
	
	if(index>*count-1)
	{
		printf("Index out of bounds!.");
		for (d = 1 ; d <= 32767 ; d++ )
       	{}
		insertInto(array,10,0,count);
	}

	while(item>9||item<0)
	{
		printf("Number to be inserted: ");
		scanf("%d",&item);
	}

	//shift the values to the right
	for(i=index;i<*count;i++)
	{
		temp[i]=array[i];
		temp2[i+1]=temp[i];
	}

	temp2[index]=item;
	*count=*count+1;
	
	for(i=index;i<*count;i++)
	{
		array[i]=temp2[i];
	}

	for(i=0;i<*count;i++)
	{
		printf("%d",array[i]);
	}
	
	getch();
	askUser(array,*count);
}
void deleteFront(int array[], int *count)
{
	int i;

	system("cls");
	//shift left the values
	for(i=0;i<*count;i++)
	{
		array[i]=array[i+1];
	}

	*count=*count-1;
	for(i=0;i<*count;i++)
	{
		printf("%d",array[i]);
	}
	getch();
	askUser(array,*count);
}
void deleteRear(int array[], int *count)
{
	int i;

	system("cls");

	*count=*count-1;

	for(i=0;i<*count;i++)
	{
		printf("%d",array[i]);
	}
	
	getch();
	askUser(array,*count);
}
void deleteItem(int array[], int item, int *count)
{
	int a;
	int b;

	system("cls");
	
	while(item>9||item<0)
	{
		printf("Number to be deleted: ");
		scanf("%d",&item);
	}

	for(a=0;a<*count;a++)
	{
		if(array[a]==item)
		{
			for(b=a;b<*count;b++)
			{
				array[b]=array[b+1];
				
			}
			*count = *count-1;
			break;
		}
	}
	
	
	for (a = 0; a < *count; a++)
	{
		printf("%d",array[a]);
	}

	getch();
	askUser(array,*count);
}
void deleteAllItem(int array[], int item, int *count)
{
	int a;
	int b;

	system("cls");
	
	while(item>9||item<0)
	{
		printf("Number to be deleted: ");
		scanf("%d",&item);
	}

	for(a=0;a<*count;a++)
	{
		if(array[a]==item)
		{
			for(b=a;b<*count;b++)
			{
				array[b]=array[b+1];
				
			}
			*count = *count-1;
		}
	}
	//check usab if naapay lain nga kapareha
	for(a=0;a<*count;a++)
	{
		if(array[a]==item)
		{
			for(b=a;b<*count;b++)
			{
				array[b]=array[b+1];
				
			}
			*count = *count-1;
		}
	}
	
	for (a = 0; a < *count; a++)
	{
		printf("%d",array[a]);
	}

	getch();
	askUser(array,*count);
}
void makeUnique(int array[], int *count)
{
	int a;
	int b;
	int c;

	system("cls");
	
	for(a=0;a<*count;a++)//changes the value that will be compared
	{
		for(b=0;b<*count;b++)//scans the array for the duplicate values
		{
			if(a!=b)
			{
				if(array[a]==array[b])//check if the same 
				{
					*count=*count-1;
					for(c=b;c<*count;c++)//shift left the values
					{
						b=0;
						array[c]=array[c+1];
					}
				}
			}
		}
	}

	for(a=0;a<*count;a++)//print the content of the array
	{
		printf("%d",array[a]);
	}
	
	
	getch();
	askUser(array,*count);
}
