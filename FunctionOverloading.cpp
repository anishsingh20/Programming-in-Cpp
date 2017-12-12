#include<iostream>

using namespace std;

//demonstrates that const functions of a class can be overloaded using const type object of class

class Person {
	
	public:
		void intro() const {
		cout<<"This is const intro"<<endl;
		}
		
		void intro() {
			cout<<"this is intro"<<endl;
		}
	};
	
int main () {
	
	
	Person p1;
	const Person p2; //to access the const member function 
	p1.intro();
	p2.intro();
	
	//function intro() overloaded

	
	return 0;
	
}
