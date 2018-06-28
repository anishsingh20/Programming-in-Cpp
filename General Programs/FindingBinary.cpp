#include<iostream>

using namespace std;


void findBin(int num)
{
	int bin;
	if(num==0) return ;
	
	if(num >  0)
	{
		
		bin = num%2; //can take values either 0 or 1
		
		//recursively find remainder of num which is halved in each iteration until it is < 0	
		findBin(num/2); 
		
		//print bin value in postorder
		cout<<bin;	
	
	}
	
	
}


void PrintBinary(int n)
{
	for(int i = n; i>=2 ;i--)
	{
		findBin(i);
		cout<<" ";
	}
}

int main()
{
	//findBin(3);
	
	PrintBinary(6);
	
	return 0;
}
