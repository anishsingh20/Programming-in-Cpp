#include<iostream>

using namespace std;

// 1) a function can take both its return rype as const , and its arguments as const type
// 2) A function which takes a non-const as argument cannot be called using a const argument, will give error
// 3)But a function which takes a const argument, can be called using both const and non-const arguments.

int f(const int *x) {
	
	return *x;
}

int g(int *x) {
	
	return *x;
}

int main()
{
	int a=10;
	int *x=&a; //non-const pointer
	int const *y=&a;//value of y cannot be changed
	
	
	cout<<f(x)<<endl; // no error, as a function taking const arg , can be called using a non-const or const arg
	cout<<f(y)<<endl; 
	
	//cout<<g(y); Error as a function taking non-const as parameter, can only be called using a non-const arg,not const.
	return 0;
}
