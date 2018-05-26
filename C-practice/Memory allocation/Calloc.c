#include <stdio.h>
#include<stdlib.h>
 
int main()
{
	int *p,*q;
	p = (int*)calloc(20,sizeof(char));
	//calloc takes 2 args - no of elements, size of each item. It also sets the values to 0 automatically.
	
	q=(int*)malloc(20);
	
	printf("%d\n",p[3]);//prints 0
	printf("%d\n",q[3]);
 }
