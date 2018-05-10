#include<stdio.h>
#include<conio.h>


int fun(int(*)());

int main()
{
  
  fun(main);
  printf("Hi\n");
  return 0;
 	
}

//function takes an integer pointer as an argument
int fun(int(*p)())
{
	printf("Hello");
	return 0;
}
