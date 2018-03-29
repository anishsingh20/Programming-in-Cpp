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
int BinCoeff(int n,int k)
{
	if(n==k)
		return 1;
	if(k==1)
		return n;
		
		
	return ( fact(n) / (fact(n-k)*fact(k))  )  ;
	
		
}//Time complexity of this method is O(n*k) , space = O(n) required by stack space



//Method-2 Efficinet solution to find binomial coefficient

int binomEfficient(int n,int k)
{
	int res = 1;
	
	if(n==k)
		return 1;
	if(k==1)
		return n;
		
	//if  k > n-k then  k = n-k as // Since C(n, k) = C(n, n-k)
	if( k > n-k)
		k = n-k;
	
	//calculating C(n,k) =  n!/ (n-k)! * k!
	for(int i = 0 ; i < k ; i++)
	{
		res *= (n-i);
		
		res /=  (i+1);
	}
	
	return res;
		
} //Time complexity = O(k) and aux space  = O(1)


int main()
{
	cout<<BinCoeff(20,9);
	cout<<endl;
	cout<<"Efficient method"<<endl;
	
	cout<<binomEfficient(20,12);
}
