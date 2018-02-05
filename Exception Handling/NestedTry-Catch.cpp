#include<iostream>
#include<stdexcept>

using namespace std;

//Program to show Nested try-catch blocks and re-throwing exceptions


int main() 
{
	
	
	try {
	
		//throw("Char error occured");-if in parent try block we throw something , then the child try block is not executed
			
		try
		{
			throw ("Character error occured");
		}
		
		catch(const char *err) 
		{
			cout<<err<<endl;
			
			cout<<"Rethrowing the runtime exception :-"<<endl;
			
			//re-throwing another type of exception
			
			//only the first re-defined throwed exception is catched not throwed after that
			throw runtime_error("Runtime exception occured");
			
			throw ("Rethrowing char exception");//not caught
		}
	}
	
	
	catch(const char *err) {
		
		cout<<"Outer character exception-->"<<err<<endl;
	}
	
	catch(runtime_error &err) {
		
		cout<<"outer runtime exception error-->"<<err.what()<<endl;
	}
	
	
	
	
	
	return 0;
}
