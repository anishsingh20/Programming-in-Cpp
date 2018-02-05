#include<iostream>
#include<stdexcept>


//FUNCTIONS WHICH CAN THROW EXCEPTIONS

using namespace std;


//function which can throw int or char or runtime error exceptions
void test() throw(const char *,int, runtime_error) {
	
	
	throw runtime_error("Runtime error occured");
	throw 20;
	//can throw multiple exceptions inside the function, but will only catch the first defined throwed exception
	
}

int main() {
	
	try
	{
		//calling the exception throwing function
		test()	;
	}
	
	
	catch(int err) 
	{
		cout<<err<<endl;
	}
	
	catch(const char *err)
	{
		cout<<err<<endl;
		
	}
	
	catch(runtime_error &err)
	{
		cout<<err.what();
		
	}
	

	
	catch(...)
 	{
 		cout<<"Some unknown exception occured"<<endl;
	 }	
return 0;
}
