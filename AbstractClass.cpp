#include<iostream>


//Pure virtual functions are virtual funcions which have no defination or implementation in base class.
//but those pure virtual functions are overridden(re-defined) in the derived class 
//Abstract Class- A class which has one or more pure virtual functions. A abstract class can have no object

using namespace std;

class Person {
	public:
		virtual void intro() = 0; //defination of a pure virtual function which has no defination in base class
};


//pure virtual function can also be defined outside a base class using a scope resolution operator
void Person :: intro() {
	cout<<"Hi this is a person"<<endl;
}

class Anish : public Person {
	public:
		void intro() {//function overridden in derived class
		
			cout<<"Hi I am Anish"<<endl;
			//Person::intro(); //calling pure virtual function 		
		}
			
};

void getIntro(Person *p) 
{
	p->intro();
	
}

int main() {
	// Person p; absatract classes cannot have objects
	Anish a;
	a.intro();
	getIntro(&a);
	a.Person::intro(); //accessing the base class intro() function, though it is a pure virtual function
	
	
	return 0;
}
