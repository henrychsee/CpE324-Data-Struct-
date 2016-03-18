#include <stdio.h>

void menu();
void insertRear(int array[], char input, int *count);
void display(int array[], int count);
void shellsort(int arr[], int num);
void merge(int arr[],int min,int mid,int max);
void part(int arr[],int min,int max);

int input;
int array[50];
int choice, count, elements, digits, index=0;



void main()
{
	while(1)
	{
		menu();
	}
}


void menu()
{	
	
	printf("\nWhat do you want to do?\n");
	printf("[1] Enter data\n");
	printf("[2] Sort Data\n");
	printf("[3] Exit\n");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case 1: 
			system("cls");
			printf("ENTERING DATA\n");
			printf("Enter number of elements: ");
			scanf("%d", &elements);
			printf("Enter the %d data\n", elements);
			for(index; index<elements; index++)
			{
				printf("Array No.[%d]: ", index);
				scanf(" %c", &input);
				insertRear(array, input, &count);
			}
			system("cls");
			display(array, count);
			menu();
			break;
		case 2:	
			system("cls");
			printf("SORTING DATA\n");
			printf("[1] Merge Sort - Array Implementation\n");
			printf("[2] Shell Sort - Array Implementation\n");
			printf("[3] Back to Menu\n");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1: part(array,0,elements-1);; system("cls"); display(array, count); menu(); break;
				case 2: shellsort(array, elements);
						system("cls");
						display(array, count);
						menu(); 
						break;
				case 3: menu(); break;
			}
			case 3: exit(0); break;
	
		default: printf("Invalid Input."); menu(); break;
	}
}

void merge(int arr[],int min,int mid,int max)
{
  int tmp[30];
  int i,j,k,m; 
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}


void part(int arr[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(arr,min,mid);
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}


void insertRear(int array[], char input, int *count)
{
	array[*count] = input;
	*count = *count+1;
}


void display(int array[], int count)
{
	int x;
	system("cls");
	for(x=0; x<count; x++)
	{
		printf("%c ", array[x]);
	}
}

void shellsort(int arr[], int num)
{
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for(k = j - i; k >= 0; k = k - i)
            {
                if (arr[k+i] >= arr[k])
                    break;
                else
                {
                    tmp = arr[k];
                    arr[k] = arr[k+i];
                    arr[k+i] = tmp;
                }
            }
        }
    }
}






