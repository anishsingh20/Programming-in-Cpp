#include<iostream>


using namespace std;


//Templates are an example of Compile time polymorphism-The compiler during compile time generates a different instances of the generic function for different data types
//using which the generic function is called. And all the local variables inside that generic function will have a separate copy for every different data type called in function .

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
