#include<stdio.h>
#include<conio.h>


int main()
{
	//Program 1
//	int a[3][4] = {2,3,4};
//	
//	printf("%u %u %u",a[0] + 1, *(a[0] + 1 ) , *(*(a + 0) + 2 ) ) ;
	//prints address of 2, 3 , 4 
	
	
	//program 2
	
	int a[3] = {3,5,6};
	
	char *ptrc = (char*)a;
	
	printf("%d ",*ptrc);
	printf("%d \n",*ptrc + 1); //prints 4, value incremented by 1
	
	ptrc = ptrc + 1; // or *ptr++; //address incremented to next byte
	printf("%d ", *ptrc); //value is 0
	
	return 0;
	
	
}
