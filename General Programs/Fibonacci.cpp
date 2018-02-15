#include<iostream>

using namespace std;

//printing the fibonacci sequence
//next number  p(n+1) = p(n) + p(n-1)

#define ll long long


//construct a recusion tree to better understand this concept- REcursive implementation is very inefficient for Fibonacci sequence and is an Exponential time algorithm-O(2^n)
ll FibonacciRec(int n)
{
	if (n==1 ||  n==2)
	 {
	 	return 1;
	 }
	 
	 else {
	 	
	 	return FibonacciRec(n-1)  + FibonacciRec(n-2);
	 }
	
} 
/*Time comlexity eqn  = T(n-1) + T(n-2) + O(1) , on solving the recurrence relation we get O(2^n)
//What this means is, the time taken to calculate fib(n) is equal to the sum of time taken to calculate subproblems fib(n-1) and fib(n-2). 
This also includes the constant time to perform the previous addition-but the tight upper bound complexity is O((1.1680)^n) .
*/

int fibonacci(int n) {
	long long int a=0,b=1,c=0;
	
	for(int i=1 ; i < n ; i++) {
		
		
		c = a+b;
		a=b;
		b=c;
		
		//or b=a and then a=c
//		cout<<c<<endl; to print the complete sequence
 		
		
		
	}
	
	return c;
} //TIME COMPLEXITY- O(n)- linear algorithm

int main()  {
	
	cout<<fibonacci(1000000000);
	
	cout<<endl;
	
//	cout<<FibonacciRec(50);
	
	
	return 0;
}
