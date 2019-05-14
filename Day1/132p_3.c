#include <stdio.h>
int main (void) 
{
	unsigned int dist = 0, sped = 0, hor = 0, min = 0;
	int sbuf=0;
	double sec = 0;
	double t_buffer = 0;
	printf ("Distance[km] and Speed[km/h] insert!! : ");
	scanf("%d %d", &dist, &sped);
	puts("");
	t_buffer = (double)dist/sped;
	
	printf("%lf\n",t_buffer);
	
	hor = (int)t_buffer;
	min = t_buffer * (double)60;
	min = min%60;
	sec = t_buffer * (double)3600;
	sbuf = (int)sec/60;
	sec = sec - (double)sbuf*60 ;
	//sbuf
	
	
	printf("arrival time : %d[hour] %d[min] %lf[sec]",hor,min,sec);
	puts("");	
}
