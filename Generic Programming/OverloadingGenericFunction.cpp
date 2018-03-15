#include<iostream>

using namespace std;

//Program to demonstrate how to overload a generic function, like any normal function based on different number and type of arguents


template<typename T> void display(T x)
{
	cout<<"Genric function with 1 argument called"<<endl;
	cout<<x<<endl;
	cout<<y<<endl;
	
}



template<typename t1,typename t2> void display(t1 x, t2 y)
{
	cout<<"generic function with 2 arguments called"<<endl;
	cout<<x<<"  "<< y<<endl;
	
}

int main()
{
	display(20);
	
	display(100,"anish");
	return 0;
}
