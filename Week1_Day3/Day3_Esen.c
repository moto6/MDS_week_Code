#include <stdio.h>
/*
int main(void)
{
	int i=0,buf=0;
	const int ans = 17;
	for(i=1 ; i<=30 ; i++) {
		printf("insert number (1~30) : ");
		scanf("%d",&buf);
		
		if(buf==ans) {
			puts("success!!");
			puts("success!!");
			puts("success!!");
			break;
		}
		else {
			puts("wrong ans");
			if(buf<ans) {
				puts("UP");
			}
			else {
				puts("DOWN");
			}
		}
	}
	
	return 0;
}

================================================================

int main(void) 
{
int a;
int *pa;

 pa = &a;
 *pa=10;
 
 printf("*pa 포인터로 출력 : %d",*pa);
 printf("a print by var name %d",*(&*(&a)));

	return 0;
}
================================================================
int main(void)
{
	char c1, c2,c3;
	
	scanf("%c%c", &c1,&c2);
	printf("[%c%c]",c1,c2,c3);
	return 0;
}

================================================================

int main(void)
{
	int res;
	char ch;
	
	while(1)
	{
		res = scanf("%c", &ch);
		if(res == -1) break;
		printf("%d ",ch);
		
	}
	return 0;
}


================================================================

int main(void)
{
	int num, grade;
	
	printf("학번입력 : ");
	scanf("%d" , &num);
	fflush(stdin);
	printf("학점입력 :");
	grade = getchar();
	printf("학번 : %d, 학점 : %c",num, grade);
	
	return 0;
}


================================================================

int main (void) 
{
	printf("주소값 : 0x%x\n","mango");
	printf("첫 번째 문자 : %c\n",*"mango");
	printf("두 번째 문자 : %c\n",*("mango"+1));
	printf("세 번째 문자 : %c\n","mango"[2]);
}


================================================================

int main(void)
{
	char *dessert = "appleasdsdfsfd";
	
	printf("오늘 후식은 %s 입니다 \n",dessert);
	dessert = "banana";
	printf("내일 후식은 %s 입니다 \n",dessert);
	
	//*(dessert +0 )= 'k';
	//printf("??? 후식은 %s 입니다 \n",dessert);
	
	return 0;
	
}


================================================================
*/
int main(void)
{
	char str[10];
	
	printf("공백이 포함된 문자열\n");
	fgets (str, sizeof(str),stdin);
	printf("입력된 문자열은 %s 입니다 \n",str);
	
	//*(dessert +0 )= 'k';
	//printf("??? 후식은 %s 입니다 \n",dessert);
	
	return 0;
	
}
