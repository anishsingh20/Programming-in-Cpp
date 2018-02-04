#include<iostream>

using namespace std;


/*
Templates are expended at compiler time. This is like macros. The difference is, compiler does type checking before template expansion. 
The idea is simple, source code contains only function/class, but compiled code may contain multiple copies of same function/class.
*/


template<typename T>

T Swap(T *a, T *b) {
	
	T temp = *a;
	*a=*b;
	*b=temp;
}

template<class T>

T max(T a, T b , T c) {
	
	if(a > b && a > c) return a;
	
	if(b>a && b>c) return b;
	
	if(c>a && c>b) return c; 
}


int main () 
{
//	int a=10,b=20;
//	string a1 = "Anish", b1 = "mrinal";
//	
//	//call by reference
//	Swap(&a,&b);
//	
//	cout<<"a :"<<a<<"  |  "<<"b :"<<b<<endl;
//	
//	Swap(&a1,&b1);
//	
//	
//	cout<<a1<<endl;
//	cout<<b1<<endl;

	cout<<max<int>(10,12,100);
	cout<<endl;	
	cout<<max<char>('a','b','z');
	

	
	return 0;
}
