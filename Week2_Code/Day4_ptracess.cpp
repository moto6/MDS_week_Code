# include <stdio.h>

/*
# pragma pack(1)
//# include <stdinit.h>
# include <stdio.h>

typedef struct _byte_2_t
{
	int d1, d2;
	
} Byte_2_t;

int main(void)
{
	
	int arr[3][2];
		
	Byte_2_t (*ptr)[4] = arr;
	*(int *)ptr[1] = 0xa5a5a5a5;
	printf("%x \n",arr[1][0])
	
	return 0;
}

int main(void) {
	int arr[3] = {2,4,6};
	int *ptr1 = arr;
	int (*ptr2)[3];// = arr;
	
	if(ptr1 == ptr2) {
		printf("Same val, diff type");
	} 
	if((ptr1 +1) ==(ptr2+1) ){
		printf("Non Excu \n")
		
	}
}


//#include "../lib2450/Uart.h"

*/


// &arr을 넘겨도 arr(&arr[0])이 들어와서 정상적으로 동작함
void To_Lower(char *str)
{
    char c;1

    while( c = *str )
    {
        if( 65 <= c && c <= 90 || 
		     97 <= c && c <= 122 )
        {
            *str  |=  1<<5;
        }

        str++;
    }
}

int Main()
{
    char arr[] = "TIME FLIES LIKE AN ARROW";

	
    To_Lower( arr ); // warning

	
	// 정확히는 &arr이 아니라 arr을 인자로 전달해야한다
    printf("%s \n", arr); // warning
    
    return 0;
}
