#include<iostream>

using namespace std;
//operator overlaoding example

class marks {
	
	public:
		marks() {
			intmark=0;
			extmark=0;
		}
		
		marks(int im,int em){
			intmark=im;
			extmark=em;
		}
		
		int intmark;
		int extmark;
		void display();
		
		//defining a operator function which return an object of type class marks
		//overloading the + operator method which takes argument as a object and returns an obj
		//now here I can overload any operator and inside the function implement any opeartion using any operator
		
		//let's overload '=' operator
		marks operator+(marks m) {
			marks temp; // a temperarory object
			temp.intmark= intmark + m.intmark;
			temp.extmark = extmark + m.extmark; 
			return temp;
		}
};

void marks::display() {
	cout<<"Internal Marks are: "<<intmark<<endl<<"external marks are: "<<extmark<<endl;
}	






int main () {
	marks m1(89,60),m2(15,55);
	
	marks m = m1 + m2;//'=' overloaded
	
	m.display();
	
	return 0;
}


