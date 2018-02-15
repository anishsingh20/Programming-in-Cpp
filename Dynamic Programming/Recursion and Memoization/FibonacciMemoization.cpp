#include<iostream>

/*PROGRAM TO USE RECURSION WITH MEMOIZATION TO IMPROVE TIME COMPLEXITY OF RECURSIVE FINONACCI SEQUENCE PROGRAM-
In order to improve the time complexity of which are inefficient when using recursion  and for higher values of n, we can use DP and memoization technique to
store the results of the subproblems and state of recursive calls in some data structure (say array) and simly return them instead of
redundantly calculating the same function calls.
*/

long long int F[51];

long long int Fibonacci(int n)
{
	//if result is stored in memory simply return it
	if(F[n] != -1)
	{
		return F[n];
	}
		
	//otherwise simply calculate the result and store it in memory
	
	F[n] = ( Fibonacci(n-1) + Fibonacci(n-2) 	);
	
	return F[n];
	
	
}
//TIME COMPLEXITY  = O(N), Extra space =  O(N)



using namespace std;

int main()
{
	
	for(int i=0;i<51;i++)
	{
		F[i] = -1;
	}
	
	F[0] = 0 , F[1]=1;
	
	long long int result  = Fibonacci(50);
	
	cout<<result;
	
	return 0;
}
