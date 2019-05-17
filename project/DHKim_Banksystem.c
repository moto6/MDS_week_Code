#define ENDMSG_RUTIN do{puts("Program terminated!!\n\n");}while(0);
#define WAITKEY_RUTIN do{printf("\ncontinue to press any key");fflush(stdin);getc(stdin);}while(0);
#define MID_DBL_LINE do{puts("=====================================================");}while(0);
#define MAXLEN 100 //max len of buf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void disp_calendar(int year, int month);
int get_weekday(int year, int month);
int get_weekday(int year, int month);
int leap_check(int year);
int app_Launcher(int mode);
//int print_accinfo(struct account myacc);//


int dispmenu(void);
int loginout(void);
int accprint(void);
int banktrns(void);
int withdraw(void);
int depositm(void);
int checkdps(void);
int calprint(void);
int levamesg(void);
int gamemode(void);



struct account {
	char *Name;
	
	int deposit;
	int trust;
	
	char ID[MAXLEN];
	char PW[MAXLEN];
	
};
struct account cur_user;

int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int loginflag = 0;
char ID_admin[] = "admin";
char PW_admin[] = "admin";
char *msgfreq[10] ;


int main(void)
{
	
	return app_Launcher(1);
}


int app_Launcher(int mode) {
	//mode 1 : nomal mode
	//mode 2 : debug mode
	int num=1;

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
		
		case 8:levamesg();
			break;
		
		case 9:gamemode();
			break;
			
		default:
			ENDMSG_RUTIN	
			exit(1);
			break;
		}
	}
    //PAUSE;
}

// 메뉴 출력 후 선택 번호 반환
int dispmenu(void)
{
	int num;
	MID_DBL_LINE 
	puts("\n===[ Welcome DHKim BANK!! ]===\n");
	puts("===[ Select your menu ]=========");
	puts(">> 1. Login / Logout");
	puts(">> 2. account info print");
	puts(">> 3. Bank Transfer");
	puts(">> 4. withdraw money");
	puts(">> 5. Deposit money");
	puts(">> 6. Deposit Check");
	puts(">> 7. Calender");
	puts(">> 8. Leave a Message");
	puts(">> 9. Program Vision");
	puts(">> 0. Exit");
	MID_DBL_LINE 
	printf(">>insert your menu number : "); 
	scanf("%d", &num);
	//puts("\n");
	return num;
}

int loginout (void) {
	int idok=0, pwok=0;
	char buf[MAXLEN];
	char ch;
	
	puts("======admin ID / Passward Check=====");
	printf("ID : ");
	scanf("%s",&buf);
	if( loginflag == 0 )
		if( 0 == strcmp(ID_admin,buf) ) {
			printf("PW : ");
			scanf("%s",&buf);
			if( 0 == strcmp(PW_admin,buf) ) {
				MID_DBL_LINE 
				puts("administor loginned!! WEEEELLLLLCOME");
				MID_DBL_LINE 
				loginflag=1;	
				WAITKEY_RUTIN
			}
		}
		else {
			puts("ID is wrong!");
			WAITKEY_RUTIN
			return;
		}
	else if( loginflag == 1) {
		puts("already admin login");
		printf("do you want Logout? (Y/N)");
		scanf("%c",&ch);
		if(ch == 'Y' || ch == 'y') {
			puts("outout! bye bye");
			WAITKEY_RUTIN
		}
		else {
			puts("cancled");
			WAITKEY_RUTIN
		}
	}
	
		
	
}

int accprint (void) {
	int i=0;
	
	for(i=0;i<10;i++) {//
		puts("구조체포인터를 넘겨받아 계좌정보를 출력하는 함수 구현");
			//print_accinfo(/*acc 구조체 주소*/);
			
	}
	MID_DBL_LINE
	puts("\nend of the Lisht") ;
	MID_DBL_LINE
	WAITKEY_RUTIN
}

int banktrns (void) {
	if(loginflag) {
		//당신의 잔액, 송금계좌, 금액 
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}

}

int withdraw (void) {
	
	if(loginflag) {
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}

}

int depositm (void) {
	if(loginflag) {
		printf("ID : %s",cur_user.ID);//기능 추가구현 필요 
		printf("deposit : %d",9999999);
	}
	else {
		puts("Login First!");
		WAITKEY_RUTIN
	}
}

int checkdps (void) {
	
}

int calprint (void) {
	char buf;
	disp_calendar(2019, 5);
	printf("continue to any key");
	fflush(stdin);
	getc(stdin);
}

int levamesg (void) {
	
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
	fflush(stdin);
	getc(stdin);
}


