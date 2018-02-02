#include<iostream>
#include<stdexcept>

using namespace std;

//Program to show Nested try-catch blocks and re-throwing exceptions


int main() {
	
	
	try {
		
		try{
			throw ("Character error occured");
		}
		catch(const char *err) 
		{
			cout<<err<<endl;
			
			cout<<"Rethrowing the runtime exception :-"<<endl;
			
			//re-throwing another type of exception
			throw runtime_error("Runtime exception occured");
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
