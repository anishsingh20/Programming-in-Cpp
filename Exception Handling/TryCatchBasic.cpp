#include<iostream>


//EXPECTION HANDLING IN CPP

using namespace std;

int main() {
	int a,b;
	
	cin>>a;
	cin>>b;
	
	try{
		if(b==0) {
			throw runtime_error("Denominator is 0");
		} 
		
		else {
			int c = a/b;
			cout<<"Product is : "<<c<<endl;
		}
		
	}catch(rumtime_error &e) {
		
		e.what();
	}
	
			
	return 0;
}
