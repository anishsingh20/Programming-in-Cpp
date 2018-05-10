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
	
	n--;
	reverse(n);
	//but when reverse(--n);	
 } 

int main()
{
	
	printf("%u",main); //address of main() is printed
	reverse(10);
	return 0;
}
