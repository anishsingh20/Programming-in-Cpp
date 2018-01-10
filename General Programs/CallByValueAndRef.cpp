#include<iostream>
//example to represent call by value and call by reference of function calling

using namespace std;

//In call by value, a copy of actual(args which are passed when func is called)
// arguments is passed to formal(args when defined a func) arguments of the called function and any change made to the 
//formal arguments in the called function have no effect on the values of actual arguments in the calling function.
int SwapByVal(int a, int b) {
	
	int temp=a;
	a=b;
	b=temp;
	return (a,b);
}


//in call by reference we pass the location(address) of the actual arguments as formal arguments when calling function. So when a function is defined 
// we pass pointers as formal arguments as using the pointers we can easily indirectly manipulte the values of the actual(passed) arguments from within the func using their address
int SwapByRef(int *a, int *b) {
	
	int temp = *a;
	*a=*b;
	*b=temp;
	
	return (*a,*b);
}


int main () {
	
	int a=10,b=20;
	
	SwapByVal(a,b);
	cout<<"a is : "<<a<<endl;
	cout<<"b is: "<<b<<endl; //values of a and b unchanged
	
	cout<<"\n";
	
	cout<<"When swap function is called by reference"<<endl;
	cout<<"\n";
	
	SwapByRef(&a,&b);
	cout<<"a is : "<<a<<endl;
	cout<<"b is: "<<b<<endl;
	
	return 0;
}

