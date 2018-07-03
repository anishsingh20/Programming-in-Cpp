//Complext declarations in C
#include<stdio.h>

typedef void v;

typedef int i;

int main()
{
	
	v fun(i,i);
	
	fun(4,3);
	
	return 0;

	
}


//v fun(i a,i b)
//{
//	
//	 i s = 3; //here i is the type int
//	float i;//i is a variable here
//	printf("%d\n",sizeof(i)); //prints size of a float i
//	
//	printf("%d",a*b*s);
//}
