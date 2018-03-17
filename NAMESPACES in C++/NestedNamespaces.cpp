#include<iostream>

using namespace std;


//Nested namespaces- we can nest a namesapce inside another namespace

namespace parent {

	int x ;
	
	namespace child{
	
		//overriding x
		int x=100;
		void display()
		{
			cout<<x<<endl;
		}
	}
	
	
	//re-defining the child namespace
	namespace child{
		
		int y;
		
		void howareyou()
		{
			cout<<y<<endl;
		}
		
	}
	
	void display()
	{
		cout<<x;
	}
}

int main()
{
	parent::x=10;
	parent::display();
	cout<<endl;
	parent::child::display();
	
	parent::child::y=200;
	parent::child::howareyou();
	
}
