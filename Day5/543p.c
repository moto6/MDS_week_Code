#include <stdio.h>

struct score {
	int kor;
	int eng;
	int mat;
	
};

int main(void) {
	struct score yuni = {90,80,70};
	struct score *ps;
	ps=&yuni;
	
	printf("국어 : %d \n", (*ps).kor);
	printf("영어 : %d \n", ps->eng);
	printf("수학 : %d \n", ps->mat);
}

