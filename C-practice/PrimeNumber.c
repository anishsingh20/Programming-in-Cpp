#include<stdio.h>
#include<conio.h>


int Prime(int n)
{
	int flag = 1;
	
	if(n==1 || n==0)
	{
		return 0;
	}
	
	for(int i=2; i <= n/2 ; i++)
	{
		if(n%i==0)
		{
			flag = 0;
			
		}
	}
	
	return flag;
}


int main()
{
	printf("%d",Prime(1));
	return 0;
}
