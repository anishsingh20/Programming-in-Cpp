#include<iostream>

//program to find HCF or GCD of 2 numbers
//GCD- HCF of of 2 numbers is the largest possible number which divides both the numbers-ie without leaving any remainder
using namespace std;



//recursive function to find GCD of 2 numbers
int GCDRecursive(int a , int b)
{
	if(b!=0) return GCDRecursive(b, a%b );
	else return a;
	
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

	int gcd = GCD(120,72);
	cout<<"The HCF is :"<<gcd; 
	
	cout<<endl;
	
	cout<<GCDRecursive(120,72);
	
	return 0;
}
