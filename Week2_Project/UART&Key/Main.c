//#include "../lib2450/Uart.h"
#include "2450addr.h"
#include "libc.h"
#include "option.h"

#define MODE GPIO
void GPIO_Init(void);

void BSP_LED_Bnk(void);
void BSP_LED_Off(void);
void BSP_LED_On(void);
void BSP_LED_Sft(void);
void BSP_LED_Tgl(int Pin);
int Get_Key(void);


void Delay_dt(void);
void Delay_ms(unsigned int ms);


int Main(void) {
	int i,buf=0;
	Uart_Init(115200);	
	Uart_Send_Byte('\n');
	Uart_Send_Byte('A');	
	Uart_Send_String("Hello Uart Test OK...!!!\n");
	
	GPIO_Init();
	Timer0_Init();
	Timer1_Init();	
	Timer2_Init();	
	Timer3_Init();	
	Timer4_Init();	
  Uart_Send_String("UART & KEY MODE\n");
	
	while(1)
	{
	
		if(buf=Get_Key()) {
			Uart_Printf("[ SW %d ] is pressed\n",buf);
			BSP_LED_Tgl(buf);
		}
		else {
		}	
			Timer1_Delay(200);	
	}
}
/*==Day3 Source==================*/


void GPIO_Init() 
{
	rGPGCON |= (0x55<<8); // LED Init 
	rGPGCON &= ~(0x55<<9); // LED Init 
  
	rGPGDAT |= (0x0f<<4); // LED Off
	   
	rGPGCON |= (0x01); //Switch downbelow Init
	rGPFCON |= (0x01<<14); //Switch downbelow Init
   
	rGPFCON &= ~(0x3ff << 4);
	rGPFCON &= ~(0x2 << 14);
   
	rGPFCON |= (0x3<<14);
	rGPGCON |= (0x1);
   
	rGPFCON |= (0x1<<14); //Switch Init(GPF7)
	rGPFCON &= ~(0x1<<15); //Switch Init(GPF7)
}

int Get_Key(void) {

	// Lonely Switch ======================================
  if ((rGPFDAT & 0x01) == 0x00) {//SW14
    return 14;
	}
	
  if ((rGPFDAT & 0x02) == 0x00) {//SW15
  	return 15;
	}

	// First Line Switch ==============================
	rGPFDAT &= ~(0x1<<7); //Clear GPF7
	rGPGDAT |= (0x1);	//Set GPG0
	
    
  if ((rGPFDAT & 0x04) == 0x00) {
		return 4;}
    
  if ((rGPFDAT & 0x08) == 0x00) {//SW10
    return 5;}
    
  if ((rGPFDAT & 0x10) == 0x00) {//SW11
	  return 6;}
     
  if ((rGPFDAT & 0x20) == 0x00) {//SW12
    return 7;}
	
  if ((rGPFDAT & 0x40) == 0x00) {//SW13
    return 8;}
	
	// Second Line Switch =====================================
	
	rGPFDAT |= (0x1<<7); //Clear GPF7
	rGPGDAT &= ~(0x1);	//Clear GPG0
	
  if ((rGPFDAT & 0x04) == 0x00) { //SW9
    return 9;}
    
  if ((rGPFDAT & 0x08) == 0x00) {//SW10
    return 10;}
    
  if ((rGPFDAT & 0x10) == 0x00) {//SW11
    return 11;}
   
  if ((rGPFDAT & 0x20) == 0x00) {//SW12
	return 12;}
	
  if ((rGPFDAT & 0x40) == 0x00) {//SW13
    return 13;}
	 	
	return 0;
}


int SW_Read(void) {
	//uncompleted func
	int i;
 
	for(i=0;i<20;i++) {
    	if(~(0x01)<<i & (rGPFDAT|~(0x01<<i))) {
    	return i;
	}
	}
	return 0;
}



void BSP_LED_On(void) {
	rGPGDAT &= ~(0xf<<4);
	return; 
}


void BSP_LED_Off(void) {
	rGPGDAT |= (0xf<<4);
	return;
}

void BSP_LED_Tgl(int Pin) {
	if(Pin>=4 && Pin<=7) {
		rGPGDAT ^= (0x1<<Pin);
	} 
	else {
		return;
	}
	return;
}
void BSP_LED_Bnk(void) {
  rGPGDAT |= (0xf<<4);
  Delay_ms(100);
  rGPGDAT &= ~(0xf<<4);
  Delay_ms(100);
}


void BSP_LED_Sft(void) {
	if(rGPGDAT & 0xf0 == 0xf0) {
		rGPGDAT |= (0x01<<4);
	}	
	else {
		rGPGDAT |= (rGPGDAT<<1)&(0xf<<4); 
	}
	return 0;
}

void Delay_dt(void) {
	volatile unsigned int i;
	for(i=0;i<0x4ff;i++) {
	}
	return;
}

void Delay_ms(unsigned int ms) {
	volatile unsigned int i;
	for(i=0;i<ms;i++) {
		Delay_dt();
	}
	return;
}

