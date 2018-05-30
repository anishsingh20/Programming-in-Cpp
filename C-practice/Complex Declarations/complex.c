//Complext declarations in C
#include<stdio.h>

double i;
double j;
int main()
{
	
  (char)(float)(int)i;
	printf("%d",sizeof(i));//prints size of a double
	
	
	printf("%d",sizeof((long double)(double)(char)(int)(float)i));
	
}
