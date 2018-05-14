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
	
	
//	float a=10.5576;
//	float *j;
//	
//	void *k;
//	
//	k = &a;
//	
//	j = k; //usually we require to typecast a void pointer when assigning values to and from a void pointer
	//conversions are done automatically in gcc compilers

//	printf("%lf ", *j );
	

	//program 4
	
//	int a[] = {10,20,30,40,50};
//	
//	char *p  = (char*)a;//p points to the base address(address of 1st byte) of a i.e points to 10
//	
//	p = (p + 16); //p now points to 50, as c char is 1 byte long
//
//	int *p1 = a;
//	
//	printf("%d %d",*p,*(p1+4)); //both will point to 50
	
	
	//program 5
		 
//	printf("%c",1["anish"]); //would print i
	
	
	//program 6
	
	char *ch = "anish";
	
	int j=65;
	
	void *pt ;
	
	pt = ch;
	
	printf("%c ",  *((char*)pt+3)  + 2); //prints u
	
	pt = &j;
	
	printf("%c", *( (int*)pt) + 1 );//prints B
	
	
	
	
	
	//program 7
		
	
	

	
	
	
	
	
	return 0;
	
	
}
