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

int main()
{
	
	cout<<powerof2(1024);
	
	return 0;
}
