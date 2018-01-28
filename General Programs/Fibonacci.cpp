#include<iostream>

using namespace std;

//printing the fibonacci sequence
//next number  p(n+1) = p(n) + p(n-1)

void fibonacci(int n) {
	long long int a=0,b=1,c;
	
	for(int i=0 ; i < n ; i++) {
		
		
		c = a+b;
		a=b;
		b=c;
		
		//or b=a and then a=c
		cout<<c<<endl;
		
		
		
	}
}

int main()  {
	
	fibonacci(10);
	
	
	return 0;
}
