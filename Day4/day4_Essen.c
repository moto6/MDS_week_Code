#include <stdio.h>

//=================================================
/*

int main (void)
{
	char str1[20],str2[20];
	printf("insert 1st string :");
	scanf("%s",str1);
	printf("insert 2nd string :");
	scanf("%s",str2);
	
	printf("Before swap : %s %s\n",str1,str2);
	swap(str1,str2);
	printf("After swap : %s %s\n",str1,str2);
	
	
	
	
	return 0;
}


void swap(char *str1,char *str2)
{
	int i=0;
	char buf;
	int flag = 0;
	while( flag!=2)
	{
		//puts("run ");
		buf = str1[i];
		str1[i] = str2[i];
		str2[i] = buf;
		if(str1[i]=='\0') {
			flag++;
		}
		if(str2[i]=='\0') {
			flag++;
		}
		i++;
	}
	return;
}
*/
//=================================================
///*//

void print_str(char **pps, int cnt);

int main (void) {
	char *ptr_ary[] = {"eagle", "tiger", "lion", "sqerrual"};
	int count;
	
	count = sizeof(ptr_ary)/sizeof(ptr_ary[0]);
	print_str(ptr_ary,count);
	
	
	return 0;
}

void print_str(char **pps, int cnt) {
	int i;
	for(i=0;i<cnt;i++) {
		printf("%s\n",pps[i]);
	}
}
