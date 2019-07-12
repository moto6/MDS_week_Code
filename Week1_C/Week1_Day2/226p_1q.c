#include <stdio.h>

int total(int kor, int eng, int mat);
double average(int tot);
void print_title(void);


int main(void) {
	int a=0,b=0,c=0;
	
	printf("세 과목의 점수 입력 : ");
	scanf("%d %d %d",&a,&b,&c);


	print_title();
	
	
	printf("%d\t %d\t %d\t %d\t %1f",a,b,c,total(a,b,c),average(total(a,b,c)));
	return 0;	
}



int total(int kor, int eng, int mat) {
	
	return (kor+eng+mat);
}


double average(int tot) {
	return ((double)tot/3);
}


void print_title(void) {
	puts("  ===<성적표>===   ");
	puts("===================");
	puts("");
	puts("-------------------");
	puts("국어\t영어\t수학\t총점\t평균"); 
	return;
}


