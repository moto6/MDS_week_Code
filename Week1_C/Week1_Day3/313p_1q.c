#include <stdio.h>
void pgrp(int *parr, int size);

int main (void) 
{
	int score[5] = {72,88,95,64,100};
	int a=1,b=2,c=3;
	
	
	pgrp(score, sizeof(score)/sizeof(score[0]) );
	
	return 0;
}


void pgrp(int *parr, int size)
{
	int i=0,j=0;
	for(i=0;i<size;i++) {
		printf("(%d):\t",parr[i]);
		for(j=0;j<parr[i]/5;j++)
		{
			printf("*");
		}
		puts("");
		
	}
	return;
}
