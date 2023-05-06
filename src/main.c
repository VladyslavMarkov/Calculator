#include "lib.h"


int main(void)
{
	long int res;
	char   expresion[255];
	char *end;
	
	scanf("%254[^\n]", expresion);

	res = calculate(expresion);
	
	printf("Вираження дорівнює:%ld",res);
	
	return 0;
}
