#include <stdio.h>
#include<stdlib.h>
 
int main()
{
	int *p;
	p = (int*)malloc(20);
	
	printf("%u\n",p);//prints some add a
	free(p);
	printf("%u",p);//prints the same address
}
 

