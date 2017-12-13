#include<iostream>

using namespace std;

//inheritence of virtual method attributes, and virtual functions and hierarchy of class

class Person {
	public:
	virtual	void intro() {
			cout<<"Hi I am a person"<<endl;
		}
};

class Anish : public Person { //inherits from class Person
	public:
		void intro() { //function overridden
		
			cout<<"Hi I am Anish derived from class Person"<<endl;
			
		}
		
};


class Mrinal : public Anish { //inherits from class Anish
	public :
		void intro() {
			cout<<"Hi I am Mrinal derived from class Anish"<<endl;
		}
		
};


//making a function which takes the argument as Object of Class Person or refers/pointer to a type Person
void getIntro(Person *p)
{
	p->intro(); //function of derived class will be executed
	
}


int main() 
{
	
	Person *p1,*p2;
	Anish a;
	Mrinal m;
	p1=&a; // pointer p1 of type Person refers the derived(Anish class) object
	p2=&m; //pointer p2 of type Person refers to the derived class of Anish ie Mrinal
	
	p1->intro();
	p2->intro();
	
//	getIntro(p); //person class method called
	getIntro(&a); // Anish class overridden function called
	getIntro(&m); // Mrinal class overridden function called
	
	//without declaring a virtual base class function,the 3 above all function calls would return "Hi I am a person" i.e method of base class due
	//to static binding-binding during compiletime 
	
	
	
	
	return 0;
} 
