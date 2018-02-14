#include<iostream>

using namespace std;
//function to check whether a number is prime or not

bool Isprime(int n) {
	
	//prime number- a number which is only divisible by itself and 1
	//The definition of a prime number is a positive integer that has exactly two positive divisors-which is 1 and the num itself. 
	//However, 1 only has one positive divisor (1 itself), so it is not prime
	if(n <= 0) {
		
		
		cout<<"Enter a valid integer"<<endl;	
		return false;
	}
		
	for(int i = 2 ; i<=n/2 ; i++) {
	
		//if divisible by 2 or a multiple of 2
		if(n%i==0) {
			
			cout<<"Not a prime"<<endl;
			return false;
			break;
		}
	}
	cout<<"Is a prime"<<endl;
	return true;	
}
//TIME COMPLEXITY =  O(n)

//recursive solution
//int Isprime(int n ,int i=2) {
//	
//	if(n > i) {
//		
//		if(n%i!=0) {
//			
//			return Isprime(n,++i);
//			
//			
//		}
//		
//		else {
//			cout<<"Not a prime"<<endl; 
//			return 0;
//			
//		}
//	}
//	
//	cout<<"Is a prime"<<endl;
//	return 1;
//
//	
//}



int main() {
	
	Isprime(10092828);
	
	
	return 0;
}
