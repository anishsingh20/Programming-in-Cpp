#include<stdio.h>
#include<conio.h>


int reverse(int n)
{
//	if( n > 0)
//	{
//		printf("%d\n",n);
//		
//		reverse(--n);
//	}
//	

//method2

	if( n < 1)
		return 0;
	else
		printf("%d\n",n);
	
	reverse(--n);	
 } 

int main()
{
	
	printf("%u",main); //address of main() is printed
	
	return 0;
}
