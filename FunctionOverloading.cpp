#include<iostream>

using namespace std;

//demonstrates that const functions of a class can be overloaded using const type object of class

class Person {
	
	public:
		int x=10;//now vlue of x is fixed and constant, and cannot be changed
		//during initialization the value of a const variable is fixed.
		
		void intro() const {
		cout<<"This is const intro"<<endl;
		
		}
		
		void intro() {
			cout<<"this is intro"<<endl;
		}
	};
	
int main () {
	
	
 	Person p1; //non-const object of class Person
	
	const Person p2; //used to access the const member function 
	
	cout<<p2.x<<endl;
	//p2.x=20; with a const object, its data members can never be changed till the lifetime of object.
		
	
	
	//1)  non-const object of class can be used to call and access the const members(variables and methods) of a class,but.
	 
	//2) but a const object of class can only call a const member function of class, but a const object can acess the non-const varibles of class.
	
	p1.intro();// will call the non-const function
	p2.intro(); //will call the const member function
	
	//function intro() overloaded

	
	return 0;
	
}
