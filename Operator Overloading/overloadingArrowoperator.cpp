#include<iostream>

using namespace std;

//overloading -> arrow operator. This operator is also called class member access operator

class Marks {
	
		public:
			int mark;
			Marks(int m) {
				mark = m;
			}
			
			void getmark() {
				cout<<"The marks are : " <<mark<<endl;
			}
			
		  Marks	*operator -> () {
		  	
		  	cout<<"The arrow -> operator is overloaded"<<endl;
		  	
		  	return this;
		  }
		  
};

int main() {
	
	Marks m1(80);
	m1.getmark(); 
	
	//overloading the arrow operator
	m1->getmark();
	return 0;
}
			
