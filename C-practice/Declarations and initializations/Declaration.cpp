#include<stdio.h>
#include<conio.h>



int main()
{
	extern int a;//declaration for a 
	printf("%d",a); //prints 20
	return 0;
}

int a  = 20;//definition of a, mamory and value initialized and allocated