int print_accinfo(struct account myacc) {
	printf("User name : $s\n", myacc.Name);
	printf("User deposit : %d\n", myacc.deposit);
	printf("User trust : %d\n", myacc.trust);
	printf("User Identiti : ", myacc.ID);
	printf("User password : ", myacc.PW);
	
	return 0;
	
}


//==================================================
//re-used func
int leap_check(int year)
{
	if(year%4!=0) return 0;
	else if(year%100!=0) return 1;
	else if(year%400==0) return 1;
	else return 0;
}

// 출력할 달의 일수 계산

int get_days(int year, int month)
{
	int days =0;
	days=mdays[month-1];
	if(leap_check(year) && month==2) ++days;  // 윤년이고 2월이면 29일로 계산
	return days;
}

// 요일 구하는 함수
int get_weekday(int year, int month)
{
	int i, tot=0;

	// 1년부터 year-1년도까지의 총 일수 누적
	for(i=1; i<year; i++){
		if(leap_check(i)) tot+=366;
		else tot+=365;
	}

	// 1월부터 month-1월 까지의 총 일수 누적
	for(i=0; i<month-1; i++){
		tot+=mdays[i];
	}

	// 윤년이고 달이 3월 이상이면 2월이 29일이므로 하루를 더한다.
	if(leap_check(year) && month>=3) tot++;

	// 당월의 1일을 누적
	tot++;

	return tot%7;  // 요일 위치 반환
}

// 달력 출력
void disp_calendar(int year, int month)
{
	int i=0;
	int cnt=0; 			 // 탭을 포함해 한 줄에 7일을 출력하기 위한 변수
	int start;                // 1일이 출력될 시작 요일 위치
	int days;                // 출력 달의 마지막 날

	start = get_weekday(year, month);                                          // 1일이 출력될 시작 요일 위치 계산
	days =get_days(year, month);

	printf("\n============< %4d. %2d >============\n\n", year, month);
	printf("------------------------------------\n");
	printf("%5s%5s%5s%5s%5s%5s%5s\n", "Sun","Mon","Tue","Wed","Thu","Fri","Sat");
	printf("------------------------------------\n");

	// 앞에서부터 요일 위치까지 공백 출력
	for(i=0; i<start; i++){
		printf("%5c", ' ');
		cnt++;  // 공백도 한 줄의 일부로 카운트한다.
	}

	// 날짜 출력 (1 ~ 그 달의 출력할 일 수)
	for(i=1; i<=days; i++){
		printf("%5d", i);
		cnt++;  // 출력할 때마다 카운트
		if(cnt%7==0) printf("\n");  // 한 줄에 7일이 출력되면 줄 바꾼다.
	}
	printf("\n");
	printf("------------------------------------\n");

}



