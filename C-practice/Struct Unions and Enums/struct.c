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


union u {
	
	int a;
	int b,c;
};

int main()
{
	union u ut;
	
	ut.a = 10;
	ut.b = 20;
	ut.c = 1002;
	
	printf("%d ", ut.a);

//	printf("%d",sizeof(s));

//	printf("%d",sizeof(bit));
	return 0;
}
