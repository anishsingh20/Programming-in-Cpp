#include<iostream>


using namespace std;

//When a reference is return type of a function,then that function can be used as lvalue(left hand operand)

int &f()
{
	static int x = 10; //x is static that means it is shared amongst all function calls and x=10 is executed only once and stored in static memory
	
	return x;
 } 
 

int main()
{

	f()  = 30; // modifies x to 30
	
	cout<<f(); //outputs 30	
}
