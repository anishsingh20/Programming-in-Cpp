#include<iostream>


using namespace std;

int fun(int n,int m)
{
	int sum = n + m;
	int s = sum;
	int c1 = 0,c2=0;
	int nn = n;
	while(s /= 10)
	{
		c1++;
		
		
	}
	
	while(nn /= 10)
	{
		c2++;
		
	}
	
	if(c1==c2) return sum;
	
	else return n ;
}

int main()
{
	cout<<fun(100,121);
	return 0;
}
