#include<iostream>

using namespace std;

//printing the fibonacci sequence
//next number  p(n+1) = p(n) + p(n-1)

void fibonacci(int n) {
	long long int a=0,b=1,c;
	
	for(int i=0 ; i < n ; i++) {
		
		
		c = a+b;
		b=a;
		a=c;
		cout<<c<<endl;
		
		
		
	}
}

int main()  {
	
	fibonacci(5);
	
	
	return 0;
}
