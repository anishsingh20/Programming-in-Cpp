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
}


int main()
{
	cout<<fact(5);
}
