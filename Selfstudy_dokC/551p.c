#include <stdio.h>

int main(void) {
	FILE *fp = NULL;
	fp = fopen("Test.txt","w");
	if( fp == NULL ) {
		puts("ERROR : Failed to open file!");
		return 0;
	}
	
	fclose(fp);
}
