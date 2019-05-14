#include <stdio.h>

int main(void) 
{
	int rawdata[5] = {0};
	int udata[3] = {0};
	int i=0,j=0;
	int buff=0,sum=0;
	
	double avr = 0;
	puts("5 nums of data insert!");
	scanf("%d %d %d %d %d",&rawdata[0],&rawdata[1],&rawdata[2],&rawdata[3],&rawdata[4]);
	
	puts("heheh");
	//udata cal
	
    for(j=0;j<5;j++)

    {
		for(i=0;i<4;i++) {
			if(rawdata[i]>rawdata[i+1]) {
				buff = rawdata[i];
				rawdata[i] = rawdata[i+1];
				rawdata[i+1] = buff;
			}
		}
		
	}
	for (i=0;i<=3;i++) {
		udata[i] = rawdata[i+1];
		
	}
	
	for (i=0;i<3;i++) {
		sum= sum + udata[i];
	}
	avr = (double)sum/3.0;
	printf("U Data : %d %d %d ", udata[0], udata[1], udata[2]);
	
	
	//cal arv 
	
	
	printf("average : %6.1lf\n",avr);
	printf("rawdata : %d %d %d %d %d",rawdata[0],rawdata[1],rawdata[2],rawdata[3],rawdata[4]);
	
	
}
