#include<stdio.h>
#include<conio.h>

//#pragma  pack(1)

//pragma directive indicated that structure should be aligned at address which are multiples of 1 , so all data types begin
//at next immediate address
struct st{
	
	double d;
	float f;// 8 bytes padded
	int data;//4 bytes
	char c;// 4 bytes, 3 bytes padded after 1 byte of c
	float *fp; // 8bytes
}s;


//struct bits{
//	
//	long int a : 1;
//}bit;


//union u {
//	
//	double d;
//	char a;
//	
//} ut;


 
 union a {
 
 	int i ;
  	char ch[20];
  	int a : 4;
 };
 

int main()
{

//	enum e {MON=-10,TUE,WED=10,THU,FRI,SAT,SUN } val;
//	printf("%d %d %d %d %d %d %d\n",MON,TUE,WED,THU,FRI,SAT,SUN);
//	//prints -10 -9 10 11 12 13 14
//	printf("%d\n",sizeof(val));
//	
//	printf("%d",sizeof(ut));

//	union u ut;
//	
//	ut.a = 10;
//	ut.b = 20;
//	ut.c = 1002;
	
//	printf("%d ", ut.a);

//	printf("%d",sizeof(s));

//	printf("%d",sizeof(bit));


	union a b;
	printf("%d",sizeof(b));
	
	

	return 0;
}
