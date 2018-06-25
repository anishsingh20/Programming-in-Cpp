#include<iostream>

using namespace std;

long long int F[30];


long long int factorial(int n)
{
	if(n==0) return 0;
	if(n==1) return 1;
	
	
	//if result is stored in array-simply return it
	if(F[n]!= -1)
	{
		return F[n];
		
	}	
	
	//otherwise first calculate result recursively and store it in array
	
	F[n] = n*factorial(n-1);
	return F[n];
	
} //as efficient as simple recursive implementation or factorial program 


int main()
{
	for(int i=0;i<20;i++)
	{
		F[i] = -1;
	}
	
	cout<<factorial(20);
	
	
	return 0;
}
