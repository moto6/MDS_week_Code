#include <stdio.h>
int main(void)
{
	char ch;
	char Max=0;
	int cnt=0;
	while(1) {
	
		puts("Insert Word and Enter!");
		
		ch = getch();
		if(ch == -1) {
			break;
		}
		else {
			if(ch == 10) {
				if(Max<cnt) {
					Max=cnt;
				}
				else {
					cnt=0;
				}
			}
			else {
				cnt++;
			}	
		}
		
	}
	printf("maxxxxium length word length : %d",Max);
	return 0;
}
