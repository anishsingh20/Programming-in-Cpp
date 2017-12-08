#include<iostream>
#include<string>

using namespace std;

class Person {
	public :
		string name;
		 display(string iname) {
			name=iname;
		}		
};

//private inheritence-now the base class members act as private member on derived class-not accessible outside the class 
class Student : private Person {
	public:
		Person :: name; //becomes public
		Person::display;
		setName() {
			cout<<name;
		 	
		}
};


int main () {
	Student s;
	s.display("Anish");//now name set to Anish
//now derived class can access display() outside the class, due to changing the scope(access) level of the base class member function
	s.setName();
	

}
