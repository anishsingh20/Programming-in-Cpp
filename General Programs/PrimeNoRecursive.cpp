#include<iostream>

using namespace std;

//Recursive program to find if a number is prime number or not

int PrimeRec(int n,int i=2)
{
	
	//corner cases
	if(n==0 || n==1 || n%i == 0) return 0;
	

	//will recur until i < n and check for the condition defined inside
	if( n > i)
	{
		if(n%i!=0)
		{
			
			return PrimeRec(n,++i);
			
			
		} 
		
	}
	
	return 1;		
	
} //TIME COMPLEXITY - O(n)


int main()
{

	cout<<PrimeRec(0);
		
}
