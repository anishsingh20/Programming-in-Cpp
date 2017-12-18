#include<iostream>

//overloading  INCREMENT AND DECREMENT OPERATORS in CPP in PREFIX form

// --x; means first decrement , then do something -this is prefix form

// ++,-- are UNARY operators as they are performed on a single operand

using namespace std;




class Marks {
	int mark;
	public:
		Marks() {
			mark=0;
		}
		
		Marks(int m) {
			mark=m;
		}
		
		void getmark() {
			cout<<"Marks are: "<<mark<<endl;
		}
		
		Marks operator ++ () {
			
			mark += 1 ;// mark = mark+1
			return *this; //this returns the address of the current object of type Marks
		}
		
		friend Marks operator--(Marks &m); 
	};
	
Marks operator--(Marks &m) {
	Marks temp(m);
	temp.mark -= 1;
	return temp;
}


int main () {
	
	Marks m(80);
	
	cout<<"Initially ";
	m.getmark();
	
	cout<<"----------------------"<<endl;
	
	cout<<"Marks increased by one :"<<endl;
	
	(++m).getmark(); //overloading ++ operator in prefix
	
	cout<<"-----------------------------------"<<endl;
	
	cout<<"Marks decreased by one : "<<endl;
	
	(--m).getmark(); //overloading -- operator in prefix
	
	return 0;
}	
