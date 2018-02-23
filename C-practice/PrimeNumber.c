#include<stdio.h>
#include<conio.h>


int Prime(int n,int i)
{
	
	
//	int flag = 1;
//	
//	if(n==1 || n==0)
//	{
//		return 0;
//	}
//	
//	for(int i=2; i <= n/2 ; i++)
//	{
//		if(n%i==0)
//		{
//			flag = 0;
//			
//		}
//	}
//	
//	return flag;

	if(i<n)
	{
		if(n%i!=0 )
		{
			return Prime(n,++i);
		}
		else
		{
			return 0;
		}

	}
	
	return 1;
}


int main()
{
	printf("%d",Prime(24,2));
	return 0;
}
