#include<stdio.h>
#include<stdlib.h>

int rows()
{
	int N=20;
	
	while(N>9||N<1)
	{
		printf("Column[1-9]=");
		scanf("%d",&N);
	}
	
	return N;
}

int column()
{
	int M=20;
	
	while(M>9||M<1)
	{
		printf("Row[1-9]=");
		scanf("%d",&M);	
	}
	return M;
}



void dispBoard(int N, int M)
{
	int row,col;
	//printf("%d\n%d\n%d\n%d",N,M,irow,icol);
	printf("\n");
	
	for(row=1;row<=M;row++)
	{
		for(col=1;col<=N;col++)
		{
			if((col==1&&row==2)||(col==4&&row==1)||(col==3&&row==3)||(col==5&&row==4)||(col==2&&row==5)||(col==8&&row==6)||(col==7&&row==9))
			{
				printf("Q ");
			}
			else 
			{
				printf("* ");
			} 
			
		}
		printf("\n");
	}
	
}
