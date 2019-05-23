//#include "../lib2450/Uart.h"
#include "2450addr.h"
#include "libc.h"
#include "option.h"
//#include "Key.c"

#define MODE GPIO
void GPIO_Init(void);
void LED_ON_Off(void);
void off_all(void);
void on(int pin);

int Get_Key(void);
//int SW_Read(void);


void Delay_dt(void);
void Delay_ms(unsigned int ms);


void Main() {
	int i;
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
	
	while(1)
	{
//#if MODE == UART
/*
		for(i=0;i<5;i++) {
			Uart_Send_String("Timer0 Delay 200ms..!!\n");
			Timer0_Delay(200);
		}
		
		
		
		for(i=0;i<5;i++) {
			Uart_Send_String("Timer1 Delay 200ms..!!!\n");
			Timer1_Delay(200);
		}
		
		
		
		for(i=0;i<5;i++) {
			Uart_Send_String("Timer2 Delay 200ms..!!!!\n");
			Timer2_Delay(200);
		}
		
		
		for(i=0;i<5;i++) {
			Uart_Send_String("Timer3 Delay 200ms..!!!!!\n");
			Timer3_Delay(200);
		}
		
		
		for(i=0;i<5;i++) {
			Uart_Send_String("Timer4 Delay 200ms..!!!!!!!\n");
			Timer4_Delay(200);
		}
#endif
*/
//==================================================
//#if MODE == GPIO
		Uart_Send_String("GPIO MODE\n");
		Uart_Printf("[ SW %d ] is pressed\n",Get_Key());
		Uart_Printf("[ SW %d ] is pressed\n",Get_Key());
		Uart_Printf("[ SW %d ] is pressed\n",Get_Key());
		Uart_Printf("[ SW %d ] is pressed\n",Get_Key());
		Uart_Printf("[ SW %d ] is pressed\n",Get_Key());
		Timer1_Delay(500);		

//# endif 
		
		
		
	}
}
/*==Day3 Source==================
void Main()
{
	
	
	Uart_Init(115200);	
	Uart_Send_Byte('\n');
	Uart_Send_Byte('A');	
	Uart_Send_String("Hello Uart Test...!!!\n");
	
	Init();
	
	int i=0;
	int SW=0;
	Uart_Send_String("Key Test \n");

	do {
		
		if(Get_Key()) {
			Uart_Printf("Key Value =%d\n",Get_Key_byPolling()); 
		}
		else {
			//Delay_ms(100);
			Uart_Printf("Wait....\n");
		}
		Delay_ms(100);		
	
	}while(1);	

	
		
}
*/


void GPIO_Init() 
{
   rGPGCON |= (0x55<<8); // LED Init 
   rGPGDAT |= (0x0f<<4); // LED Off
   
   rGPGCON |= (0x01); //Switch downbelow Init
   rGPFCON |= (0x01<<14); //Switch downbelow Init
   
   rGPFCON &= ~(0x3ff << 4);
   rGPFCON &= ~(0x2 << 14);
   
   rGPFCON |= (0x3<<14);
   rGPGCON |= (0x1);
   
}


int Get_Key(void) {

	//rGPFDAT &= ~(0x1<<7); //Clear GPF7
	rGPFDAT &= ~(0x1<<7); //Clear GPF7
	
	rGPGDAT &= ~(0x1);	//Clear GPG0
	//rGPGDAT |= (0x1);	//Clear GPG0
	
	
	//if( rGPFDAT & 0x7f) == 	
    
	/*
	if (!(rGPFDAT&0x02)) {//SW9
        return 9;
    }
	
	
	if ((rGPFDAT & 0x0f) == 0x07) //SW10
        return 10;
    
	
	*/
    if ((rGPFDAT & 0x04) == 0x00) { //SW9
        return 9;
    }
    
    if ((rGPFDAT & 0x08) == 0x00) {//SW10
        return 10;
    }
    
    if ((rGPFDAT & 0x10) == 0x00) {//SW11
        return 11;
    }
    
    if ((rGPFDAT & 0x20) == 0x00) {//SW12
        return 12;
	}
	
    if ((rGPFDAT & 0x40) == 0x00) {//SW13
        return 13;
	}


	
/*
	if ((rGPFDAT & 0x07) == 0x03) //
        return 4;
    if ((rGPFDAT & 0x0f) == 0x07) //3  
        return 5;
    if ((rGPFDAT & 0x1f) == 0x0f) //2
        return 6;
    if ((rGPFDAT & 0x3f) == 0x1f) //1
        return 7;
    if ((rGPFDAT & 0x7f) == 0x3f) //5
        return 8;
  //
  */  	
	return 0;
}

int SW_Read(void) {
  int i;
 
  for(i=0;i<20;i++) {
    if(~(0x01)<<i & (rGPFDAT|~(0x01<<i))) {
      return i;
    }
  }
return 0;
}



void on(int pin) {
  rGPGDAT &= ~(0x1<<pin);
}


void off_all(void) {
  rGPGDAT |= (0xf<<4);
}


void LED_ON_Off() {
  int i;

  rGPGDAT |= (0xf<<4);
  Delay_ms(100);
  rGPGDAT &= ~(0xf<<4);
  Delay_ms(100);
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
}

