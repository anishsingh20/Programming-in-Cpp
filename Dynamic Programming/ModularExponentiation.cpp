#include<iostream>


//Program to find modular exponent using recursion- 
//it is (x^n % m) , i.e the remainder left after x raised to some n is divided by a positive number M
using namespace std;

/* x^n can be written as  = x^n/2 * x^n/2 when n = even
x^n can be written as  = x . x^n-1 for odd n;
using these recurrence relations we will find x^n mod M

also (a*b) mod M = { (a mod M) * (b mod M)} mod M

*/


int ModExpo(int x, int n , int M)
{
	//base terminating condition
	if(n==0)
		return 1;
		
	//when n is even
	else if(n%2==0)
	{
		int y = ModExpo(x,n/2,M);
		
		return (y*y)%M;
		
	}
	
	//when n is odd
	else 
	{
		return ( ( x%M)*ModExpo(x,n-1,M) )% M;	
	}
}

//TIme complexity  = O(logn) , as T(n) = T(n/2) + c for n = even
//for n=odd , T(n) = T(n-1) + c2, so upper bound we consider T(n) = T(n/2) + C ,
//on solving the above recurrence relation we get T(N) =  O(logn)

int main()
{
	
	cout<<ModExpo(2,10,4); // means 2^10 mod 4
	
	return 0;
}
