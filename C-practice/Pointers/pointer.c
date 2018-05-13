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
	
//	int a[3] = {3,5,6};
//	
//	char *ptrc = (char*)a;
//	
//	printf("%d ",*ptrc);
//	printf("%d \n",*ptrc + 1); //prints 4, value incremented by 1
//	
//	ptrc = ptrc + 1; // or *ptr++; //address incremented to next byte
//	printf("%d \n", *ptrc); //value is 0
//	
//	int arr[5];
//	char arrc[5];	
//	printf("%d %d\n",sizeof(arr),sizeof(&arr)); //&arr is the size of pointer 8 bytes
//	
//	printf("%d %d\n",sizeof(arrc),sizeof(&arrc));//prints 5 and 8 as c char
//	
//	int b = 5;
//	printf("%d %d",sizeof(b),sizeof(&b)); // prints 4 and 8
	
	//program 3
	
	
	float a=10;
	float *j;
	
	void *k;
	
	k = &a;
	
	j = k; //usually we require to typecast a void pointer when assigning values to and from a void pointer
	//conversions are done automatically in gcc compilers
	
	printf("%f", *j);

	
	
	
	
	
	return 0;
	
	
}
