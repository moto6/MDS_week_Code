#include <stdio.h>
#include "2450addr.h"
#include "my_lib.h"
#include "macro.h"

void MMU_Init(void);

// ¾ÆÀÌÄÜ ±×¸²µéÀÇ ÁöÁ¤
#include "./button/RUN_ER.H"
#include "./button/RUN_EP.H"

// ºÒ·¯¿Ã ±×·¡ÇÈ È­ÀÏÀ» ÁöÁ¤
#include "./Images/myimg.h"
#include "./Images/S01.H"

// Color Define
// [D15-D11]RED, [D10-D6]GREEN, [D5-D1]BLUE
#define BLACK	0x0000
#define WHITE		0xfffe
#define BLUE		0x003e
#define GREEN	0x07c0
#define RED		0xf800
#define YELLOW	0xffc0

// ISR Functions declaration

#define LCD_XSIZE 		(480)	
#define LCD_YSIZE 		(272)

// Functions Declaration

void HW_Initial(void);
void Show_Welcome(char * msg);

// Global Variables Declaration

// ÅÍÄ¡ÆÐµå°¡ ´­¸²À» ¾Ë¼ö ÀÖ´Â °ª
volatile int Touch_pressed = 0;
// ADC °ª
volatile int ADC_x=0, ADC_y=0;

// Calibration Á¤º¸ ÀúÀå °ª
volatile int Cal_x1=848;
volatile int Cal_y1=656;
volatile int Cal_x2=186;
volatile int Cal_y2=349; 

// ÁÂÇ¥ º¯È¯ °ª
volatile int Touch_x, Touch_y;
// Calibration ¿Ï·á °ª
volatile unsigned int Touch_config=1;

void Touch_ISR(void) __attribute__ ((interrupt ("IRQ")));

void Touch_ISR()
{
	/* TO DO: Pendng Clear on Touch */	
	rSUBSRCPND = (0x1<<9);//Touch Interrupt -> PIC3
	rSRCPND1 = (0x1<<31);//ADC interrupt 
	rINTPND1 = (0x1<<31);
	
	// Touch UP
	if(rADCTSC&0x100)
	{
		rADCTSC&=0xff;
		Touch_pressed = 0;
	}
	// Touch Down
	else 
	{
		rADCTSC=(0<<8)|(1<<7)|(1<<6)|(0<<5)|(1<<4)|(1<<3)|(1<<2)|(0);
		// SADC_ylus Down,Don't care,Don't care,Don't care,Don't care,XP pullup Dis,Auto,No operation
		
		rADCCON|=0x1;
		while(rADCCON & 0x1);
		while(!(0x8000&rADCCON)); // AD convert wait until end


		ADC_x=(int)(0x3ff&rADCDAT0);
		ADC_y=(int)(0x3ff&rADCDAT1);
		//양자화 계수 

		// Touch calibration complete
		if(Touch_config)
		{
			Touch_y=(ADC_y-Cal_y1)*(LCD_YSIZE-10)/(Cal_y2-Cal_y1)+5;
			Touch_x=(ADC_x-Cal_x2)*(LCD_XSIZE-10)/(Cal_x1-Cal_x2)+5;
			Touch_x=LCD_XSIZE-Touch_x;
			if(Touch_x<0) Touch_x=0;
			if(Touch_x>=LCD_XSIZE) Touch_x=LCD_XSIZE-1;
			if(Touch_y<0) Touch_y=0;
			if(Touch_y>=LCD_YSIZE) Touch_y=LCD_YSIZE-1;
		}
		// before calibration		
		else
		{
			Touch_x = ADC_x;
			Touch_y = ADC_y;
		}

		rADCTSC=(1<<8)|(1<<7)|(1<<6)|(0<<5)|(1<<4)|(0<<3)|(0<<2)|(3);
		// SADC_ylus Up,Don't care,Don't care,Don't care,Don't care,XP pullup En,Normal,Waiting mode
		Touch_pressed = 1; 
	}

	rINTSUBMSK &= ~(0x1<<9);
	rINTMSK1 &= ~(0x1<<31);
}
// Lower Layer Functions

