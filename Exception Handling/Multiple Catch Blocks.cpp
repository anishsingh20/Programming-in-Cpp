#include<iostream>
#include<stdexcept>


//CATCHING MULTIPLE EXPECTIONS Based on type of Exception occured

using namespace std;




int main()
{
	try {
		
		throw runtime_error("Runtime error occured");
	}
	
	//if integer exception occurs this catch block is called
	catch(int err) {
		
		cout<<"Integer Error occured: "<<err<<endl;
	}
	//if rumtime exception occurs this catch block is called
	catch(runtime_error  err) {
		
		cout<<"Runtime Error :"<<err.what();
		
	}
	//if character exception occurs this catch block is called
	catch(const char *) {
		cout<<"Character error occured:"<<endl;
	}
	
	//this catch block can hanlde any types of exceptions-all types of exceptions
	catch(...) {
		cout<<"Some exception occured"<<endl;
	}
	
	return 0;
}
