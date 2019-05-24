//#include "../lib2450/Uart.h"

#define sleep do{Delay_ms(100);}while(0);
#define puts Uart_Send_String
#define printf Uart_Send_String
#define ENDMSG_RUTIN do{puts("Program terminated!!\n\n");}while(0);
#define WAITKEY_RUTIN do{printf("\ncontinue to press any key");}while(0);
#define MID_DBL_LINE do{puts("=====================================================");}while(0);
#define WAIT_RUTIN do{puts("Looding..");sleep(1);puts("Looding......");sleep( 1 );}while(0);
#define MAXLEN 100 //max len of buf


int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int loginflag = 0;
char ID_admin[] = "admin";
char PW_admin[] = "admin";


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

int app_init(int cmd);
int app_deinit(int state);
int app_launch(int mode);


//=================================================
// Stadard Fucn
//================================================


int dispmenu(void);
int loginout(void);
int accprint(void);
int banktrns(void);
int withdraw(void);
int depositm(void);
int checkdps(void);
int levamesg(char **str);
int gamemode(void);


int printmsg (char **ps);




struct account {
	char *Name;
	
	int deposit;
	int trust;
	
	char ID[MAXLEN];
	char PW[MAXLEN];
	
};
struct account cur_user;

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
  Uart_Send_String("ATM Sim\n");
	
	while(1)
	{

	app_init(1);
	return app_deinit(app_launch(1));
		
		Uart_Send_Byte(Uart_Get_Char());
		Uart_Printf("]\n");	
			





		Timer1_Delay(200);	
	}
}

//========================================

int app_init(int cmd) {
		
}
int app_deinit(int state) {
	
}

int app_launch(int mode) {
	//mode 1 : nomal mode
	//mode 2 : debug mode
	int num=1;
	
	char *str[21];
	
	int acc_cnt;
	
	

	while (num)
	{
		num = dispmenu();
		switch (num) {
		
		case 1:loginout();
			break;
		
		case 2:accprint();
			break;
		
		case 3:banktrns();
			break;
			
		case 4:withdraw();
			break;
		
		case 5:depositm();
			break;
						
		case 6:checkdps();
			break;

		case 7:calprint();
			break;
		
		case 8://levamesg(str);
			break;
		
		case 9:gamemode();
			break;
			
		
		default:
			ENDMSG_RUTIN	
			//exit(1);
			break;
		}
	}
    //PAUSE;
}
//=======================================


// 메뉴 출력 후 선택 번호 반환
int dispmenu(void)
{
	int num;
	MID_DBL_LINE 
	puts("\n===[ Welcome DHKim BANK!! ]===\n");
	puts("===[ Select your menu ]=========\n");
	puts(">> 1. Login / Logout\n");
	puts(">> 2. account info print\n");
	puts(">> 3. Bank Transfer\n");
	puts(">> 4. withdraw money\n");
	puts(">> 5. Deposit money\n");
	puts(">> 6. Deposit Check\n");
	puts(">> 7. Calender\n");
	puts(">> 8. Leave a Message\n");
	puts("   >> 81. My Message List\n");
	puts(">> 9. Program Vision\n");
	puts(">> 0. Exit\n");
	MID_DBL_LINE 
	printf(">>insert your menu number : \n"); 
	//puts("\n");
	return num;
}

int loginout (void) {
	int idok=0, pwok=0;
	char buf[MAXLEN];
	char ch;

	
	if( loginflag == 1) {
		puts("already admin login");
		printf("do you want Logout? (Y/N)");
	//	scanf("%c",&ch);
		if(ch == 'Y' || ch == 'y') {
			puts("outout! bye bye");
			WAITKEY_RUTIN
		}
		else {
			puts("cancled");
			WAITKEY_RUTIN
		}
	}
	

	
	puts("======admin ID / Passward Check=====");
	puts("defulat : admin/admin") ;
	printf("ID : ");
	//scanf("%s",&buf);
	
		if( 0 == strcmp(ID_admin,buf) ) {
			printf("PW : ");
			//scanf("%s",&buf);
			if( 0 == strcmp(PW_admin,buf) ) {
				MID_DBL_LINE 
				MID_DBL_LINE 
				loginflag=1;	
				WAIT_RUTIN
				puts("administor loginned!! WEEELLLCOME");
				WAITKEY_RUTIN
			}
		}
		else {
			puts("ID is wrong!");
			WAITKEY_RUTIN
			return;
		}
	
		
	return 0;
}

int accprint (void) {
	int i=0;
	if(loginflag) {
		for(i=0;i<5;i++) {//
			puts("구조체포인터를 넘겨받아 계좌정보를 출력");
			//print_accinfo(/*acc 구조체 주소*/);
			
		}
		MID_DBL_LINE
		puts("end of the Lisht") ;
		MID_DBL_LINE
		WAITKEY_RUTIN
		//당신의 잔액, 송금계좌, 금액 
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}

	return 0;
	
	
}

int banktrns (void) {
	if(loginflag) {
		//당신의 잔액, 송금계좌, 금액 
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}
	return 0;
}

int withdraw (void) {	
	if(loginflag) {
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}
	return 0;
}

int depositm (void) {
	if(loginflag) {
		printf("ID : cur_user.ID");//기능 추가구현 필요 
		printf("deposit : making...");
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}
	return 0;
}

int checkdps (void) {
		if(loginflag) {
		printf("ID : USER");//기능 추가구현 필요 
		//printf("deposit : %d",9999999);
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}
	return 0;
}

int calprint (void) {
	char buf;
	printf("continue to any key");
	return 0;
}



int gamemode (void) {
	puts("\n\n");
	puts("======Comming soon======");
	puts("Meeting reservation");
	puts("FILE I/O-> Save : data.csv ");
	puts("Calculator");
	puts("Double Linked List custmer ");
	puts("");
	printf("continue to any key");
	return 0;
}


int print_accinfo(struct account myacc) {
	printf("User name : $s\n");
	printf("User deposit : %d\n");
	printf("User trust : %d\n");
	printf("User Identiti : ");
	printf("User password : ");
	
	return 0;
	
}


//==================================================
//re-used func



//BSP Func
//========================================
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

