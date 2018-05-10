#include<stdio.h>
#include<conio.h>


//call by value and call by reference

int main()
{
	int fun(int* );
	int fun1(int* );
	
	int i = 3;
	
	fun(&i);
	
	printf("%d\t",i);
	
	fun1(&i);
	
	printf("%d\t",i);
	//no changes will be made to i, it will remain 3 
	
}


int fun(int *i)
{
	*i = (*i + 1);
	printf("%d\t",*i);
}

int fun1(int *j)
{
	*j = (*j + 1);
	printf("%d\t",*j);
}
