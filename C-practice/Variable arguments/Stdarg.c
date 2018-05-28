
#include <stdio.h>
#include<stdarg.h>
#include<stdlib.h>

// best example of a variable arguments function is int printf(char const *,...)
 void fun(int num,...)
{
	va_list ptr;//vah_list is an array which holds the information of the arg list needed by va_arg
        va_start(ptr,num);
        int c = va_arg(ptr,int);
        c = va_arg(ptr,int);
	  //va_arg used to extract an argument from the args list and 
  //va_arg used to advance to next argument
  //
	printf("%d",c);
	
	
	}

 //when dealong with var no of arguments char and unsigned int is promoted to int 
//and 
int main()
{
	
	fun(20,'A','B','C');
	
	
	
	//prints 66- ascii value of c
	return 0;
	
 }

	
