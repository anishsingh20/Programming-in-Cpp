#include<iostream>

//program to find HCF or GCD of 2 numbers
//GCD- HCF of of 2 numbers is the largest possible number which divides both the numbers-ie without leaving any remainder
using namespace std;



//recursive function to find GCD of 2 numbers
int GCDRecur(int a , int b)
{
	
	if(b!=0) return GCDRecur(b, a%b );
	else return a;
	
	
}


//Euclid's algorithm which is based on DIVIDE AND CONQUER STRATEGY TO FIND GCD-HCF of 2 numbers
int EuclidGCD(int m,int n)
{
	//substract larger from smaller number until they both become equal is the logic of Euclidean algo
	int count = 0;
	while(m!=n)
	{
		if(m>n)
			m = m-n;
		else
			n = n-m;
			
		count++;
			
	}
	//when both number becomes equal, that number is the GCD
	
	cout<<"Number of Substraction: "<<count<<endl;
	return n;
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
//	cout<<GCDRecur(120,72);
	cout<<endl;
	cout<<EuclidGCD(10,3);
	
	return 0;
}
