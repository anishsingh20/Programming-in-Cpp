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


int countSetUsing(int n)
{
	int count= 0 ;
	while(n)
	{
		n &= (n-1);
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
	//	n >>= 1; //simply right shift the no by 1 
		//right shift is equivalent to division by 2
		n /= 2;	
	}
	
	return count;
}

//int countUnset(int n){
//	
//	int count = 0;
//	while(n)
//	{
//		count += n | 1;
//		
//		n /= 2;
//	}
//}

int main()
{
	cout<<countSetUsing(19);
//	cout<<endl<<countUnset(5);
	
	return 0;
}