/*

int get_checkRange(char* what, int min, int max) {
	int input = 0;
	printf("> %s(%d-%d) : ", what, min, max); 
	scanf("%d", &input);
	if ((input < min) || (input > max))     // 허용 범위의 숫자가 아니면 반환
	{
		printf("@ 유효한 번호가 아닙니다!\n");
		return -1;
	}
	return input;
}

void deleteFromIDList(int dno) {
	int i=0;

	for (i = dno; i < (e_cnt - 1); i++)
	{
		e_num[i] = e_num[i + 1];
		e_pwd[i] = e_pwd[i + 1];
	}
	e_cnt--;										// 등록된 사번 수 감소
}

void insertToIDList(int id, int pwd) {
	e_num[e_cnt] = id;
	e_pwd[e_cnt] = pwd;
	e_cnt++;                                   // 등록된 사번 수 증가
	printf("# %d번이 등록되었습니다!\n", id);
}

void printIDList(){
	int i=0;

	printf("\n>> 현재 등록된 사번(비밀번호) : ");
	for (i = 0; i < e_cnt; i++)
	{
		printf("%5d(%d)", e_num[i], e_pwd[i]);
	}
	printf("\n\n");
}


void deleteID(int dno) {
	char yn = 0;

	printf("@ 이미 등록되었습니다!\n");
	printf("@ 삭제 하시겠습니까(Y/N)?"); 

	fflush(stdin);
	scanf("%c", &yn);
	if ((yn == 'Y') || (yn == 'y'))
	{
		deleteFromIDList(dno);
		printf("@ %d번이 삭제 되었습니다!\n", e_num[dno]);
		printIDList();
	}
	printf("@ 취소 되었습니다!\n");
}

void insertID(int id){
	int pwd = 0;
	int cnt =  sizeof(e_num) / sizeof(e_num[0]);    	// 최대 등록인원 수 계산
	if (e_cnt == cnt)                          						// 등록인원 수가 최대 인원 수와 같으면 반환
	{
		printf("@ 등록 인원이 초과되었습니다!");
		return;
	}
	pwd = get_checkRange("비밀번호", 0, 9999);
	if (pwd == 0)  return;
	insertToIDList(id, pwd);
	printIDList();
}

// 사번 등록 / 삭제
void enroll_num(void)//1:등록or 삭제 함수 
{
	int num,pwd;                          			// 사번, 비밀번호 
	int index;                                  // 사번이 있는 배열의 위치
	int buf=0;
	int ch=0;

	if (login_num != 0)                   // 이미 로그인 된 상태면 반환
	{
		printf("@ 로그아웃 후 사용할 수 있습니다!\n");
		return;
	}
	else {
	
		printf("\n[ 사번 등록/삭제 ]\n\n");
	
	    // todo: 사번 등록 / 삭제 코드 작성
	    printf("> 사번(1-9999) :");
	    scanf("%d", &num);
		
		if(is_enroll_num(num)) {//사번이 기 등록여부 확인 등록되있으면 1 없으면 0 
				deleteID(1);
			//삭제여부를 묻는 코드까지 들어있음 scanf yn코드 다있음. 
			
		}
		else {
			printf("> 비밀번호(0-9999) :");
		    scanf("%d", &pwd);
		    printf("# %d번이 등록되었습니다!\n\n",num);
		    printf(" 현재 등록된 사번(비밀번호)  :  %d (%d)", num  , pwd);
		    insertToIDList(num,pwd);
		    printf("e_cnt : %d",e_cnt);
		}
	}
	return;
	
}

// 로그인 / 로그아웃
void login_out(void)
{
	int num, pwd;
	int index;
	
	if(login_num) {//로그인상태?
		puts("# 로그아웃 되었습니다!");
		login_num = 0;
		return; 
	}
	
	else {//로그인 안된 경우 들어오는 코드 
		 
		puts("\n\r[ 로그인 ] \n\r");
		printf("> 사번 :");
		scanf("%d",&num); 
		printf("> 비밀번호 :");
		scanf("%d",&pwd); 
		
		//is_vaild_accunt(num,pwd) 1=유효,0=무효
		if( is_vaild_accunt(num,pwd) ) {//전체 사번에서 입력된 번호를 확인 
			
		//todo 로그인 플래그  
			login_num = num;
			puts("# 로그인 되었습니다!");
		}
		else{
			puts(" 비밀번호가 틀렸습니다! ");
		}
	 
	}
	//로그인 체크 
	

}

// 등록된 번호인지 확인 등록되있으면 1 없으면 0 
int is_enroll_num(int num)
{
	int i;
	
	for(i=0;i<e_cnt;i++) {
		if(num==e_num[i]) {
			return 1;
		}
		else {
			
		} 
		
	}
	// todo: 등록된 번호인지 확인 코드 작성

	return 0;
}


//int is_vaild_accunt(int num,int pwd);//함수 추가함 1=유효,0=무효
int is_vaild_accunt(int num,int pwd)
{
	int i;
	puts("\r\nis_vaild_accunt\r\n");
	
	for(i=0 ; i<(e_cnt+2) ; i++) {
		if(e_num == num && e_pwd == pwd) {
			return 1;
		}
		else {}
		
	puts("\r\nis_vaild_accunt run loop\r\n");
	}
	
	
	return 0;
}

// 회의실 예약 등록
void input_schedule(void)
{
	int year, month, day;    // 스케줄을 입력할 날

	if (login_num == 0)      // 로그인되지 않았다면 반환
	{
		printf("@ 로그인 후 사용할 수 있습니다!\n");
		return;
	}

	printf("\n[ 회의실 예약 ]\n\n");

	printf("> 년, 월 입력 : ");
	scanf("%d%d", &year, &month);
	// todo: 회의실 예약 등록 코드 작성





	printf("@ 회의실 예약이 등록되었습니다!\n");

}

// 해당 날짜에 대한 스케줄 수 확인, 없는 경우 0 반환
int on_schedule(int year, int month, int day)
{
	int cnt = 0;
	int i;
    // todo: year, month, day에 해당하는 스케쥴 수 반환

	return cnt;
}

// 회의실 예약 상태 조회
void search_schedule(void)
{
	int year, month, day;    // 예약 상태를 검색할 날
	int cnt;                		    // 예약 건 수

	if (login_num == 0)      // 로그인되지 않았다면 반환
	{
		printf("@ 로그인 후 사용할 수 있습니다.\n");
		return;
	}

	printf("\n[ 회의실 예약 상태 조회 ]\n\n");

	printf("> 년, 월 입력 : ");
	scanf("%d%d", &year, &month);
	// todo: 회의실 예약 상태 확인 코드 작성





	printf("@ %d건의 예약된 스케줄이 있습니다!\n", cnt);

}


//=======< 여기서 부터는 달력 출력 관련 함수 >=================================================

// 윤년 검사 함수

*/
