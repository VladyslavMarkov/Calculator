#include "lib.h"

long int calculate(char expresion[])
{	
	char expresion_group[255];
	char new_str[255];
	long int result;
	
	for(int index_element = 0; expresion[index_element] != '\0';index_element++) {
		
		for(unsigned int i = 0; expresion[i] != '\0'; i++) {
			
			if(expresion[i] == '^') {
				double a;
				double b;
				double res;
				unsigned long int number_after = 0;
				unsigned long int number_befor = 0;
				
				for(unsigned long int j = i + 1; '0' <= expresion[j] && expresion[j] <= '9'; j++) 
					number_after++;
					
					
				for(unsigned long int j = i - 1; '0' <= expresion[j] && expresion[j] <= '9'; j--)
					number_befor++;
				
				a = atoi((expresion + i - number_befor));
				b = atoi((expresion + i + 1));
				res = pow(a,b);
				
				strncpy(expresion_group, expresion, i-number_befor);
				sprintf(expresion_group + i - number_befor,"%f",res);
				strcpy(new_str, expresion_group);
				printf("%s\n",new_str);
				strncpy(expresion_group, expresion + i + number_after, 255 - i);
				strcat(new_str, expresion_group);
				strcpy(expresion, new_str);
				
				i = 0;
			}
		}
		
		
		
		for(unsigned int i = 0; expresion[i] != '\0'; i++) {
			
			if(expresion[i] == '*' || expresion[i] == '/') {
				int a;
				int b;
				int res;
				unsigned long int number_after = 0;
				unsigned long int number_befor = 0;
				
				for(unsigned long int j = i + 1; '0' <= expresion[j] && expresion[j] <= '9'; j++) 
					number_after++;
					
					
				for(unsigned long int j = i - 1; '0' <= expresion[j] && expresion[j] <= '9'; j--)
					number_befor++;
				
					
				a = atoi((expresion + i - number_befor));
				b = atoi((expresion + i + 1));
				if(expresion[i] == '*')
					res = a * b;
				else
					res = a / b;
				//printf("%ld\n", a);
				
				strncpy(expresion_group, expresion, i-number_befor);
				sprintf(expresion_group + i - number_befor,"%d",res);
				strcpy(new_str, expresion_group);
				strncpy(expresion_group, expresion + i + number_after + 1, 255 - i);
				strcat(new_str, expresion_group);
				strcpy(expresion, new_str);
				
				i = 0;
			}
		}
		
		for(unsigned long int i = 0; expresion[i] != '\0'; i++) {
			
			if(expresion[i] == '%') {
				int a;
				 int b;
				 int res;
				unsigned long int number_after = 0;
				unsigned long int number_befor = 0;
				
				for(unsigned long int j = i + 1; '0' <= expresion[j] && expresion[j] <= '9'; j++) 
					number_after++;
					
					
				for(unsigned long int j = i - 1; '0' <= expresion[j] && expresion[j] <= '9'; j--)
					number_befor++;
				
				a = atoi((expresion + i - number_befor));
				b = atoi((expresion + i + 1));
				
				res = a % b;
				
				strncpy(expresion_group, expresion, i-number_befor);
				sprintf(expresion_group + i - number_befor,"%d",res);
				strcpy(new_str, expresion_group);
				strncpy(expresion_group, expresion + i + number_after, 255 - i);
				strcat(new_str, expresion_group);
				strcpy(expresion, new_str);
				
				i = 0;
			}
			
		}
		
		
		printf("%s\n", expresion);
		for(unsigned long int i = 1; expresion[i] != '\0'; i++) {
			
			if(expresion[i] == '+' || expresion[i] == '-') {
				 int a;
				 int b;
				 int res;
				unsigned long int number_after = 0;
				unsigned long int number_befor = 0;
				
				for(unsigned long int j = i + 1; '0' <= expresion[j] && expresion[j] <= '9'; j++) 
					number_after++;
					
					
				for(unsigned  long int j = i - 1; '0' <= expresion[j] && expresion[j] <= '9'; j--)
					number_befor++;
				
				a = atoi((expresion + i - number_befor));
				b = atoi((expresion + i + 1));
				if(expresion[i] == '+')
					res = a + b;
				else
					res = a - b;
					
				sprintf(expresion_group + i - number_befor,"%d",res);
				strcpy(new_str, expresion_group);
				strncpy(expresion_group, expresion + i + number_after +1, 255 - i - number_after +1);
				strcat(new_str, expresion_group);
				strcpy(expresion, new_str);
				
				i = 0;
			}
		}
		
	}	
	
	result = atoi(expresion);
	
	return result;
}
