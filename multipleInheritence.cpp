#include<iostream>

using namespace std;

class father {
	public:
		int height;
		father() {
			
			cout<<"Father constructor called"<<endl;
			
		}
		
		void getHt() {
			
			cout<<"Height is "<<height<<endl;
		}
		
		
		
	
};

class mother {
	public :
		string skincolor;
		mother() {
			
			
			cout<<"Mother constructor called"<<endl;
		}
		
		void getColor() {
			cout<<"Skin color is "<< skincolor<<endl;
		}
		
	
};


//multiple inheritence
class child: private father, private mother {
	
	public :
	//making the base class members public in derived class
	using father::height;
	using father::getHt;
	using mother::getColor;
	using mother::skincolor;
	//calling parent class constructors and passing arguments to them
		child(int ht,string color) : father() , mother() {
			height=ht;
			skincolor=color;
			cout<<"Child constructor called"<<endl;
			
		}
	
};


int main ()  {
	
	child c(172,"white");
	c.getColor();
	c.getHt();
	
	
	
	return 0;
}
