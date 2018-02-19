#include<iostream>

using namespace std;

//const objects and const member functions

class Person {
	public:
		//const class data member
		const int age=20;//has to be initialized, when declared, cannot be initialized inside a constructor
		string name;
		//constructor
		Person(int iage,string iname){
			
//			age=iage; initializing  const data age using constructor produces error
			
			name = iname;
		}

		void getage() const {
			
		cout<<"My age is-"<<age<<endl;
		//age++; produces error as inside a const member function data members of class become const too and value cannot be changed once declared

		}
		
		void getname() { //a non const function which cannot be called by a const object
			
			//age++;
			cout<<"My name is :"<<name<<endl;
			
		}
};


int main () {
	
	Person p(20,"anish");
	Person const p1(30,"Mrinal"); // a const object and a data member cannot be changed using a const object throughtout its lifetime
	
	
	
	p.getage(); //const member function can be called using non-const object too.
	p.getname();
//	p.age=25; error produced- age is read only
	p.getage();//value of age is now 25

	//using const object only for const member functions
	p1.getage();
	// p1.age=25; produces ERROR as when using a const member object,the class data members become constant too i.e read-only and cannot be changed once initialized
	
	//p1.getname(); ERROR as const object cannot call a non-const member function
	
	
	

	
	
	return 0;
	
}
