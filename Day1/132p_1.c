#include <stdio.h>

int main(void) {
	double wi=0;
	double hi_me = 0;
	double hi_cm = 0;
	double BMI = 0;
	
	printf ("insert your Weight(kg) and Hight(cm) : ");
	scanf( "%d %lf", &wi, &hi_cm);
	hi_me = hi_cm/100;
	
	BMI = wi/(hi_cm*hi_cm);
	
	if (20<=BMI && BMI >= 25 ){
		printf("good!");
	}
	else {
		printf(" you need manege your weight");
	}
	
	return 0;
}
