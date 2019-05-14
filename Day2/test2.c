#include <stdio.h>

void printBit(unsigned char num);

int main()
{
    // todo : 필요한 변수 선언
	unsigned char packed = 0;  // 비트를 셋팅할 변수
	unsigned char Gend =0, Year=0, Majr=0;

	printf("Insert Gender (M=0/F=1) : ");
	scanf("%d", &Gend);
    
    
	printf("Inser Year : ");
	scanf("%d", &Year);
	
	printf("Inser Major(No=0/Yes=1) : ");
	scanf("%d", &Majr);
	
	packed|=Gend;
	packed|=(Year<<1);
	packed|=(Majr<<4);
	
	
	printf("\r\nGender %d - 0 bit :  ",  Gend);
	printBit(Gend);
	printf("\r\nYear %d - 1,2,3 bit : ", Year );
	printBit(Year<<1);
	printf("\r\nMajor %d - Set bit :", Majr );
    printfBit(Majr<<4);
	// todo : 필요한 값을 입력 받고 packed 변수에 비트를 셋팅하는 코드 작성

	printBit(packed);          // 셋팅한 비트 프린트해보기


	return 0;
}

void printBit(unsigned char num)
{
    unsigned char mask = 0x01;
    int i=0;
    for(i=7; i>=0 ; i--)
	{
		if((mask << i) & num)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

