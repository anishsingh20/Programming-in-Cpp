#include<iostream>

using namespace std;


//function to find LCM of 2 numbers
//The LCM of two integers n1 and n2 is the smallest positive integer that is perfectly divisible by both n1 and n2 (without a remainder). ie is a multipe of n1 and n2

//eg- LCM of 72 and 120 = 360

//LCM = (num1*num2)/GCD
//GCD= greatest common divisor/HCF
//The HCF or GCD of two integers is the largest integer that can exactly divide both numbers (without a remainder).

int LCM(int a,int b) {
	
	int gcd,lcm;
	//first finding HCF
	for(int i = 1; i<=a && i<=b; i++){
		
		//checking is i divides a and b
		if(a%i==0 && b%i==0) {
			gcd = i;
				
		}
	}
	
	lcm = ( (a*b)/gcd );
	
	return lcm;
	
}

int main() {
	
	
	int lcm = LCM(5,10);
	
	cout<<"The LCM is:"<<lcm;
	
	return 0;
}
