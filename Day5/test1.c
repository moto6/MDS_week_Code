/*# if 0
#define POS 3
int main(void) {
	char *string[POS + ~0] = { "apple","banana"};
	
	char *ptr = string [1+ ~0];
	printf("%c",*++ptr);
	return 0;
}

# endif
========================================================
#define LGF160 0
#define LGF180 1
#define LGF160 2

#define MODLE_TYPE LGF160

#if (MODEL_TYPE == LGF180)
#define NAME "G"
 
#elif (MODEL_TYPE == LGF200)
#define NAME "Vu2"
 
#elif (MODEL_TYPE == LGF160)
#error "LTE2"

#endif

void main (void)
{
	printf("%s\n",NAME);
	
}
 
 ===========================================================
int main(void) {
	char[][3][2] = {5,6,7,8,9,10,11,12,13,14,15,16};
	
	
	
}



*/


int main (void){

	unsigned int var = 77;
	unsigned int arr[3] = {1,3,5};
	
	puts("\n\nbefore");
	printf("arr[3] = %d \n",arr[3]);
	printf("var = %d \n",var) ;
	
	puts("\n\nafter");
	arr[3] = arr[0];
	printf("arr[3] = %d \n",arr[3]);
	printf("var = %d \n",var) ;
	
	return 0;
}
