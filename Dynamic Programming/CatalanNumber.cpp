#include<iostream>

using namespace std;

/*Program to calculate nth CATALAN NUMBER-catalan number is simply a sequence of number which has lots of applications in DSA.

We have the recurrence relation for Catalan no(s) as C(0) = 1, C(1) = 1 so C(n<=1) = 1, 
else C(n>=1) =  sum( C(i) * C(n-i)) where i = 2 to n

Method to calculate CATALAN NUMBER-
1) Using the above recurrence relation and recursion
2) Using Dynamic programming to optimize 
3) Binomial coefficient = C(n) =  1/(n+1) * (2n c n) , linear time algorithm
4) C(n) = product(n+k/k) , where  k = 2 to n 	, linear time algorithm
					      
*/


//Method-1 Recursion-exponential time algorithm
long long int CatalanRecursive(int n)
{
	long long int res=0;
	//base case
	if(n<=1)
		return 1;

	for(int i = 0; i < n ; i++)
	{
		res += CatalanRecursive(i)*CatalanRecursive(n-i-1);
	}
	
	
	//or we can also do this
//	for(int i = 0; i < n ; i++)
//	{
//		res += CatalanRecursive(i)*CatalanRecursive(n-i-1);
//	}

	return res;

} //time complexity = exponential, not efficient technique.


//Method-4-Most efficient method as it takes linear time O(n)
long long int Catalan4(int n)
{	

	if(n<=1)
		return 1;
	static int res=1;
	
	
		
	for(int k = 2 ; k <= n; ++k){
		
		res = (res * (n+k)/k ) ;
		
	}
	
	return res;
}



int main()
{
	cout<<CatalanRecursive(4);
	cout<<endl;
	cout<<"linear time method"<<endl;
	cout<<Catalan4(4);
}
