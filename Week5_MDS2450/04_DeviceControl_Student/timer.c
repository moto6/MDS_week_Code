#include "2450addr.h"
#include "option.h"
#include "my_lib.h"

void Timer_Init(void)
{
	/* 
	* 	Timer0 Init 
	* Prescaler value : 255, dead zone length = 0
	* Divider value : 1/16, no DMA mode
	* New frequency : (PCLK/(Prescaler value+1))*Divider value = (66Mhz/(256))*(1/16)
	*				= 16.113Khz(16113Hz)
	*/
	// target freq : 16.113khz ->> 	rTCFG0=255, rTCFG1=16
 /* TODO : Timer Clock Configure */
	rTCFG0 |= 0xff; //Bit set
	rTCFG1 |= 0xf;
	rTCFG1 &= ~(0xf<<2); 
	
	/* TCON설정 :Dead zone disable,  auto reload on, output inverter off
	*  manual update no operation, timer0 stop, TCNTB0=0, TCMPB0 =0
	*/
	rTCON  = (0<<4)|(1<<3)|(0<<2)|(0<<1)|(0);
	rTCNTB0 = 0;
	rTCMPB0 = 0;
 
}

void Timer_Delay(int msec)
{
	/*
	* 1) TCNTB0설정 : 넘겨받는 data의 단위는 msec이다.
	*                  따라서 msec가 그대로 TCNTB0값으로 설정될 수는 없다.
	* 2) manual update후에  timer0를 start시킨다. 
	* 	 note : The bit has to be cleared at next writing.
	* 3) TCNTO0값이 0이 될때까지 기다린다. 	
	*/
 /* TODO : Timer Counter Setting */
	rTCNTB0 = 16.113 * msec;

	rTCON |= (1<<1)|(0);//manul updata
	rTCON &= ~(1<<1);//manul updata
	
	rTCON |= 1;	//trigger timer start
	
	while(rTCNTO0 != 0);// TCNTO0 : wait for Observation Registor -> read only
											// blocked until setting time
	
}


// like as millis func
// Use Timer0 for PC_ElapsedStart
// Timer INPUT clock Resolution 1.5625MHz
void ElapseTimer_Start(void)
{ 
 rTCFG0 = (rTCFG0 & ~0xff) | 1; //1.5625메가 대충 높은 클럭이 필요해요
 rTCFG1 = (rTCFG1 & ~0xf) | 3; 
 
 /* TCON설정 :Dead zone disable,  auto reload on, output inverter off
 *  manual update no operation, timer0 stop, TCNTB0=0, TCMPB0 =0
 */
 rTCON  = (rTCON & ~((1<<4)|(1<<2)|(1<<1)|(1))) | (1<<3);

 rTCNTB0 = 0;
 rTCMPB0 = 0;

 rTCNTB0 = 0xffff; // initial value(65535) for timer
//업카운트 회로 다운카운트 회로
 rTCON |= (1<<1)|(0);
 rTCON &= ~(1<<1);
 rTCON |= 1;
}
//65536 = 1562500(1.5625메가헤르쯔) = 0.040ms time 최대 40미리까지 측정 가능



//
// Use Timer0 for PC_ElapsedStart
// Timer Resolution 1.5625MHz
unsigned int ElapseTimer_Stop(void)
{
 rTCON &= ~1;//timer stop!

 //return (0xffff - rTCNTO0);// passed time 
 return (0xffff - rTCNTO0)/1562.500;//ms
}

