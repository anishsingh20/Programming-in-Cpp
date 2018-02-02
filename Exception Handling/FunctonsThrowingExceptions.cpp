#include<iostream>
#include<stdexcept>


//FUNCTIONS WHICH CAN THROW EXCEPTIONS

using namespace std;


//function which can throw int or char or runtime error exceptions
void test() throw(int ,const char *, runtime_error) {
	
	throw runtime_error("Runtime error occured");
}

int main() {
	
	try
	{
		//calling the exception throwing function
		test()	;
	}
	
	catch(const char *err)
	{
		cout<<err<<endl;
		
	}
	
	catch(runtime_error &err)
	{
		cout<<err.what();
		
	}
	
	catch(int err) 
	{
		cout<<err<<endl;
	}
	
	catch(...)
 	{
 		cout<<"Some unknown exception occured"<<endl;
	 }	
return 0;
}
