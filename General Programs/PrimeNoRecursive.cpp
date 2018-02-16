#include<iostream>

using namespace std;

//Recursive program to find if a number is prime number or not

int PrimeRec(int n,int i=2)
{
	//will recur until i < n and check for the condition defined inside
	if( n > i)
	{
		if(n%i!=0)
		{
			
			return PrimeRec(n,i++);
			
			
		} 
		//case when n is divisible by i-//base condition
		else
			return 0;
			
	}
	
	//control comes here when above n > i becomes false
	return 1;
	
	
} //TIME COMPLEXITY - O(n)


int main()
{

	cout<<PrimeRec(14);
		
}
