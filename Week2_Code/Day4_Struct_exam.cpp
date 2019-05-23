#include <stdlib.h>
#include <string.h>


typedef struct person_t
{
    char *name;
    int age;    
} Person;


void Normal_Copy_Test(void)
{
	Person src = { NULL, 20 };
    Person dest;
	
    src.name = (char *)malloc(4);
    strcpy(src.name, "JSH");
    
    dest = src; // (X)
    strcpy(dest.name, "AAA"); // (X)

    printf(q"Src[%s], Dest[%s] \n",
        src.(char *)name, dest.(char *)name);
}

void Deep_Copy_Test(void)
{
	Person dest, src = { NULL, 20 };
    
    src.name = malloc(4);
    strcpy(src.name, "JSH");
    
    dest.name = malloc(strlen(src.name) + 1);
    strcpy(dest.name, src.name);
    dest.age = src.age;

    strcpy(dest.name, "AAA");
  
    Uart_Printf("Src[%s], Dest[%s] \n",
        src.name, dest.name);
}

int Main(void)
{
    Uart_Printf("========== Normal_Copy_Test ========== \n");
	Normal_Copy_Test();
	
	
	Uart_Printf("\n\n\n========== Deep_Copy_Test ========== \n");
	Deep_Copy_Test();
	return 0;
}
