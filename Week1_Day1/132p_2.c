#include <stdio.h>
#include <string.h>
int main (void) {
	
	int Qunit[5] = {5000,1000,500,100,50};//else all by 10
	int item1 = 0, item2 = 0, item3 = 0;
	int sum = 0,changes = 0;
	int buffer = 0;
	unsigned int i = 0;
	
	printf("Insert 3 Price ");
	scanf("%d %d %d", &item1 , &item2 , &item3);
	puts("");
	sum = item1 + item2 + item3;
	changes = 10000-sum;
	
	for (i=0 ; i <= 4 ; i++ ) {
		if ( changes/Qunit[i] ) {
			buffer = changes/Qunit[i];
			printf("%d Won : %d [ea]\n", Qunit[i],buffer);
			changes = changes-Qunit[i]*buffer;
			
		}
	}
	printf("10 Won : %d [ea]\n", changes/10);
	
	
	
	return 0;
}
