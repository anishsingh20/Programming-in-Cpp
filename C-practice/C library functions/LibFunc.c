#include<stdio.h>
#include<conio.h>


//Important C library functions

int main()
{
	int i;
	char *s = "heyIam\0 Anish"; 


	
	printf("%d\n", *(s++));//first prins the ascii value of the first element ie h	
	printf("%d", *s);//now prints the ascii value of e, i.e second element in char sequence
	return 0;
	
}
