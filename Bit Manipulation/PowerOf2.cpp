#include<iostream>

using namespace std;

//program to check if an integer is power of 2

int powerof2(int n)
{
	//we know that all powers of 2 have only 1 bit set, all other bits 0
	//so we check the count of set bits, if it equals 1, then it is a power of 2
	if(__builtin_popcount(n)==1)
		return true;
		
	else return false;
}

int powerofTwo(int n)
{
	if(n==1) return 0;
	
	return ((n & n-1)==0)	;
	
}
/*In the above method if n is a power of 2 , then n-1 will have all the bits set from lSB to the set bit of n, as every power
of 2 has only 1 set bit. And when we do n & n-1 , if it is 0 then n is a power of 2
*/


int main()
{
	
	cout<<powerof2(1024);

	
	return 0;
}
