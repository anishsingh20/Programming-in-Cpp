#include<stdio.h>
#include<conio.h>


void fun(char**);

int main()
{
	return 0;
}

void fun(char c**)
{
	char *p;
	
	p = (c += sizeof(int))[-1];
	
	printf("%s",p);
}
