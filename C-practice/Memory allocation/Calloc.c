#include <stdio.h>
#include<stdlib.h>
 
int main()
{
	int *p;
	p = (int*)calloc(20,sizeof(char));
	//calloc takes 2 args - no of elements, size of each item. It also sets the values to 0 automatically.
	
	printf("%d\n",p[3]);//prints 0
	
 }
