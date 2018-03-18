#include<iostream>


using namespace std;


//Templates are an example of Compile time polymorphism

template <typename T> void fun(T x)
{
	static int y = 0;
	
	cout<<++y<<endl;
	
	
	
}


int main()
{
	//compiler creates a new instance of fun() for every data type.
	fun(10); //y becomes 1
	 
	fun(100);//y become 2
	
	fun(100.2); //when called using another types-compiler creates a new version of fun() and keeps a different copy of y-so y=1 again for float.
	
	//every instance of fun() called on different data type has its own copy of static variable.
	
	
}
