#include<iostream>


using namespace std;

//Recrsive program to find Factorial of a number
int factorial(int n)
{
//	if(n==0) return 0;
	
	
	if(n==1) return 1;
	
	//otherwise, recursively find factorial of n* factorial(n-1)
	else
		return n*factorial(n-1);
		
	
	
}


int main()
{
	
	cout<<factorial(6)<<endl;
	
	return 0;
}
