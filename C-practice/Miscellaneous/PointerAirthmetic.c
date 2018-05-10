#include<stdio.h>
#include<conio.h>


void fun(char**);

int main()
{
	char *arr[]  = {"ab","cd","ef","gh"};
	fun(arr);
	return 0;
}

void fun(char **c)
{
	char *p;
	
	p = (c += sizeof(int))[-1];
	
	printf("%s",p);
}
