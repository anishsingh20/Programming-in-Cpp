#include<iostream>

using namespace std;

//overloading ()-function call operator
//one special thing about overloading () operator function is that,only this operator can take default arguments ,no other operator can take default arguments

class Marks {
	
		public:
			int mark;
			Marks(int m) {
				mark = m;
			}
			
			
			//operator function
			Marks operator () (int m=20) {
				
				cout<<"Operator function called"<<endl;
				mark=m;
				
				return *this; //this operator fuction returns the current address of the object
			}
			
	
};

int main () {
	
	Marks m1(90);
	cout<<m1.mark; //prints 90
	
	cout<<"\n";
	m1(); //operator function called
	
	cout<<m1.mark; //now marks is 20
	return 0;
}
