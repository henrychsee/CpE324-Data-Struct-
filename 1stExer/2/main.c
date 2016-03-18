#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int row,col,irow,icol;
	row=rows();
	col=column();
	dispBoard(row,col);
	return 0;
}
