#include<iostream>

using namespace std;

class father {
	public:
		int height;
		father(int h) {
			height = h ;
			cout<<"Father constructor called"<<endl;
			
		}
		
		void getHt() {
			cout<<"Height is "<<height<<endl;
		}
		
		
		
	
};

class mother {
	public :
		string skincolor;
		mother(string iscolor) {
			
			skincolor = iscolor;
			cout<<"Mother constructor called"<<endl;
		}
		
		void getColor() {
			cout<<"Skin color is "<< skincolor<<endl;
		}
		
	
};


//multiple inheritence
class child: public father, public mother {
	
	public :
	//calling parent class constructors and passing arguments to them
		child(int ht,string color) : father(ht) , mother(color) {
			cout<<"Child constructor called"<<endl;
			
		}
	
};


int main ()  {
	
	child c(172,"white");
	c.getColor();
	c.getHt();
	
	
	
	return 0;
}
