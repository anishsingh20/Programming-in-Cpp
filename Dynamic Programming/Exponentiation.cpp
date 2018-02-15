#include<iostream>

//Program to demonstrate Recursive approaches to fidn pow(x,n) with different time complexities
//First to solve any problem by recursion we need to define and calculate a recurrence relation or recursion defination


int Pow(int x,int n)
{
	if(n==0)
		return 1;
		
	return x*Pow(x,n-1);
} //Time complexity  = O(n) = linear

int Pow1(int x,int n)
{
	
}

using namespace std;

int main()
{
	
	cout<<Pow(2,10);
	
	return 0;
}
