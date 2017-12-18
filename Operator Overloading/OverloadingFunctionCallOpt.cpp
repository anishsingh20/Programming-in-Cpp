#include<iostream>

using namespace std;

class Marks {
	int mark;
	
	public:
		Marks() 
		{
			mark=0;
		}
		
		Marks(int m) {
			mark=m;
			cout<<"Constructor function called"<<endl;
		}
		
		void getmark() {
			cout<<"Your score is :"<<mark<<endl;
		}
		
		
		Marks operator () (int m) {
			mark = m ;
			cout<<"Operator function called"<<endl;
			return *this; //returns the current object
		}
};


int main() {
	
	Marks m(90); //this is constructor calling, as object is created
	
	m.getmark(); //prints 90
	
	m(85); //overloading () function call operator
	//marks now become 85 
	m.getmark(); //prints 85
	
	return 0;
}
