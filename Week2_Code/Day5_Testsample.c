#include <stdio.h>
#include <string.h>

#define EX 10



#if (EX==6)

int main(void) {
	int i;
	for(i=10; i>0 ; i--) {
		if(i%2==0 || i%3==0)
			continue;
		printf("%d ", i);	
		
	}
	return 0;
}

#endif


#if (EX==7)

int main(void) {
	int i;
	for(i=0;i<10;i+=2)
		do printf("test "); while(0);
	
	return 0;	
}

#endif



#if (EX==8)

int main(void) {
	int i, a[100];
	for(i=0;i<100;i++)
		a[i] = i;
	for(i=0;i<100;i++)
		printf("%6d%c",a[i],(i%10==9 || i==100-1)?'\n' : ' ');
		
	
	return 0;	
}

#endif


#if (EX==10)

#include <string.h>
int strfunc(char *str);

int main(void) {
	int i ;
	
	char samplestr[]  = {1,1,1,1,0};
	
	//printf("Str = %s, fucn = %d","Helloworld!",strfunc("Helloworld!"));
	printf("%d",strfunc(samplestr));
	printf("%d",strlen(samplestr));
	return 0;	
}
int strfunc(char *str) {
	int i;
	for(i=0;str[i];i++);
	return i;
}
#endif


