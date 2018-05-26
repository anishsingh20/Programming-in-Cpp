#include <stdio.h>
#include<stdlib.h>
 
int main()
{
	int *p;
	p = (int*)malloc(20);
	
	printf("%u\n",p);
	free(p);
	printf("%u",p);//prints the same address
}
 

