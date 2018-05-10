#include<stdio.h>
#include<conio.h>

int func1(int);

int main()
{
	int k = 35;
	func1(k=func1(k=func1(k))); // k becomes 37
	// k = func1(k = func1(k = func1(k))); k becomes 38 as the result is stored in k
	//k = func1(func1(func1(k))); also outputs 38
	
	printf("%d",k);
	return 0;
}

int func1(int n)
{
	n++;
	return n;
}
