#include <stdio.h>
#include <string.h>

int main(void){
	char szBuffer[20] = {"Hellow world!"};
	char szNewBuffer[12] = {0};
	
	memcpy(szNewBuffer, szBuffer, 4);
	puts(szNewBuffer);
	
	memcpy(szNewBuffer, szBuffer, 6);
	puts(szNewBuffer);
	
	memcpy(szNewBuffer, szBuffer, sizeof(szBuffer));
	puts(szNewBuffer);
	
	return 0;
	
	
	
	

}
