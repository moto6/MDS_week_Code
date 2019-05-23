#include "2450addr.h"
#include "option.h"
#include "libc.h"

//Function Declaration
void Timer1_Init(void);
void Timer1_Delay(int msec);

void Timer0_Init(void)
{
	rTCFG0 |= 	(0xff);
	rTCFG1 |= 	(0x03); //manual update no operation, timer0 stop, TCNTB0=0, TCMPB0 =0
	rTCON |= 	(0x01<<3);
	rTCNTB0 &= 	0x00;
	rTCMPB0 &= 	0x00;
}

void Timer0_Delay(int msec)
{
	rTCNTB0 =	16.113*msec; // HCLK 133MHz ,Div 1/2 =62MHz , 16.113 clock =  ms 
	rTCON |=	(0x01<<1); // Set Bit TCON [1] ->> mannual update
	rTCON &= 	~(0x01<<1); // Clear Bit TCON [1] ->> no more update
	rTCON |=  	(0x01); // Start for Timer 0
	while(rTCNTO0); // Every (1/16.113) msec, TCNTB0 Counter value reduced by Timer 0
}


void Timer1_Init(void)
{
	rTCFG0 |= 	(0xff);
	rTCFG1 |= 	(0x3<<4); //manual update no operation, timer0 stop, TCNTB0=0, TCMPB0 =0 ,Div1/16
	rTCON |= 	(0x01<<11);
	rTCNTB1 &= 	0x00;
	rTCMPB1 &= 	0x00;
}

void Timer1_Delay(int msec)
{
	rTCNTB1 =	16.113*msec; // HCLK 133MHz ,Div 1/2 =62MHz , 16.113 clock =  ms 
	rTCON |=	(0x01<<9); // Set Bit TCON [1] ->> mannual update
	rTCON &= 	~(0x01<<9); // Clear Bit TCON [1] ->> no more update
	rTCON |=  	(0x01<<8); // Start for Timer 1
	while(rTCNTO1); // Every (1/16.113) msec, TCNTB1 Counter value reduced by Timer 1
}


void Timer2_Init(void)
{
	rTCFG0 |= 	(0xffff);
	rTCFG1 |= 	(0x3<<8); //manual update no operation, timer2 stop, TCNTB2=0, TCMPB2 =0 ,Div1/16
	rTCON |= 	(0x01<<15);//Timer2 auto reload mode set
	rTCNTB2 &= 	0x00;
	rTCMPB2 &= 	0x00;
}

void Timer2_Delay(int msec)
{
	rTCNTB2 =	16.113*msec; // HCLK 133MHz ,Div 1/2 =62MHz , 16.113 clock =  ms 
	rTCON |=	(0x01<<13); // Set Bit TCON [1] ->> mannual update
	rTCON &= 	~(0x01<<13); // Clear Bit TCON [1] ->> no more update
	rTCON |=  	(0x01<<12); // Start for Timer 1
	while(rTCNTO2); // Every (1/16.113) msec, TCNTB1 Counter value reduced by Timer 1
}


void Timer3_Init(void)
{
	rTCFG0 |= 	(0xffff);
	rTCFG1 |= 	(0x3<<12); //manual update no operation, timer2 stop, TCNTB2=0, TCMPB2 =0 ,Div1/16
	rTCON |= 	(0x01<<19);//Timer3 auto reload mode set
	rTCNTB3 &= 	0x00;
	rTCMPB3 &= 	0x00;
}

void Timer3_Delay(int msec)
{
	rTCNTB3 =	16.113*msec; // HCLK 133MHz ,Div 1/2 =62MHz , 16.113 clock =  ms 
	rTCON |=	(0x01<<17); // Set Bit TCON [1] ->> mannual update
	rTCON &= 	~(0x01<<17); // Clear Bit TCON [1] ->> no more update
	rTCON |=  	(0x01<<16); // Start for Timer 1
	while(rTCNTO3); // Every (1/16.113) msec, TCNTB1 Counter value reduced by Timer 1
}

void Timer4_Init(void)
{
	rTCFG0 |= 	(0xffff);
	rTCFG1 |= 	(0x3<<16); //manual update no operation, timer2 stop, TCNTB2=0, TCMPB2 =0 ,Div1/16
	rTCON |= 	(0x01<<22);//Timer3 auto reload mode set
	rTCNTB4 &= 	0x00;
	
}

void Timer4_Delay(int msec)
{
	rTCNTB4 =	16.113*msec; // HCLK 133MHz ,Div 1/2 =62MHz , 16.113 clock =  ms 
	rTCON |=	(0x01<<21); // Set Bit TCON [1] ->> mannual update
	rTCON &= 	~(0x01<<21); // Clear Bit TCON [1] ->> no more update
	rTCON |=  	(0x01<<20); // Start for Timer 1
	while(rTCNTO4); // Every (1/16.113) msec, TCNTB1 Counter value reduced by Timer 1
}
