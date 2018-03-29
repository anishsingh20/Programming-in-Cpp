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

} //time complexity = exponential, not efficient technique i.e it is equivalent to the catalan number itself.
//S(n) = O(n) for recursion call stack




//Using Dynamic Programming to find catalan number in O(n^2)

long long int CatalanDP(int n)
{
	long long int catalan_arr[n+1];
	catalan_arr[0] = catalan_arr[1] = 1;
	
	//base case
	if(n<=1)
		return catalan_arr[n];
		
	//otherwise fill the array
	for(int i = 2 ; i <= n ; i++)
	{
		catalan_arr[i] = 0;
		 
		for(int j = 0 ; j < i ; j++)
		{
			catalan_arr[i] += catalan_arr[j] * catalan_arr[i-j-1]; 
		}
	}
		
	return catalan_arr[n];
}//Time complexity = O(n^2) - quadratic time algorithm



//Method-3) Uisng binomial coefficient to find catalan number. C(n) = BinomCoeff(2n,n) / n+1
long long int binomEfficient(int n,int k)
{
	long long int res = 1;
	
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



long long int CatalanBinom(int n)
{
	if(n<=1)
		return 1;
	
	long long int c = binomEfficient(2*n,n);
	
	return c/(n+1);
}

//Method-4-Most efficient method as it takes linear time O(n)
//long long int Catalan4(int n)
//{	
//
//	if(n<=1)
//		return 1;
//		
// 	int res=1;
//	
//	
//		
//	for(int k = 2 ; k <=n ; k++){
//		
//		res =  ( res * ((n+k)/k) )      ;
//		
//	}
//	
//	return res;
//}



int main()
{
	
//	cout<<CatalanRecursive(9);
//	cout<<endl;
//	
//	
//	cout<<"Catalan by binomial coefficient method:"<<endl;
//	cout<<CatalanBinom(9);
//	cout<<endl;
//	
//	
//	cout<<"By dynamic programming"<<endl;
//	cout<<CatalanDP(9);


	//calculating the first 20 Cataaln numbers
	cout<<"Number"<<"        "<<"Catalan Number"<<endl;
	
	for(int i=0 ; i<=20 ;i++)
	{
		cout<<i<< "                   "<< CatalanBinom(i);
		cout<<endl;
	}
}
