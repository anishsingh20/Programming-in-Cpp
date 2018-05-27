
#include <stdio.h>
#include<stdarg.h>
#include<stdlib.h>


 void fun(int num,...)
{
	va_list ptr;
        va_start(ptr,num);
        int c = va_arg(ptr,int);
        c = va_arg(ptr,int);
	printf("%d",c);
	
	
	}
 
int main()
{
	
	fun(20,'A','B','C');
	
	return 0;
	
 }

	
