#include<iostream>


using namespace std;


//Program to demonstarte how to overload a generic function with a normal function-called Explicit specialization

template<class T> void display(T x)
{
	cout<<"Generic function called,x = "<<x<<endl;
 } 
 
 
 
//another form of function declaration 
template<> void display <int> (int x)
{
	
	cout<<"Normal function called,x = "<<x<<endl;
}

int main()
{
	
	
	display("anish singh walia");
	display(10.22);	
	display(10);

	
	
}




