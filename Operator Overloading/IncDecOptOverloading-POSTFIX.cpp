#include<iostream>

using namespace std;

//overloading  INCREMENT AND DECREMENT OPERATORS in CPP in POSTFIX form- we need to pass and argumene to the operator function

// --x; means first decrement , then do something -this is prefix form

// ++,-- are UNARY operators as they are performed on a single operand



class Marks {
	int mark;
	public:
		Marks() {
			mark=0;
		}
		
		Marks(int m) {
			mark=m;
		}
		
		void getMark() {
			cout<<"Marks are: "<<mark<<endl;
		}
		
		Marks operator++(int) {
			Marks duplicate(*this); //making a duplicate object which is copy of current object
			mark += 1;
			return duplicate;
		}
		
		friend Marks operator--(Marks &m,int) ;
};


Marks operator--(Marks &m,int) {
	Marks duplicate(m);
	m.mark -= 1;
	return duplicate;
}



int main()
{

	Marks m(90);
	
	cout<<"Initially ";
	m.getMark();
	
	cout<<"----------------------"<<endl;
	
	cout<<"Marks increased by one :"<<endl;
	
	(m++).getMark(); //first old value is printed, then it is increased
	
	m.getMark(); //will now print incremented value	
	
	cout<<"-----------------------------------"<<endl;
	
	cout<<"Marks decreased by one : "<<endl;
	
	(m--).getMark();//first old value printed , then decremented
	
	m.getMark();//now decremented value is printed 
	
	return 0;
}
