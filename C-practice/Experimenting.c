#include<stdio.h>
#include<conio.h>
#include<math.h>

//union u {
//	
//	int a;
//	char c;
//	double d;
//}; //size of union prints the maximum size of the data member inside it
//
//struct s{
//	int b;
//	char d;
//	double f;
//};
//
int main()
{


char c[] = "";

printf("%d",sizeof(c)); //size is 2 bytes-1 for char and 1 for NUll character

float f = 2.650098;

printf("%.4f",f);
}


//union u u1;
//struct s s1;
//
//printf("%d",sizeof(u1)); //prints 8 i.e max size is of double in union
//printf("\n"); 
//
//printf("%d",sizeof(s1));//prints 16
//printf("\n"); 
//
//
//int arr[10] = {1,2,3,4,5,6,7};
//
//for(int i=0;i<sizeof(arr)/sizeof(arr[1]);i++)
//{
//	printf("%d ",arr[i]); //prints 0 for the remaining empty values in array
//}


//int *ptr = &(arr+1)[3]; //points to 5 
//
//
//int **ptr2 = &ptr; //points to the complete array =
//
//printf("\n");
//printf("%d",*ptr);
//printf("\n");
//printf("%d",*(*ptr2-1)); //prints 4

//	int i =5;
//	
//	 i = i + ++i;
//	 
//	 printf("%d",i);



