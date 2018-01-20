#include<iostream>

//example program to show overriding of base class methods in derived class-

//when methods in base class and in derived class have same signatures i.e same name, same return type and same no of args, then
//the base class method is overidden by the derived class method-i.e when called using the derived class object, the derived class method will be called not base class.

using namespace std;


class Person {
	public:
		void intro() {
			cout<<"hello I am a person"<<endl;
		}
		
};


class Anish : public Person { //public inheritence
	public:
		void intro() {
			cout<<"Hello I am Anish"<<endl;
//			Person::intro();
		}
	
};


int main() {
	
	Anish *a= new Anish;
	
	a->intro(); //derived class method is called , not base class . Although derived class has access to base class method too, but it is overidden
	
	cout<<"\n";
	//to access the Base class overloaded method
	//use
	a->Person::intro();
	
}

