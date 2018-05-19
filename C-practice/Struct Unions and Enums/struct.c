#include<stdio.h>
#include<conio.h>

#pragma  pack(1)

//pragma directive indicated that structure should be aligned at address which are multiples of 1 , so all data types begin
//at next immediate address
struct st{
	
	double d;
	float f;// 8 bytes padded
	int data;//4 bytes
	char c;// 4 bytes, 3 bytes padded after 1 byte of c
}s;

int main()
{

	printf("%d",sizeof(s));
	return 0;
}
