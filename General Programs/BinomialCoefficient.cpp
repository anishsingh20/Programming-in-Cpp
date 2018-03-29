#include<iostream>

using namespace std;

/*Program to find binomial coefficient C(n,k) i.e n c K-combination

C(n,k) =  n! / (n-k)! . k! = fact(n) / fact(n-k)*fact(k)



*/

int fact(int n)
{
	if(n<=1)	
		return n;
	
	else
		return n*fact(n-1);
} //Time complexity = O(n) , S(n)  = O(n) required by recursion call stack


//function to find the binomial coefficient 
long long int BinCoeff(int n,int k)
{
	if(n==k)
		return 1;
	if(k==1)
		return n;
		
		
	return ( fact(n) / (fact(n-k)*fact(k))  )  ;
	
		
}//Time complexity of this method is O(n*k) , space = O(n) required by stack space

int main()
{
	cout<<BinCoeff(12,10);
}
