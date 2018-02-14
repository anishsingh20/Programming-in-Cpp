#include<iostream>

using namespace std;


//function to find LCM of 2 numbers
//The LCM of two integers n1 and n2 is the smallest positive integer that is perfectly divisible by both n1 and n2 (without a remainder). ie is a multipe of n1 and n2

//eg- LCM of 72 and 120 = 360

//LCM = (num1*num2)/GCD
//GCD= greatest common divisor/HCF
//The HCF or GCD of two integers is the largest integer that can exactly divide both numbers (without a remainder).

//int LCM(int a,int b) {
//	
//	//converting negetive inputs to positive
//	a =  (a<0) ? -a : a;
//	b =  (b<0) ? -b : b;
//	
//	int gcd,lcm;
//	//first finding HCF
//	for(int i = 1; i<=a && i<=b; i++){
//		
//		//checking is i divides a and b
//		if(a%i==0 && b%i==0) {
//			gcd = i;
//				
//		}
//	}
//	
//	lcm = ( (a*b)/gcd );
//	
//	return lcm;
//	
//}


//METHOD-2 to find LCM recursively and iteratively

int LCMRecur(int a, int b)
{
	//static variable lcm to maintain just one copy of the lcm variable
	static int lcm = 1;
	
	//lcm will increment until it is prefectly divisible by both a and b or is  multiple of a and b
	if(lcm%a==0 && lcm%b==0) return lcm;
	
	else
	{
		
		lcm++;
		//recur until lcm variable becomes divisible by a and b
		LCMRecur(a,b);
	}
		
}



int LCM(int a,int b) {
	int lcm;
	
	//converting -ve to +ve no(s)
	a =  (a<0) ? -a : a;
	b =  (b<0) ? -b : b;
	
	//lcm = minMultiple is the greater among a or b 
	lcm = (a>b) ? a : b;
	
	//always true
	while(1) {
		
		//if the no is divisible by both a and b
		if(lcm%a==0 && lcm%b==0) {
			return lcm;
			break;
		}
		
		lcm++;
		
	}
	
	return lcm;	
}


int main() {
	
	
	int lcm = LCM(-72,-120);
	
	cout<<"The LCM is:"<<lcm;
	
	cout<<endl;
	
	cout<<LCMRecur(3,4);
	
	return 0;
}
