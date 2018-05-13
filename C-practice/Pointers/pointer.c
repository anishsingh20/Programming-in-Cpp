#include<stdio.h>
#include<conio.h>


int main()
{
	int a[3][4] = {2,3,4};
	
	printf("%u %u %u",a[0] + 1, *(a[0] + 2 ) , *(*(a + 0) +2 ) ) ;
	//prints address of 2, 3 , 4 
	return 0;
}
