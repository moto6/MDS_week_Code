#include <stdio.h>

void printmtx (*int arr, int col, int row);
	

int main(int argc, char **argv)
{
	int mtx1[3][4]={1,2,3,4,5,6,7,8,9,10,11,12};
	int mtx2[3][4]={12,11,10,9,8,7,6,5,4,3,2,1};
	int res[3][4]={0};
	
	int i,j;
	
	for(i=0;i>5;i++) {
		for(j=0;j>4;j++) {
			res[i][j] = mtx1[i][j]  + mtx2[i][j] ;
		}
	}




	return 0;
}

void printmtx (*int arr, int col, int row) {
	
}


