#include<iostream>

//program to count number of set bits
using namespace std;

/*
1) Using & operator right shift operation
2) Using __buildtin_popcount(n) function to get count of set bits
3)Brian Kernighan’s Algorithm:
*/

//program to count no of bits
int CountBits(int n)
{
	int count=0;
	while(n)
	{
		n >>= 1; //simply right shift the no by 1 
		count++;
	}
	
	return count;
}


int CountSet(int n)
{
	int count=0;
	while(n)
	{
		count += n & 1;
		n >>= 1; //simply right shift the no by 1 
		
	}
	
	return count;
}

int main()
{
	//cout<<CountSet(10);
	int n =  __builtin_popcount(7);
	
	cout<<n;
	return 0;
}
