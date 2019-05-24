/*
 * packing.c
 */

int pack(int val);
int Unpack(int val);

int bi2hi (void);
int hi2bi (void);

unsigned int B_data=0;

unsigned int Id=0, Type=0;
char Mfid=0; 


int main(void)
{
	int buf=0;
	do {
		
		puts("Select your Menu");
		puts("1.Packing");
		puts("2.UnPacking");
		scanf("%d",&buf);
		
		if (--buf) {
			pack(buf);
		} 
		else {
			Unpack(buf);
		}
	
	
		
	}while(1);
	
	return 0;
}




int pack(int val)
{
	puts("Worker info insert");
	printf("ID(int) : ");
	scanf("%d",&Id);
	
	printf("Type(int) : ");
	scanf("%d",&Type);
	
	printf("M or F ? : ");
	scanf("%c",&Mfid)

	return 0	
}


int Unpack(int val)
{
	
	return 0
}


int bi2hi (void)
{
	Id=0x0;
	Type=0x0;
	Mfid=0x0;
	
	Id		= 0x0000&B_data;
	Type	= 0x000&B_data;
	Mfid 	= 0x0800&B_data;

	B_data=;

	return 0
}


int hi2bi (void)
{
	B_data=0;


	Id=;
	Type=;
	Mfid=; 
	return 0
}
