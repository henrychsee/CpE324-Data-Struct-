#include <stdio.h>

int choice, count, elements, digits, index=0;
char input;
char array[50]={0};

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
				printf("Array[%d]: ", index);
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
			printf("[1] Selection Sort - Array Implementation\n");
			printf("[2] Radix Sort - Array Implementation\n");
			printf("[3] Back to Menu\n");
			scanf("%d", &choice);
			switch(choice)
			{
				case 1: selectionArr(array, &count); system("cls"); display(array, count); menu(); break;
				case 2: radixArr(array, elements);
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

void insertRear(char array[], char input, int *count)
{
	array[*count] = input;
	*count = *count+1;
}

void display(char array[], int count)
{
	int x;
	system("cls");
	for(x=0; x<count; x++)
	{
		printf("%c ", array[x]);
	}
}

void selectionArr(char array[], int *count)
{
	int c, position, swap, d;
	for(c=0; c<(*count-1); c++)
    {
		position=c;
		for(d=c+1; d<*count; d++)
		{
			if(array[position]>array[d])
				position=d;
		}
	  
		if (position!=c )
		{
			swap=array[c];
			array[c]=array[position];
			array[position]=swap;
		}
    }
}

void radixArr(char array[], int elements)
{
	char bucket[10][5],buck[10],b[10];
	int i,j,k,l,num,div,large,passes;
	  
	div=1;
	num=0;
	large=array[0];
  
	for(i=0 ; i<elements ; i++)
	{
		if(array[i] > large)
		{
			large = array[i];
		}
		
		while(large > 0)
		{
			num++;
			large = large/10;
		}
		
		for(passes=0 ; passes<num ; passes++)
		{
			for(k=0 ; k<10 ; k++)
			{
				buck[k] = 0;
			}
			
			for(i=0 ; i<elements  ;i++)
			{
				l = ((array[i]/div)%10);
				bucket[l][buck[l]++] = array[i];
			}
			
			i=0;
			for(k=0 ; k<10 ; k++)
			{
				for(j=0 ; j<buck[k] ; j++)
				{
					array[i++] = bucket[k][j];
				}
			}   
			div*=10;   
		}
	}
}

