//Complext declarations in C
#include<stdio.h>

double i;

int main()
{
	
  (char)(float)(int)i;
	printf("%d\n",sizeof(i));//prints size of a double
	
	
	//but here it prints the size of a long double as i becomes a long double, and sizeof() operator has right to left associativity
	//so left most is evaluated at last i.e long double
 	printf("%d",sizeof((long double)(double)(char)(int)(float)i)); //prints 16
 	
 	
 	//program 2
 	
 	
	
		
}