void HW_Initial(void)
{
	// ÇÊ¿äÇÑ ÃÊ±âÈ­ ·çÆ¾µéÀ» ±âÀÔÇÑ´Ù
	Exception_Init();
	Uart_Init(115200);	
//	Led_Init();
//	Buzzer_Init();

	Timer0_Init();
	Graphic_Init();
	
	Touch_Isr_Init(Touch_ISR);
	MMU_Init();
}

void Show_Welcome(char * msg)
{
	int a, j; 
	
	Uart_Printf("\n%s\n", msg);
	
	for(a=0;a<2;a++)
	{
		Led_Display(7);
		for(j=0; j<0x0ffff; j++);
		Led_Display(0);
		for(j=0; j<0x0ffff; j++);
	}
}

void main(void)
{
	int xtmp, ytmp;
	char* myPtr;

	Uart_Init(115200);

	HW_Initial();

/* malloc test */
	myPtr= malloc(4096);
	*myPtr= 'W';
/* printf test */
	printf("c=%c\n", *myPtr);
	free(myPtr);

	Show_Welcome("LCD & Touch Test");

	Lcd_Clr_Screen(BLACK);
	Lcd_Select_Frame_Buffer(0);
	Lcd_Get_Info_BMP(&xtmp, &ytmp, MYIMG);
	Lcd_Draw_BMP(((LCD_XSIZE/2)-(xtmp/2)), ((LCD_YSIZE/2)-(ytmp/2)), MYIMG); 
	Lcd_Printf(10,254, YELLOW, BLACK, 1,1,"Hello world!! !!");

	Lcd_Select_Frame_Buffer(1);
	Lcd_Clr_Screen(BLUE);
	Lcd_Get_Info_BMP(&xtmp, &ytmp, s01);
	Lcd_Draw_BMP(((LCD_XSIZE/2)-(xtmp/2)), ((LCD_YSIZE/2)-(ytmp/2)), s01);  
	Lcd_Printf(10,254, YELLOW, BLACK, 1,1,"´ÙÀ½´Ü°è·Î ³Ñ¾î°¡·Á¸é ÅÍ¹Ì³Î¿¡¼­ ¾Æ¹«Å°³ª ÀÔ·ÂÇÏ¼¼¿ä");

	Uart_Printf("\ngogo \n");

  Lcd_Hline(5,0,10-1,BLUE);
  Lcd_Vline(5,0,10-1,BLUE);

  Lcd_Put_Pixel(200,45,RED);
  Lcd_Put_Pixel(201,45,RED);
  Lcd_Put_Pixel(202,45,RED);
  Lcd_Put_Pixel(203,45,RED);

	do
	{
		Lcd_Wait_Blank();
		Lcd_Display_Frame_Buffer(0);
		Timer0_Delay(1000);
		Lcd_Wait_Blank();
		Lcd_Display_Frame_Buffer(1);
		Timer0_Delay(1000);
	}while(!Uart_Get_Pressed());	
	
	Uart_Printf("\nÅÍÄ¡2 Calibration\n");
	
	Touch_ISR_Enable(1);   //
    	Lcd_Clr_Screen(WHITE);	     

#if 1 // Ä¶¸®ºê·¹ÀÌ¼Ç »ý·« 
  Lcd_Hline(5,0,10-1,BLUE);
  Lcd_Vline(5,0,10-1,BLUE);

  Lcd_Put_Pixel(200,45,RED);
  Lcd_Put_Pixel(201,45,RED);
  Lcd_Put_Pixel(202,45,RED);
  Lcd_Put_Pixel(203,45,RED);



	Lcd_Hline(5,0,10-1,BLUE);
	Lcd_Vline(5,0,10-1,BLUE);
	Lcd_Printf(10,40, BLUE, WHITE, 1,1,"ÁÂÃø»ó´Ü¿¡ º¸ÀÌ´Â '+' Ç¥½Ã¸¦ ´©¸£¼¼¿ä");    
	Timer0_Delay(200);
	while(Touch_pressed == 0);
	Uart_Printf("\nADC_x:%d, ADC_y:%d", ADC_x, ADC_y); 
	Touch_pressed = 0;
	
	Cal_x1=ADC_x;  //
	Cal_y1=ADC_y;  // 좌 상단  
	
	Lcd_Hline(5,0,10-1,WHITE);
	Lcd_Vline(5,0,10-1,WHITE);
    	Lcd_Clr_Screen(WHITE);	     

	Lcd_Hline(LCD_YSIZE-5,LCD_XSIZE-0,LCD_XSIZE-10+1,BLUE);
	Lcd_Vline(LCD_XSIZE-5,LCD_YSIZE-0,LCD_YSIZE-10+1,BLUE);
	Lcd_Printf(80,200, BLUE, WHITE, 1,1,"¿ìÃøÇÏ´Ü¿¡ º¸ÀÌ´Â '+' Ç¥½Ã¸¦ ´©¸£¼¼¿ä");
	Timer0_Delay(200);
	while(Touch_pressed == 0);
	Uart_Printf("\nADC_x:%d, ADC_y:%d", ADC_x, ADC_y); 
	Touch_pressed = 0;
	
	Cal_x2=ADC_x;  //
	Cal_y2=ADC_y;  // 우 하단  
	
	Lcd_Hline(LCD_YSIZE-5,LCD_XSIZE-0,LCD_XSIZE-10+1,WHITE);
	Lcd_Vline(LCD_XSIZE-5,LCD_YSIZE-0,LCD_YSIZE-10+1,WHITE);
    	Lcd_Clr_Screen(WHITE);	     

       Touch_config=1;  //

	Lcd_Printf(0,100,BLUE,WHITE,1,1,"ÅÍÄ¡ÆÐµå¸¦ ´­·¯º¸¼¼¿ä x,y ÁÂÇ¥Á¤º¸¸¦ Ç¥½ÃÇØ ÁÝ´Ï´Ù");   
	Lcd_Printf(0,140,BLUE,WHITE,1,1,"[ÅÍ¹Ì³Î Å°º¸µåÀ» ¾Æ¹«Å°³ª ´©¸£¸é Á¾·á]");  
	
	Uart_Printf("\nÅÍÄ¡ÆÐ³ÎÀ» ´©¸£¸é À§Ä¡°¡ Ç¥½ÃµË´Ï´Ù.\n");
	Uart_Printf("Å°º¸µå¸¦ ´©¸£¸é ´ÙÀ½µ¿ÀÛÀ¸·Î ³Ñ¾î°©´Ï´Ù.\n");	 	
	
	do
	{
		if(Touch_pressed == 1)
		{
			Uart_Printf("\nX:%d, Y:%d", Touch_x, Touch_y); 
			Touch_pressed = 0;
		}
	}while(!Uart_Get_Pressed());	
	
	
	/* Touch-panel Test */
	Uart_Printf("\nÅÍÄ¡ÆÐ³Î ÀÀ¿ë ½Ç½À\n");
	Uart_Printf("±×¸²À» ´­·¯º¾½Ã´Ù\n");	
#endif

	Uart_Printf("\nCal_x1=%d\n", Cal_x1);	
	Uart_Printf("\nCal_x2=%d\n", Cal_x2);	
	Uart_Printf("\nCal_y1=%d\n", Cal_y1);	
	Uart_Printf("\nCal_y2=%d\n", Cal_y2);
	
	Lcd_Clr_Screen(BLACK);    
	Lcd_Get_Info_BMP(&xtmp, &ytmp, run_er);     

	Lcd_Printf(10,40, YELLOW, BLACK, 1,1,"¾ÆÀÌÄÜÀ» ´­·¯º¸¼¼¿ä");

	for(;;)
	{
		Lcd_Draw_BMP((160-(xtmp/2)), (120-(ytmp/2)), run_er);    
	
		for(;;)
		{
			if(Touch_pressed == 1)
			{
				if((Touch_x >= (160 - (xtmp/2))) && (Touch_x <= (160 + (xtmp/2))) && (Touch_y >= (120 - (ytmp/2))) && (Touch_y <= (120 + (ytmp/2))))
				{
					Uart_Printf("\n Pressed"); 
					Lcd_Printf(80,120, BLACK, RED, 1,1," PUSH ");
					break;
				}
			}
		}
	
		Lcd_Draw_BMP((160-(xtmp/2)), (120-(ytmp/2)), run_ep);    
	
		for(;;)
		{
			if(Touch_pressed == 0)
			{
				Uart_Printf("\n Released"); 
				Lcd_Printf(80,120, BLACK, BLACK, 1,1," PULL ");
				break;
			}
		}
	}	
}
