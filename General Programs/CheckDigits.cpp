#include<iostream>


using namespace std;

int fun(int n,int m)
{
	int sum = n + m;
	int s = sum;
	int c1 = 0,c2=0;
	int nn = n;
	while(s>0)
	{
		c1++;
		s /= 10;
		
	}
	
	while(nn>0)
	{
		c2++;
		nn /= 10;
	}
	
	if(c1==c2) return sum;
	
	else return n ;
}

int main()
{
	cout<<fun(10,121);
	return 0;
}
