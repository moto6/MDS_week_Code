//triangle
#include <stdio.h>
void inoTRI(int len);
void otoTRI(int len);
void diaTRI(int len);
void dbgTRI(int len);
	
int main(void) {
	int val = 0;
	puts("insert val ");
	scanf("%d",&val);
	
	if(0==val%2) {
		puts("짝수가 입력되었습니다!"); 
	}
	else {
		inoTRI(val);
		otoTRI(val);
		diaTRI(val);
		dbgTRI(val);
	}
	return 0;
}



void inoTRI(int len) {
	unsigned int i1=0, i2=0;
	
	for(i1 = 0 ; i1 <= len ; i1++) {
		for(i2 =0; i2 <= len ; i2++) {
			if(len-i1<i2) {
				putchar('*');
			}
			else {
				putchar(' ');
			}
		
		}
		puts("");
	}
	puts("");
	puts("");
}

void otoTRI(int len) {
	unsigned int i1=0, i2=0;

	for(i1 = 0 ; i1 <= len ; i1++) {
		for(i2 =0; i2 <= len ; i2++) {
			if(i2<i1) {
				putchar(' ');
			}
			else {
				putchar('*');
			}
		
		}
		puts("");
	}
	puts("");
	puts("");	
}


void diaTRI(int len) {
	unsigned int i1=0, i2=0, mid=0; 
	mid = (len/2)+1;
	
	for(i1 = 0 ; i1 <= len ; i1++) {
		for(i2 =0; i2 <= len ; i2++) {
			if(i1 <= mid) {
				if( ( i2 > (mid-i1) ) && ( (mid+i1) > i2  ) ) {
					putchar('*');
				}
				else {
					putchar(' ');
				}
			}
			else {//in case (i1 > mid)
				if( ( i2 > (i1-mid) ) && ( i2 <= len-(i1-mid) ) ) {				
				//if( ( i2 > (i1-mid) ) && ( (i1-mid) < i2  ) ) {
					putchar('*');
				}
				else {
					putchar(' ');
				}				
			}
			
		}
		puts("");
	}
	puts("");
	puts("");	
	
	
}


void dbgTRI(int len) {
	
	int b=0,i=0,j=0;
	b = (len/2) + 1;
	
	for ( i=0 ; i<=len ; i++) {
		for ( j=0 ; j<=len ; j++)	{
			if(i <= b) {
				if( (j > b-i) && j < (b+i) )  {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
			else {
				if( (j > i-b) && (j <= len-(i-b))) {
					printf("*");
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}


//==============================

	for ( i=0 ; i<=len ; i++) 
	{
		for ( j=0 ; j<=len ; j++) 
		{
			if(i <= b)
			{
				if( (j > b-i) && j < (b+i) ) 
				{
					printf(" ");
				}
				else
					printf("*");
					
			}
			else
			{
				if( (j > i-b) && (j <= len -(i-b)))
				{
					printf(" ");
				}
				else {
					printf("*");
				}
			}
		}
		printf("\n");
	}
}

