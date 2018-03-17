#include<iostream>


using namespace std;

//inline namespaces- are simply nested namespaces which behave like their parent namespace member


namespace AppVersion{

	namespace Version1{
		
		void display()
		{
			cout<<"This is version 1"<<endl;
			
		}
		
	}
	
	namespace Version2{
	
		void display()
		{
			cout<<"This is version 2"<<endl;
			
		}
		
	
	}
	
	
	inline namespace Version3 {
		
		void display()
		{
			cout<<"This is the latest update of version three"<<endl;
		}
		
	}
	
	//this defination of Version3 namespace is also inline
	namespace Version3 {
	
		void whoAreYou()
		{
			cout<<"I am Anish Singh Walia"<<endl;
		}
	}
	
	
	
	
	
}




int main()
{
	
	AppVersion::display();
	AppVersion::whoAreYou();
	
	AppVersion::Version1::display();

	AppVersion::Version2::display();	
}
