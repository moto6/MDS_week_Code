#include <stdio.h>

int *sum(int a, int b);                 // int형 변수의 주소를 반환하는 함수 선언

int main(void)
{
	int *p;                             // 반환값을 저장할 포인터
	int i;
	
	p = sum(10, 20);                    // 반환된 주소는 p에 저장
	
	for(i=0;i<0x100;i++) 
		printf("두 정수의 합 : %d\n", *p);  // p가 가리키는 변수값 출력

	return 0;
}

int *sum(int a, int b)                  // int형 변수의 주소를 반환하는 함수
{
	static int res;                     // 정적 지역 변수
	//static 안쓰고 자동변수라면 한번만 제대로 찍히고 이후로 쓰래기값 찍힘
	//static 대신 malloc 과 free 사용 가능 

	res = a + b;                        // 두 정수의 합을 res에 저장

	return &res;                        // 정적 지역 변수의 주소 반환
}
