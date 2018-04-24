#include<iostream>

//program to find HCF or GCD of 2 numbers
//GCD- HCF of of 2 numbers is the largest possible number which divides both the numbers-ie without leaving any remainder
using namespace std;


/*TIME COMPLEXITY OF EUCLIDEAN ALGORITHM EXPLAINED-
Euclidean algorithm is the most efficient way of calculating GCD of 2 numbers.
It is based on the fact that when we substract larger number by smaller , then also the GCD of substracted no and other no will
be same and not change.

So logic is to keep replacing the larger no by the difference between larger and smaller number until both the numbers become equal.
When both numbers are equal that is the GCD(a,b).

So say GCD(x,y) <= T(n) and n = x*y
the decreasing factor d = x / (x%y).

so T(n) = T(n/d) + C
T(n) = T(n/d^2) + 2c
T(n) = T(n/d^3) + 3c
		
on solving the above recurrence relation we get
T(n) = T(n/d^k) + Kc. ,  where  k = log(n) to the base d.

so upper bound of the above algo is T(n) = O( log(xy))
Hence we can have atmost log(xy) operations to calculate the GCD using Euclidean algorithm.


*/


//recursive function to find GCD of 2 numbers-efficient version of Euclidean algorithm
long int GCDRecur(long long int a ,long long int b)
{
	static long long int count =0;
	if(b!=0)
	{
		count++;
		
		return GCDRecur(b,a%b);
		
		
	 } 
	 
	cout<<"NUmber of operations to find GCD are "<< count<<endl;
	
	return a;
	
	
}//This approach takes lesser oerations to find GCD then normal Euclidaen algorithm explained below


//Euclid's algorithm which is based on DIVIDE AND CONQUER STRATEGY TO FIND GCD-HCF of 2 numbers
long long int EuclidGCD(long long int m,long long int n)
{
	//substract larger from smaller number until they both become equal is the logic of Euclidean algo
	long long int count = 0;
	while(m!=n)
	{
		if(m>n)
			m = m-n;
		else
			n = n-m;
			
		count++;
			
	}
	//when both number becomes equal, that number is the GCD
	
	cout<<"Number of Substractions done to find GCD: "<<count<<endl;
	return n;
}

//recursive approach to find GCD using Euclidean algorithm
long long int EuclidGCDRecursive(long long int a,long long int b)
{

	if(a==b)
		return a;


	if(a!=b)
	{
		
		//replace the larger of 2 no(s) by the dfference between it and the smaller number
		if(a > b)
			return EuclidGCDRecursive(a-b,b);
			
		else
			return EuclidGCDRecursive(a,b-a);
	}
				
	
}


int GCD(int a, int b) {
	
	//converting negetive inputs to positive
	a =  (a<0) ? -a : a;
	b =  (b<0) ? -b : b;
	int gcd;
	
	for(int i=1 ; i <= a && i <= b; i++) {
		
		//checking if i is a factor of a and b-ie i perfectly divides a and b
		if(a%i==0 && b%i==0) {
			gcd = i;
		}
		
	}
	return gcd;
}


int main() {

//	int gcd = GCD(120,72);
//	cout<<"The HCF is :"<<gcd; 
//	
//	cout<<endl;
//	
	cout<<GCDRecur(55,100);
	cout<<endl;
	cout<<EuclidGCD(100,55);
	cout<<endl;
	
	cout<<EuclidGCDRecursive(120,72);
	
	return 0;
}
