#include<iostream>

using namespace std;

class Person {
	public:
		
		void getname() {
			cout<<"Hi I am Anish"<<endl;
		}
};


//we can access the public members of a class in any other function defined which takes a var of that class type as argument
//or which takes a object of that class as argument
void printName(Person &p) {
	//calling Person class member function using the object as argument
	p->getname();
}


int main() {
	Person p;
	printName(p);
}
