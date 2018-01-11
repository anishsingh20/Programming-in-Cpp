#include<iostream>


//program to overload = operator
//Special thing about = operator is that the derived class cannot overload = operator function
using namespace std;

class Marks {
	
		public:
			int mark;
			Marks() {
				cout<<"parent class constructor called"<<endl;
			}
			
			Marks(int m) {
				mark = m;
			}
			
			void getmarks() {
				cout<<"The marks are: "<<mark<<endl;
			}
			
			Marks operator = (int m) {
				
				mark = m ;
				
				cout<<"Overloading = operator"<<endl;
				
				return *this;
			}
		};
		
		


int main() {
	Marks m1(90);
	
	m1.getmarks(); //prints 90
	
	//overloading = operator
	Marks m2 = m1 = 85;
	
	m2.getmarks();

	

	
	return 0;
}
